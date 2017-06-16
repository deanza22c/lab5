#ifndef GLOBALS_H
#define GLOBALS_H
#include<string>
#include<iostream>

const int ARRAY_SIZE = 26;


int getDoubleDigitMenuInput(std::string size)
{
	int size1 = stoi(size.substr(0, 1));
	int size2 = stoi(size.substr(1, 1));
	int safety;
	int entry;
	int userInput = 0;
	std::string tempString;
	getline(std::cin, tempString);
	if (tempString.length() > 1){
		while ((tempString[0] < 49 || tempString[0] > (48 + size1)) || tempString[1] < 49 || tempString[1] > (48 + size2) || tempString[2] != '\0')
		{
			safety = stoi(size);
			entry = stoi(tempString);
			//clif - uncomment this to get a better idea of what i am doing
			//std::cout << safety << " " << entry;
			if (safety < entry){
				std::cout << "1 - " << size << " are the only valid choices, try again: ";
				getline(std::cin, tempString);
			}
			else {
				break;;
			}
		}
	}
	else {
		int size1 = stoi(size);
		while ((tempString[0] < 49 || tempString[0] > (48 + size1)) || tempString[1] != '\0')
		{
			std::cout << "1 - " << size << " are the only valid choices, try again: ";
			getline(std::cin, tempString);
		}
	}
	userInput = stoi(tempString);
	return userInput;
}


int getIntegerInput()
{
	int number;
	std::string inputString;
	bool hasAlphaChars = false;
	getline(std::cin, inputString);
	for (int count = 0; count < inputString.length(); count++)
	if (isdigit(inputString[count]) == 0)
	{
		hasAlphaChars = true;
	}
	while (hasAlphaChars || inputString == "\0")
	{
		hasAlphaChars = false;
		std::cout << "please enter an integer: ";
		getline(std::cin, inputString);
		for (unsigned int count = 0; count < (inputString.length()); count++)
		if (isdigit(inputString[count]) == 0)
		{
			hasAlphaChars = true;
		}
	}
	number = stoi(inputString);
	return number;
}


#endif