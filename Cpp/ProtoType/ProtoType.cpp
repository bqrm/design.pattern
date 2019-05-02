/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "BeeLine.h"
#include "CurveLine.h"

int main(int argc, char**argv)
{
	CBeeLine *pBeeLine = new CBeeLine();
	pBeeLine->SetWeight(10);
	CBeeLine *pBeeClone = (CBeeLine*)(pBeeLine->Clone());
	pBeeClone->Show();
	delete pBeeClone;
	pBeeClone = nullptr;
	delete pBeeLine;
	pBeeLine = nullptr;

	CCurveLine *pCurveLine = new CCurveLine();
	pCurveLine->SetType("DOT");
	CCurveLine *pCurveClone = (CCurveLine*)(pCurveLine->Clone());
	pCurveClone->Show();
	delete pCurveClone;
	pCurveClone = nullptr;
	delete pCurveLine;
	pCurveLine = nullptr;

	printf("press any key to exit...\n");
	getchar();
}