#include "ApplicationManager.h"


ApplicationManager::ApplicationManager()
{
	CompCount = 0;

	for(int i=0; i<MaxCompCount; i++)
		CompList[i] = NULL;

	//Creates the Input / Output Objects & Initialize the GUI
	OutputInterface = new Output();
	InputInterface = OutputInterface->CreateInput();
}
////////////////////////////////////////////////////////////////////
void ApplicationManager::AddComponent(Component* pComp)
{
	CompList[CompCount++] = pComp;		
}
void ApplicationManager::RemoveComponent(Component* pComp){
	for (int i = 0; i < CompCount; i++)
	{
		if(CompList[i]== pComp){
			delete CompList[i];
			CompList[i] = CompList[CompCount-1];
			CompList[CompCount-1] = NULL;
			CompCount-=1;
		}

	}

}


Component* ApplicationManager::getselectedComponent(){
	for (int i = 0; i < CompCount; i++)
	{
		if(CompList[i]->isselected())
			return CompList[i];
	}
	return NULL;

}


void ApplicationManager::unselectall(){

	for (int i = 0; i < CompCount; i++)
	{
		CompList[i]->unselect(OutputInterface);
	}


}
Switch** ApplicationManager::getswitches(int &n){
	n=0;
	for (int i = 0; i < CompCount; i++)
	{
		if(CompList[i]->gettype()==SWITCH){
		n+=1;
		}
	}
	Switch** s = new Switch*[n];
	n =0;
	for (int i = 0; i < CompCount; i++)
	{
		if(CompList[i]->gettype()==SWITCH){
			Switch* ss = (Switch*)CompList[i];
			s[n] = ss;
		    n = n+1;
		}
	}
	return s;
}
Component* ApplicationManager::getcomponent(int x  ,int y){
	for (int i = 0; i < CompCount; i++)
	{
		if(CompList[i]->InArea(x , y)){
			return CompList[i];
		
		}
	}
	return NULL;

}
////////////////////////////////////////////////////////////////////

ActionType ApplicationManager::GetUserAction()
{
	//Call input to get what action is reuired from the user
	return InputInterface->GetUserAction(); 	
}
////////////////////////////////////////////////////////////////////

void ApplicationManager::ExecuteAction(ActionType ActType)
{
	Action* pAct = NULL;
	switch (ActType)
	{
		case ADD:
				OutputInterface->PrintMsg("add, what do you want to add");
			OutputInterface->CreateDesignToolBar2();
				break;

				case ADDgate:
				OutputInterface->PrintMsg("Action: add a gate , Click on the desired gate");
				OutputInterface->CreateDesignToolBar3();
				break;

		case ADD_Buff:
			pAct= new AddBufferGate(this);
			break;

		case ADD_INV:
			pAct= new AddNOTGate(this);
			break;

		case Menuselect:
			pAct = new Select(this);
			break;

		case ADD_NAND_GATE_2:
			pAct= new AddNANDgate2(this);
			break;

		case ADD_OR_GATE_2:
			pAct= new AddORGate(this);
			break;

		case ADD_NOR_GATE_2:
			pAct= new AddNORgate2(this);
			break;

		case ADD_XOR_GATE_2:
			pAct= new AddXORgate2(this);
			break;

		case ADD_XNOR_GATE_2:
			pAct= new AddXNORgate2(this);
			break;
		case ADD_XOR_GATE_3:
			pAct= new AddXORgate3(this);
			break;
		case ADD_NOR_GATE_3:
			pAct= new AddNORgate3(this);
			break;
		case ADD_AND_GATE_3:
			pAct = new AddAND3gate(this);
			break;

			case ADD_Switch:
			pAct = new AddSwitch(this);
			break;
		case ADD_LED:
			pAct= new AddLed(this);
			break;

		
				case ADD_Label:
					pAct = new AddLabel(this);
			break;

				case Create_TruthTable:
			OutputInterface->PrintMsg("Action: create truth table for the circuit , Click anywhere");
			break;

				case PST:
			OutputInterface->PrintMsg("Action: paste , Click anywhere");
			break;
				case DEL:
			pAct = new Del(this);
			break;

				case CUT:
			OutputInterface->PrintMsg("Action: CUT , Click anywhere");
			break;

				case COPY:
			OutputInterface->PrintMsg("Action: COPY , Click anywhere");
			break;


				case SAVE:
			OutputInterface->PrintMsg("save circuit to file");
			break;
				case LOAD:
			OutputInterface->PrintMsg("Action: load a circuit from file , Click anywhere");
			break;
				case UNDO:
			OutputInterface->PrintMsg("Action: undo an action");
			break;
				case EDIT_CONNECTION:
					pAct = new editconnection(this);
			break;

			case PROB:
			OutputInterface->PrintMsg("Action: PROBING TOOL IN SIM MODE , Click anywhere");
			break;

        case BACK:
			OutputInterface->CreateDesignToolBar();
				OutputInterface->PrintMsg("Action: return to design tool bar, Click anywhere");
				break;
		case BACK2:
				OutputInterface->CreateDesignToolBar2();
				OutputInterface->PrintMsg("Action: return to the add menu , Click anywhere");
				break;
		case Change_Switch:
			pAct = new ChangeSwitch(this);
			break;

			
		case SELECT:
			unselectall();
				OutputInterface->PrintMsg("a click on the Drawing area, unselect all");
				break;
			
		case STATUS_BAR:
				OutputInterface->PrintMsg("a click on the Status Bar");
				break;
 
		case DSN_TOOL:
				OutputInterface->PrintMsg("a click on empty area in the Design Tool Bar");
				break;

		case SIM_TOOL:
				OutputInterface->PrintMsg("a click on empty area in the SIMULATION Tool Bar");
				break;

		case SIM_MODE:
				OutputInterface->PrintMsg("Switch to Simulation Mode,creating simualtion tool bar , your circuit is simulated");
				OutputInterface->CreateSimulationToolBar();
				pAct = new operate(this);
				break;
		case OPERATE:
			OutputInterface->PrintMsg("Operate, Simulating the circuit");
			pAct = new operate(this);
			break;

		case DSN_MODE:
				OutputInterface->PrintMsg("Switch to Design Mode, creating Design tool bar");
				OutputInterface->CreateDesignToolBar();
				break;


		case EXIT:				
				break;



		case ADD_AND_GATE_2:
			pAct= new AddANDgate2(this);
			break;

		case ADD_CONNECTION:
			pAct = new AddConnection(this);
			break;
	


	}
	if(pAct)
	{
		pAct->Execute();
		delete pAct;
		pAct = NULL;
	}
}


////////////////////////////////////////////////////////////////////

void ApplicationManager::UpdateInterface()
{
		for(int i=0; i<CompCount; i++)
			CompList[i]->Draw(OutputInterface);

}

////////////////////////////////////////////////////////////////////
Input* ApplicationManager::GetInput()
{
	return InputInterface;
}

////////////////////////////////////////////////////////////////////
Output* ApplicationManager::GetOutput()
{
	return OutputInterface;
}

////////////////////////////////////////////////////////////////////

ApplicationManager::~ApplicationManager()
{
	for(int i=0; i<CompCount; i++)
		delete CompList[i];
	delete OutputInterface;
	delete InputInterface;
	
}