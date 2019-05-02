/***************************************************
 * @file		QueueManager.h
 * @section		
 * @class		CQueueManager
 * @brief		manger of shared queue
 * @author		bqrmtao@gmail.com
 * @date		2018/03/18
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#include <math.h>
#include <mutex>

//#include "CommonMethod.h"
//#include "Logger.h"
#include "QueueManager.h"
//#include "ReadConfig.h"

using namespace std;

std::mutex m_oMutexQueueManager;

/*
 * @brief	default constructor
*/
CQueueManager::CQueueManager()
{
	try
	{
		// parse the size of buffer of a queue
		m_ullMaxBufferLen = /*atol(CReadConfig::GetInstance()->GetCfgItem("PipelineBufferLen").c_str())*/ 100 * 1024 * 1024;
	}
	catch (...)
	{
		//__LOG_WARN__("fail to parse initial buffer size, use default 50 MB");
		m_ullMaxBufferLen = 52428800;
	}

	m_ullInitBufferLen = m_ullMaxBufferLen / 2;

	//__LOG_INFO__(Name() + " created");
}

/*
 * @brief	default destructor
*/
CQueueManager::~CQueueManager()
{
	ClearAllQueue();

	//__LOG_INFO__(Name() + " destroyed");
}

/*
 * @brief	clear all queue
*/
void CQueueManager::ClearAllQueue()
{
	//__LOG_FUNC_START__;

	std::unique_lock<std::mutex> oQueueLock(m_oMutexQueueManager);

	m_mapQueueSizeU8.clear();
	if (!m_mapQueuePtrU8.empty())
	{
		// iterate all queue in map
		for (std::map<std::string, U8BufferPointer>::iterator mapIterIdx = m_mapQueuePtrU8.begin(); mapIterIdx != m_mapQueuePtrU8.end(); mapIterIdx++)
		{
			U8BufferPointer pQueuePtr = mapIterIdx->second;
	
			if (nullptr != pQueuePtr)
			{
				// free arrays in queue
				uint8_t *pVal = nullptr;
				while (pQueuePtr->QueueSize() > 0)
				{
					// pop out an array and delete it
					if (pQueuePtr->TryPop(pVal))
					{
						delete [] pVal;
						pVal = nullptr;
					}
					else
					{
						break;
					}
				}
	
				pQueuePtr = nullptr;
				//__LOG_INFO__("queue " + mapIterIdx->first + " deleted");
			}
		}
	
		m_mapQueuePtrU8.clear();
	}

	m_mapQueueSizeU16.clear();
	if (!m_mapQueuePtrU16.empty())
	{
		// iterate all queue in map
		for (std::map<std::string, U16BufferPointer>::iterator mapIterIdx = m_mapQueuePtrU16.begin(); mapIterIdx != m_mapQueuePtrU16.end(); mapIterIdx++)
		{
			U16BufferPointer pQueuePtr = mapIterIdx->second;
	
			if (nullptr != pQueuePtr)
			{
				// free arrays in queue
				uint16_t *pVal = nullptr;
				while (pQueuePtr->QueueSize() > 0)
				{
					// pop out an array and delete it
					if (pQueuePtr->TryPop(pVal))
					{
						delete [] pVal;
						pVal = nullptr;
					}
					else
					{
						break;
					}
				}
	
				pQueuePtr = nullptr;
				//__LOG_INFO__("queue " + mapIterIdx->first + " deleted");
			}
		}

		m_mapQueuePtrU16.clear();
	}

	m_mapQueueSizeU32.clear();
	if (!m_mapQueuePtrU32.empty())
	{
		// iterate all queue in map
		for (std::map<std::string, U32BufferPointer>::iterator mapIterIdx = m_mapQueuePtrU32.begin(); mapIterIdx != m_mapQueuePtrU32.end(); mapIterIdx++)
		{
			U32BufferPointer pQueuePtr = mapIterIdx->second;
	
			if (nullptr != pQueuePtr)
			{
				// free arrays in queue
				uint32_t *pVal = nullptr;
				while (pQueuePtr->QueueSize() > 0)
				{
					// pop out an array and delete it
					if (pQueuePtr->TryPop(pVal))
					{
						delete [] pVal;
						pVal = nullptr;
					}
					else
					{
						break;
					}
				}
	
				pQueuePtr = nullptr;
				//__LOG_INFO__("queue " + mapIterIdx->first + " deleted");
			}
		}
	
		m_mapQueuePtrU32.clear();
	}

	m_mapQueueSizeFloat.clear();
	if (!m_mapQueuePtrFloat.empty())
	{
		// iterate all queue in map
		for (std::map<std::string, FloatBufferPointer>::iterator mapIterIdx = m_mapQueuePtrFloat.begin(); mapIterIdx != m_mapQueuePtrFloat.end(); mapIterIdx++)
		{
			FloatBufferPointer pQueuePtr = mapIterIdx->second;
	
			if (nullptr != pQueuePtr)
			{
				// free arrays in queue
				float *pVal = nullptr;
				while (pQueuePtr->QueueSize() > 0)
				{
					// pop out an array and delete it
					if (pQueuePtr->TryPop(pVal))
					{
						delete [] pVal;
						pVal = nullptr;
					}
					else
					{
						break;
					}
				}
	
				pQueuePtr = nullptr;
				//__LOG_INFO__("queue " + mapIterIdx->first + " deleted");
			}
		}
	
		m_mapQueuePtrFloat.clear();
	}

	//__LOG_FUNC_END__;
}

