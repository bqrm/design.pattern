/***************************************
 * FileName:	
 * Project:		
 * Function:	
 * Creator:		bqrmtao@gmail.com
 * DateTime:	
***************************************/

#ifndef __FACADE_H__
#define __FACADE_H__

#include "Camera.h"
#include "Light.h"
#include "Screen.h"

class CFacade
{
public:
	CFacade()
	{
		m_pCamera = new CCamera();
		m_pLights = new CLight();
		m_pScreen = new CScreen();
	}
	~CFacade()
	{
		delete m_pCamera;
		m_pCamera = nullptr;
		delete m_pLights;
		m_pLights = nullptr;
		delete m_pScreen;
		m_pScreen = nullptr;
	}

	void Activate()
	{
		printf("activate all equipments.\n");
		m_pCamera->TurnOn();
		m_pCamera->Rotate(90);
		m_pLights->TrunOn();
		m_pScreen->TrunOn();
	}

	void Deactivate()
	{
		m_pScreen->TrunOff();
		m_pLights->TrunOff();
		m_pCamera->Rotate(0);
		m_pCamera->TurnOff();
		printf("all equipments deactivated.\n");
	}

private:
	CCamera *m_pCamera;
	CLight  *m_pLights;
	CScreen *m_pScreen;
};

#endif