/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "Singleton.h"

int main(int argc, char** argv)
{
	for (int rIdx = 0; rIdx < 10; rIdx++)
	{
		CSingleton::GetInstance()->Show();
	}
	
	printf("press any key to exit...\n");
	getchar();
}