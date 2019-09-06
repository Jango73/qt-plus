
// Qt
#include <QWaitCondition>
#include <QDateTime>
#include <QDebug>

// Application
#include "CAssemblyEngine.h"

//-------------------------------------------------------------------------------------------------
// Constants
// https://github.com/zester/Quantum/tree/master/QTermWidget

//-------------------------------------------------------------------------------------------------

static void msleep(unsigned long msecs)
{
    QMutex mutex;
    mutex.lock();

    QWaitCondition waitCondition;
    waitCondition.wait(&mutex, msecs);

    mutex.unlock(); // Not necessary since new mutex will always be created,
    // but since destroying locked mutex
    // is bringing undefined behavior, let's follow some ethics
}

//-------------------------------------------------------------------------------------------------

CAssemblyEngine::CAssemblyEngine()
    : m_pMachine(new CAssemblyMachine())
    , m_iColumns(CONSOLE_W)
    , m_iRows(CONSOLE_H)
{
    connect(m_pMachine, SIGNAL(executing(const QString&)), this, SLOT(onExecuting(const QString&)));
    connect(m_pMachine, SIGNAL(consoleCharChanged(qint32, qint32, qint32)), this, SLOT(onConsoleCharChanged(qint32, qint32, qint32)));
}

//-------------------------------------------------------------------------------------------------

CAssemblyEngine::~CAssemblyEngine()
{
    delete m_pMachine;
}

//-------------------------------------------------------------------------------------------------

QString CAssemblyEngine::compileErrors() const
{
    return m_pMachine->compileErrors();
}

//-------------------------------------------------------------------------------------------------

QString CAssemblyEngine::text() const
{
    return m_sText;
}

//-------------------------------------------------------------------------------------------------

QString CAssemblyEngine::currentInstruction() const
{
    return m_pMachine->currentInstruction();
}

//-------------------------------------------------------------------------------------------------

int CAssemblyEngine::currentLine() const
{
    return m_pMachine->currentLine();
}

//-------------------------------------------------------------------------------------------------

CAssemblyMachine::CRegisters CAssemblyEngine::registers() const
{
    return m_pMachine->registers();
}

//-------------------------------------------------------------------------------------------------

QByteArray CAssemblyEngine::stack(int iFrom, int iCount) const
{
    return m_pMachine->stack().mid(iFrom, iCount);
}

//-------------------------------------------------------------------------------------------------

int CAssemblyEngine::evaluate(const QString& sCode, int iOperand1, int iOperand2, int iOperand3, int iOperand4, bool bDebug)
{
    m_pMachine->setDebug(bDebug);

    if (m_pMachine->code() != sCode)
    {
        m_pMachine->setCode(sCode);
        m_pMachine->compile();
    }

    return m_pMachine->run(iOperand1, iOperand2, iOperand3, iOperand4);
}

//-------------------------------------------------------------------------------------------------

void CAssemblyEngine::onExecuting(const QString& sText)
{
    emit executing(sText);
}

//-------------------------------------------------------------------------------------------------

void CAssemblyEngine::onConsoleCharChanged(qint32 x, qint32 y, qint32 c)
{
    emit consoleCharChanged(x, y, c);
}

//-------------------------------------------------------------------------------------------------

