#include <iostream>
#include <vector>
#include <stdlib.h>
#include "tictactoe.hpp"

using namespace std;

void greet(){
  
	cout << "\n\n\n					===============================\n";
	cout << "					=== Welcome to tic tac toe! ===\n";
	cout << "					===============================\n";
	cout << "\n\n	Instructions:\n";
	cout << "	1. Player 1 needs to choose between X or O and Player 2 will automatically get the other sign\n";
	cout << "	2. Each player needs to pick a number assigned for grid position you want to place in\n\n	";
	system("pause");

}

void view_grid_position(vector<char> position){						//output the current tictactoe
  
  int count = 0;

  cout << "\n			- - - - - - - - - - - -\n";
  for (int i = 0; i < 3; i++)
  {
    cout << "			||  ";
    for (int j = 0; j < 6; j++)
    {
      if (j%2 == 0)
      {
        cout << position[count];
        count++;
      }
      else
      {
        cout << "  ||  ";
      }

    }
    cout << "\n			- - - - - - - - - - - -\n";
  }
}

bool checking(vector<char> position, char side)
{
  bool win = false;


  //checking rows
  if (side == position[0] && side == position[1] && side == position[2])
  {
    win = true;
  }
  else if(side == position[3] && side == position[4] && side == position[5])
  {
    win = true;
  }
  else if(side == position[6] && side == position[7] && side == position[8])
  {
    win = true;
  }

  //checking columns
  else if(side == position[0] && side == position[3] && side == position[6])
  {
    win = true;
  }
  else if(side == position[1] && side == position[4] && side == position[7])
  {
    win = true;
  }
  else if(side == position[2] && side == position[5] && side == position[8])
  {
    win = true;
  }
  
  //checking diagonal
  else if(side == position[0] && side == position[4] && side == position[8])
  {
    win = true;
  }
  else if(side == position[2] && side == position[4] && side == position[6])
  {
    win = true;
  }
  else
  {
    win = false;
  }

  return win;
  
}

void winning(int win)
{
	system("CLS");
	
	cout << "\n\n";
	
  	if (win == 1)
  	{
    	cout <<"			=====================================\n";
		cout <<"			========= WE HAVE A WINNER!! ========\n";
    	cout <<"			========= CONGRATS PLAYER 1 =========\n";
    	cout <<"			=====================================\n";
  	}
  	else if(win == 2)
  	{
  		cout <<"			=====================================\n";
		cout <<"			========= WE HAVE A WINNER!! ========\n";
    	cout <<"			========= CONGRATS PLAYER 2 =========\n";
    	cout <<"			=====================================\n";
	  }
  	else
  	{
		cout <<"			========================\n";
    	cout <<"			====== STALEMENT!! =====\n";
    	cout <<"			========================\n";
 	 }
}


