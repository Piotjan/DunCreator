#include"text_display.h"

void displayRooms(level& lev)
{
	system("CLS");
	{
		for (int i = 0; i < lev.getSize(); ++i)
		{
			for (int j = 0; j < lev.getSize(); ++j)
			{
				cords c = { i,j };
				if (lev.getSement(c))
					std::cout << "o";
				else
					std::cout << "-";
				std::cout << " ";
			}
			std::cout << std::endl;
		}
	}
	std::cout << std::endl << lev.getElementsCount() << std::endl;
}
