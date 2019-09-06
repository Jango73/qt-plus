
// Qt
#include <QDebug>

// Application
#include "CAssemblyEngine.h"

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::handleInt_Time()
{
    // Function in d1

    switch (m_rCPU.D1)
    {
    case INT_TIME_GET:
    {
        qint32 iPrec = m_rCPU.D2;
        m_rCPU.D1 = getTime(iPrec);
        break;
    }

    default:
        break;
    }
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::handleInt_Mem()
{
    // Function in d1

    switch (m_rCPU.D1)
    {
    case INT_MEM_ALLOC:
    {
        qint32 iBase = m_rCPU.A1;
        qint32 iLimit = m_rCPU.A2;
        qint32 iSize = m_rCPU.D2;
        m_rCPU.D1 = findFreeMemoryBlock(iBase, iLimit, iSize);
        break;
    }

    case INT_MEM_FREE:
    {
        qint32 iBase = m_rCPU.A1;
        qint32 iLimit = m_rCPU.A2;
        qint32 iAddress = m_rCPU.A3;
        freeMemoryBlock(iBase, iLimit, iAddress);
        m_rCPU.D1 = 0;
        break;
    }

    default:
        break;
    }
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::handleInt_File()
{
    // Function in d1

    switch (m_rCPU.D1)
    {
    case INT_FILE_OPEN:
    {
        qint32 iName = m_rCPU.A1;
        qint32 iMode = m_rCPU.D2;
        m_rCPU.D1 = openFile(iName, iMode);
        break;
    }

    case INT_FILE_DELETE:
    {
        qint32 iName = m_rCPU.A1;
        m_rCPU.D1 = deleteFile(iName);
        break;
    }

    case INT_FILE_READ:
    {
        qint32 iWhere = m_rCPU.A1;
        qint32 iHandle = m_rCPU.D2;
        qint32 iCount = m_rCPU.D3;
        m_rCPU.D1 = readFile(iWhere, iHandle, iCount);
        break;
    }

    case INT_FILE_WRITE:
    {
        qint32 iWhere = m_rCPU.A1;
        qint32 iHandle = m_rCPU.D2;
        qint32 iCount = m_rCPU.D3;
        m_rCPU.D1 = writeFile(iWhere, iHandle, iCount);
        break;
    }

    case INT_FILE_SIZE:
    {
        qint32 iHandle = m_rCPU.D2;
        m_rCPU.D1 = getFileSize(iHandle);
        break;
    }

    default:
        break;
    }
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::handleInt_Thread()
{
    // Function in d1

    switch (m_rCPU.D1)
    {
    case INT_THREAD_CREATE:
    {
        m_rCPU.D1 = 0;
        break;
    }
    case INT_THREAD_TERMINATE:
    {
        m_rCPU.D1 = 0;
        break;
    }
    case INT_THREAD_SLEEP:
    {
        m_rCPU.D1 = 0;
        break;
    }
    default:
        break;
    }
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::getTime(qint32 iPrec)
{
    Q_UNUSED(iPrec);

    return QDateTime::currentDateTime().toTime_t();
}

//-------------------------------------------------------------------------------------------------

static bool compareMemAlloc(QPair<qint32, qint32>& left, QPair<qint32, qint32>& right)
{
    return left.first < right.first;
}

qint32 CAssemblyMachine::findFreeMemoryBlock(qint32 iBase, qint32 iLimit, qint32 iRequestedSize)
{
    // qDebug() << "iBase : " << iBase << " , iLimit : " << iLimit << " , iRequestedSize : " << iRequestedSize;

    if (iBase > 0 && iLimit > 0)
    {
        qSort(m_baMemAlloc.begin(), m_baMemAlloc.end(), compareMemAlloc);

        for (int index = 0; index < m_baMemAlloc.count(); index++)
        {
            qint32 iBlockStart = m_baMemAlloc[index].first;
            qint32 iBlockEnd = iBlockStart + m_baMemAlloc[index].second;

            // qDebug() << "iBlockStart : " << iBlockStart << " , iBlockEnd : " << iBlockEnd;

            if (iBlockStart - iBase >= iRequestedSize)
            {
                m_baMemAlloc << QPair<qint32, qint32>(iBase, iRequestedSize);
                return iBase;
            }

            iBase = iBlockEnd;
        }

        if (iBase + iRequestedSize < iLimit)
        {
            m_baMemAlloc << QPair<qint32, qint32>(iBase, iRequestedSize);
            return iBase;
        }
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

void CAssemblyMachine::freeMemoryBlock(qint32 iBase, qint32 iLimit, qint32 iAddress)
{
    if (iBase > 0 && iLimit > 0)
    {
        for (int index = 0; index < m_baMemAlloc.count(); index++)
        {
            if (m_baMemAlloc[index].first == iAddress)
            {
                m_baMemAlloc.removeAt(index);
                return;
            }
        }
    }
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::openFile(qint32 iName, qint32 iMode)
{
    QString sFileName((const char*) addressToPointer(iName));
    QIODevice::OpenModeFlag flags = QIODevice::NotOpen;

    if (iMode & INT_FILE_OP_READ)
        flags = QIODevice::ReadOnly;

    if (iMode & INT_FILE_OP_WRITE)
        flags = QIODevice::WriteOnly;

    if (sFileName.isEmpty() == false)
    {
        for (int index = 1; index < m_vFiles.count(); index++)
        {
            if (m_vFiles[index]->isOpen() == false)
            {
                m_vFiles[index]->setFileName(sFileName);

                if (m_vFiles[index]->open(flags))
                {
                    return index;
                }

                return 0;
            }
        }

        if (m_vFiles.count() > 256)
            return 0;

        QFile* pFile = new QFile(sFileName);

        m_vFiles << pFile;

        int last = m_vFiles.count() - 1;

        bool bOK = pFile->open(flags);

        if (bOK)
        {
            return last;
        }
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::closeFile(qint32 iHandle)
{
    if (iHandle < m_vFiles.count())
    {
        if (m_vFiles[iHandle]->isOpen())
        {
            m_vFiles[iHandle]->close();
            return 0;
        }
    }

    return 1;
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::deleteFile(qint32 iName)
{
    Q_UNUSED(iName);

    return 0;
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::readFile(qint32 iWhere, qint32 iHandle, qint32 iCount)
{
    if (iHandle < m_vFiles.count())
    {
        if (m_vFiles[iHandle]->isOpen())
        {
            quint8* pData = addressToPointer(iWhere);
            return m_vFiles[iHandle]->read((char*)pData, iCount);
        }
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::writeFile(qint32 iWhere, qint32 iHandle, qint32 iCount)
{
    if (iHandle < m_vFiles.count())
    {
        if (m_vFiles[iHandle]->isOpen())
        {
            quint8* pData = addressToPointer(iWhere);
            return m_vFiles[iHandle]->write((char*)pData, iCount);
        }
    }

    return 0;
}

//-------------------------------------------------------------------------------------------------

qint32 CAssemblyMachine::getFileSize(qint32 iHandle)
{
    if (iHandle < m_vFiles.count())
    {
        return m_vFiles[iHandle]->size();
    }

    return 0;
}
