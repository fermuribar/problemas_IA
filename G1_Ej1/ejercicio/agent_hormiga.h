#ifndef AGENT__
#define AGENT__

#include <string>
#include <iostream>
using namespace std;

// -----------------------------------------------------------
//				class Agent
// -----------------------------------------------------------
class Environment;
class Agent
{
public:
	Agent(){
	    FEROMONA_=false;
		accion_anterior = actFORWARD;
		sin_salida = false;
		//mapa = vector<vector<int>>(20,vector<int>(20,0));
	}

	enum ActionType
	{
	    actFORWARD,
	    actTURN_L,
	    actTURN_R,
		actIDLE
	};

	void Perceive(const Environment &env);
	ActionType Think();

private:
	bool FEROMONA_, sin_salida;
	ActionType accion_anterior;
	//vector<vector<int>> mapa;
};

string ActionStr(Agent::ActionType);

#endif
