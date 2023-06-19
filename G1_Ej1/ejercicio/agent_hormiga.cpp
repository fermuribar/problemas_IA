#include "agent_hormiga.h"
#include "environment.h"
#include <iostream>
#include <cstdlib>
#include <vector>
#include <utility>

using namespace std;

// -----------------------------------------------------------
Agent::ActionType Agent::Think()
{
	ActionType accion = actFORWARD;
	
	/* ESCRIBA AQUI LAS REGLAS */
	if(FEROMONA_){
		accion = actFORWARD;
		sin_salida = false;
	}else{
		if(accion_anterior == actFORWARD){
			accion = actTURN_R;
		}else if(accion_anterior == actTURN_R){
			accion = actTURN_L;
		}else if(accion_anterior == actTURN_L and !sin_salida){
			accion = actTURN_L;
			sin_salida = true;
		}else{
			accion = actFORWARD;
			sin_salida = false;
		}
	}
		
	
	accion_anterior = accion;
	return accion;

}
// -----------------------------------------------------------
void Agent::Perceive(const Environment &env)
{
	FEROMONA_ = env.isFeromona();
}
// -----------------------------------------------------------
string ActionStr(Agent::ActionType accion)
{
	switch (accion)
	{
	case Agent::actFORWARD: return "FORWARD";
	case Agent::actTURN_L: return "TURN LEFT";
	case Agent::actTURN_R: return "TURN RIGHT";
	case Agent::actIDLE: return "IDLE";
	default: return "????";
	}
}
