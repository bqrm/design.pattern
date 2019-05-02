/***************************************
 * FileName:	
 * Project:		
 * Function:		
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#include "Drawing1.h"
#include "Drawing2.h"
#include "Circle.h"
#include "Rectangle.h"

int main(int argc, char** argv)
{
	IDrawing *pDraw = new CConcreteDrawing1();
	IShape *pShape = new CRectangle(pDraw);
	pShape->Draw();
	delete pShape;
	pShape = nullptr;
	delete pDraw;
	pDraw = nullptr;

	pDraw = new CConcreteDrawing2();
	pShape = new CCircle(pDraw);
	pShape->Draw();
	delete pShape;
	pShape = nullptr;
	delete pDraw;
	pDraw = nullptr;

	printf("press any key to exit...\n");
	getchar();
}