/*********************************************************************
*      Filename: A4Part2.cpp                                         *
*      Login: lm890                                                  *
*      lab No: Assignment 4                                          *
*      File Description: Part 2. 2048 File Output                    *
*      Date Last Modified: 02/11/2014                                *
**********************************************************************/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstdlib>
using namespace std;

void displayGame(int const array[4][4]);
void combineCells(int array[4][4], int a, int b, char d);
int checkMove(int const array[4][4], char d);
int moveLeft(int array[4][4]);
int moveRight(int array[4][4]);
int moveUp(int array[4][4]);
int moveDown(int array[4][4]);
void addTwo(int array[4][4]);

int main() 
{
	int game[4][4] = {0};
	char direction;
	char confirm;
	bool end = true;
	char fileName[50];
	bool save = true;
	int random = 0;
	ofstream ofile;
	ifstream ifile;
	
	//for seed()
	cout << "Enter a number as seed:";
	cin >> random;
	srand(random);

	//game start
	addTwo(game);
	displayGame(game);

	cout << "Input A for left," << endl;
	cout << "Input D for right," << endl;
	cout << "Input W for up," << endl;
	cout << "Input S for down:" << endl;
	cout << "Input B for Save:" << endl;

	
	//move
	while(end == true)
	{
		cin >> direction;
		
		if(checkMove(game, direction) == 0)
		{
			switch(direction)
			{
				case 'A':
				case 'a':
					moveLeft(game);
					addTwo(game);
				    break;
				case 'D':
				case 'd':
					moveRight(game);
					addTwo(game);
				    break;
				case 'W':
				case 'w':
					moveUp(game);
					addTwo(game);
				    break;
				case 'S':
				case 's':
					moveDown(game);
					addTwo(game);
				    break;
				case 'B':
				case 'b':
					cout << "Do you want to save the game?(Y/N)" << endl;
					cin >> confirm;
					if(confirm == 'Y' || confirm == 'y')
					{
						save = true;
						while(save == true)
						{
							cout << "Input the name of the file: ";
							cin.ignore(10, '\n');
							cin.getline(fileName, 50, '\n');
							
							ifile.open(fileName);
							if(!ifile.good())
							{
								ofile.open(fileName);
								for(int i = 0; i < 4; i++)
										for(int j = 0; j < 4; j++)
											ofile << game[i][j] << endl;
								ofile.close();
								save = false;
							}
							else
							{
								ifile.close();
								cout << "Are you sure you want to overwirte it?(Y/N)"
								 	 << endl;
								cin >> confirm;
								if(confirm == 'Y' || confirm == 'y')
								{
									ofile.open(fileName);
									for(int i = 0; i < 4; i++)
										for(int j = 0; j < 4; j++)
											ofile << game[i][j] << endl;
									ofile.close();
									save = false;
									cin.ignore(10, '\n');
								}
								else
								{
									cout << "Do you want to input a new file name?(Y/N)"
										 << endl;
									cin >> confirm;
									if(!(confirm == 'Y' || confirm == 'y'))
									{
										cout << "Game is not saved." << endl;
										ofile.close();
										save = false;
									}
								}
							}
						}
					}
					else
						cout << "Game is not saved." << endl;
					cout << "Input Y to continue, others to end: " << endl; 
					cin >> confirm;
					if(confirm != 'Y' && confirm != 'y')
						end = false;
					break;
				default:
					cout << "invalid input.\n";
			}
		}
		else
			cout << "invalid direcltion!" << endl;
		
		displayGame(game);
		
		//game end
		if(checkMove(game, direction = 'a') && 
			checkMove(game, direction = 'd') &&
			checkMove(game, direction = 'w') &&
			checkMove(game, direction = 's'))
			end = false;
	}

	cout << "Game End!" << endl;

	return 0;
}

void displayGame(int const array[4][4])
{
	for(int i = 0; i < 4; i++)
	{
		for(int j = 0; j < 4; j++)
			if(array[i][j] == 0)
				cout << setw(5) << left << "| " ;
			else
			{
				cout << "|" 
					 << setw(4) << left << array[i][j] ;
			}
		cout << "|" <<endl; 
	}
	cout << endl;
}

int checkMove(int const array[4][4], char d)
{
	int move = 1;
	switch(d)
	{
		case 'A':
		case 'a':
			for(int i = 0; i < 4 && move; i++)
				for(int j = 0; j < 3 && move; j++)
				{
					if(array[i][j] == array[i][j+1] && array[i][j] != 0)
					{
						move = 0;
					}
					else if(array[i][j] == 0 && array[i][j+1] != 0)
					{
						move = 0;
					}
					else
						move = 1;
				}
				break;
		case 'D':
		case 'd':
			for(int i = 0; i < 4 && move; i++)
				for(int j = 3; j > 0 && move; j--)
				{
					if(array[i][j] == array[i][j-1] && array[i][j] != 0)
					{
						move = 0;
					}
					else if(array[i][j] == 0 && array[i][j-1] != 0)
					{
						move = 0;
					}
					else
						move = 1;
				}
				break;
		case 'W':
		case 'w':
			for(int i = 0; i < 4 && move; i++)
				for(int j = 0; j < 3 && move; j++)
				{
					if(array[j][i] == array[j+1][i] && array[j][i] != 0)
					{
						move = 0;
					}
					else if(array[j][i] == 0 && array[j+1][i] != 0)
					{
						move = 0;
					}
					else
						move = 1;
				}
				break;
		case 'S':
		case 's':
			for(int i = 0; i < 4 && move; i++)
				for(int j = 3; j > 0 && move; j--)
				{
					if(array[j][i] == array[j-1][i] && array[j][i] != 0)
					{
						move = 0;
					}
					else if(array[j][i] == 0 && array[j-1][i] != 0)
					{
						move = 0;
					}
					else
						move = 1;
				}
				break;
		case 'B':
		case 'b':
			move = 0;

	}
	
	return move;
}

