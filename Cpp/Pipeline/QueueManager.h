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

#ifndef _QUEUE_MANAGER_H_
#define _QUEUE_MANAGER_H_

#include <map>
#include <memory>
#include <stdint.h>
#include <string>

#include "BufferInfo.h"
#include "ConcurrentQueue.h"

/* enum */
//enum 
//{
//		,   ///< 
//};

typedef std::shared_ptr<CConcurrentQueue<uint8_t>> U8BufferPointer;
typedef std::shared_ptr<CConcurrentQueue<uint16_t>> U16BufferPointer;
typedef std::shared_ptr<CConcurrentQueue<uint32_t>> U32BufferPointer;
typedef std::shared_ptr<CConcurrentQueue<float>> FloatBufferPointer;

/*
 * @class	CQueueManager
 * @brief	manager of the queue, initializing, getting, pushing
*/
class CQueueManager
{
public:
	/*
	 * @brief	default constructor
	*/
	CQueueManager();

	/*
	 * @brief	default destructor
	*/
	~CQueueManager();
	
	/*
	 * @brief	clear all queue
	*/
	void ClearAllQueue();
	
	/*
	 * @brief	clear selected queue
	 * @param	strTypeName: name of variable, such as "unsigned char" and "float"
	 * @param	ullDataLen
	*/
	void ClearQueue(std::string strTypeName, const size_t ullDataLen);
	
	/*
	 * @brief	get an array from queue according the type of variable
	 * @param	tArrar: T*&
	 * @param	ullDataLen
	 * @return	result of getting an array
	*/
	template<typename T>
	bool GetArrayFromQueue(T*& tArrar, const size_t ullDataLen)
	{
		// find the sub function according to the type of variable
		if (typeid(T) == typeid(uint8_t))
		{
			return GetU8FromQueue((uint8_t*&)tArrar, ullDataLen);
		}
		else if (typeid(T) == typeid(uint16_t))
		{
			return GetU16FromQueue((uint16_t*&)tArrar, ullDataLen);
		}
		else if (typeid(T) == typeid(uint32_t))
		{
			return GetU32FromQueue((uint32_t*&)tArrar, ullDataLen);
		}
		else if (typeid(T) == typeid(float))
		{
			return GetFloatFromQueue((float*&)tArrar, ullDataLen);
		}
		else
		{
			return false;
		}
	}
	
	/*
	 * @brief	initialize a queue according to the name of variable and the size of array
	 * @param	strTypeName: name of variable, such as "unsigned char" and "float"
	 * @param	ullDataLen
	 * @return	result of initializing a queue
	*/
	bool InitQueue(std::string strTypeName, const size_t ullDataLen);
	
	/*
	 * @brief	get name of the Class
	 * @return	name of the class
	*/
	std::string Name() const { return std::string("QueueManager"); }
	
	/*
	 * @brief	push an array into queue according the type of variable
	 * @param	tArrar: T*&
	 * @param	ullDataLen
	 * @return	result of pushing an array
	*/
	template<typename T>
	bool PushArrayIntoQueue(T*& tArrar, const size_t ullDataLen)
	{
		// find the sub function according to the type of variable
		if (typeid(T) == typeid(uint8_t))
		{
			return PushU8IntoQueue((uint8_t*&)tArrar, ullDataLen);
		}
		else if (typeid(T) == typeid(uint16_t))
		{
			return PushU16IntoQueue((uint16_t*&)tArrar, ullDataLen);
		}
		else if (typeid(T) == typeid(uint32_t))
		{
			return PushU32IntoQueue((uint32_t*&)tArrar, ullDataLen);
		}
		else if (typeid(T) == typeid(float))
		{
			return PushFloatIntoQueue((float*&)tArrar, ullDataLen);
		}
		else
		{
			return false;
		}
	}

protected:
	/*
	 * @brief	get an array from queue
	 * @param	pFloat: float*&
	 * @param	ullDataLen
	 * @return	result of getting an array
	*/
	bool GetFloatFromQueue(float*& pFloat, const size_t ullDataLen);
	/*
	 * @brief	get an array from queue
	 * @param	pU8Ptr: uint8_t*&
	 * @param	ullDataLen
	 * @return	result of getting an array
	*/
	bool GetU8FromQueue(uint8_t*& pU8Ptr, const size_t ullDataLen);
	/*
	 * @brief	get an array from queue
	 * @param	pU16Ptr: uint16_t*&
	 * @param	ullDataLen
	 * @return	result of getting an array
	*/
	bool GetU16FromQueue(uint16_t*& pU16Ptr, const size_t ullDataLen);
	/*
	 * @brief	get an array from queue
	 * @param	pU32Ptr: uint32_t*&
	 * @param	ullDataLen
	 * @return	result of getting an array
	*/
	bool GetU32FromQueue(uint32_t*& pU32Ptr, const size_t ullDataLen);
	
