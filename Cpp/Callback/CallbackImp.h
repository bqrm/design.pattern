/***************************************************
 * @file		CallbackImp.h
 * @section		
 * @class		CCallbackImp
 * @brief		implementation of callback
 * @author		bqrmtao@gmail.com
 * @date		2018/07/12
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

#ifndef __CALLBACK_IMP_H__
#define __CALLBACK_IMP_H__

#include "CallbackBase.h"

/* enum */
enum EventID
{
	EVENT_ADD,   ///< 
	EVENT_SUB,
	EVENT_MUL,
	EVENT_DIV,
	EVENT_MOD
};

/*
 * @class	CCallbackImp
 * @brief	implementation of callback
*/
class CCallbackImp : public ICallback
{
public:
	/*
	 * @brief	constructor
	*/
	CCallbackImp() { printf("CCallbackImp created\n"); }
	/*
	 * @brief	destructor
	*/
	~CCallbackImp() { printf("CCallbackImp destroyed"); }
	
	/*
	 * @brief	main method of callback, should be overwritten in derived class
	 * @param	unEventID
	 * @param	pEventParam (CallbackParam*)
	 * @return	void
	*/
	virtual void ProcessCallback(unsigned int unEventID, CallbackParam *pEventParam)
	{
		switch (unEventID)
		{
		case EVENT_ADD:
			printf("\n\tevent \"EVENT_ADD\" called.\n\t%1.0f + %1.0f = %1.0f\n\n", pEventParam->fOprd1, pEventParam->fOprd2, pEventParam->fOprd1 + pEventParam->fOprd2);
			break;
		case EVENT_SUB:
			printf("\n\tevent \"EVENT_SUB\" called.\n\t%1.0f - %1.0f = %1.0f\n\n", pEventParam->fOprd1, pEventParam->fOprd2, pEventParam->fOprd1 - pEventParam->fOprd2);
			break;
		case EVENT_MUL:
			printf("\n\tevent \"EVENT_MUL\" called.\n\t%1.0f * %1.0f = %1.0f\n\n", pEventParam->fOprd1, pEventParam->fOprd2, pEventParam->fOprd1 * pEventParam->fOprd2);
			break;
		case EVENT_DIV:
			printf("\n\tevent \"EVENT_DIV\" called.\n\t%1.0f / %1.0f = %1.3f\n\n", pEventParam->fOprd1, pEventParam->fOprd2, pEventParam->fOprd1 / pEventParam->fOprd2);
			break;
		case EVENT_MOD:
			printf("\n\tevent \"EVENT_MOD\" called.\n\t%1.0f %% %1.0f = %d\n\n", pEventParam->fOprd1, pEventParam->fOprd2, (int)pEventParam->fOprd1 % (int)pEventParam->fOprd2);
			break;
		default:
			printf("\tthis branch should never be hit\n");
			break;
		}
	}
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

#endif	// __CALLBACK_IMP_H__