CAssemblyMachine::CAssemblyMachine()
    : m_iLine(0)
    , m_iColumn(0)
    , m_bDebug(false)
{
    m_mOpcodeToString[Op_A1] = "A1";
    m_mOpcodeToString[Op_A2] = "A2";
    m_mOpcodeToString[Op_A3] = "A3";
    m_mOpcodeToString[Op_A4] = "A4";
    m_mOpcodeToString[Op_A5] = "A5";
    m_mOpcodeToString[Op_A6] = "A6";
    m_mOpcodeToString[Op_A7] = "A7";
    m_mOpcodeToString[Op_A8] = "A8";
    m_mOpcodeToString[Op_D1] = "D1";
    m_mOpcodeToString[Op_D2] = "D2";
    m_mOpcodeToString[Op_D3] = "D3";
    m_mOpcodeToString[Op_D4] = "D4";
    m_mOpcodeToString[Op_D5] = "D5";
    m_mOpcodeToString[Op_D6] = "D6";
    m_mOpcodeToString[Op_D7] = "D7";
    m_mOpcodeToString[Op_D8] = "D8";
    m_mOpcodeToString[Op_AtA1] = "[A1";
    m_mOpcodeToString[Op_AtA2] = "[A2";
    m_mOpcodeToString[Op_AtA3] = "[A3";
    m_mOpcodeToString[Op_AtA4] = "[A4";
    m_mOpcodeToString[Op_AtA5] = "[A5";
    m_mOpcodeToString[Op_AtA6] = "[A6";
    m_mOpcodeToString[Op_AtA7] = "[A7";
    m_mOpcodeToString[Op_AtA8] = "[A8";
    m_mOpcodeToString[Op_Byte] = "@b";
    m_mOpcodeToString[Op_Word] = "@w";
    m_mOpcodeToString[Op_Long] = "@l";
    m_mOpcodeToString[Op_Move] = "<";
    m_mOpcodeToString[Op_Add] = "+";
    m_mOpcodeToString[Op_Sub] = "-";
    m_mOpcodeToString[Op_Mul] = "*";
    m_mOpcodeToString[Op_Div] = "/";
    m_mOpcodeToString[Op_Shl] = "<<";
    m_mOpcodeToString[Op_Shr] = ">>";
    m_mOpcodeToString[Op_And] = "&";
    m_mOpcodeToString[Op_Or] = "|";
    m_mOpcodeToString[Op_Xor] = "^";
    m_mOpcodeToString[Op_Cmp] = "?";
    m_mOpcodeToString[Op_Push] = "-<";
    m_mOpcodeToString[Op_Pop] = "->";
    m_mOpcodeToString[Op_Jump] = "=|>";
    m_mOpcodeToString[Op_JumpIfSame] = "==>";
    m_mOpcodeToString[Op_JumpIfNotSame] = "=!>";
    m_mOpcodeToString[Op_JumpIfGreater] = "=>>";
    m_mOpcodeToString[Op_JumpIfLower] = "=<>";
    m_mOpcodeToString[Op_Call] = "=>";
    m_mOpcodeToString[Op_Ret] = "<=";
    m_mOpcodeToString[Op_Int] = "!!";

    reset();
}

//-------------------------------------------------------------------------------------------------

CAssemblyMachine::~CAssemblyMachine()
{
}

//-------------------------------------------------------------------------------------------------

