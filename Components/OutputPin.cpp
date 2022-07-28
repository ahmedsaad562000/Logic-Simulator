#include "OutputPin.h"
#include "Connection.h"

OutputPin::OutputPin(int r_FanOut)
{
	nulls = 0;
	m_Conn = 0;		//initially Pin is not connected to anything.
	m_FanOut = r_FanOut > MAX_CONNS ? MAX_CONNS: r_FanOut;	//set the fan out of the pin.
}

//Functionn ConnectTo:
//Connects the ouput pin the the passed connection if the fan out permits
//if the no. of connections is already equals to the fan out, no more connections can be created.
bool OutputPin::ConnectTo(Connection *r_Conn)
{
	if((m_Conn-nulls) < m_FanOut)
	{
		
		m_Connections[m_Conn++] = r_Conn;	//add a new connection the the array of connections
		return true;
		
	}
	
	return false;	//can't connect to any more connections
}

bool OutputPin::removeconnection(Connection *r_Conn){
	for (int i = 0; i < m_Conn; i++)
	{
		if(m_Connections[i]== r_Conn){
			m_Connections[i] =NULL;
			
			nulls = nulls +1;
		
		
			return true;
		}
		
	}
	return false;
}
void OutputPin::deleteconnections(Output* pOut , ApplicationManager* pApp){
	
	for (int i = 0; i < m_Conn; i++)
	{
		if(!m_Connections[i]){}
		
		else
		m_Connections[i]->deletecmpn(pOut , pApp);
	
	
	}

}

void OutputPin::operate(){

	for (int i = 0; i < m_Conn; i++)
	{
		if(!m_Connections[i]){}
		else{
			m_Connections[i]->Operate();}
	}
}