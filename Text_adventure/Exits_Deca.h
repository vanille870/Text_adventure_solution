#pragma once
#include <iostream>
#include <string>

class Exit
{
public:
	bool Open;
	char ExitDirection;
	std::string BlockedMessage;
	std::string ExitLocation;

	Exit(bool InputIfOpen, int InputExitNumber, std::string InputBlockedMessage)
	{
		Open = InputIfOpen;
		ExitDirection = InputExitNumber;
		BlockedMessage = InputBlockedMessage;
	}

	Exit()
	{
		Open = false;
		ExitDirection = 'S';
		BlockedMessage = "exit is not set   ";
	}
};
