#pragma once

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QObject>
#include <QDateTime>
#include <QString>
#include <QVector>
#include <QMap>
#include <QPair>
#include <QByteArray>
#include <QMutex>
#include <QFile>

//-------------------------------------------------------------------------------------------------

#define RAM_INTERRUPTS_LOW      (qint32(0))
#define RAM_INTERRUPTS_HIGH     (qint32(256 * sizeof(qint32)))     // = 256 interrupts with 32 bit pointers

#define RAM_CONSOLE_LOW         (qint32(RAM_INTERRUPTS_HIGH))
#define RAM_CONSOLE_HIGH        (qint32(RAM_CONSOLE_LOW + (CONSOLE_W * CONSOLE_H * sizeof(qint32))))

#define RAM_INPUT_LOW           (qint32(RAM_CONSOLE_HIGH))
#define RAM_INPUT_HIGH          (qint32(RAM_INPUT_LOW + INPUT_RAM_SIZE))

#define RAM_OS_LOW              (qint32(RAM_INPUT_HIGH))
#define RAM_OS_HIGH             (qint32(RAM_OS_LOW + OS_RAM_SIZE))

#define RAM_USER                (qint32(RAM_OS_HIGH))

//-------------------------------------------------------------------------------------------------

#define CONSOLE_W               80
#define CONSOLE_H               25
#define INPUT_RAM_SIZE          512
#define OS_RAM_SIZE             4096

#define REG_SIZE_BYTE           0
#define REG_SIZE_WORD           1
#define REG_SIZE_LONG           2

#define INT_TIME                1
#define INT_MEM                 2
#define INT_FILE                3
#define INT_THREAD              4

#define INT_TIME_GET            1

#define INT_MEM_ALLOC           1
#define INT_MEM_FREE            2

#define INT_FILE_OPEN           1
#define INT_FILE_CLOSE          2
#define INT_FILE_DELETE         3
#define INT_FILE_READ           4
#define INT_FILE_WRITE          5
#define INT_FILE_SIZE           6

#define INT_FILE_OP_READ        0x0001
#define INT_FILE_OP_WRITE       0x0002

#define INT_THREAD_CREATE       1
#define INT_THREAD_TERMINATE    2
#define INT_THREAD_SLEEP        3

//-------------------------------------------------------------------------------------------------

class CAssemblyMachine : public QObject
{
    Q_OBJECT

public:

    enum EOpCode
    {
        Op_None         = 0,
        Op_A1,
        Op_A2,
        Op_A3,
        Op_A4,
        Op_A5,
        Op_A6,
        Op_A7,
        Op_A8,

        Op_D1,
        Op_D2,
        Op_D3,
        Op_D4,
        Op_D5,
        Op_D6,
        Op_D7,
        Op_D8,

        Op_AtA1,
        Op_AtA2,
        Op_AtA3,
        Op_AtA4,
        Op_AtA5,
        Op_AtA6,
        Op_AtA7,
        Op_AtA8,

        Op_SP,

        Op_Constant,
        Op_Label,
        Op_Identifier,
        Op_Literal,

        Op_Byte,
        Op_Word,
        Op_Long,

        Op_Move         = 64,
        Op_Add,
        Op_Sub,
        Op_Mul,
        Op_Div,
        Op_Shl,
        Op_Shr,
        Op_And,
        Op_Or,
        Op_Xor,
        Op_Not,
        Op_Cmp,
        Op_Push,
        Op_Pop,
        Op_Jump,
        Op_JumpIfSame,
        Op_JumpIfNotSame,
        Op_JumpIfGreater,
        Op_JumpIfLower,
        Op_Call,
        Op_Ret,
        Op_Int,

        Op_ResBytes     = 128,

        Op_Ignore       = 253,
        Op_Nop          = 254,
        Op_EOF          = 255
    };

    class CRegisters
    {
    public:

        qint32                              IP;
        qint32                              SP;
        qint32                              A1;
        qint32                              A2;
        qint32                              A3;
        qint32                              A4;
        qint32                              A5;
        qint32                              A6;
        qint32                              A7;
        qint32                              A8;
        qint32                              D1;
        qint32                              D2;
        qint32                              D3;
        qint32                              D4;
        qint32                              D5;
        qint32                              D6;
        qint32                              D7;
        qint32                              D8;

        union
        {
            qint32 All;
            struct
            {
                qint32                      m_iSame : 1;
                qint32                      m_iGreater : 1;
                qint32                      m_iLower : 1;
                qint32                      m_iSize : 4;        // 0: byte, 1: word, 2: long, 3: long long
            } Bits;
        } Flags;
    };

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    CAssemblyMachine();

    virtual ~CAssemblyMachine();

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    void setCode(const QString& sCode);

    void setDebug(bool value);

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    QString code() const;

    QByteArray& data();

    QByteArray& stack();

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Reset the machine
    void reset();

    //! Return current instruction
    QString currentInstruction() const;

    //! Return current code line
    int currentLine() const;

