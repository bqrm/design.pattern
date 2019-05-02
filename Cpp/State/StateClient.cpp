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

#include "AirPlane.h"
#include "Flying.h"
#include "StandingBy.h"

using namespace std;

int main(int argc, char** argv)
{
	CAirPlane *pAirPlane = new CAirPlane();
	IState *pState = new CStandingBy();
	pAirPlane->SetState(pState);
	pAirPlane->Board();
	pAirPlane->Climb();
	pAirPlane->TakeOff();
	
	delete pState;
	pState = new CFlying();

	pAirPlane->SetState(pState);
	pAirPlane->Climb();
	pAirPlane->Deplane();
	pAirPlane->Descend();
	pAirPlane->Land();

	delete pState;
	pState = new CStandingBy();

	pAirPlane->SetState(pState);
	pAirPlane->Deplane();

	delete pAirPlane;
	pAirPlane = nullptr;
	delete pState;
	pState = nullptr;

	printf("press any key to exit...\n");
	getchar();
}