	/*
	 * @brief	initialize a queue according to the size of array
	 * @param	ullDataLen
	 * @return	result of initializing a queue
	*/
	bool InitFloatQueue(const size_t ullDataLen);
	/*
	 * @brief	initialize a queue according to the size of array
	 * @param	ullDataLen
	 * @return	result of initializing a queue
	*/
	bool InitU8Queue(const size_t ullDataLen);
	/*
	 * @brief	initialize a queue according to the size of array
	 * @param	ullDataLen
	 * @return	result of initializing a queue
	*/
	bool InitU16Queue(const size_t ullDataLen);
	/*
	 * @brief	initialize a queue according to the size of array
	 * @param	ullDataLen
	 * @return	result of initializing a queue
	*/
	bool InitU32Queue(const size_t ullDataLen);
	
	/*
	 * @brief	push a float pointer into queue
	 * @param	pFloatPtr: float*&
	 * @param	ullDataLen
	 * @return	result of inserting queue
	*/
	bool PushFloatIntoQueue(float*& pFloat, const size_t ullDataLen);
	/*
	 * @brief	push a uint8 pointer into queue
	 * @param	pU8Ptr: uint8_t*&
	 * @param	ullDataLen
	 * @return	result of inserting queue
	*/
	bool PushU8IntoQueue(uint8_t*& pU8Ptr, const size_t ullDataLen);
	/*
	 * @brief	push a uint16 pointer into queue
	 * @param	pU16Ptr: uint16_t*&
	 * @param	ullDataLen
	 * @return	result of inserting queue
	*/
	bool PushU16IntoQueue(uint16_t*& pU16Ptr, const size_t ullDataLen);
	/*
	 * @brief	push a uint32 pointer into queue
	 * @param	pU32Ptr: uint32_t*&
	 * @param	ullDataLen
	 * @return	result of inserting queue
	*/
	bool PushU32IntoQueue(uint32_t*& pU32Ptr, const size_t ullDataLen);

private:
	size_t m_ullMaxBufferLen;
	size_t m_ullInitBufferLen;

	std::map<std::string, U8BufferPointer> m_mapQueuePtrU8;
	std::map<std::string, BufferInfo> m_mapQueueSizeU8;
	std::map<std::string, U16BufferPointer> m_mapQueuePtrU16;
	std::map<std::string, BufferInfo> m_mapQueueSizeU16;
	std::map<std::string, U32BufferPointer> m_mapQueuePtrU32;
	std::map<std::string, BufferInfo> m_mapQueueSizeU32;
	std::map<std::string, FloatBufferPointer> m_mapQueuePtrFloat;
	std::map<std::string, BufferInfo> m_mapQueueSizeFloat;
};

/*
 * @brief	
 * @param	
 * @return	
*/

//#ifdef __cplusplus
//extern "C"
//{
//#endif // __cplusplus
//
//
//#ifdef __cplusplus
//};
//#endif // __cplusplus

#endif