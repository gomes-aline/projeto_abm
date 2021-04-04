/*****ENERGY VARIABLES*****/

EQUATION("Firm_Energy_Tech_Coefficient")
/*
Firm's energy tech coefficient is a function of the sector's initial tech coefficient and a parameter of an energy efficiency improvement by innovation/imitation
*/
	v[0]=V("sector_energy_tech_coefficient");               //sector energy technical coefficient;
	v[1]=V("Firm_Innovation_Energy_Efficiency");			//Improvement in energy efficiency through innovation process
	v[2]=V("Firm_Imitation_Energy_Efficiency");				//Improvement in energy efficiency through imitation process
	v[3]=VL("Firm_Energy_Tech_Coefficient",1);				//firm's energy tech coefficient last period
	if(v[3]==0)												//if firm's energy tech coefficient last period is zero
		v[4]=v[0];											//firm's energy tech coefficient is equal to the sector inicial energy tech coefficient
	else													//if firm's energy tech coefficient last period is not zero
		v[4]=min(v[1],v[2]);								//firm's energy tech coefficient is the lowest between the result from innovation and from imitation
RESULT(v[4])


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
	v[4]=v[2]*(1-v[3]);  						    		//amount of energy demanded considering energy constrain 
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
	v[0]=V("Firm_Planned_Production");                     	//firm's planned production for the current period
	v[1]=V("Firm_Energy_Tech_Coefficient");              	//firm's energy technical coefficient
	v[2]=V("sector_energy_constrain");      				//the percentage of energy constrained by energy policy or rationing
	v[4]=v[0]*v[1]*(1-v[2]);                             	//the amount of energy demanded considering energy constrain 
	v[5]=max(v[4],0);                               		//firm's demand of energy can never be negative
	v[6]=V("sector_energy_import_share");					//firm's energy import share
	v[7]=v[5]*(1-v[6]);										//firm's domestic demand of energy
	v[8]=v[5]*v[6];											//firm's imported demand of energy			
	v[9]=V("sector_energy_use_tax");						//sector's energy policy tax over energy use
	v[10]=v[9]*v[7];										//firm's energy use tax								
	WRITE("Firm_Energy_Imports",v[8]);
	WRITE("Firm_Energy_Tax",v[8]);
RESULT(v[7])

EQUATION_DUMMY("Firm_Energy_Imports", "Firm_Energy_Demand")
EQUATION_DUMMY("Firm_Energy_Tax", "Firm_Energy_Demand")



/*
EQUATION("Firm_Energy_Imports")
/*
The demand for energy imports is calculated based on the planned production, the energy tech coefficient and the share of imports.
*//*
	v[0]=V("Firm_Planned_Production");                     	//firm's planned production for the current period
	v[1]=V("Firm_Energy_Tech_Coefficient");              	//firm's energy technical coefficient
	v[2]=V("sector_energy_constrain");      				//the percentage of energy constrained by energy policy or rationing
	v[4]=v[2]*(1-v[3]);                             		 //amount of energy demanded considering energy constrain 
	v[5]=max(v[4],0);                               		//firm's demand of energy can never be negative
	v[6]=V("sector_energy_import_share");					//firm's energy import share
	v[7]=v[5]*v[6];											//firm's imported demand of energy
RESULT(v[7])
*/