/*
 * @brief	clear selected queue
 * @param	strTypeName: name of variable, such as "unsigned char" and "float"
 * @param	ullDataLen
*/
void CQueueManager::ClearQueue(string strTypeName, const size_t ullDataLen)
{
	//__LOG_FUNC_START__;

	std::unique_lock<std::mutex> oQueueLock(m_oMutexQueueManager);

	// find the sub function according to the name of variable
	if (strTypeName == "unsigned char")
	{
		// key of the queue according to the size of the array
		string strQueueModeKey = "U8_" + to_string(ullDataLen);

		// search for the queue
		if (!m_mapQueuePtrU8.empty() && m_mapQueuePtrU8.find(strQueueModeKey) != m_mapQueuePtrU8.end())
		{
			U8BufferPointer pQueuePtr = m_mapQueuePtrU8[strQueueModeKey];

			if (nullptr != pQueuePtr)
			{
				uint8_t *pVal = nullptr;
				while (pQueuePtr->QueueSize() > 0)
				{
					// pop out an array and delete it
					if (pQueuePtr->TryPop(pVal))
					{
						delete [] pVal;
						pVal = nullptr;
					}
					else
					{
						break;
					}
				}
			}

			m_mapQueuePtrU8.erase(strQueueModeKey);

			//__LOG_INFO__("queue " + strQueueModeKey + " deleted");
		}

		if (!m_mapQueueSizeU8.empty() && m_mapQueueSizeU8.find(strQueueModeKey) != m_mapQueueSizeU8.end())
		{
			m_mapQueueSizeU8.erase(strQueueModeKey);
		}
	}
	else if (strTypeName == "unsigned short")
	{
		// key of the queue according to the size of the array
		string strQueueModeKey = "U16_" + to_string(ullDataLen);

		// search for the queue
		if (!m_mapQueuePtrU16.empty() && m_mapQueuePtrU16.find(strQueueModeKey) != m_mapQueuePtrU16.end())
		{
			U16BufferPointer pQueuePtr = m_mapQueuePtrU16[strQueueModeKey];

			if (nullptr != pQueuePtr)
			{
				uint16_t *pVal = nullptr;
				while (pQueuePtr->QueueSize() > 0)
				{
					// pop out an array and delete it
					if (pQueuePtr->TryPop(pVal))
					{
						delete [] pVal;
						pVal = nullptr;
					}
					else
					{
						break;
					}
				}
			}

			m_mapQueuePtrU16.erase(strQueueModeKey);

			//__LOG_INFO__("queue " + strQueueModeKey + " deleted");
		}

		if (!m_mapQueueSizeU16.empty() && m_mapQueueSizeU16.find(strQueueModeKey) != m_mapQueueSizeU16.end())
		{
			m_mapQueueSizeU16.erase(strQueueModeKey);
		}
	}
	else if (strTypeName == "unsigned int")
	{
		// key of the queue according to the size of the array
		string strQueueModeKey = "U32_" + to_string(ullDataLen);

		// search for the queue
		if (!m_mapQueuePtrU32.empty() && m_mapQueuePtrU32.find(strQueueModeKey) != m_mapQueuePtrU32.end())
		{
			U32BufferPointer pQueuePtr = m_mapQueuePtrU32[strQueueModeKey];

			if (nullptr != pQueuePtr)
			{
				uint32_t *pVal = nullptr;
				while (pQueuePtr->QueueSize() > 0)
				{
					// pop out an array and delete it
					if (pQueuePtr->TryPop(pVal))
					{
						delete [] pVal;
						pVal = nullptr;
					}
					else
					{
						break;
					}
				}
			}

			m_mapQueuePtrU32.erase(strQueueModeKey);

			//__LOG_INFO__("queue " + strQueueModeKey + " deleted");
		}

		if (!m_mapQueueSizeU32.empty() && m_mapQueueSizeU32.find(strQueueModeKey) != m_mapQueueSizeU32.end())
		{
			m_mapQueueSizeU32.erase(strQueueModeKey);
		}
	}
	else if (strTypeName == "float")
	{
		// key of the queue according to the size of the array
		string strQueueModeKey = "Float_" + to_string(ullDataLen);

		// search for the queue
		if (!m_mapQueuePtrFloat.empty() && m_mapQueuePtrFloat.find(strQueueModeKey) != m_mapQueuePtrFloat.end())
		{
			FloatBufferPointer pQueuePtr = m_mapQueuePtrFloat[strQueueModeKey];

			if (nullptr != pQueuePtr)
			{
				float *pVal = nullptr;
				while (pQueuePtr->QueueSize() > 0)
				{
					// pop out an array and delete it
					if (pQueuePtr->TryPop(pVal))
					{
						delete [] pVal;
					}
					else
					{
						break;
					}
				}
			}

			m_mapQueuePtrFloat.erase(strQueueModeKey);

			//__LOG_INFO__("queue " + strQueueModeKey + " deleted");
		}

		if (!m_mapQueueSizeFloat.empty() && m_mapQueueSizeFloat.find(strQueueModeKey) != m_mapQueueSizeFloat.end())
		{
			m_mapQueueSizeFloat.erase(strQueueModeKey);
		}
	}
	else
	{
		//__LOG_ERROR__("unsupported variable type: " + strTypeName);
	}

	//__LOG_FUNC_END__;
}

