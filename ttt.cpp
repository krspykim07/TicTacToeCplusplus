#include <iostream>
#include <vector>
#include <stdlib.h>
#include "tictactoe.hpp"

using namespace std;

int main()
{
	vector<char> sign(2); 				//	Player X and Player O
	bool trying = false;			//	Use for loops
	int winner;
	int turns;						//	Use for each space grid being occupied (max = 9)
	int pos;						//	Use to input Player's choice of position
	int count;
	vector<char> position;
	bool done = false;
	bool win = false;
  	
	// Introduction function showing welcome message and instruction.
	greet();
	 
	
	//	Player 1 picking a sign (X or O) and Player 2 automatically gets the opposite.
	//	User allows multiple attempts when inputting wrong sign.
	do{
		cout << "\n\n	========================================================================\n";
		cout << "\n	Player 1: Please choose a sign (X or O): ";
		cin >> sign[0];
		
		if(sign[0] == 'X')
		{
			sign[1] = 'O';
			trying = true;
		}
	  	else if (sign[0] == 'O')
		{
			sign[1] = 'X';
			trying = true;
	  	}
	  	else
	  	{
	    	cout << "\n\n		====== Wrong input! ======\n";
	    	cout << "		==== Please Try Again! ====\n";
	  	} 	
	}while(!trying);
	
	system("CLS");
	
	trying = false;
	
	//	Creating the vector to store values for tictactoe
  	for (int i = 0; i < 9; i++)
  	{
    	position.push_back('_');
  	}
    

  	do
  	{
  		trying = false;
  		
		for(int k = 0; k < 2; k++)
		{
			view_grid_position(position);
	    	cout << "PLAYER "<< k+1 << ":\nPlease choose grid position you want to: ";
	    	cin >> pos;
	    	
		
			for (int i = 1; i < 10; i++)
		    {
		      	if (pos == i)
		     	{
		    
		      		if(position[i-1] != '_')
		     		{
		     			cout << "\n=====This position is already occupied. Please try again.=====\n";
		     			system("pause");
		      			system("CLS");
					}
					else
					{
						position[i-1] = sign[k];
						turns++;
					}
		     	}
		   	}
		    	
		   	done = checking(position, sign[k]);
		   	
			if(done == true)
		   	{
		     	winner = k+1;
		     	trying = true;
		      	break;
			}
			
			if(turns > 8)
			{
				trying = true;
				break;
			}	
			
			system("CLS");		
		}
				
	}while(!trying);
  
  winning(winner);
  
}
