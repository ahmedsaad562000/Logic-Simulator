#ifndef _ADD_CONNECTION_H
#define _ADD_CONNECTION_H

#include "action.h"
#include "..\Components\Connection.h"
#include "AddANDgate2.h"
#include "..\ApplicationManager.h"

class OutputPin;
class InputPin;
class AddConnection :	public Action
{
	
private:
	//Parameters for rectangular area to be occupied by the gate
	
	InputPin* inpin;
	OutputPin* outpin;
	int x1, y1, x2, y2;	//Two corners of the rectangluar area
public:
	AddConnection(ApplicationManager *pApp);
	virtual ~AddConnection();

	//Reads parameters required for action to execute
	virtual void ReadActionParameters();
	//Execute action (code depends on action type)
	virtual void Execute();

	virtual void Undo();
	virtual void Redo();


};

#endif