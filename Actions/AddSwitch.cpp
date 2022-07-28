#include "AddSwitch.h"
#include "..\ApplicationManager.h"


AddSwitch::AddSwitch(ApplicationManager* pApp):Action(pApp)
{
	execute = true;
}


AddSwitch::~AddSwitch()
{
}

void AddSwitch::ReadActionParameters(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("Switch: Click to add the switch");


	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if(!(Cy >= UI.ToolBarHeight+12 && Cy < UI.height -12- UI.StatusBarHeight && Cx>25 && Cx<975)) {
	pOut->PrintMsg("NOT IN DRAWING AREA! , NOTHING IS ADDED , click to advance.");
	pIn->GetPointClicked(Cx, Cy);
	execute = false;
	}
	//Clear Status Bar
	pOut->ClearStatusBar();

}

 void AddSwitch::Execute(){
 ReadActionParameters();
 if(execute){
	//Calculate the rectangle Corners
 int Len = UI.Switch_Width;
	int Wdth = UI.Switch_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	Switch* pA=new Switch(GInfo, AND2_FANOUT); 
	pManager->AddComponent(pA);
 
 
 }
 }
 void AddSwitch::Undo(){}
 void AddSwitch::Redo(){}