/*
 * @brief	initialize a queue according to the name of variable and the size of array
 * @param	strTypeName: name of variable, such as "unsigned char" and "float"
 * @param	ullDataLen
 * @return	result of initializing a queue
*/
bool CQueueManager::InitQueue(string strTypeName, const size_t ullDataLen)
{
	std::unique_lock<std::mutex> oQueueLock(m_oMutexQueueManager);

	// find the sub function according to the name of variable
	if (strTypeName == "unsigned char")
	{
		return InitU8Queue(ullDataLen);
	}
	else if (strTypeName == "unsigned short")
	{
		return InitU16Queue(ullDataLen);
	}
	else if (strTypeName == "unsigned int")
	{
		return InitU32Queue(ullDataLen);
	}
	else if (strTypeName == "float")
	{
		return InitFloatQueue(ullDataLen);
	}

	//__LOG_ERROR__("unsupported variable type: " + strTypeName);

	return false;
}

/*
 * @brief	get an array from queue
 * @param	pFloat: float*&
 * @param	ullDataLen
 * @return	result of getting an array
*/
bool CQueueManager::GetFloatFromQueue(float*& pFloat, const size_t ullDataLen)
{
	try
	{
		// key of the queue according to the size of the array
		string strQueueModeKey = "Float_" + to_string(ullDataLen);

		// search for the queue, if not found, return false and set pU16Ptr to nullptr
		if (m_mapQueuePtrFloat.find(strQueueModeKey) == m_mapQueuePtrFloat.end())
		{
			//__LOG_ERROR__("failed to find a queue named " + strQueueModeKey);

			pFloat = nullptr;
			return false;
		}

		FloatBufferPointer pQueuePtr = m_mapQueuePtrFloat[strQueueModeKey];

		// try to pop an array
		if (!pQueuePtr->TryPop(pFloat))
		{
			// if failed, lock the queue, and pop the array again
			std::unique_lock<std::mutex> oQueueLock(m_oMutexQueueManager);

			if (pQueuePtr->TryPop(pFloat))
			{
				return true;
			}

			// failed again, check status of the queue
			BufferInfo oBuffInfo = m_mapQueueSizeFloat[strQueueModeKey];
			if (oBuffInfo.ullCurrentSize >= oBuffInfo.ullMaxSize)
			{
				// size of the queue has reached the maximum of the memory, return false
				//__LOG_ERROR__(ConvertValToString<size_t>(oBuffInfo.ullCurrentSize) + " element(s) allocated, exceeded the maximum limmit " + ConvertValToString<size_t>(oBuffInfo.ullMaxSize));
				pFloat = nullptr;
				return false;
			}
			else
			{
				// empty space available, new some array according to the information
				size_t ullNumNewElement = oBuffInfo.ullNextSize > (oBuffInfo.ullMaxSize - oBuffInfo.ullCurrentSize) ? (oBuffInfo.ullMaxSize - oBuffInfo.ullCurrentSize) : oBuffInfo.ullNextSize;
				for (size_t ullNewElementIdx = 0; ullNewElementIdx < ullNumNewElement; ullNewElementIdx++)
				{
					float *pVal = new float[ullDataLen];
					PushFloatIntoQueue(pVal, ullDataLen);
				}

				m_mapQueueSizeFloat[strQueueModeKey].ullCurrentSize += ullNumNewElement;
			}

			return pQueuePtr->TryPop(pFloat);
		}

		return true;
	}
	catch (...)
	{
		//__LOG_ERROR__("exception caught");
		printf("exception caught\n");
		pFloat = nullptr;
		return false;
	}
}

