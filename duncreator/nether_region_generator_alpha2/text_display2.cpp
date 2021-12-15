#include"text_display2.h"

void displayStep(const std::vector<cords> toDisplay, const int size)
{
	system("CLS");
	for (int i = 0; i < size; ++i)
	{
		for (int j = 0; j < size; ++j)
		{
			cords c = { i,j };
			bool empty = true;
			for (int k = 0; k < toDisplay.size(); ++k)
			{
				if (c.x == toDisplay[k].x && c.y == toDisplay[k].y)
				{
					std::cout << "o";
					empty = false;
				}
			}
			if (empty)
				std::cout << "-";
			std::cout << " ";
		}
		std::cout << std::endl;
	}
}
