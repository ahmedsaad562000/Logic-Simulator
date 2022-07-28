#ifndef _OPERATE_H
#define _OPERATE_H
#include "action.h"
class operate :
	public Action
{
public:

	operate(ApplicationManager *pApp);
	~operate();
	void ReadActionParameters();
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};
#endif
