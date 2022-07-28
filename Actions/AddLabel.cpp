#include "AddLabel.h"
#include"..\ApplicationManager.h"


AddLabel::AddLabel(ApplicationManager *pApp):Action(pApp)
{
	execute = true;
}


AddLabel::~AddLabel(void)
{
}

void AddLabel::ReadActionParameters(){

	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Add or Edit LABEL , Choose any component then enter or edit it's label");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if(!(Cy >= UI.ToolBarHeight && Cy < UI.height - UI.StatusBarHeight && Cx>0 && Cx<1000)) {
	pOut->PrintMsg("NOT IN DRAWING AREA! , NOTHING ADDED , click to advance.");
	pIn->GetPointClicked(Cx, Cy);
	execute = false;
	}

	//Clear Status Bar
	pOut->ClearStatusBar();


}
void AddLabel::Execute(){
	ReadActionParameters();
	if(execute){
	Component* cmpn = pManager->getcomponent(Cx,Cy);
	if(!cmpn){
		pManager->GetOutput()->PrintMsg("No Component in this location.");
	}
	else{
	cmpn->getlabelplace(Cx , Cy);
	string e = cmpn->getlabel(); // get the old label to erase it 
	string s = pManager->GetInput()->GetSrting(pManager->GetOutput());

	cmpn->setlabel(s);
	pManager->GetOutput()->Draw_rectangle_label(Cx , Cy ,e.size()); // draw rectangle in the old label place

	pManager->GetOutput()->Printlabel(s , Cx , Cy);
	pManager->unselectall();

	}
	}


}

	//To undo this action (code depends on action type)
void AddLabel::Undo(){}

	//To redo this action (code depends on action type)
 void AddLabel::Redo(){
	
	}