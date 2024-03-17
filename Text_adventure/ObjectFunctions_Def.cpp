#include <iostream>
#include <vector>
#include "ObjectFunctionsDeca.h"
#include "Locations_Declarations.h"

void ChangExitAcces(Exit InputExit, bool InputExitOpen)
{
	InputExit.Open = InputExitOpen;
}

void InvertExitAcces(Exit InputExit)
{
	InputExit.Open = !InputExit.Open;

}
