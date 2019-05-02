/***************************************************
 * @file		
 * @section		
 * @class		
 * @brief		
 * @author		bqrmtao@gmail.com
 * @date		
 * @version		1.0
 * @copyright	bqrmtao@gmail.com
***************************************************/

//#include <boost/filesystem.hpp>
#include <typeinfo>

//#include "CommonMethod.h"
//#include "ErrorMsg.h"
//#include "Logger.h"
#include "PipelineManager.h"

using namespace std;

int main(int argc, char** argv)
{
	//log4cxx::PropertyConfigurator::configure("logcfg.properties");

	size_t ullDataLen = 100;

	CQueueManager *pQueueManager = new CQueueManager();
	pQueueManager->InitQueue(typeid(float).name(), ullDataLen);

	FloatBufferPointer pQueueIn = make_shared<CConcurrentQueue<float>>();
	FloatBufferPointer pQueueOut = make_shared<CConcurrentQueue<float>>();

	CPipelineManager *pPipelineManager = new CPipelineManager(pQueueManager, pQueueIn, pQueueOut);
	if (0 != pPipelineManager->InitPipeline(ullDataLen))
	{
		printf("failed to initialize pipeline, press any key to exit...\n");
		//__LOG_ERROR__("failed to initialize pipeline");
		getchar();
	}

	for (size_t ullRoundIdx = 0; ullRoundIdx < 5; ullRoundIdx++)
	{
		float *pVal = nullptr;
		if (pQueueManager->GetArrayFromQueue<float>(pVal, ullDataLen))
		{
			//__LOG_DEBUG__("element acquired");
			printf("element acquired\n");

			for (size_t ullFloatIdx = 0; ullFloatIdx < ullDataLen; ullFloatIdx++)
			{
				*(pVal + ullFloatIdx) = ullRoundIdx;
			}
			pQueueIn->PushIn(pVal);
		}
		else
		{
			printf("failed to get bland float element\n");
			//__LOG_ERROR__("failed to get bland float element");
		}
	}

	size_t ullFloatNum = 0;

	while (true)
	{
		float *pVal = nullptr;
		pQueueOut->WaitPop(pVal);

		if (nullptr != pVal)
		{
			printf("get value from pipeline\n");
			//__LOG_DEBUG__("get value from pipeline");

			for (size_t ullFloatIdx = 0; ullFloatIdx < ullDataLen; ullFloatIdx++)
			{
				printf("%1.2f, ", *(pVal + ullFloatIdx));
				if (4 == (ullFloatIdx) % 5)
				{
					printf("\n");
				}
			}

			printf("\n");

			ullFloatNum++;
			if (ullFloatNum >= 5)
			{
				pPipelineManager->StopPipeline();
				delete pPipelineManager;
				pPipelineManager = nullptr;
				break;
			}

			pQueueManager->PushArrayIntoQueue(pVal, ullDataLen);
		}
	}

	printf("\ndone!\npress any key to exit...\n");
	getchar();
	
	pQueueManager->ClearAllQueue();
	delete pQueueManager;
	pQueueManager = nullptr;
}