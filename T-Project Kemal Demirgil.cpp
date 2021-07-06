//  Kemal Demirgil
//  Semester Project
//	T-Test

#include <iostream>

#include <iostream>
#include <cmath>


using namespace std;

double meanFunction(double x[], int numValues)
{
	double sum = 0.0f;
	int i=0;
	while( i < numValues){

		sum+= x[i];
		
		i++;
	}
	
	double mean = sum/numValues;

	return mean;
}


int main(){
 

	/********************************************************VARIABLES*********************************************************************************************/

	//arrays
	double x[120]; //user raw data inputs
	double table[36]={6.314, 2.920, 2.353, 2.132, 2.015, 1.943, 1.895, 1.860, 1.833, 1.813, 1.796, 1.783, 1.771, 1.762, 1.753, 1.746, 1.740, 1.743, 1.729, 1.725, 1.721, 1.717, 1.714, 1.711, 1.708, 1.706, 1.704, 1.701, 1.699, 1.698, 1.690, 1.684, 1.671, 1.664, 1.660, 1.658};

	//int
	int i=0, df;
	int pause;

	//double
	double sum, num, M, XMS, XM, SD, SEM, TC, TG, AVG;





	/******************************************************* INSTRUCTION LIST *************************************************************************************/

	cout<<"This program can intake as many as 120 values to run a t-test. The hypothesis testing is one-tailed with a p-value of 0.05: ho Tg=Tc  or h1 Tg!=Tc\n";

	cout<<"What is the population average? ";
	cin>>AVG;
	cout<<"\n";

	cout<<"How many numbers do you have to enter?: ";
	cin>> num;
	cout<<"\n";

	//collect raw data from user
	//if user enters "0" during raw data collection, then loop is complete and data finished being collected
	while(i < num)
	{
		cout<<"Please enter a value: ";
		cin>> x[i];
		cout<<"\n";
		
		if(x[i] == 0.0)
		{
			break;
		}
		
		i++;
	};

	//find df
	df= num-1;
	cout<<"You have: " << df <<"Degrees of freedom\n";


	//find M; sample average
	M = meanFunction(x, num);
	cout<<"The sample average is: "<< M << "\n";


	//find SD
	i = 0;

	while( i < num ){	 

		XM = x[i] - M;

		XMS += pow(XM, 2);

		i++;
		
	}


	SD = sqrt( XMS/df);


	//find SEM
	SEM = SD / sqrt(num);


	//find TG
	TG = (M -AVG) / SEM;


	cout<<"SD: " << SD <<"\n";

	cout<<"SEM: " << SEM <<"\n";

	cout<<"Test Group t-value: " << TG <<"\n";



	//Find TC
	if (df < 30){
		
		TC = table[df-1];
		
	}

	else if ((df > 30 ) && ( df < 35)){
		
		TC = table[30];
		
	}

	else if ((df >= 35 ) && ( df < 40)){
		
		TC = table[31];
		
	}

	else if ((df >= 40 ) && ( df < 60)){
		
		TC = table[32];
		
	}

	else if ((df >= 60 ) && ( df < 80)){
		
		TC = table[32];
		
	}

	else if ((df >= 80 ) && ( df < 100)){
		
		TC = table[33];
		
	}

	else{
		
		TC = table[35];
		
	}


	cout<<"the critical values (TC): " << TC << "\n";



	//find final answer to hypothesis test
	if ( TG == TC){
		
		cout<<"There is no difference between your population and your sample group\n";
		
	}

	else{
		
		if (TG > TC){
			
				cout<<"There is a difference between your sample group and the population: TG > TC \n";
			
		}
		
		else{
			
				cout<<"There is a difference between your sample group and the population: TG < TC \n";
				
			}
	}









	cin>> pause; 
	return 0; 
} // end main program

/******************************************************FUNCTIONS***********************************************************************************************/
