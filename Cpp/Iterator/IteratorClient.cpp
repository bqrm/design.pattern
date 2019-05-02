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

#include <stdio.h>

#include "ConcreteAggregate.h"
#include "ConcreteIterator.h"

using namespace std;

int main(int argc, char**argv)
{
	IAbstractAggregate *pAggreator = new CConcreteAggregate();
	pAggreator->Push("hello");
	pAggreator->Push("world");
	pAggreator->Push("cxue");

	IAbstractIterator *pIterator = pAggreator->CreateIterator();
	if (nullptr != pIterator)
	{
		printf("%s is ok\n", pIterator->Next().c_str());
		printf("%s is ok\n", pIterator->Current().c_str());
		printf("%s is ok\n", pIterator->First().c_str());
	}

	printf("press any key to exit...\n");
	getchar();
}