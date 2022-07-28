#ifndef APPLICATION_MANAGER_H
#define APPLICATION_MANAGER_H

#include "Defs.h"
#include "GUI\Output.h"
#include "GUI\Input.h"
#include "Actions\Action.h"
#include "Actions\AddConnection.h"
#include "Components\Component.h"
#include "Actions\AddANDgate2.h"
#include "Actions\AddSwitch.h"
#include "Actions\AddLed.h"
#include "Actions\ADDAND3Gate.h"
#include "Actions\ADDBufferGate.h"
#include "Actions\AddNANDgate2.h"
#include "Actions\AddNORgate2.h"
#include "Actions\AddNORgate3.h"
#include "Actions\ADDNOTGate.h"
#include "Actions\ADDORGate.h"
#include "Actions\AddXNORgate2.h"
#include "Actions\AddXORgate2.h"
#include "Actions\AddXORgate3.h"
#include "Actions\AddLabel.h"
#include "Actions\Select.h"
#include "Actions\ChangeSwitch.h"
#include "Actions\Del.h"
#include"Actions\operate.h"
#include "Actions\editconnection.h"



//Main class that manages everything in the application.
class ApplicationManager
{

	enum { MaxCompCount = 200 };	//Max no of Components	

private:
	int CompCount;		//Actual number of Components
	Component* CompList[MaxCompCount];	//List of all Components (Array of pointers)

	Output* OutputInterface; //pointer to the Output Clase Interface
	Input* InputInterface; //pointer to the Input Clase Interface





public:	
	ApplicationManager(); //constructor
	friend class AddConnection;
	//Reads the required action from the user and returns the corresponding action type
	ActionType GetUserAction();
	
	//Creates an action and executes it
	void ExecuteAction(ActionType);
	
	void UpdateInterface();	//Redraws all the drawing window

	//Gets a pointer to Input / Output Object
	Output* GetOutput();
	Input* GetInput();
	Component* getcomponent(int x  ,int y);
	Switch** getswitches(int &n);
	Component* getselectedComponent();
	//Adds a new component to the list of components
	void AddComponent(Component* pComp);
	void RemoveComponent(Component* pComp);
	void unselectall();
	//destructor
	~ApplicationManager();
};

#endif