#ifndef _INPUTPIN_H
#define _INPUTPIN_H

#include "Pin.h"
class Component; //Forward class declaration
class Connection;
class ApplicationManager;
class Output;
class InputPin: public Pin	//inherited from class Pin
{
	Connection* m_connection;
	int connected;
	Component* pComp; //Component at which this pin is associated
public:
	InputPin();
	
	void setComponent(Component* pCmp);	//sets the component of this input pin
	Component* getComponent();	//returns the component of this input pin
	bool Connectto(Connection* pConn);
	void disconnect();
	void deleteconnection(Output* pOut , ApplicationManager* pApp);
	
};

#endif