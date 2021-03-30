/*****INNOVATION/IMITATION*****/


EQUATION("Firm_Frontier_Productivity")
/*
The new productivity is the maximum among the previous one and the ones possibly obtained imitation and innovation.  
*/
	v[0]=CURRENT;       							//frontier productivity of the firm in the last period
	v[1]=V("Firm_Imitation_Productivity");          //productivity achievied with imitation in that period
	v[2]=V("Firm_Innovation_Productivity");         //productivity achievied with innovation in that period
	v[3]=max(v[0],max(v[1],v[2]));             		//current frontier productivity is the maximum between the three
RESULT(v[3])


EQUATION("Firm_Quality")
/*
The new quality is the maximum among the previous one and the ones possibly obtained imitation and innovation. 
*/
	v[0]=CURRENT;       							//frontier quality of the firm in the last period
	v[1]=V("Firm_Imitation_Quality");          		//quality achievied with imitation in that period
	v[2]=V("Firm_Innovation_Quality");         		//quality achievied with innovation in that period
	v[3]=max(v[0],max(v[1],v[2]));        			//current frontier quality is the maximum between the three
RESULT(v[3])


EQUATION("Firm_Imitation_Productivity")
/*
Imitation process. The sucess depends on the amount of recources alocated to imitation. Firms search for best productivity and best quality of the sector, trying to copy if succeded.
*/
	v[0]=V("Firm_RND_Expenses");                    //firm's RND expenses
	v[1]=V("sector_innovation_proportion");    		//firm's share of RND expenses destinated to innovation
	v[2]=(v[0]*(1-v[1]));                           //amount of recources for imitation
	v[3]=1-exp(-v[2]);                   			//probability of success of the imitation depends on amount of recources available
	if(RND<v[3])                              		//draws a random number. if it is lower then imitation probability
     	v[4]=VL("Sector_Max_Productivity", 1);  	//imitation has succeded and the firm can copy the maximum probability of the sector in the last perio
  	else                                      		//if the random number is not lower than imitation probability
     	v[4]=0;                                 	//imitation failed and return a productivity zero
RESULT(v[4])


EQUATION("Firm_Innovation_Productivity")
/*
Innovation process. The sucess depends on the amount ou recources alocated to innovation. Firms search for new productivity and porduct quality and the result depends on a random distribution with exonegous parameters.
*/
	v[0]=V("Firm_RND_Expenses");                    	//firm's RND expenses                       
	v[1]=V("sector_innovation_proportion");    			//firm's share of RND expenses destinated to innovation
	v[2]=(v[0]*v[1]);                           		//amount of recources for innovation
	v[3]=1-exp(-v[2]);                     				//probability of success of the innovation depends on the parameter and the amount of recources available  
	if(RND<v[3])                                		//draws a random nuumber. if it is lower then innovation probability 
		{
		v[4]=V("sector_std_dev_innovation");           	//innovation standard deviation
		v[5]=V("sector_initial_productivity");			//initial frontier productivity
		v[6]=V("sector_tech_opportunity_productivity"); //sector technological opportunity for process innovation
		v[7]=log(v[5])+(double)t*(v[6]);        		//the average of the innovation distribution will be the initial frontier productivity plus the opportunity parameter times the time period
		v[8]=exp(norm(v[7],v[4]));             			//the innovation productivity will be a draw from a normal distribution with average depending of the tech regime and std. dev fixed
		}
	else                                        		//if the random number is not lower then  the innovation probability
		v[8]=0;                                			//innovation failed and the productivity is zero
RESULT(v[8])


EQUATION("Firm_Imitation_Quality")
/*
Imitation process. The sucess depends on the amount of recources alocated to imitation. Firms search for best quality of the sector, trying to copy if succeded.
*/
	v[0]=V("Firm_RND_Expenses");                   		//firm's RND expenses
	v[1]=V("sector_innovation_proportion");    			//firm's share of RND expenses destinated to innovation
	v[2]=(v[0]*(1-v[1]));                           	//amount of recources for imitation
	v[3]=1-exp(-v[2]);                   				//probability of success of the imitation depends on amount of recources available
	if(RND<v[3])                              			//draws a random number. if it is lower then imitation probability
     	v[5]=VL("Sector_Max_Quality", 1);				//imitation has succeded and the firm can copy the maximum quality of the sector in the last period
  	else                                      			//if the random number is not lower than imitation probability
     	v[5]=0;											//imitation failed and return a quality zero
