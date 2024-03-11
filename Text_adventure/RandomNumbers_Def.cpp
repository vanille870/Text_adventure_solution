#include "RandomNumber_Deca.h"
#include "random"

std::default_random_engine dre(std::random_device{}()); 

int MakeRandomNumber(int InputMin ,int InputMax) 
{
	std::uniform_int_distribution<int> distribution(InputMin, InputMax);

	int number = distribution(dre);

	return number;
}

