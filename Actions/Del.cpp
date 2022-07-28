#include "Del.h"
#include"..\ApplicationManager.h"

Del::Del(ApplicationManager *pApp):Action(pApp)
{
	

}


Del::~Del()
{
}


void Del::ReadActionParameters(){
	
	


	
}
void Del::Execute(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Component* cmpn = pManager->getselectedComponent();
	if(!cmpn){ 
		int x , y;
	pOut->PrintMsg("Nothing is selected , click to advance");
	pIn->GetPointClicked(x , y);
	pOut->ClearStatusBar();
	}
	else
	{
		
		cmpn->deletecmpn(pOut , pManager);
		
	
	}

	

	


}

	//To undo this action (code depends on action type)
void Del::Undo(){}

	//To redo this action (code depends on action type)
 void Del::Redo(){
	
	}
