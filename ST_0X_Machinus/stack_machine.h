#ifndef STACK_MACHINE_H
#define STACK_MACHINE_H

#include <iostream>
#include <vector>

typedef int32_t i32;

class StackMachine {
		
	i32 pc = 100;	// 32 Bit Program Counter
	i32 sp = 0;		// Stack Pointer
	std::vector<i32> memory;
	i32 typax = 0;	// TYPAX 32 Bit Register
	i32 smdat = 0;	// 32 Bit Stack Machine Data Register
	i32 on = 1;

	i32 GetType(i32 instruction);
	i32 GetData(i32 instruction);
	void Fetch();
	void Decode();
	void Execution();
	void DoPrimitive();

	public:
		StackMachine();
		void Run();
		void LoadProgram(std::vector<i32> program);
		~StackMachine() { std::cout << "Free'd all objectal memory from the heap or Did we?\n" << std::endl; }
	
};

#endif // STACK_MACHINE_H