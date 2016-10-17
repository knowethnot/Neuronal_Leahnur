#include <iostream>
#include <cstdlib>
#include "stack_machine.h"

int main()
{
	StackMachine vm;
	std::vector <i32> program { 1, 1, 0x40000001, 1, 0x40000002, 16, 0x40000003, 1, 0x40000004, 8, 0x40000005, 64, 0x40000006, 0x40000000 };
	vm.LoadProgram(program);
	vm.Run();
	
	std::cout << "\nPress [Enter] To Quit....." << std::endl;
	std::cin.ignore(10, '\n');
	std::cin.get();

	return 0;
}