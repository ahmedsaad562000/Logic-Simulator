#ifndef _DEL_H
#define _DEL_H
#include "action.h"
class Del :
	public Action
{

public:
	Del(ApplicationManager *pApp);
	~Del();
	void ReadActionParameters();
	virtual void Execute();

	//To undo this action (code depends on action type)
	virtual void Undo();

	//To redo this action (code depends on action type)
	virtual void Redo();
};
#endif