RESULT(v[5])


EQUATION("Firm_Innovation_Quality")
/*
Innovation process. The sucess depends on the amount ou recources alocated to innovation. Firms search for new quality and the result depends on a random distribution with exonegous parameters.
*/
	v[0]=V("Firm_RND_Expenses");                    	//firm's RND expenses                       
	v[1]=V("sector_innovation_proportion");    			//firm's share of RND expenses destinated to innovation
	v[2]=(v[0]*v[1]);                           		//amount of recources for innovation
	v[3]=1-exp(-v[2]);                     				//probability of success of the innovation depends on the parameter and the amount of recources available  
	if(RND<v[3])                                		//draws a random nuumber. if it is lower then innovation probability 
		{
		v[4]=V("sector_std_dev_innovation");           	//innovation standard deviation
		v[5]=V("sector_initial_quality");				//initial quality
		v[6]=V("sector_tech_opportunity_quality");      //sector technological opportunity for product innovation
		v[7]=log(v[5])+(double)t*(v[6]);        		//the average of the innovation distribution will be the initial quality plus the opportunity parameter times the time period
		v[8]=exp(norm(v[7],v[4]));						//the innovation quality will be a draw from a normal distribution with average depending of the tech regime and std. dev fixed
		}
	else                                        		//if the random number is not lower then the innovation probability
		v[8]=0;											//innovation failed and the quality is zero
RESULT(v[8])


EQUATION("Firm_Imitation_Energy_Efficiency")
/*
Imitation process. The sucess depends on the amount of recources alocated to imitation. Firms search for best energy efficiency of the sector, trying to copy if succeded.
*/

v[0]=VL("Firm_Energy_Tech_Coefficient",1);						//firm's energy tech coefficient last period
if(V("switch_energy_efficiency_imitation")==1)
{
	v[1]=V("Firm_RND_Expenses");                    			//firm's RND expenses                       
	v[2]=V("sector_innovation_proportion");    					//firm's share of RND expenses destinated to innovation
	v[3]=(v[2]*v[1]);                           				//amount of recources for innovation
	v[4]=1-exp(-v[3]);                     						//probability of success of the innovation depends on the parameter and the amount of recources available  
	if(RND<v[4])                                				//draws a random number. if it is lower then innovation probability 
		v[5]=VL("Sector_Min_Energy_Tech_Coefficient", 1);		//imitation has succeded and the firm can copy the minimum energy tech coefficient of the sector in the last period
	else                                      					//if the random number is not lower than imitation probability
		v[5]=v[0];													//imitation failed and the firm's new energy tech coefficient is the same than the last period
}
else
v[5]=v[0];	
RESULT(v[5])


EQUATION("Firm_Innovation_Energy_Efficiency")
/*
Innovation process. The sucess depends on the amount ou recources alocated to innovation. Firms search for improvement in energy efficiency and the result depends on a random distribution with exonegous parameters.
*/
v[0]=VL("Firm_Energy_Tech_Coefficient",1);				//firm's energy tech coefficient last period
if(V("switch_energy_efficiency_innovation")==1)
{
	v[1]=V("Firm_RND_Expenses");                    	//firm's RND expenses                       
	v[2]=V("sector_innovation_proportion");    			//firm's share of RND expenses destinated to innovation
	v[3]=(v[2]*v[1]);                           		//amount of recources for innovation
	v[4]=1-exp(-v[3]);                     				//probability of success of the innovation depends on the parameter and the amount of recources available  
	if(RND<v[4])                                		//draws a random number. if it is lower then innovation probability 
	{
		v[5]=norm(0.01,0.005);							//the energy efficiency improvemente will be a draw from a normal distribution
		v[6]=max(0,v[5]);								//the energy improvement can never be negative
		v[7]=v[0]-v[6];									//the firm's new energy tech coefficient is lower than the last period
		v[8]=max(0.01,v[7]);							//the lower limit to energy efficiency is 1% (it can never be lower than 0.01)
	}
	else                                        		//if the random number is not lower then the innovation probability
		v[8]=v[0];									 	//the firm's new energy tech coefficient is the same than the last period
}
else
	v[8]=v[0];											// if the switch is of, the firm's energy tech coefficient is the same than the last period	
RESULT(v[8])