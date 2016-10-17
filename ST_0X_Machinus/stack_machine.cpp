#include "stack_machine.h"

#include <cmath>

StackMachine::StackMachine()
{
	memory.reserve(10000);
}

i32 StackMachine::GetType(i32 instruction)
{
	i32 type = 0xc0000000;
	type = (type & instruction) >> 30;		// Bitwise operation shifting 30 Bits
	return type;
}

i32 StackMachine::GetData(i32 instruction)
{
	i32 data = 0x3fffffff;
	data = data & instruction;
	return data;
}

void StackMachine::Fetch()
{
	pc++;	// CPU Fetch Cycles relearn them, fetch an instruction through incremental val rep!
}

void StackMachine::Decode()
{
	typax = GetType(memory[pc]);	// Operation performed within the bounds of memory with the program counter as the index
	smdat = GetData(memory[pc]);	// Stack Machine operation performed within the bounds of memory using the program counter
}

void StackMachine::Execution()
{
	if (typax == 0 || typax == 2)
	{
		sp++;	// Incremental op via the stack pointer
		memory[sp] = smdat;		// Memory's stack pointer element initialized to the Data Register
	}
	else { DoPrimitive(); }
}

void StackMachine::DoPrimitive()
{
	switch(smdat) {
		
		case 0:
			std::cout << "\nHalt" << std::endl;
			on = 0;
			break;
		case 1:
			std::cout << "\nAdd: " << memory[sp - 1] << " + " << memory[sp] << std::endl;
			memory[sp - 1] = memory[sp - 1] + memory[sp];
			sp--;
			break;
		case 2:
			std::cout << "\nSubtract: " << memory[sp - 1] << " - " << memory[sp] << std::endl;
			memory[sp - 1] = memory[sp - 1] - memory[sp];
			sp--;
			break;
		case 3:
			std::cout << "\nMultiply: " << memory[sp - 1] << " * " << memory[sp] << std::endl;
			memory[sp - 1] = memory[sp - 1] * memory[sp];
			sp--;
			break;
		case 4:
			std::cout << "\nDivision: " << memory[sp - 1] << " / " << memory[sp] << std::endl;
			memory[sp - 1] = memory[sp - 1] / memory[sp];
			sp--;
			break;
		case 5:
			std::cout << "\nExponentiation: " << memory[sp - 1] << " ^ " << memory[sp] << std::endl;
			memory[sp - 1] = pow(memory[sp - 1], memory[sp]);
			sp--;
			break;
		case 6:
			std::cout << "\nSquare Root: " << memory[sp] << std::endl;
			memory[sp - 1] = sqrt(memory[sp]);
			sp--;
			break;
		default:
			break; // To Have an idea of the default Construction!
	}
}

void StackMachine::Run()
{
	pc -= 1;

	while (on == 1)
	{
		Fetch();
		Decode();
		Execution();
		std::cout << "\nTop of the Stack: " << memory[sp] << std::endl;
	}
}

void StackMachine::LoadProgram(std::vector<i32> program)
{
	for (int i = 0; i < program.size(); i++)
	{
		memory[pc + i] = program[i]; 
	}
}