/*
 * @brief	get an array from queue
 * @param	pU8Ptr: uint8_t*&
 * @param	ullDataLen
 * @return	result of getting an array
*/
bool CQueueManager::GetU8FromQueue(uint8_t*& pU8Ptr, const size_t ullDataLen)
{
	try
	{
		// key of the queue according to the size of the array
		string strQueueModeKey = "U8_" + to_string(ullDataLen);

		// search for the queue, if not found, return false and set pU8Ptr to nullptr
		if (m_mapQueuePtrU8.find(strQueueModeKey) == m_mapQueuePtrU8.end())
		{
			//__LOG_ERROR__("failed to find a queue named " + strQueueModeKey);

			pU8Ptr = nullptr;
			return false;
		}

		U8BufferPointer pQueuePtr = m_mapQueuePtrU8[strQueueModeKey];

		// try to pop an array
		if (!pQueuePtr->TryPop(pU8Ptr))
		{
			// if failed, lock the queue, and pop the array again
			std::unique_lock<std::mutex> oQueueLock(m_oMutexQueueManager);

			if (pQueuePtr->TryPop(pU8Ptr))
			{
				return true;
			}

			// failed again, check status of the queue
			BufferInfo oBuffInfo = m_mapQueueSizeU8[strQueueModeKey];
			if (oBuffInfo.ullCurrentSize >= oBuffInfo.ullMaxSize)
			{
				// size of the queue has reached the maximum of the memory, return false
				//__LOG_ERROR__(ConvertValToString<size_t>(oBuffInfo.ullCurrentSize) + " element(s) allocated, exceeded the maximum limmit " + ConvertValToString<size_t>(oBuffInfo.ullMaxSize));
				pU8Ptr = nullptr;
				return false;
			}
			else
			{
				// empty space available, new some array according to the information
				size_t ullNumNewElement = oBuffInfo.ullNextSize > (oBuffInfo.ullMaxSize - oBuffInfo.ullCurrentSize) ? (oBuffInfo.ullMaxSize - oBuffInfo.ullCurrentSize) : oBuffInfo.ullNextSize;
				for (size_t ullNewElementIdx = 0; ullNewElementIdx < ullNumNewElement; ullNewElementIdx++)
				{
					uint8_t *pVal = new uint8_t[ullDataLen];
					PushU8IntoQueue(pVal, ullDataLen);
				}

				m_mapQueueSizeU8[strQueueModeKey].ullCurrentSize += ullNumNewElement;
			}

			return pQueuePtr->TryPop(pU8Ptr);
		}

		return true;
	}
	catch (...)
	{
		//__LOG_ERROR__("exception caught");
		printf("exception caught\n");
		pU8Ptr = nullptr;
		return false;
	}
}

/*
 * @brief	get an array from queue
 * @param	pU16Ptr: uint16_t*&
 * @param	ullDataLen
 * @return	result of getting an array
*/
bool CQueueManager::GetU16FromQueue(uint16_t*& pU16Ptr, const size_t ullDataLen)
{
	try
	{
		// key of the queue according to the size of the array
		string strQueueModeKey = "U16_" + to_string(ullDataLen);

		// search for the queue, if not found, return false and set pU16Ptr to nullptr
		if (m_mapQueuePtrU16.find(strQueueModeKey) == m_mapQueuePtrU16.end())
		{
			//__LOG_ERROR__("failed to find a queue named " + strQueueModeKey);

			pU16Ptr = nullptr;
			return false;
		}

		U16BufferPointer pQueuePtr = m_mapQueuePtrU16[strQueueModeKey];

		// try to pop an array
		if (!pQueuePtr->TryPop(pU16Ptr))
		{
			// if failed, lock the queue, and pop the array again
			std::unique_lock<std::mutex> oQueueLock(m_oMutexQueueManager);

			if (pQueuePtr->TryPop(pU16Ptr))
			{
				return true;
			}

			// failed again, check status of the queue
			BufferInfo oBuffInfo = m_mapQueueSizeU16[strQueueModeKey];
			if (oBuffInfo.ullCurrentSize >= oBuffInfo.ullMaxSize)
			{
				// size of the queue has reached the maximum of the memory, return false
				//__LOG_ERROR__(ConvertValToString<size_t>(oBuffInfo.ullCurrentSize) + " element(s) allocated, exceeded the maximum limmit " + ConvertValToString<size_t>(oBuffInfo.ullMaxSize));
				pU16Ptr = nullptr;
				return false;
			}
			else
			{
				// empty space available, new some array according to the information
				size_t ullNumNewElement = oBuffInfo.ullNextSize > (oBuffInfo.ullMaxSize - oBuffInfo.ullCurrentSize) ? (oBuffInfo.ullMaxSize - oBuffInfo.ullCurrentSize) : oBuffInfo.ullNextSize;
				for (size_t ullNewElementIdx = 0; ullNewElementIdx < ullNumNewElement; ullNewElementIdx++)
				{
					uint16_t *pVal = new uint16_t[ullDataLen];
					PushU16IntoQueue(pVal, ullDataLen);
				}

				m_mapQueueSizeU16[strQueueModeKey].ullCurrentSize += ullNumNewElement;
			}

			return pQueuePtr->TryPop(pU16Ptr);
		}

		return true;
	}
	catch (...)
	{
		//__LOG_ERROR__("exception caught");
		printf("exception caught");
		pU16Ptr = nullptr;
		return false;
	}
}

