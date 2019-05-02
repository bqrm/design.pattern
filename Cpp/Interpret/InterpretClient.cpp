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

#include "Formula.h"
#include "Parser.h"

using namespace std;

void SplitString(const string& strSrc, const string& strSplitter, list<string>& listSplittedStr)
{
	// index of character in string
	string::size_type nSubStrIdxStart = 0;
	string::size_type nSubStrIdxStop = 0;
	string::size_type nSubStrIdxTemp = 0;

	listSplittedStr.clear();

	do
	{
		// find first matched splitter from 
		nSubStrIdxStop = strSrc.find_first_of(strSplitter, nSubStrIdxStart);
		if (nSubStrIdxStop != string::npos)
		{
			nSubStrIdxTemp = nSubStrIdxStop;
			while (' ' == strSrc[nSubStrIdxTemp - 1])
			{
				nSubStrIdxTemp--;
			}
			listSplittedStr.push_back(strSrc.substr(nSubStrIdxStart, nSubStrIdxTemp - nSubStrIdxStart));

			do
			{
				nSubStrIdxStart = strSrc.find_first_not_of(strSplitter, ++nSubStrIdxStop);
			} while (string::npos != nSubStrIdxStart && ' ' == strSrc[nSubStrIdxStart]);

			if (string::npos == nSubStrIdxStart)
			{
				return;
			}
		}
		else
		{
			listSplittedStr.push_back(strSrc.substr(nSubStrIdxStart));
		}
	} while (nSubStrIdxStop != string::npos);
}

int main(int argc, char** argv)
{
	CParser *pParser = new CParser();

	string strFormula = "+ - + - - 2 3 4 + - -5 6 + -7 8 9 0";
	list<string> listFormula;
	SplitString(strFormula, " ", listFormula);
	IFormula *pFormula = pParser->ParseNext(listFormula);

	printf("Polish Notation \"%s\" = %1.2f\n", strFormula.c_str(), pFormula->Calculate());

	delete pFormula;
	pFormula = nullptr;
	delete pParser;
	pParser = nullptr;

	printf("press any key to exit...\n");
	getchar();
}