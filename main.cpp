#include<iostream>
#include<string>
#include<fstream>
#include"Globals.h"

using namespace std;

//declaration of the recursive printing function
void recursiveCP(int *a, int n, ofstream &file, int called=0);

//declaration for recrusive insertion sort
void insertionSort(int *a, int n, ofstream &file);
void RISA(int *a, int n, ofstream &file, int value, int hole, int i = 0);
int RISB(int *a, int n, ofstream &file, int value, int hole);

//declaration for the recursive quick sort
void QuickSort(int *A, int start, int end, ofstream &file, int size);
int PartitionA(int *A, int start, int end, ofstream &file, int size);
int PartitionB(int *A, int start, int end, ofstream &file, int pivot, int pIndex, int i, int size);




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




//RECURSIVE INSERTION SORT:
//takes an array and the number of element in the array
void QuickSort(int *A, int start, int end, ofstream &file, int size){
	int pIndex;
	if (start < end) {
		pIndex = PartitionA(A, start, end, file, size);
		QuickSort(A, start, pIndex - 1, file, size);
		QuickSort(A, pIndex + 1, end, file, size);

	}
}
int PartitionA(int *A, int start, int end, ofstream &file, int size){
	int pivot = A[end];
	int pIndex = start;
	int temp;
	int i = start;
	pIndex = PartitionB(A, start, end, file, pivot, pIndex, i, size);
	cout << "A";
	recursiveCP(A, size, file);
	temp = A[pIndex];
	A[pIndex] = A[end];
	A[end] = temp;
	cout << "B";
	recursiveCP(A, size, file);

	return pIndex;
}
int PartitionB(int *A, int start, int end, ofstream &file, int pivot, int pIndex, int i, int size){
	if (i < end){
		int temp;
		if (A[i] <= pivot)
		{
			cout << "C";
			recursiveCP(A, size, file);
			temp = A[i];
			A[i] = A[pIndex];
			A[pIndex] = temp;
			pIndex++;
			cout << "D";
			recursiveCP(A, size, file);
		}
		i++;
		pIndex = PartitionB(A, start, end, file, pivot, pIndex, i, size); 
	}
	return pIndex;
}





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



int main()
{	
	//acquire the size of the array from the user 
	//then create a dynamically sized array in the heap
	cout << "Yo, enter an array size (max size is 32): ";
	int size = getDoubleDigitMenuInput("32");
	int *A, *B, *C;
	A = new int[size];
	B = new int[size];
	C = new int[size];

	//smooth - jazzy - UX line to make users feel reassured
	cout << "\nThanks, time to populate the array.\n\n";

	//populate the array to size specified
	int number;
	for (int i = 0; i < size; i++){
		cout << "enter in an integer for slot " << i+1 << ": ";
		number = getIntegerInput();
		A[i] = number;
		B[i] = number;
		C[i] = number;
	}

	ofstream myfile;
	myfile.open("EC_Lab.txt");

	insertionSort(A, size, myfile);

	cout << "hihihi" << endl << endl;
	QuickSort(B, 0, size-1, myfile, size);

	myfile.close();


	cin.get();
	return 0;
}


