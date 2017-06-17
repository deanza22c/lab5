#include<iostream>
#include<string>
#include<fstream>
#include"Globals.h"

using namespace std;

void recursiveCP(int *a, int n, ofstream &file, int called=0);
void insertionSort(int *a, int n, ofstream &file);
void RISA(int *a, int n, ofstream &file, int value, int hole, int i = 0);
int RISB(int *a, int n, ofstream &file, int value, int hole);


/*
//RECURSIVE INSERTION SORT:
//takes an array and the number of element in the array
void insertionSort(int *a, int n, ofstream &file){
int value;
int hole;
for (int i = 1; i < n; i++){
value = a[i];
hole = i;
recursiveCP(a, n, file);
while (hole > 0 && a[hole - 1] > value){
a[hole] = a[hole - 1];
hole = hole - 1;
recursiveCP(a, n, file);
}
a[hole] = value;
}
}
*/

//RECURSIVE INSERTION SORT:
//takes an array and the number of element in the array
void insertionSort(int *a, int n, ofstream &file){
	int value=0;
	int hole=0;
	RISA(a, n, file, value, hole);
	recursiveCP(a, n, file);
}


//RISA - recursive insertion sort part A 
//moves the whole throught the array
void RISA(int *a, int n, ofstream &file, int value, int hole, int i){
		value = a[i];
		hole = i;
		recursiveCP(a, n, file);
		hole = RISB(a, n, file, value, hole);
		a[hole] = value;
		i++;
		if (i != n){
			RISA(a, n, file, value, hole, i);
		}
}

//RISB  - recursive insertion sort part B 
//places the correct value into the whole
int RISB(int *a, int n, ofstream &file, int value, int hole){
	if (hole > 0 && a[hole - 1] > value){
		a[hole] = a[hole - 1];
		hole = hole - 1;
		recursiveCP(a, n, file);
		hole = RISB(a, n, file, value, hole);
	}
	return hole;
}

//recursiveCP is short for "recursive cout and print"
//this will be used to print sorting functions at each step to screen and the file
void recursiveCP(int *a, int n, ofstream &file, int called){
	cout << a[called] << " ";
	file << a[called] << " ";
	called++;
	//base case for void print function
	if (called == n){
		cout << endl;
		file << endl;
	}
	//if base case not triggered increment called and call recursiveCP again
	else {
		recursiveCP(a, n, file, called);
	}
}

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

	ofstream myfile;
	myfile.open("EC_Lab.txt");

	insertionSort(arrPtr, size, myfile);

	myfile.close();


	cin.get();
	return 0;
}


