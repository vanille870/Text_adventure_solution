#include <iostream>
#include <string>
#include <map>

using namespace std;

class ActionMap
{
public: 
	map<string, int> Map;

	  void LoadActionToMap(int InputActionID, string InputActionName)
	  {
		  this->Map[InputActionName] = InputActionID;
	  }
};

void CreateMapOfActions(ActionMap* InputActionMapP);

int ReturnActionID(std :: string);

void EnterAction(ActionMap* InputActionMapP);

void DisplayHelp();
