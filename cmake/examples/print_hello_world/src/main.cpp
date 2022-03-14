#include "Hello.h"
#include <conio.h>
#include <iostream>

int main(int argc, char *argv[])
{
	Hello hi;
	hi.print();
	std::cout << "Press any key to exit!" << std::endl;
	getch();
	return 0;
}