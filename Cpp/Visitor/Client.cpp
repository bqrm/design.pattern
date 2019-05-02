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

#include "Cellphone.h"
#include "Computer.h"
#include "Server.h"

using namespace std;

int main(int argc, char** argv)
{
	CComputer *pComputer = new CComputer();
	CCellphone *pCellphone = new CCellphone();

	CServer *pBlogServer = new CServer();

	pBlogServer->Accept(pCellphone);
	printf("\n");
	pBlogServer->Accept(pComputer);

	delete pBlogServer;
	pBlogServer = nullptr;
	delete pCellphone;
	pCellphone = nullptr;
	delete pComputer;
	pComputer = nullptr;

	printf("\npress any key to exit...\n");
	getchar();
}