/*
 * @brief	get an array from queue
 * @param	pU32Ptr: uint32_t*&
 * @param	ullDataLen
 * @return	result of getting an array
*/
bool CQueueManager::GetU32FromQueue(uint32_t*& pU32Ptr, const size_t ullDataLen)
{
	try
	{
		// key of the queue according to the size of the array
		string strQueueModeKey = "U32_" + to_string(ullDataLen);

		// search for the queue, if not found, return false and set pU32Ptr to nullptr
		if (m_mapQueuePtrU32.find(strQueueModeKey) == m_mapQueuePtrU32.end())
		{
			//__LOG_ERROR__("failed to find a queue named " + strQueueModeKey);

			pU32Ptr = nullptr;
			return false;
		}

		U32BufferPointer pQueuePtr = m_mapQueuePtrU32[strQueueModeKey];

		// try to pop an array
		if (!pQueuePtr->TryPop(pU32Ptr))
		{
			// if failed, lock the queue, and pop the array again
			std::unique_lock<std::mutex> oQueueLock(m_oMutexQueueManager);

			if (pQueuePtr->TryPop(pU32Ptr))
			{
				return true;
			}

			// failed again, check status of the queue
			BufferInfo oBuffInfo = m_mapQueueSizeU32[strQueueModeKey];
			if (oBuffInfo.ullCurrentSize >= oBuffInfo.ullMaxSize)
			{
				// size of the queue has reached the maximum of the memory, return false
				//__LOG_ERROR__(ConvertValToString<size_t>(oBuffInfo.ullCurrentSize) + " element(s) allocated, exceeded the maximum limmit " + ConvertValToString<size_t>(oBuffInfo.ullMaxSize));
				pU32Ptr = nullptr;
				return false;
			}
			else
			{
				// empty space available, new some array according to the information
				size_t ullNumNewElement = oBuffInfo.ullNextSize > (oBuffInfo.ullMaxSize - oBuffInfo.ullCurrentSize) ? (oBuffInfo.ullMaxSize - oBuffInfo.ullCurrentSize) : oBuffInfo.ullNextSize;
				for (size_t ullNewElementIdx = 0; ullNewElementIdx < ullNumNewElement; ullNewElementIdx++)
				{
					uint32_t *pVal = new uint32_t[ullDataLen];
					PushU32IntoQueue(pVal, ullDataLen);
				}

				m_mapQueueSizeU32[strQueueModeKey].ullCurrentSize += ullNumNewElement;
			}

			return pQueuePtr->TryPop(pU32Ptr);
		}

		return true;
	}
	catch (...)
	{
		//__LOG_ERROR__("exception caught");
		printf("exception caught");
		pU32Ptr = nullptr;
		return false;
	}
}

/*
 * @brief	initialize a queue according to the size of array
 * @param	ullDataLen
 * @return	result of initializing a queue
*/
bool CQueueManager::InitFloatQueue(const size_t ullDataLen)
{
	//__LOG_FUNC_START__;

	// key of the queue according to the size of the array
	string strQueueModeKey = "Float_" + to_string(ullDataLen);
	
	try
	{
		// if the information of the queue
		if (0 == m_mapQueueSizeFloat.count(strQueueModeKey))
		{
			BufferInfo oBufInfo = BufferInfo();

			// number of array allocated in queue
			oBufInfo.ullMaxSize = m_ullMaxBufferLen / ullDataLen / sizeof(float);
			oBufInfo.ullInitSize = m_ullInitBufferLen / ullDataLen / sizeof(float);

			// if the size of array is larger than 5MB, new 1 element each time
			oBufInfo.ullNextSize = (ullDataLen * sizeof(float)) / 1024 / 1024 > 5 ? 1 : 3;

			// insert into map
			m_mapQueueSizeFloat.insert(make_pair(strQueueModeKey, oBufInfo));
		}

		// check if the queue exists, if not new a queue
		if (0 == m_mapQueuePtrFloat.count(strQueueModeKey))
		{
			m_mapQueuePtrFloat.insert(make_pair(strQueueModeKey, make_shared<CConcurrentQueue<float>>()));
		}

		// check if the number of pointers stored in queue is larger than initial size
		if (m_mapQueueSizeFloat[strQueueModeKey].ullCurrentSize >= (m_ullInitBufferLen / ullDataLen / sizeof(float)))
		{
			//__LOG_DEBUG__("memory buffer for [" + strQueueModeKey + "] exists, skip initialization");
		}
		else
		{
			// allocate new pointer to the initial size
			FloatBufferPointer pQueuePtr = m_mapQueuePtrFloat[strQueueModeKey];
			while (pQueuePtr->QueueSize() < m_mapQueueSizeFloat[strQueueModeKey].ullInitSize)
			{
				float *pDataPtr = new float[ullDataLen];
				pQueuePtr->PushIn(pDataPtr);
			}

			m_mapQueueSizeFloat[strQueueModeKey].ullCurrentSize = m_ullInitBufferLen / ullDataLen / sizeof(float);

			//__LOG_DEBUG__("memory buffer for [" + strQueueModeKey + "] allocated");
		}

		//__LOG_INFO__("Queue Status: initial size = " + to_string(m_mapQueueSizeFloat[strQueueModeKey].ullInitSize) + ", current size = " + to_string(m_mapQueueSizeFloat[strQueueModeKey].ullCurrentSize) + ", current size in queue = " + to_string(m_mapQueuePtrFloat[strQueueModeKey]->QueueSize()) + ", max size = " + to_string(m_mapQueueSizeFloat[strQueueModeKey].ullMaxSize));
	}
	catch (...)
	{
		//__LOG_ERROR__("fail to initialize queue for [" + strQueueModeKey + "]");
		return false;
	}

	//__LOG_FUNC_END__;

	return true;
}

