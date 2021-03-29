/*****ENERGY VARIABLES*****/

EQUATION("Firm_Energy_Demand")
/*
The demand for energy goods is calculated based on the planned production, the energy tech coefficient and the share of imports.
*/
	v[0]=V("Firm_Planned_Production");                     	//firm's planned production for the current period
	v[1]=V("sector_energy_tech_coefficient");               //energy technical coefficient
	v[2]=(v[0]*v[1]);
	v[3]=max(v[2],0);                               		//the demand of energy for the next period can never be negative
	v[4]=V("sector_energy_import_share");
	v[5]=v[3]*(1-v[4]);
	//v[6]=v[3]*v[4];
	//WRITE("Firm_Energy_Imports",v[6]);
RESULT(v[5])

//EQUATION_DUMMY("Firm_Energy_Imports", "Firm_Energy_Demand")
//OBS: deu problema


EQUATION("Firm_Energy_Imports")
/*
The demand for energy imports is calculated based on the planned production, the energy tech coefficient and the share of imports.
*/
	v[0]=V("Firm_Planned_Production");                     	//firm's planned production for the current period
	v[1]=V("sector_energy_tech_coefficient");               //energy technical coefficient
	v[2]=(v[0]*v[1]);
	v[3]=max(v[2],0);                               		//the demand of energy for the next period can never be negative
	v[4]=V("sector_energy_import_share");
	v[5]=v[3]*v[4];
RESULT(v[5])







