/*****ENERGY VARIABLES*****/

EQUATION("Firm_Energy_Tech_Coefficient")
/*
Firm's energy tech coefficient is a function of the sector's initial tech coefficient and a parameter of an energy efficiency improvement by inovation
*/
	v[0]=V("sector_energy_tech_coefficient");               //sector energy technical coefficient
RESULT(v[0])


EQUATION("Firm_Energy_Demand")
/*
The demand for energy goods is calculated based on the planned production, the energy tech coefficient and the share of imports.
*/
	v[0]=V("Firm_Planned_Production");                     	//firm's planned production for the current period
	v[1]=V("Firm_Energy_Tech_Coefficient");              	//firm's energy technical coefficient
	v[2]=V("sector_energy_tech_coefficient"); 				//sector's energy technical coefficient
	v[3]=min(v[1],v[2]);									//firm's energy tech coefficient is never larger than the sector's 
	v[4]=(v[0]*v[3]);										//firm's demand of energy
	v[5]=max(v[4],0);                               		//firm's demand of energy can never be negative
	v[6]=V("sector_energy_import_share");					//firm's energy import share
	v[7]=v[5]*(1-v[6]);										//firm's domestic demand of energy
	//v[8]=v[5]*v[6];
	//WRITE("Firm_Energy_Imports",v[8]);
RESULT(v[7])

//EQUATION_DUMMY("Firm_Energy_Imports", "Firm_Energy_Demand")
//OBS: deu problema


EQUATION("Firm_Energy_Imports")
/*
The demand for energy imports is calculated based on the planned production, the energy tech coefficient and the share of imports.
*/
	v[0]=V("Firm_Planned_Production");                     	//firm's planned production for the current period
	v[1]=V("Firm_Energy_Tech_Coefficient");              	//firm's energy technical coefficient
	v[2]=V("sector_energy_tech_coefficient"); 				//sector's energy technical coefficient
	v[3]=min(v[1],v[2]);									//firm's energy tech coefficient is never larger than the sector's 
	v[4]=(v[0]*v[3]);										//firm's demand of energy
	v[5]=max(v[4],0);                               		//firm's demand of energy can never be negative
	v[6]=V("sector_energy_import_share");					//firm's energy import share
	v[7]=v[5]*v[6];											//firm's imported demand of energy
RESULT(v[7])