/*
 * @brief	initialize a queue according to the size of array
 * @param	ullDataLen
 * @return	result of initializing a queue
*/
bool CQueueManager::InitU8Queue(const size_t ullDataLen)
{
	//__LOG_FUNC_START__;

	// key of the queue according to the size of the array
	string strQueueModeKey = "U8_" + to_string(ullDataLen);

	try
	{
		// if the information of the queue
		if (0 == m_mapQueueSizeU8.count(strQueueModeKey))
		{
			BufferInfo oBufInfo = BufferInfo();

			// number of array allocated in queue
			oBufInfo.ullMaxSize = m_ullMaxBufferLen / ullDataLen / sizeof(uint8_t);
			oBufInfo.ullInitSize = m_ullInitBufferLen / ullDataLen / sizeof(uint8_t);

			// if the size of array is larger than 5MB, new 1 element each time
			oBufInfo.ullNextSize = ullDataLen * sizeof(uint8_t) / 1024 / 1024 > 5 ? 1 : 3;

			// insert into map
			m_mapQueueSizeU8.insert(make_pair(strQueueModeKey, oBufInfo));
		}

		// check if the queue exists, if not new a queue
		if (0 == m_mapQueuePtrU8.count(strQueueModeKey))
		{
			m_mapQueuePtrU8.insert(make_pair(strQueueModeKey, make_shared<CConcurrentQueue<uint8_t>>()));
		}

		// check if the number of pointers stored in queue is larger than initial size
		if (m_mapQueueSizeU8[strQueueModeKey].ullCurrentSize >= (m_ullInitBufferLen / ullDataLen / sizeof(uint8_t)))
		{
			//__LOG_DEBUG__("memory buffer for [" + strQueueModeKey + "] exists, skip initialization");
		}
		else
		{
			// allocate new pointer to the initial size
			U8BufferPointer pQueuePtr = m_mapQueuePtrU8[strQueueModeKey];
			while (pQueuePtr->QueueSize() < m_mapQueueSizeU8[strQueueModeKey].ullInitSize)
			{
				uint8_t *pDataPtr = new uint8_t[ullDataLen];
				pQueuePtr->PushIn(pDataPtr);
			}

			m_mapQueueSizeU8[strQueueModeKey].ullCurrentSize = m_ullInitBufferLen / ullDataLen / sizeof(uint8_t);

			//__LOG_DEBUG__("memory buffer for [" + strQueueModeKey + "] allocated");
		}

		//__LOG_INFO__("Queue Status: initial size = " + to_string(m_mapQueueSizeU8[strQueueModeKey].ullInitSize) + ", current size = " + to_string(m_mapQueueSizeU8[strQueueModeKey].ullCurrentSize) + ", current size in queue = " + to_string(m_mapQueuePtrU8[strQueueModeKey]->QueueSize()) + ", max size = " + to_string(m_mapQueueSizeU8[strQueueModeKey].ullMaxSize));
	}
	catch (...)
	{
		//__LOG_ERROR__("fail to initialize queue for [" + strQueueModeKey + "]");
		return false;
	}

	return true;
}