int CAssemblyMachine::run(int iOperand1, int iOperand2, int iOperand3, int iOperand4)
{
    reset();

    m_rCPU.D1 = iOperand1;
    m_rCPU.D2 = iOperand2;
    m_rCPU.D3 = iOperand3;
    m_rCPU.D4 = iOperand4;

    pushInt32(0);

    while (true)
    {
        if (processNextInstruction())
            break;

        if (m_bDebug)
            msleep(10);
    }

    return m_rCPU.D1;
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::setCode(const QString& sCode)
{
    m_sCode = sCode;
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::setDebug(bool value)
{
    m_bDebug = value;
}

//-------------------------------------------------------------------------------------------------

QString CAssemblyMachine::code() const
{
    return m_sCode;
}

//-------------------------------------------------------------------------------------------------

QByteArray& CAssemblyMachine::data()
{
    return m_baData;
}

//-------------------------------------------------------------------------------------------------

QByteArray& CAssemblyMachine::stack()
{
    return m_baStack;
}

//-------------------------------------------------------------------------------------------------

bool CAssemblyMachine::processNextInstruction()
{
    EOpCode leftOpCode = Op_Nop;
    EOpCode centerOpCode = Op_Nop;
    EOpCode rightOpCode = Op_Nop;
    qint32 iLeftValue = 0;
    qint32 iRightValue = 0;

    if (m_rCPU.IP < m_baData.size())
    {
        qint32 offset = readOpcodes(m_baData.constData() + m_rCPU.IP, &leftOpCode, &centerOpCode, &rightOpCode, &iLeftValue, &iRightValue);

        if (m_bDebug)
            emit executing(QString("%1 : %2").arg(currentLine()).arg(disassemble(m_baData.constData() + m_rCPU.IP).first));

        m_rCPU.IP += offset;

        if (leftOpCode == Op_Nop)
        {
            return false;
        }
        else if (leftOpCode == Op_Ret)
        {
            qint32 newIP = popInt32();

            if (newIP == 0)
            {
                if (m_bDebug)
                    emit executing("Return to IP 0");

                return true;
            }

            m_rCPU.IP = newIP;
        }
        else if (isSize(leftOpCode))
        {
            switch (leftOpCode)
            {
            default:
            case Op_Byte:
            {
                m_rCPU.Flags.Bits.m_iSize = REG_SIZE_BYTE;
                break;
            }
            case Op_Word:
            {
                m_rCPU.Flags.Bits.m_iSize = REG_SIZE_WORD;
                break;
            }
            case Op_Long:
            {
                m_rCPU.Flags.Bits.m_iSize = REG_SIZE_LONG;
                break;
            }
            }

            return false;
        }

        switch (centerOpCode)
        {
        case Op_Move:
            writeRegister(leftOpCode, iRightValue);
            break;

        case Op_Add:
            switch (m_rCPU.Flags.Bits.m_iSize)
            {
            case REG_SIZE_BYTE:
                writeRegister(leftOpCode, qint8(iLeftValue) + qint8(iRightValue));
                break;
            case REG_SIZE_WORD:
                writeRegister(leftOpCode, qint16(iLeftValue) + qint16(iRightValue));
                break;
            case REG_SIZE_LONG:
                writeRegister(leftOpCode, qint32(iLeftValue) + qint32(iRightValue));
                break;
            }
            break;

        case Op_Sub:
            switch (m_rCPU.Flags.Bits.m_iSize)
            {
            case REG_SIZE_BYTE:
                writeRegister(leftOpCode, qint8(iLeftValue) - qint8(iRightValue));
                break;
            case REG_SIZE_WORD:
                writeRegister(leftOpCode, qint16(iLeftValue) - qint16(iRightValue));
                break;
            case REG_SIZE_LONG:
                writeRegister(leftOpCode, qint32(iLeftValue) - qint32(iRightValue));
                break;
            }
            break;

        case Op_Mul:
            switch (m_rCPU.Flags.Bits.m_iSize)
            {
            case REG_SIZE_BYTE:
                writeRegister(leftOpCode, qint8(iLeftValue) * qint8(iRightValue));
                break;
            case REG_SIZE_WORD:
                writeRegister(leftOpCode, qint16(iLeftValue) * qint16(iRightValue));
                break;
            case REG_SIZE_LONG:
                writeRegister(leftOpCode, qint32(iLeftValue) * qint32(iRightValue));
                break;
            }
            break;

        case Op_Div:
            if (iRightValue != 0)
            {
                switch (m_rCPU.Flags.Bits.m_iSize)
                {
                case REG_SIZE_BYTE:
                    writeRegister(leftOpCode, qint8(iLeftValue) / qint8(iRightValue));
                    break;
                case REG_SIZE_WORD:
                    writeRegister(leftOpCode, qint16(iLeftValue) / qint16(iRightValue));
                    break;
                case REG_SIZE_LONG:
                    writeRegister(leftOpCode, qint32(iLeftValue) / qint32(iRightValue));
                    break;
                }
            }
            else
            {
                writeRegister(leftOpCode, 0);
            }
            break;

        case Op_Shl:
            switch (m_rCPU.Flags.Bits.m_iSize)
            {
            case REG_SIZE_BYTE:
                writeRegister(leftOpCode, qint8(iLeftValue) << qint8(iRightValue));
                break;
            case REG_SIZE_WORD:
                writeRegister(leftOpCode, qint16(iLeftValue) << qint16(iRightValue));
                break;
            case REG_SIZE_LONG:
                writeRegister(leftOpCode, qint32(iLeftValue) << qint32(iRightValue));
                break;
            }
            break;

        case Op_Shr:
            switch (m_rCPU.Flags.Bits.m_iSize)
            {
            case REG_SIZE_BYTE:
                writeRegister(leftOpCode, qint8(iLeftValue) >> qint8(iRightValue));
                break;
            case REG_SIZE_WORD:
                writeRegister(leftOpCode, qint16(iLeftValue) >> qint16(iRightValue));
                break;
            case REG_SIZE_LONG:
                writeRegister(leftOpCode, qint32(iLeftValue) >> qint32(iRightValue));
                break;
            }
            break;

        case Op_And:
            switch (m_rCPU.Flags.Bits.m_iSize)
            {
            case REG_SIZE_BYTE:
                writeRegister(leftOpCode, qint8(iLeftValue) & qint8(iRightValue));
                break;
            case REG_SIZE_WORD:
                writeRegister(leftOpCode, qint16(iLeftValue) & qint16(iRightValue));
                break;
            case REG_SIZE_LONG:
                writeRegister(leftOpCode, qint32(iLeftValue) & qint32(iRightValue));
                break;
            }
            break;

        case Op_Or:
            switch (m_rCPU.Flags.Bits.m_iSize)
            {
            case REG_SIZE_BYTE:
                writeRegister(leftOpCode, qint8(iLeftValue) | qint8(iRightValue));
                break;
            case REG_SIZE_WORD:
                writeRegister(leftOpCode, qint16(iLeftValue) | qint16(iRightValue));
                break;
            case REG_SIZE_LONG:
                writeRegister(leftOpCode, qint32(iLeftValue) | qint32(iRightValue));
                break;
            }
            break;

        case Op_Xor:
            switch (m_rCPU.Flags.Bits.m_iSize)
            {
            case REG_SIZE_BYTE:
                writeRegister(leftOpCode, qint8(iLeftValue) ^ qint8(iRightValue));
                break;
            case REG_SIZE_WORD:
                writeRegister(leftOpCode, qint16(iLeftValue) ^ qint16(iRightValue));
                break;
            case REG_SIZE_LONG:
                writeRegister(leftOpCode, qint32(iLeftValue) ^ qint32(iRightValue));
                break;
            }
            break;

        case Op_Cmp:
            switch (m_rCPU.Flags.Bits.m_iSize)
            {
            case REG_SIZE_BYTE:
                m_rCPU.Flags.Bits.m_iSame = (qint8(iLeftValue) == qint8(iRightValue));
                m_rCPU.Flags.Bits.m_iGreater = (qint8(iLeftValue) > qint8(iRightValue));
                m_rCPU.Flags.Bits.m_iLower = (qint8(iLeftValue) < qint8(iRightValue));
                break;
            case REG_SIZE_WORD:
                m_rCPU.Flags.Bits.m_iSame = (qint16(iLeftValue) == qint16(iRightValue));
                m_rCPU.Flags.Bits.m_iGreater = (qint16(iLeftValue) > qint16(iRightValue));
                m_rCPU.Flags.Bits.m_iLower = (qint16(iLeftValue) < qint16(iRightValue));
                break;
            case REG_SIZE_LONG:
                m_rCPU.Flags.Bits.m_iSame = (iLeftValue == iRightValue);
                m_rCPU.Flags.Bits.m_iGreater = (iLeftValue > iRightValue);
                m_rCPU.Flags.Bits.m_iLower = (iLeftValue < iRightValue);
                break;
            }
            break;

        case Op_Call:
            pushInt32(m_rCPU.IP);

            m_rCPU.IP = iRightValue;

            if (m_rCPU.IP >= m_baData.count())
            {
                return true;
            }
            break;

        case Op_Int:
            switch (iRightValue)
            {
            case INT_MEM:
                handleInt_Mem();

            case INT_TIME:
                handleInt_Time();

            case INT_FILE:
                handleInt_File();

            case INT_THREAD:
                handleInt_Thread();

            default:
                break;
            }
            break;

        case Op_Push:
            pushInt32(iRightValue);
            break;

        case Op_Pop:
            writeRegister(rightOpCode, popInt32());
            break;

        case Op_Not:
            writeRegister(rightOpCode, !iRightValue);
            break;

        case Op_Jump:
            m_rCPU.IP = iRightValue;
            break;

        case Op_JumpIfSame:
            if (m_rCPU.Flags.Bits.m_iSame)
                m_rCPU.IP = iRightValue;
            break;

        case Op_JumpIfNotSame:
            if (!m_rCPU.Flags.Bits.m_iSame)
                m_rCPU.IP = iRightValue;
            break;

        case Op_JumpIfGreater:
            if (m_rCPU.Flags.Bits.m_iGreater)
                m_rCPU.IP = iRightValue;
            break;

        case Op_JumpIfLower:
            if (m_rCPU.Flags.Bits.m_iLower)
                m_rCPU.IP = iRightValue;
            break;

        default:
            break;
        }
    }
    else
    {
        return true;
    }

    return false;
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::readOpcodes(const char* pCode, EOpCode* leftOpCode, EOpCode* centerOpCode, EOpCode* rightOpCode, qint32* iLeftValue, qint32* iRightValue) const
{
    qint32 offset = 0;

    *leftOpCode = EOpCode(quint8(pCode[offset]));
    offset += sizeof(quint8);

    if (*leftOpCode == Op_Nop)
    {
        return offset;
    }
    else if (*leftOpCode == Op_Ret || isSize(*leftOpCode))
    {
        return offset;
    }
    else
    {
        if (isOperand(*leftOpCode))
        {
            *centerOpCode = EOpCode(quint8(pCode[offset]));
            offset += sizeof(quint8);
        }
        else
        {
            *centerOpCode = *leftOpCode;
        }

        *rightOpCode = EOpCode(quint8(pCode[offset]));
        offset += sizeof(quint8);

        *iLeftValue = readRegister(*leftOpCode);

        if (isConstant(*rightOpCode))
        {
            *iRightValue = *((qint32*)(pCode + offset));
            offset += sizeof(qint32);
        }
        else
        {
            *iRightValue = readRegister(*rightOpCode);
        }
    }

    return offset;
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::pushInt8(quint8 iValue)
{
    if (m_rCPU.SP + int(sizeof(quint8)) < m_baStack.count())
    {
        m_baStack[m_rCPU.SP] = iValue;
        m_rCPU.SP += sizeof(quint8);
    }
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::pushInt32(qint32 iValue)
{
    if (m_rCPU.SP + int(sizeof(qint32)) < m_baStack.count())
    {
        *((qint32*)(m_baStack.data() + m_rCPU.SP)) = iValue;
        m_rCPU.SP += sizeof(qint32);
    }
}

//-------------------------------------------------------------------------------------------------

quint8 CAssemblyMachine::popInt8()
{
    if (m_rCPU.SP >= int(sizeof(quint8)))
    {
        m_rCPU.SP -= sizeof(quint8);
        return m_baStack[m_rCPU.SP];
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::popInt32()
{
    if (m_rCPU.SP >= int(sizeof(qint32)))
    {
        m_rCPU.SP -= sizeof(qint32);
        return *((qint32*)(m_baStack.data() + m_rCPU.SP));
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::readRegister(EOpCode eCode) const
{
    switch (eCode)
    {
    case Op_A1: return m_rCPU.A1;
    case Op_A2: return m_rCPU.A2;
    case Op_A3: return m_rCPU.A3;
    case Op_A4: return m_rCPU.A4;
    case Op_A5: return m_rCPU.A5;
    case Op_A6: return m_rCPU.A6;
    case Op_A7: return m_rCPU.A7;
    case Op_A8: return m_rCPU.A8;

    case Op_D1: return m_rCPU.D1;
    case Op_D2: return m_rCPU.D2;
    case Op_D3: return m_rCPU.D3;
    case Op_D4: return m_rCPU.D4;
    case Op_D5: return m_rCPU.D5;
    case Op_D6: return m_rCPU.D6;
    case Op_D7: return m_rCPU.D7;
    case Op_D8: return m_rCPU.D8;

    case Op_AtA1: return readRam(m_rCPU.A1);
    case Op_AtA2: return readRam(m_rCPU.A2);
    case Op_AtA3: return readRam(m_rCPU.A3);
    case Op_AtA4: return readRam(m_rCPU.A4);
    case Op_AtA5: return readRam(m_rCPU.A5);
    case Op_AtA6: return readRam(m_rCPU.A6);
    case Op_AtA7: return readRam(m_rCPU.A7);
    case Op_AtA8: return readRam(m_rCPU.A8);

    default : return 0;
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::writeRegister(EOpCode eCode, qint32 iValue)
{
    switch (eCode)
    {
    case Op_A1: m_rCPU.A1 = iValue; break;
    case Op_A2: m_rCPU.A2 = iValue; break;
    case Op_A3: m_rCPU.A3 = iValue; break;
    case Op_A4: m_rCPU.A4 = iValue; break;
    case Op_A5: m_rCPU.A5 = iValue; break;
    case Op_A6: m_rCPU.A6 = iValue; break;
    case Op_A7: m_rCPU.A7 = iValue; break;
    case Op_A8: m_rCPU.A8 = iValue; break;

    case Op_D1: m_rCPU.D1 = iValue; break;
    case Op_D2: m_rCPU.D2 = iValue; break;
    case Op_D3: m_rCPU.D3 = iValue; break;
    case Op_D4: m_rCPU.D4 = iValue; break;
    case Op_D5: m_rCPU.D5 = iValue; break;
    case Op_D6: m_rCPU.D6 = iValue; break;
    case Op_D7: m_rCPU.D7 = iValue; break;
    case Op_D8: m_rCPU.D8 = iValue; break;

    case Op_AtA1: writeRam(m_rCPU.A1, iValue); break;
    case Op_AtA2: writeRam(m_rCPU.A2, iValue); break;
    case Op_AtA3: writeRam(m_rCPU.A3, iValue); break;
    case Op_AtA4: writeRam(m_rCPU.A4, iValue); break;
    case Op_AtA5: writeRam(m_rCPU.A5, iValue); break;
    case Op_AtA6: writeRam(m_rCPU.A6, iValue); break;
    case Op_AtA7: writeRam(m_rCPU.A7, iValue); break;
    case Op_AtA8: writeRam(m_rCPU.A8, iValue); break;

    default: break;
    }
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::readRam(qint32 iAddress) const
{
    qint32 iReturnValue = 0;

    switch (m_rCPU.Flags.Bits.m_iSize)
    {
    case REG_SIZE_BYTE:
    {
        if (iAddress + int(sizeof(qint8)) < m_baData.count())
        {
            iReturnValue = *((qint8*)(m_baData.data() + iAddress));
        }

        break;
    }

    case REG_SIZE_WORD:
    {
        if (iAddress + int(sizeof(qint16)) < m_baData.count())
        {
            iReturnValue = *((qint16*)(m_baData.data() + iAddress));
        }

        break;
    }

    case REG_SIZE_LONG:
    {
        if (iAddress + int(sizeof(qint32)) < m_baData.count())
        {
            iReturnValue = *((qint32*)(m_baData.data() + iAddress));
        }

        break;
    }
    }

    return iReturnValue;
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::writeRam(qint32 iAddress, qint32 iValue)
{
    switch (m_rCPU.Flags.Bits.m_iSize)
    {
    case REG_SIZE_BYTE:
    {
        if (iAddress + int(sizeof(qint8)) < m_baData.count())
        {
            *((qint8*)(m_baData.data() + iAddress)) = qint8(iValue);
        }

        break;
    }

    case REG_SIZE_WORD:
    {
        if (iAddress + int(sizeof(qint16)) < m_baData.count())
        {
            *((qint16*)(m_baData.data() + iAddress)) = qint16(iValue);
        }

        break;
    }

    case REG_SIZE_LONG:
    {
        if (iAddress + int(sizeof(qint32)) < m_baData.count())
        {
            *((qint32*)(m_baData.data() + iAddress)) = iValue;
        }

        break;
    }
    }

    if (iAddress >= RAM_CONSOLE_LOW && iAddress < RAM_CONSOLE_HIGH)
    {
        qint32 stride = CONSOLE_W * sizeof(qint32);
        qint32 y = (iAddress - RAM_CONSOLE_LOW) / stride;
        qint32 x = ((iAddress - RAM_CONSOLE_LOW) % stride) / sizeof(qint32);

        emit consoleCharChanged(x, y, iValue);
    }
}

//-------------------------------------------------------------------------------------------------

quint8* CAssemblyMachine::addressToPointer(qint32 iAddress)
{
    if (iAddress < m_baData.count())
    {
        return (quint8*) m_baData.data() + iAddress;
    }

    return nullptr;
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::reset()
{
    // Reset RAM

    m_baData.clear();
    m_baData.fill(0, RAM_USER);
    m_baData.append(m_baCode);
    m_baData.append(QByteArray().fill(0, 65536));

    m_baStack.clear();
    m_baStack.fill(0, 1024);

    // Reset CPU

    m_rCPU.IP = RAM_USER;
    m_rCPU.SP = 0;
    m_rCPU.A1 = 0;
    m_rCPU.A2 = 0;
    m_rCPU.A3 = 0;
    m_rCPU.A4 = 0;
    m_rCPU.A5 = 0;
    m_rCPU.A6 = 0;
    m_rCPU.A7 = 0;
    m_rCPU.A8 = 0;
    m_rCPU.D1 = 0;
    m_rCPU.D2 = 0;
    m_rCPU.D3 = 0;
    m_rCPU.D4 = 0;
    m_rCPU.D5 = 0;
    m_rCPU.D6 = 0;
    m_rCPU.D7 = 0;
    m_rCPU.D8 = 0;

    m_rCPU.Flags.Bits.m_iSame = 0;
    m_rCPU.Flags.Bits.m_iLower = 0;
    m_rCPU.Flags.Bits.m_iGreater = 0;
    m_rCPU.Flags.Bits.m_iSize = REG_SIZE_LONG;

    // Reset OS

    m_baMemAlloc.clear();

    foreach (QFile* pFile, m_vFiles) delete pFile;
    m_vFiles.clear();
    m_vFiles << new QFile("dummy");
}

//-------------------------------------------------------------------------------------------------

QString CAssemblyMachine::currentInstruction() const
{
    if (m_rCPU.IP < m_baData.size())
    {
        return disassemble(m_baData.constData() + m_rCPU.IP).first;
    }

    return "";
}

//-------------------------------------------------------------------------------------------------

int CAssemblyMachine::currentLine() const
{
    qint32 iInstructionAddress = m_rCPU.IP - RAM_USER;

    if (m_mLines.contains(iInstructionAddress))
    {
        return m_mLines[iInstructionAddress] + 1;
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

CAssemblyMachine::CRegisters CAssemblyMachine::registers() const
{
    return m_rCPU;
}

//-------------------------------------------------------------------------------------------------

bool CAssemblyMachine::isOperand(EOpCode eOpCode) const
{
    return (eOpCode >= Op_A1 && eOpCode <= Op_Literal);
}

//-------------------------------------------------------------------------------------------------

bool CAssemblyMachine::isConstant(EOpCode eOpCode) const
{
    return (eOpCode == Op_Constant);
}

//-------------------------------------------------------------------------------------------------

bool CAssemblyMachine::isLabel(EOpCode eOpCode) const
{
    return (eOpCode == Op_Label);
}

//-------------------------------------------------------------------------------------------------

bool CAssemblyMachine::isIdentifier(EOpCode eOpCode) const
{
    return (eOpCode == Op_Identifier);
}

//-------------------------------------------------------------------------------------------------

bool CAssemblyMachine::isLiteral(EOpCode eOpCode) const
{
    return (eOpCode == Op_Literal);
}

//-------------------------------------------------------------------------------------------------

bool CAssemblyMachine::isSize(EOpCode eOpCode) const
{
    return (eOpCode >= Op_Byte && eOpCode <= Op_Long);
}
