#pragma once
struct Map
{
	int width = 20;
	int height = 20;
};

Map map;


class Fruit
{
private:
	int fruitX;
	int fruitY;

public:
	void makeNULL() { fruitX = 0; fruitY = 0; }
	void randomPOS() { fruitX = rand() % map.width; fruitY = rand() % map.height; }
	bool checkPOS(int x, int y)
	{
		if (fruitX == x && fruitY == y)
			return true;
		else
			return false;
	}
};

enum eDirecrtion { STOP = 0, LEFT, RIGHT, UP, DOWN };
eDirecrtion dir;

class Snake
{
private:
	int score, x, y;
public:
	void cout_score() { std::cout << "Score: " << score; }
	void give_score(int x) { score += x; }
	void mov_snake(eDirecrtion arg) 
	{
		switch (dir)
		{
		case LEFT:
			x--;
			break;
		case RIGHT:
			x++;
			break;
		case UP:
			y--;
			break;
		case DOWN:
			y++;
			break;
		default:
			break;
		}
	}
	int X() const { return x; }
	int Y() const { return y; }
	void setup_cords(int x1, int y1) { x = x1; y = y1; }
};

class DrawGame
{
private:
	Map map;
	bool print = false;
public:
	void snakeDraw(Snake snake, )
	{
		for (int i = 0; i < map.height; i++)
		{
			for (int j = 0; j < map.width; j++)
			{

				if ((j == 0) || (j == map.width - 1)) cout << "#";
				if (i == snake.Y() && j == snake.X()) cout << "0";
				else if (fruit.checkPOS(j, i) == true) cout << "f";
				else
				{
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
	}
};