void addTwo(int array[4][4])
{
	bool added = true;
	while(added == true)
	{
		int i = rand() % 4;
		int j = rand() % 4;
		if(array[i][j] == 0)
		{
			array[i][j] = 2;	
			added = false;
		}
	}
}

void combineCells(int a[4][4], int m, int n, char d)
{
	switch(d)
	{
		case 'a':
			a[m][n] = 2 * a[m][n];
			a[m][n+1] = 0;
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++)
				{
					if(a[i][j] == 0)
						for (int k = j; k < 3; k++)
						{
							a[i][k] = a[i][k+1];
							a[i][k+1] = 0;
						}
				}
			break;
		case 'd':
			a[m][n] =2 * a[m][n-1];
			a[m][n-1] = 0;
			for(int i = 3; i >= 0; i--)
				for(int j = 3; j >= 0; j--)
				{
					if(a[i][j] == 0)
						for (int k = j; k > 0; k--)
						{
							a[i][k] = a[i][k-1];
							a[i][k-1] = 0;
						}
				}
			break;
		case 'w':
			a[n][m] = 2 * a[n+1][m];
			a[n+1][m] = 0;
			for(int i = 0; i < 4; i++)
				for(int j = 0; j < 4; j++)
				{
					if(a[j][i] == 0)
						for (int k = j; k < 3; k++)
						{
							a[k][i] = a[k+1][i];
							a[k+1][i] = 0;
						}
				}
			break;
		case 's':
			a[n][m] = 2 * a[n-1][m];
			a[n-1][m] = 0;
			for(int i = 3; i >= 0; i--)
				for(int j = 3; j >= 0; j--)
				{
					if(a[j][i] == 0)
						for (int k = j; k > 0; k--)
						{
							a[k][i] = a[k-1][i];
							a[k-1][i] = 0;
						}
				}
			break;
	}
}

int moveLeft(int a[4][4])
{
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			if(a[i][j] == 0)
			for (int k = j; k < 3; k++)
			{
				a[i][k] = a[i][k+1];
				a[i][k+1] = 0;
			}
		}
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			if(a[i][j] == 0)
			for (int k = j; k < 3; k++)
			{
				a[i][k] = a[i][k+1];
				a[i][k+1] = 0;
			}
		}
	char direction = 'a';
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 3; j++)
		{
			if(a[i][j] == a[i][j+1])
				combineCells(a, i, j, direction);
		}
}
int moveRight(int a[4][4])
{
	for(int i = 3; i >= 0; i--)
		for(int j = 3; j >= 0; j--)
		{
			if(a[i][j] == 0)
			for (int k = j; k > 0; k--)
			{
				a[i][k] = a[i][k-1];
				a[i][k-1] = 0;
			}
		}
	for(int i = 3; i >= 0; i--)
		for(int j = 3; j >= 0; j--)
		{
			if(a[i][j] == 0)
			for (int k = j; k > 0; k--)
			{
				a[i][k] = a[i][k-1];
				a[i][k-1] = 0;
			}
		}
	char direction = 'd';
	for(int i = 3; i >= 0; i--)
		for(int j = 3; j >= 0; j--)
		{
			if(a[i][j] == a[i][j-1])
				combineCells(a, i, j, direction);
		}
}
int moveUp(int a[4][4])
{	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			if(a[j][i] == 0)
			for (int k = j; k < 3; k++)
			{
				a[k][i] = a[k+1][i];
				a[k+1][i] = 0;
			}
	}	
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 4; j++)
		{
			if(a[j][i] == 0)
			for (int k = j; k < 3; k++)
			{
				a[k][i] = a[k+1][i];
				a[k+1][i] = 0;
			}
	}
	char direction = 'w';
	for(int i = 0; i < 4; i++)
		for(int j = 0; j < 3; j++)
		{
			if(a[j][i] == a[j+1][i])
				combineCells(a, i, j, direction);
		}
}
int moveDown(int a[4][4])
{		
	for(int i = 3; i >= 0; i--)
		for(int j = 3; j >= 0; j--)
		{
			if(a[j][i] == 0)
			for (int k = j; k > 0; k--)
			{
				a[k][i] = a[k-1][i];
				a[k-1][i] = 0;
			}
		}		
	for(int i = 3; i >= 0; i--)
		for(int j = 3; j >= 0; j--)
		{
			if(a[j][i] == 0)
			for (int k = j; k > 0; k--)
			{
				a[k][i] = a[k-1][i];
				a[k-1][i] = 0;
			}
		}
	char direction = 's';
	for(int i = 3; i >= 0; i--)
		for(int j = 3; j >= 0; j--)
		{
			if(a[j][i] == a[j-1][i])
				combineCells(a, i, j, direction);
		}
}
