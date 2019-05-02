/***************************************
 * FileName:	
 * Project:		
 * Func:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "DispCmd.h"
#include "RedoCmd.h"
#include "UndoCmd.h"
#include "CmdInvoker.h"

int main(int argc, char **argv)
{
	CDocRecv *pDoc = new CDocRecv();

	IDocCmd *pDisp = new CDispCmd(pDoc);
	IDocCmd *pUndo = new CUndoCmd(pDoc);
	IDocCmd *pRedo = new CRedoCmd(pDoc);

	CCmdInvoker *pCmdInvoker = new CCmdInvoker();
	pCmdInvoker->AddCmd(pDisp);
	pCmdInvoker->AddCmd(pUndo);
	pCmdInvoker->AddCmd(pRedo);

	pCmdInvoker->ExecuteCmd();

	delete pCmdInvoker;
	pCmdInvoker = nullptr;
	delete pRedo;
	pRedo = nullptr;
	delete pUndo;
	pUndo = nullptr;
	delete pDisp;
	pDisp = nullptr;
	delete pDoc;
	pDoc = nullptr;

	printf("press any key to exit...\n");
	getchar();
}