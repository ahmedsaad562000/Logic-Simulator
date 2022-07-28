#ifndef _EDITCONNECTION_H
#define _EDITCONNECTION_H
#include "action.h"
class editconnection :
	public Action
{

public:
	editconnection(ApplicationManager *pApp);
	~editconnection();
	void ReadActionParameters();
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};
#endif

