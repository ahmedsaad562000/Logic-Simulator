#include "AddLed.h"
#include "..\ApplicationManager.h"

AddLed::AddLed(ApplicationManager *pApp):Action(pApp)
{

	execute = true;
}


AddLed::~AddLed()
{
}


void AddLed::ReadActionParameters()
{
	//Get a Pointer to the Input / Output Interfaces
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();

	//Print Action Message
	pOut->PrintMsg("LED , click to add");

	//Wait for User Input
	pIn->GetPointClicked(Cx, Cy);
	if(!(Cy >= UI.ToolBarHeight+25 && Cy < UI.height-25 - UI.StatusBarHeight && Cx>17 && Cx<983)) {
	pOut->PrintMsg("NOT IN DRAWING AREA! , NOTHING ADDED , click to advance.");
	pIn->GetPointClicked(Cx, Cy);
	execute = false;
	}
	//Clear Status Bar
	pOut->ClearStatusBar();
	
}
void AddLed::Execute()
{
	//Get Center point of the Gate
	ReadActionParameters();
	if(execute){
	//Calculate the rectangle Corners
	int Len = UI.LED_Width;
	int Wdth = UI.LED_Height;
	
	GraphicsInfo GInfo; //Gfx info to be used to construct the AND2 gate
	
	GInfo.x1 = Cx - Len/2;
	GInfo.x2 = Cx + Len/2;
	GInfo.y1 = Cy - Wdth/2;
	GInfo.y2 = Cy + Wdth/2;
	LED *pA=new LED(GInfo); 
	pManager->AddComponent(pA);
}
}
void AddLed::Undo()
{}

void AddLed::Redo()
{}
