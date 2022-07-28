#include "InputPin.h"
#include "Connection.h"

InputPin::InputPin()
{
	m_connection = NULL;
	connected =0;
}

void InputPin::setComponent(Component *pCmp)
{
	this->pComp = pCmp;
}
bool InputPin::Connectto(Connection* pConn){
	if(connected == 0){
		m_connection = pConn;
			connected =1;
		return true;
	}

	return false; }
Component* InputPin::getComponent()
{
	return pComp;
}

void InputPin::disconnect(){
	m_connection = NULL;
	connected = 0;
}


void InputPin::deleteconnection(Output* pOut , ApplicationManager* pApp){

		if (!m_connection){
			return;}
		else
		{
			m_connection->deletecmpn(pOut , pApp );
		}

	}
