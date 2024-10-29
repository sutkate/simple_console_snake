#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "snake_lib.h"
using namespace std;


Fruit fruit;
Snake snake;
bool gameOver = false;
int tailX[100], tailY[100];
int nTail;

void Setup()
{
	dir = STOP;
	snake.setup_cords(map.width / 2 - 1, map.height / 2 - 1);
	fruit.randomPOS();
}

void Draw()
{
	system("CLS");
	for (int i = 0; i < map.width + 1; i++) 
		cout << "#";
	
	cout << endl;

	for (int i = 0; i < map.height; i++)
	{
		for (int j = 0; j < map.width; j++)
		{

			if ((j == 0) || (j == map.width - 1)) cout << "#";
			if (i == snake.Y() && j == snake.X()) cout << "0";
			else if (fruit.checkPOS(j, i) == true) cout << "f";
			else
			{
				bool print = false;

				for (int k = 0; k < nTail; k++)
				{
					if (tailX[k] == j && tailY[k] == i)
					{
						print = true;
						cout << "o";
					}
				}
				if (print == false) cout << " ";
			}

		}
		cout << endl;
	}

	for (int i = 0; i < map.width + 1; i++) cout << "#";
	cout << endl;
	snake.cout_score();
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case 'a':
			if (dir == RIGHT)
				break;
			else
				dir = LEFT;
			break;
		case 'd':
			if (dir == LEFT)
				break;
			else
				dir = RIGHT;
			break;
		case 'w':
			if (dir == DOWN)
				break;
			else
				dir = UP;
			break;
		case 's':
			if (dir == UP)
				break;
			else
				dir = DOWN;
			break;

		case 'x':
			gameOver = true;
			break;
		}
	}
}


void Logic()
{
	int prevX = tailX[0];
	int prevY = tailY[0];
	int prev2X, prev2Y;
	tailX[0] = snake.X(); tailY[0] = snake.Y();
	for (int i = 1; i < nTail; i++)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
	
	snake.mov_snake(dir);

	if (snake.X() >= map.width - 1) 
		snake.setup_cords(0, snake.Y());
	else if (snake.X() < 0) 
		snake.setup_cords(map.width - 1, snake.Y());
	if (snake.Y() >= map.height) 
		snake.setup_cords(snake.X(), 0);
	else if (snake.Y() < 0) 
		snake.setup_cords(snake.X(), map.height - 1);
	for (int i = 0; i < nTail; i++)
	{
		if (tailX[i] == snake.X() && tailY[i] == snake.Y()) gameOver = true;
	}
	if (fruit.checkPOS(snake.X(), snake.Y()) == true)
	{
		snake.give_score(10);
		fruit.randomPOS();
		nTail++;
	}
}

int main()
{
	Setup();
	while (!gameOver)
	{
		Sleep(20);
		Draw();
		Input();
		Logic();
	}
	return 0;
}