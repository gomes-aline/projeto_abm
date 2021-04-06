/*****ENERGY VARIABLES*****/

EQUATION("Firm_Energy_Tech_Coefficient")
/*
Firm's energy tech coefficient is a function of the sector's initial tech coefficient and a parameter of an energy efficiency improvement by innovation/imitation
*/
	v[0]=V("sector_energy_tech_coefficient");               //sector energy technical coefficient;
	v[1]=VL("Firm_Innovation_Energy_Efficiency",1);			//Improvement in energy efficiency through innovation process
	v[2]=VL("Firm_Imitation_Energy_Efficiency",1);			//Improvement in energy efficiency through imitation process
	if(t<2)													//if it is time step before 1
		v[3]=v[0];											//firm's energy tech coefficient is equal to the sector inicial energy tech coefficient
	else													//if firm's energy tech coefficient last period is not zero
		v[3]=min(v[1],v[2]);								//firm's energy tech coefficient is the lowest between the result from innovation and from imitation
RESULT(v[3])


EQUATION("Firm_Available_Energy_Ratio")
/*
This variable defines the ratio between available energy and energy demanded for each sector in order to fulfil desired production.
The energy constrain is related to an instrument of energy policy or energy rationing.
OBS: This is different than the Available Input Ratio, which is related to the time difference between input production by intemediate firms(t) and input use by all firms(t+1).
*/
	v[0]=V("Firm_Planned_Production");                      
	v[1]=V("Firm_Energy_Tech_Coefficient");	
	v[2]=v[0]*v[1];                    			    		//total amount of energy to required to fulfil planned production
	v[3]=V("sector_energy_constrain");      				//the percentage of energy constrained by energy policy or rationing
	v[10]=V("time_energy_policy");							//time step when the energy policy begins
	
	if(t>=v[10])											//if time step is equal or higher than the time step when the energy policy begins
		v[4]=v[2]*(1-v[3]);  						    	//amount of energy demanded considering energy constrain 
	else
		v[4]=v[2];											//no energy constrain befone the energy policy time step
	
	if(v[4]>0)                                         		//if required energy is a positive value
		v[5]=v[4]/v[2];                                  	//gives the ratio between necessary energy and available energy
	else                                               		//if required energy is not a positive value
		v[5]=1;                                          	//the ratio between necessary energy and available energy equals 1
	
	v[6]=min(1,v[5]);                                  		//the ratio can never be higher then 1
RESULT(v[6])


EQUATION("Firm_Energy_Demand")
/*
The demand for energy goods is calculated based on the planned production, the energy tech coefficient and the share of imports.
*/
	v[0]=V("Firm_Effective_Production");                    //firm's effective production (already considering energy constrain)
	v[1]=V("Firm_Energy_Tech_Coefficient");              	//firm's energy technical coefficient
	v[4]=v[0]*v[1];											//no energy constrain befone the energy policy time step
	v[5]=max(v[4],0);                               		//firm's demand of energy can never be negative
	v[6]=V("sector_energy_import_share");					//firm's energy import share
	v[7]=v[5]*(1-v[6]);										//firm's domestic demand of energy
	v[8]=v[5]*v[6];											//firm's imported demand of energy			
	v[9]=V("sector_energy_use_tax");						//sector's energy policy tax over energy use
	v[10]=V("time_energy_policy");							//time step when the energy policy begins
	if(t>=v[10])											//if time step is equal or higher than the time step when the energy policy begins
		v[11]= v[7]*v[9];									//Firm's Energy Tax is equal the tax multiplied by the amount of energy demanded
	else													//if time step is lower than the time step when the energy policy begins
		v[11]=0;											//Firm's Energy Tax is null	
	WRITE("Firm_Energy_Imports",v[8]);
	WRITE("Firm_Energy_Tax",v[11]);
RESULT(v[7])

EQUATION_DUMMY("Firm_Energy_Imports", "Firm_Energy_Demand")
EQUATION_DUMMY("Firm_Energy_Tax", "Firm_Energy_Demand")









