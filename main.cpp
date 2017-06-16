#include<iostream>
#include<string>
#include"Globals.h"

using namespace std;

//array max size as specified by docs

int main()
{	
	//acquire the size of the array from the user 
	//then create a dynamically sized array in the heap
	cout << "Yo, enter an array size (max size is 32): ";
	int size = getDoubleDigitMenuInput("32");
	int *arrPtr;
	arrPtr = new int[size];

	//smooth - jazzy - UX line to make users feel reassured
	cout << "\nThanks, time to populate the array.\n\n";

	//populate the array to size specified
	int number;
	for (int i = 0; i < size; i++){
		cout << "enter in an integer for slot " << i+1 << ": ";
		number = getIntegerInput();
		arrPtr[i] = number;
	}

	for (int i = 0; i < size; i++){
		cout << arrPtr[i];
	}
	
	cin.get();
	return 0;
}


