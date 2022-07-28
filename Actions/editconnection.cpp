#include "editconnection.h"
#include"..\ApplicationManager.h"

editconnection::editconnection(ApplicationManager *pApp):Action(pApp)
{
	execute = true;

}


editconnection::~editconnection()
{
}


void editconnection::ReadActionParameters(){
	
	


	
}
void editconnection::Execute(){
	Output* pOut = pManager->GetOutput();
	Input* pIn = pManager->GetInput();
	Component* cmpn = pManager->getselectedComponent();
	if(!cmpn ){ 
		int x , y;
	pOut->PrintMsg("Nothing is selected , click to advance");
	pIn->GetPointClicked(x , y);
	pOut->ClearStatusBar();
	}
	else
	{
		if(!(cmpn->gettype() == CONNECTION))
		{
			int x , y;
		pOut->PrintMsg("Selected component isn't a connection  , click to advance");
	pIn->GetPointClicked(x , y);
	pOut->ClearStatusBar();
		}
		else{
				//Print Action Message
	pOut->PrintMsg("choose start (Output) pin");
	int x1 , x2 , y1 , y2;
	//Wait for User Input
	pIn->GetPointClicked(x1, y1);


		if(!pManager->getcomponent(x1,y1)){
			pOut->PrintMsg("NO COMPONENT SELECTED , Connection isn't edited , click to advance");
			pIn->GetPointClicked(x1, y1);
			execute = false;
		}
		if(execute){
	pOut->PrintMsg("Choose end (INPUT) pin");
	pIn->GetPointClicked(x2, y2);

	if(!pManager->getcomponent(x2,y2)){
			pOut->PrintMsg("NO COMPONENT SELECTED , Connection isn't edited , click to advance");
			pIn->GetPointClicked(x2, y2);
			execute = false;
		}
	if(execute){
		
		GraphicsInfo GInfo; 
	Component* Srccmpn = pManager->getcomponent(x1,y1);
	Component* Dstcmpn = pManager->getcomponent(x2,y2);
	InputPin* inpin;
	OutputPin* outpin;
	if (Srccmpn->gettype() == Led){
	pManager->GetOutput()->PrintMsg("LEDS can't be chosen as a Source component , Connection isn't edited , click to advance");
		execute = false;
		pManager->GetInput()->GetPointClicked(x1 , y1);
		pManager->GetOutput()->ClearStatusBar();
	
	}
	else if(Srccmpn->gettype() == SWITCH) 
	{
		Switch* s =(Switch*)Srccmpn ;
		outpin= s->getoutputpinlocation(x1 , y1);
		GInfo.x1 = x1;
		GInfo.y1 = y1;
	}
	else{
		Gate* g = (Gate*)Srccmpn;
		outpin= g->getoutputpinlocation(x1 , y1);
		GInfo.x1 = x1;
		GInfo.y1 = y1;
	
	}

	if(Dstcmpn->gettype() == SWITCH){
		pManager->GetOutput()->PrintMsg("Switches can't be chosen as a destination component , Connection isn't edited , click to advance");
		execute = false;
		pManager->GetInput()->GetPointClicked(x2 , y2);
		pManager->GetOutput()->ClearStatusBar();
	
	}
	else if(Dstcmpn->gettype() == Led){
	LED* g = (LED*)Dstcmpn;
		inpin= g->getinputpin(x2 , y2 , 5);
		inpin->setComponent(g);
		GInfo.x2 = x2;
		GInfo.y2 = y2;
	}
	else if(Dstcmpn->gettype() == GATE1){

		Gate* g = (Gate*)Dstcmpn;
		inpin= g->getinputpin(x2 , y2 , 1);
		inpin->setComponent(g);
		GInfo.x2 = x2;
		GInfo.y2 = y2;
	
	
	}
	else {
	
		if(execute){
		pManager->GetOutput()->PrintMsg("Enter the number of the wanted pin");
		int n =  stoi( pManager->GetInput()->GetSrting(pManager->GetOutput()));
		Gate* g = (Gate*)Dstcmpn;
		inpin= g->getinputpin(x2 , y2 , n);
		inpin->setComponent(g);
		GInfo.x2 = x2;
		GInfo.y2 = y2;
		}
	}


	
	 //Gfx info to be used to draw the line
	

	
	
	
	if(execute){
		cmpn->deletecmpn(pOut , pManager);
	Connection* pA =new Connection(GInfo,outpin , inpin );
	if (inpin->Connectto(pA) ){
	if (outpin->ConnectTo(pA)){
		
		pManager->AddComponent(pA);}
	}
	}
	}	
		
		}
	
	}

	}

	


}

	//To undo this action (code depends on action type)
void editconnection::Undo(){}

	//To redo this action (code depends on action type)
 void editconnection::Redo(){
	
	}

