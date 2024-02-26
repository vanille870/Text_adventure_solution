#include <iostream>
#include <cctype>
#include <algorithm>
#include <map>
#include "Travel_Declarations.h"
#include "Action_Declarations.h" 
#include "Locations_Declarations.h"

using namespace std;

void PickDirection(Navigator* InputNavigator, LocationMap* InputLocationMap)
{
	char Direction;
	cout << "enter a direction (N,E,S,W), B to cancel" << endl;
	cin >> Direction;

	switch (toupper(Direction)) 
	{
	case 'N':

		InputNavigator->ChangeLocation(InputLocationMap->LocationMap, 'N');

		break;

	case 'E':

		InputNavigator->ChangeLocation(InputLocationMap->LocationMap, 'E');

		break;

	case 'S':

		InputNavigator->ChangeLocation(InputLocationMap->LocationMap, 'S');

		break;

	case 'W':

		InputNavigator->ChangeLocation(InputLocationMap->LocationMap, 'W');

		break;

	default:
		cout << "Not a valid direction, enter again" << endl;
		PickDirection(InputNavigator, InputLocationMap); 

	}
}