/*
 * @brief	initialize a queue according to the size of array
 * @param	ullDataLen
 * @return	result of initializing a queue
*/
bool CQueueManager::InitU16Queue(const size_t ullDataLen)
{
	//__LOG_FUNC_START__;

	// key of the queue according to the size of the array
	string strQueueModeKey = "U16_" + to_string(ullDataLen);

	try
	{
		// if the information of the queue
		if (0 == m_mapQueueSizeU16.count(strQueueModeKey))
		{
			BufferInfo oBufInfo = BufferInfo();

			// number of array allocated in queue
			oBufInfo.ullMaxSize = m_ullMaxBufferLen / ullDataLen / sizeof(uint16_t);
			oBufInfo.ullInitSize = m_ullInitBufferLen / ullDataLen / sizeof(uint16_t);

			// if the size of array is larger than 5MB, new 1 element each time
			oBufInfo.ullNextSize = ullDataLen * sizeof(uint16_t) / 1024 / 1024 > 5 ? 1 : 3;

			// insert into map
			m_mapQueueSizeU16.insert(make_pair(strQueueModeKey, oBufInfo));
		}

		// check if the queue exists, if not new a queue
		if (0 == m_mapQueuePtrU16.count(strQueueModeKey))
		{
			m_mapQueuePtrU16.insert(make_pair(strQueueModeKey, make_shared<CConcurrentQueue<uint16_t>>()));
		}

		// check if the number of pointers stored in queue is larger than initial size
		if (m_mapQueueSizeU16[strQueueModeKey].ullCurrentSize >= (m_ullInitBufferLen / ullDataLen / sizeof(uint16_t)))
		{
			//__LOG_DEBUG__("memory buffer for [" + strQueueModeKey + "] exists, skip initialization");
		}
		else
		{
			// allocate new pointer to the initial size
			U16BufferPointer pQueuePtr = m_mapQueuePtrU16[strQueueModeKey];
			while (pQueuePtr->QueueSize() < m_mapQueueSizeU16[strQueueModeKey].ullInitSize)
			{
				uint16_t *pDataPtr = new uint16_t[ullDataLen];
				pQueuePtr->PushIn(pDataPtr);
			}

			m_mapQueueSizeU16[strQueueModeKey].ullCurrentSize = m_ullInitBufferLen / ullDataLen / sizeof(uint16_t);

			//__LOG_DEBUG__("memory buffer for [" + strQueueModeKey + "] allocated");
		}

		//__LOG_INFO__("Queue Status: initial size = " + to_string(m_mapQueueSizeU16[strQueueModeKey].ullInitSize) + ", current size = " + to_string(m_mapQueueSizeU16[strQueueModeKey].ullCurrentSize) + ", current size in queue = " + to_string(m_mapQueuePtrU16[strQueueModeKey]->QueueSize()) + ", max size = " + to_string(m_mapQueueSizeU16[strQueueModeKey].ullMaxSize));
	}
	catch (...)
	{
		//__LOG_ERROR__("fail to initialize queue for [" + strQueueModeKey + "]");
		return false;
	}

	//__LOG_FUNC_END__;

	return true;
}

/*
 * @brief	initialize a queue according to the size of array
 * @param	ullDataLen
 * @return	result of initializing a queue
*/
bool CQueueManager::InitU32Queue(const size_t ullDataLen)
{
	//__LOG_FUNC_START__;

	// key of the queue according to the size of the array
	string strQueueModeKey = "U32_" + to_string(ullDataLen);

	try
	{
		// if the information of the queue
		if (0 == m_mapQueueSizeU32.count(strQueueModeKey))
		{
			BufferInfo oBufInfo = BufferInfo();

			// number of array allocated in queue
			oBufInfo.ullMaxSize = m_ullMaxBufferLen / ullDataLen / sizeof(uint32_t);
			oBufInfo.ullInitSize = m_ullInitBufferLen / ullDataLen / sizeof(uint32_t);

			// if the size of array is larger than 5MB, new 1 element each time
			oBufInfo.ullNextSize = ullDataLen * sizeof(uint32_t) / 1024 / 1024 > 5 ? 1 : 3;

			// insert into map
			m_mapQueueSizeU32.insert(make_pair(strQueueModeKey, oBufInfo));
		}

		// check if the queue exists, if not new a queue
		if (0 == m_mapQueuePtrU32.count(strQueueModeKey))
		{
			m_mapQueuePtrU32.insert(make_pair(strQueueModeKey, make_shared<CConcurrentQueue<uint32_t>>()));
		}

		// check if the number of pointers stored in queue is larger than initial size
		if (m_mapQueueSizeU32[strQueueModeKey].ullCurrentSize >= (m_ullInitBufferLen / ullDataLen / sizeof(uint32_t)))
		{
			//__LOG_DEBUG__("memory buffer for [" + strQueueModeKey + "] exists, skip initialization");
		}
		else
		{
			// allocate new pointer to the initial size
			U32BufferPointer pQueuePtr = m_mapQueuePtrU32[strQueueModeKey];
			while (pQueuePtr->QueueSize() < m_mapQueueSizeU32[strQueueModeKey].ullInitSize)
			{
				uint32_t *pDataPtr = new uint32_t[ullDataLen];
				pQueuePtr->PushIn(pDataPtr);
			}

			m_mapQueueSizeU32[strQueueModeKey].ullCurrentSize = m_ullInitBufferLen / ullDataLen / sizeof(uint32_t);

			//__LOG_DEBUG__("memory buffer for [" + strQueueModeKey + "] allocated");
		}

		//__LOG_INFO__("Queue Status: initial size = " + to_string(m_mapQueueSizeU32[strQueueModeKey].ullInitSize) + ", current size = " + to_string(m_mapQueueSizeU32[strQueueModeKey].ullCurrentSize) + ", current size in queue = " + to_string(m_mapQueuePtrU32[strQueueModeKey]->QueueSize()) + ", max size = " + to_string(m_mapQueueSizeU32[strQueueModeKey].ullMaxSize));
	}
	catch (...)
	{
		//__LOG_ERROR__("fail to initialize queue for [" + strQueueModeKey + "]");
		return false;
	}

	//__LOG_FUNC_END__;

	return true;
}

