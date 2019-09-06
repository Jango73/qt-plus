
// Qt
#include <QDebug>
#include <QDataStream>

// Application
#include "CAssemblyEngine.h"

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::compile()
{
    m_iTokenIndex = 0;
    m_iLine = 0;
    m_iColumn = 0;

    m_baCode.clear();
    m_mLabels.clear();
    m_mLabelReferences.clear();
    m_mIdentifiers.clear();
    m_mLines.clear();
    m_sCompileErrors.clear();

    QDataStream sCodeStream(&m_baCode, QIODevice::WriteOnly);
    sCodeStream.setByteOrder(QDataStream::LittleEndian);

    while (true)
    {
        EOpCode leftOpCode = nextOpCode();

        if (leftOpCode == Op_EOF)
            break;

        if (leftOpCode != Op_Ignore)
        {
            m_mLines[m_baCode.count()] = m_iLine;

            if (isOperand(leftOpCode))
            {
                if (leftOpCode == Op_Label)
                {
                    m_mLabels[m_sLabel] = m_baCode.count();
                }
                else
                {
                    EOpCode centerOpCode = nextOpCode();

                    if (centerOpCode == Op_EOF)
                    {
                        addError("Expected opcode, got EOF");
                        break;
                    }

                    EOpCode rightOpCode = nextOpCode();

                    if (rightOpCode == Op_EOF)
                    {
                        addError("Expected opcode, got EOF");
                        break;
                    }

                    if (isConstant(leftOpCode))
                    {
                        addError("Left operand cannot be a constant");
                        break;
                    }

                    if (isLiteral(leftOpCode))
                    {
                        addError("Left operand cannot be a literal");
                        break;
                    }

                    if (isIdentifier(leftOpCode))
                    {
                        if (isConstant(rightOpCode))
                        {
                            m_mIdentifiers[m_sIdentifier] = m_sConstant.toInt();
                        }
                        else
                        {
                            addError("Can only assign a constant to an identifier");
                            break;
                        }
                    }
                    else
                    {
                        sCodeStream << quint8(leftOpCode);
                        sCodeStream << quint8(centerOpCode);

                        if (isConstant(rightOpCode))
                        {
                            sCodeStream << quint8(rightOpCode);
                            sCodeStream << qint32(m_sConstant.toInt());
                        }
                        else if (isLabel(rightOpCode))
                        {
                            sCodeStream << quint8(Op_Constant);

                            m_mLabelReferences << QPair<qint32, QString>(m_baCode.count(), m_sLabel);

                            sCodeStream << qint32(0);
                        }
                        else if (isIdentifier(rightOpCode))
                        {
                            sCodeStream << quint8(Op_Constant);

                            sCodeStream << qint32(m_mIdentifiers.contains(m_sIdentifier) ? m_mIdentifiers[m_sIdentifier] : 0);
                        }
                        else
                        {
                            sCodeStream << quint8(rightOpCode);
                        }
                    }
                }
            }
            else
            {
                if (leftOpCode == Op_Ret || isSize(leftOpCode))
                {
                    sCodeStream << qint8(leftOpCode);
                }
                else
                {
                    EOpCode rightOpCode = nextOpCode();

                    if (isOperand(rightOpCode))
                    {
                        if (leftOpCode == Op_ResBytes)
                        {
                            if (isConstant(rightOpCode))
                            {
                                int count = m_sConstant.toInt();

                                count = qBound<int>(0, count, 4096);

                                for (int index = 0; index < count; index++)
                                {
                                    sCodeStream << qint8(0);
                                }
                            }
                            else if (isLiteral(rightOpCode))
                            {
                                for (int index = 0; index < m_sLiteral.count(); index++)
                                {
                                    sCodeStream << qint8(m_sLiteral[index].toLatin1());
                                }

                                sCodeStream << qint8(0);
                            }
                            else
                            {
                                addError("Reserved data can only be made with a constant or a literal");
                                break;
                            }
                        }
                        else
                        {
                            sCodeStream << quint8(leftOpCode);

                            if (isConstant(rightOpCode))
                            {
                                sCodeStream << quint8(rightOpCode);
                                sCodeStream << qint32(m_sConstant.toInt());
                            }
                            else if (isLabel(rightOpCode))
                            {
                                sCodeStream << quint8(Op_Constant);

                                m_mLabelReferences << QPair<qint32, QString>(m_baCode.count(), m_sLabel);

                                sCodeStream << qint32(0);
                            }
                            else
                            {
                                sCodeStream << quint8(rightOpCode);
                            }
                        }
                    }
                    else
                    {
                        addError("Expected operand, got operator");
                        break;
                    }
                }
            }
        }
    }

    // Solve references

    for (auto tReference : m_mLabelReferences)
    {
        qint32 iAddressToSet = tReference.first;
        qint32 iAddressOfLabel = m_mLabels[tReference.second];

        if (iAddressToSet + int(sizeof(qint32)) <= m_baCode.count())
        {
            *((qint32*)(m_baCode.data() + iAddressToSet)) = RAM_USER + iAddressOfLabel;
        }
    }

    if (m_baCode.count() == 0)
    {
        addError("Empty code");
    }

    // Clear members
    m_sConstant.clear();
    m_sLabel.clear();
    m_sIdentifier.clear();
    m_sLiteral.clear();
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::addError(const QString& sText)
{
    m_sCompileErrors += QString("<Line %1> %2").arg(m_iLine).arg(sText);
}

//-------------------------------------------------------------------------------------------------

QString CAssemblyMachine::compileErrors() const
{
    return m_sCompileErrors;
}

//-------------------------------------------------------------------------------------------------

CAssemblyMachine::EOpCode CAssemblyMachine::nextOpCode()
{
    QChar c = m_sCode[m_iTokenIndex++].toLower();
    QChar d, e;

    while (c.isSpace())
    {
        if (c == '\n')
            m_iLine++;

        if (m_iTokenIndex == m_sCode.length())
        {
            return Op_EOF;
        }
        c = m_sCode[m_iTokenIndex++].toLower();
    }

    bool bIndexedOperand = false;

    if (c == '[')
    {
        // The operand is indexed

        bIndexedOperand = true;

        if (m_iTokenIndex < m_sCode.length())
        {
            c = m_sCode[m_iTokenIndex++].toLower();
        }
        else
        {
            return Op_EOF;
        }
    }

    if (c == ':')
    {
        // Read a label

        m_sLabel.clear();

        if (m_iTokenIndex < m_sCode.length())
        {
            c = m_sCode[m_iTokenIndex++];
        }
        else
        {
            return Op_EOF;
        }

        while (c.isSpace() == false)
        {
            m_sLabel += QString(c);

            if (m_iTokenIndex == m_sCode.length())
            {
                break;
            }

            c = m_sCode[m_iTokenIndex++];
        }

        return Op_Label;
    }

    if (c == '\'')
    {
        // Read a string

        m_sLiteral.clear();

        if (m_iTokenIndex < m_sCode.length())
        {
            c = m_sCode[m_iTokenIndex++];
        }
        else
        {
            return Op_EOF;
        }

        while (c != '\'')
        {
            m_sLiteral += QString(c);

            if (m_iTokenIndex == m_sCode.length())
                break;

            c = m_sCode[m_iTokenIndex++];
        }

        m_iTokenIndex++;

        return Op_Literal;
    }

    if (c == '#')
    {
        // Read an identifier

        m_sIdentifier.clear();

        if (m_iTokenIndex < m_sCode.length())
        {
            c = m_sCode[m_iTokenIndex++];
        }
        else
        {
            return Op_EOF;
        }

        while (c.isSpace() == false)
        {
            m_sIdentifier += QString(c);

            if (m_iTokenIndex == m_sCode.length())
            {
                break;
            }

            c = m_sCode[m_iTokenIndex++];
        }

        return Op_Identifier;
    }

    if (c.isLetter())
    {
        switch (c.toLatin1())
        {
            case 'a':
            {
                // Read an address register

                if (m_iTokenIndex < m_sCode.length())
                {
                    d = m_sCode[m_iTokenIndex++].toLower();

                    if (d.isDigit())
                    {
                        switch (d.toLatin1())
                        {
                            case '1': return bIndexedOperand ? Op_AtA1 : Op_A1;
                            case '2': return bIndexedOperand ? Op_AtA2 : Op_A2;
                            case '3': return bIndexedOperand ? Op_AtA3 : Op_A3;
                            case '4': return bIndexedOperand ? Op_AtA4 : Op_A4;
                            case '5': return bIndexedOperand ? Op_AtA5 : Op_A5;
                            case '6': return bIndexedOperand ? Op_AtA6 : Op_A6;
                            case '7': return bIndexedOperand ? Op_AtA7 : Op_A7;
                            case '8': return bIndexedOperand ? Op_AtA8 : Op_A8;
                        }
                    }
                    else
                    {
                        m_iTokenIndex--;
                    }
                }
                break;
            }

            case 'd':
            {
                // Read a data register

                if (m_iTokenIndex < m_sCode.length())
                {
                    d = m_sCode[m_iTokenIndex++].toLower();

                    if (d.isDigit())
                    {
                        switch (d.toLatin1())
                        {
                            case '1': return Op_D1;
                            case '2': return Op_D2;
                            case '3': return Op_D3;
                            case '4': return Op_D4;
                            case '5': return Op_D5;
                            case '6': return Op_D6;
                            case '7': return Op_D7;
                            case '8': return Op_D8;
                        }
                    }
                    else
                    {
                        m_iTokenIndex--;
                    }
                }
                break;
            }
        }
    }

    if (c.isDigit())
    {
        // Read a constant

        m_sConstant.clear();

        while (c.isDigit())
        {
            m_sConstant += QString(c);

            if (m_iTokenIndex == m_sCode.length())
            {
                break;
            }

            c = m_sCode[m_iTokenIndex++].toLower();
        }

        return Op_Constant;
    }

    {
        // Read operators

        switch (c.toLatin1())
        {
            case '@':
                if (m_iTokenIndex < m_sCode.length())
                {
                    d = m_sCode[m_iTokenIndex++].toLower();

                    switch (d.toLatin1())
                    {
                        case 'b':
                            return Op_Byte;
                        case 'w':
                            return Op_Word;
                        case 'l':
                            return Op_Long;
                    }

                    m_iTokenIndex--;
                }
                return Op_EOF;

            case '.':
                return Op_ResBytes;

            case '+':
                return Op_Add;

            case '-':
                if (m_iTokenIndex < m_sCode.length())
                {
                    d = m_sCode[m_iTokenIndex++].toLower();

                    switch (d.toLatin1())
                    {
                        case '<':
                            return Op_Push;
                        case '>':
                            return Op_Pop;
                    }

                    m_iTokenIndex--;
                }
                return Op_Sub;

            case '*':
                return Op_Mul;

            case '/':
                if (m_iTokenIndex < m_sCode.length())
                {
                    d = m_sCode[m_iTokenIndex++].toLower();

                    switch (d.toLatin1())
                    {
                        case '/':
                        {
                            e = 0;

                            while (e != '\n')
                            {
                                if (m_iTokenIndex == m_sCode.length())
                                    return Op_EOF;

                                e = m_sCode[m_iTokenIndex++].toLower();
                            }

                            m_iLine++;

                            return Op_Ignore;
                        }
                    }

                    m_iTokenIndex--;
                }
                return Op_Div;

            case '&':
                return Op_And;

            case '|':
                return Op_Or;

            case '^':
                return Op_Xor;

            case '!':
                if (m_iTokenIndex < m_sCode.length())
                {
                    d = m_sCode[m_iTokenIndex++].toLower();

                    switch (d.toLatin1())
                    {
                        case '!':
                            return Op_Int;
                    }

                    m_iTokenIndex--;
                }
                return Op_Not;

            case '?':
                return Op_Cmp;

            case '=':
            {
                if (m_iTokenIndex < m_sCode.length())
                {
                    d = m_sCode[m_iTokenIndex++].toLower();

                    switch (d.toLatin1())
                    {
                        case '<':
                        {
                            if (m_iTokenIndex < m_sCode.length())
                            {
                                e = m_sCode[m_iTokenIndex++].toLower();

                                switch (e.toLatin1())
                                {
                                    case '>':
                                        return Op_JumpIfLower;
                                }

                                m_iTokenIndex--;
                            }

                            break;
                        }

                        case '>':
                        {
                            if (m_iTokenIndex < m_sCode.length())
                            {
                                e = m_sCode[m_iTokenIndex++].toLower();

                                switch (e.toLatin1())
                                {
                                    case '>':
                                        return Op_JumpIfGreater;
                                }

                                m_iTokenIndex--;
                            }

                            return Op_Call;
                        }

                        case '=':
                        {
                            if (m_iTokenIndex < m_sCode.length())
                            {
                                e = m_sCode[m_iTokenIndex++].toLower();

                                switch (e.toLatin1())
                                {
                                    case '>':
                                        return Op_JumpIfSame;
                                }

                                m_iTokenIndex--;
                            }

                            break;
                        }

                        case '!':
                        {
                            if (m_iTokenIndex < m_sCode.length())
                            {
                                e = m_sCode[m_iTokenIndex++].toLower();

                                switch (e.toLatin1())
                                {
                                    case '>':
                                        return Op_JumpIfNotSame;
                                }

                                m_iTokenIndex--;
                            }

                            break;
                        }

                        case '|':
                        {
                            if (m_iTokenIndex < m_sCode.length())
                            {
                                e = m_sCode[m_iTokenIndex++].toLower();

                                switch (e.toLatin1())
                                {
                                    case '>':
                                        return Op_Jump;
                                }

                                m_iTokenIndex--;
                            }

                            break;
                        }
                    }

                    m_iTokenIndex--;
                }
            }

            case '<':
            {
                if (m_iTokenIndex < m_sCode.length())
                {
                    d = m_sCode[m_iTokenIndex++].toLower();

                    switch (d.toLatin1())
                    {
                        case '<':
                            return Op_Shl;
                        case '=':
                            return Op_Ret;
                    }

                    m_iTokenIndex--;
                }

                return Op_Move;
            }

            case '>':
            {
                if (m_iTokenIndex < m_sCode.length())
                {
                    d = m_sCode[m_iTokenIndex++].toLower();

                    switch (d.toLatin1())
                    {
                        case '>':
                            return Op_Shr;
                    }

                    m_iTokenIndex--;
                }
            }
        }
    }

    return Op_EOF;
}

//-------------------------------------------------------------------------------------------------

QPair<QString, int> CAssemblyMachine::disassemble(const char* pCode) const
{
    EOpCode leftOpCode = Op_Nop;
    EOpCode centerOpCode = Op_Nop;
    EOpCode rightOpCode = Op_Nop;
    qint32 iLeftValue = 0;
    qint32 iRightValue = 0;

    qint32 offset = readOpcodes(pCode, &leftOpCode, &centerOpCode, &rightOpCode, &iLeftValue, &iRightValue);
    QString sInst;

    if (isConstant(rightOpCode))
    {
        if (leftOpCode == centerOpCode)
        {
            sInst = QString("%1 %2")
                    .arg(opcodeToString(leftOpCode))
                    .arg(iRightValue, 8, 16, QChar('0'));
        }
        else
        {
            sInst = QString("%1 %2 %3")
                    .arg(opcodeToString(leftOpCode))
                    .arg(opcodeToString(centerOpCode))
                    .arg(iRightValue, 8, 16, QChar('0'));
        }
    }
    else
    {
        if (leftOpCode == centerOpCode)
        {
            sInst = QString("%1 %2")
                    .arg(opcodeToString(leftOpCode))
                    .arg(opcodeToString(rightOpCode));
        }
        else
        {
            sInst = QString("%1 %2 %3")
                    .arg(opcodeToString(leftOpCode))
                    .arg(opcodeToString(centerOpCode))
                    .arg(opcodeToString(rightOpCode));
        }
    }

    return QPair<QString, int>(sInst, offset);
}

//-------------------------------------------------------------------------------------------------

QString CAssemblyMachine::opcodeToString(EOpCode eOpCode) const
{
    if (m_mOpcodeToString.contains(eOpCode))
    {
        return m_mOpcodeToString[eOpCode];
    }

    return " ";
}

//-------------------------------------------------------------------------------------------------
/* Assembly reference

@b              operand size is byte
a1 < 802064     load address 1
a2 < 623814     load address 2
d1 < [a1        load d1 with value pointed by a1
d2 < 10         load d2 with 10
d1 + d2         add d1 and d2 and store in d1
d1 & d2         and d1 and d2 and store in d1
! d1            negate d1
[a2 < d1        store d1 at address pointed by a2
a1 < 934210     load a1
d1 ? d2         compare d1 and d2
a1 < :foo       load address of label foo in a1
=> a1           call a1
-< a1           push a1
-> a2           pop a2
d1 << 5         shift d1 left 5
d2 >> 2         shift d2 right 2
:foo            define label foo
#bar < 5        define constant bar = 5
<=              return
==> a1          jump to a1 if same
=!> a2          jump to a2 if not same
=>> a3          jump to a3 if greater
=<> a4          jump to a4 if lower
=|> a4          jump to a4
!! 10           interrupt 10
. 4             reserve 4 bytes
. 'hello'       reserve space for hello string (including terminating 0)
// hey          comment

*/

/*
a1 < 1024
d8 < 4
[a1 < 72
a1 + d8
[a1 < 101
a1 + d8
[a1 < 108
a1 + d8
[a1 < 108
a1 + d8
[a1 < 111
a1 + d8
[a1 < 33
*/