    //! Return registers
    CRegisters registers() const;

    int run(int iOperand1 = 0, int iOperand2 = 0, int iOperand3 = 0, int iOperand4 = 0);

    //! Register read/write
    qint32 readRegister(EOpCode eCode) const;
    void writeRegister(EOpCode eCode, qint32 iValue);

    //! RAM read/write
    qint32 readRam(qint32 iAddress) const;
    void writeRam(qint32 iAddress, qint32 iValue);
    quint8* addressToPointer(qint32 iAddress);

    //! File : CAssemblyEngine_Compile

    //! Compile the code
    void compile();

    //! Adds an error line to the error string
    void addError(const QString& sText);

    //! Return copmile errors
    QString compileErrors() const;

    //! Disassembles an instruction
    QPair<QString, int> disassemble(const char* pCode) const;

signals:

    void executing(const QString& sText);

    void consoleCharChanged(qint32 x, qint32 y, qint32 c);

protected:

    bool processNextInstruction();

    qint32 readOpcodes(const char* pCode, EOpCode* leftOpCode, EOpCode* centerOpCode, EOpCode* rightOpCode, qint32* iLeftValue, qint32* iRightValue) const;

    void pushInt8(quint8 iValue);
    void pushInt32(qint32 iValue);

    quint8 popInt8();
    qint32 popInt32();

    //! File : CAssemblyEngine_Compile
    EOpCode nextOpCode();

    QString opcodeToString(EOpCode eOpCode) const;

    bool isOperand(EOpCode eOpCode) const;
    bool isConstant(EOpCode eOpCode) const;
    bool isLabel(EOpCode eOpCode) const;
    bool isIdentifier(EOpCode eOpCode) const;
    bool isLiteral(EOpCode eOpCode) const;
    bool isSize(EOpCode eOpCode) const;

    //! File : CAssemblyEngine_Interrupts

    //! Interrupts
    void handleInt_Time();
    void handleInt_Mem();
    void handleInt_File();
    void handleInt_Thread();

    qint32 getTime(qint32 iPrec);
    qint32 findFreeMemoryBlock(qint32 iBase, qint32 iLimit, qint32 iRequestedSize);
    void freeMemoryBlock(qint32 iBase, qint32 iLimit, qint32 iAddress);
    qint32 openFile(qint32 iName, qint32 iMode);
    qint32 closeFile(qint32 iHandle);
    qint32 deleteFile(qint32 iName);
    qint32 readFile(qint32 iWhere, qint32 iHandle, qint32 iCount);
    qint32 writeFile(qint32 iWhere, qint32 iHandle, qint32 iCount);
    qint32 getFileSize(qint32 iHandle);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    // Compile

    QMap<EOpCode, QString>              m_mOpcodeToString;
    QMap<QString, qint32>               m_mLabels;
    QVector<QPair<qint32, QString> >    m_mLabelReferences;
    QMap<QString, qint32>               m_mIdentifiers;
    QMap<qint32, qint32>                m_mLines;
    QString                             m_sCode;
    QString                             m_sCompileErrors;
    QString                             m_sConstant;
    QString                             m_sLabel;
    QString                             m_sIdentifier;
    QString                             m_sLiteral;
    int                                 m_iTokenIndex;
    int                                 m_iLine;
    int                                 m_iColumn;
    bool                                m_bDebug;

    // CPU

    CRegisters                          m_rCPU;

    // RAM

    QByteArray                          m_baCode;
    QByteArray                          m_baData;
    QByteArray                          m_baStack;

    // OS

    QVector<QPair<qint32, qint32> >     m_baMemAlloc;
    QVector<QFile*>                     m_vFiles;
};

//-------------------------------------------------------------------------------------------------

class Q_DECL_EXPORT CAssemblyEngine : public QObject
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    CAssemblyEngine();

    //! Destructor
    virtual ~CAssemblyEngine();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns compile errors
    QString compileErrors() const;

    //!
    QString text() const;

    //!
    QString currentInstruction() const;

    //!
    int currentLine() const;

    //!
    CAssemblyMachine::CRegisters registers() const;

    //!
    QByteArray stack(int iFrom, int iCount) const;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Evaluates code
    int evaluate(const QString& sCode, int iOperand1, int iOperand2, int iOperand3, int iOperand4, bool bDebug = false);

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

protected:

    //-------------------------------------------------------------------------------------------------
    // Signals
    //-------------------------------------------------------------------------------------------------

signals:

    void executing(const QString& sText);
    void consoleChanged();
    void consoleCharChanged(qint32 x, qint32 y, qint32 c);

    //-------------------------------------------------------------------------------------------------
    // Slots
    //-------------------------------------------------------------------------------------------------

protected slots:

    //!
    void onExecuting(const QString& sText);

    //!
    void onConsoleCharChanged(qint32 x, qint32 y, qint32 c);

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    CAssemblyMachine*   m_pMachine;
    QString             m_sText;
    int                 m_iColumns;
    int                 m_iRows;
};