/*
 * @brief	push a float pointer into queue
 * @param	pFloatPtr: float*&
 * @param	ullDataLen
 * @return	result of pushing an array into queue
*/
bool CQueueManager::PushFloatIntoQueue(float*& pFloatPtr, const size_t ullDataLen)
{
	string strQueueModeKey = "Float_" + to_string(ullDataLen);

	// search for the correct queue to insert the pointer into
	if (m_mapQueuePtrFloat.find(strQueueModeKey) == m_mapQueuePtrFloat.end())
	{
		//__LOG_ERROR__("fail to locate queue [" + strQueueModeKey + "] in memory, release this buffer");
		delete[] pFloatPtr;
	}
	else
	{
		// queue found, check if the queue had reached the maximum amount
		if (m_mapQueuePtrFloat[strQueueModeKey]->QueueSize() >= m_mapQueueSizeFloat[strQueueModeKey].ullMaxSize)
		{
			// maximum amount reached
			//__LOG_ERROR__("queue [" + strQueueModeKey + "] has reached the upper limitation, release this buffer");
			delete[] pFloatPtr;
		}
		else
		{
			// insert the pointer into queue
			m_mapQueuePtrFloat[strQueueModeKey]->PushIn(pFloatPtr);
			return true;
		}
	}

	return false;
}

/*
 * @brief	push a uint8 pointer into queue
 * @param	pU8Ptr: uint8_t*&
 * @param	ullDataLen
 * @return	result of pushing an array into queue
*/
bool CQueueManager::PushU8IntoQueue(uint8_t*& pU8Ptr, const size_t ullDataLen)
{
	string strQueueModeKey = "U8_" + to_string(ullDataLen);

	// search for the correct queue to insert the pointer into
	if (m_mapQueuePtrU8.find(strQueueModeKey) == m_mapQueuePtrU8.end())
	{
		//__LOG_ERROR__("fail to locate queue [" + strQueueModeKey + "] in memory, release this buffer");
		delete[] pU8Ptr;
	}
	else
	{
		// queue found, check if the queue had reached the maximum amount
		if (m_mapQueuePtrU8[strQueueModeKey]->QueueSize() >= m_mapQueueSizeU8[strQueueModeKey].ullMaxSize)
		{
			// maximum amount reached
			//__LOG_ERROR__("queue [" + strQueueModeKey + "] has reached the upper limitation, release this buffer");
			delete[] pU8Ptr;
		}
		else
		{
			// insert the pointer into queue
			m_mapQueuePtrU8[strQueueModeKey]->PushIn(pU8Ptr);
			return true;
		}
	}

	return false;
}

/*
 * @brief	push a uint16 pointer into queue
 * @param	pU16Ptr: uint16_t*&
 * @param	ullDataLen
 * @return	result of pushing an array into queue
*/
bool CQueueManager::PushU16IntoQueue(uint16_t*& pU16Ptr, const size_t ullDataLen)
{
	string strQueueModeKey = "U16_" + to_string(ullDataLen);

	// search for the correct queue to insert the pointer into
	if (m_mapQueuePtrU16.find(strQueueModeKey) == m_mapQueuePtrU16.end())
	{
		//__LOG_ERROR__("fail to locate queue [" + strQueueModeKey + "] in memory, release this buffer");
		delete[] pU16Ptr;
	}
	else
	{
		// queue found, check if the queue had reached the maximum amount
		if (m_mapQueuePtrU16[strQueueModeKey]->QueueSize() >= m_mapQueueSizeU16[strQueueModeKey].ullMaxSize)
		{
			// maximum amount reached
			//__LOG_ERROR__("queue [" + strQueueModeKey + "] has reached the upper limitation, release this buffer");
			delete[] pU16Ptr;
		}
		else
		{
			// insert the pointer into queue
			m_mapQueuePtrU16[strQueueModeKey]->PushIn(pU16Ptr);
			return true;
		}
	}

	return false;
}

/*
 * @brief	push a uint32 pointer into queue
 * @param	pU32Ptr: uint32_t*&
 * @param	ullDataLen
 * @return	result of pushing an array into queue
*/
bool CQueueManager::PushU32IntoQueue(uint32_t*& pU32Ptr, const size_t ullDataLen)
{
	string strQueueModeKey = "U32_" + to_string(ullDataLen);

	// search for the correct queue to insert the pointer into
	if (m_mapQueuePtrU32.find(strQueueModeKey) == m_mapQueuePtrU32.end())
	{
		// not found
		//__LOG_ERROR__("fail to locate queue [" + strQueueModeKey + "] in memory, release this buffer");
		delete[] pU32Ptr;
	}
	else
	{
		// queue found, check if the queue had reached the maximum amount
		if (m_mapQueuePtrU32[strQueueModeKey]->QueueSize() >= m_mapQueueSizeU32[strQueueModeKey].ullMaxSize)
		{
			// maximum amount reached
			//__LOG_ERROR__("queue [" + strQueueModeKey + "] has reached the upper limitation, release this buffer");
			delete[] pU32Ptr;
		}
		else
		{
			// insert the pointer into queue
			m_mapQueuePtrU32[strQueueModeKey]->PushIn(pU32Ptr);
			return true;
		}
	}

	return false;
}