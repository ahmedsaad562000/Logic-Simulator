#include "operate.h"
#include"..\ApplicationManager.h"

operate::operate(ApplicationManager *pApp):Action(pApp)
{
	

}


operate::~operate()
{
}


void operate::ReadActionParameters(){
	
	


	
}
void operate::Execute(){
	
	int x;
	pManager->getswitches(x);
	
	Switch** ss = new Switch*[x];
		
		ss = pManager->getswitches(x);
		for (int i = 0; i < x; i++)
		{
			ss[i]->Operate();
		}
		
		if (x==0){
			pManager->GetOutput()->PrintMsg("NO SWITCHES IN THE CIRCUIT");
		}

		delete []ss;


}

	//To undo this action (code depends on action type)
void operate::Undo(){}

	//To redo this action (code depends on action type)
 void operate::Redo(){
	
	}
