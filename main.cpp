/*
6/16/2017 - Manish Goel - Lab 5 EC - Recursive Sorting
Partners: Alexander McNulty, Clifford Smith

this program sorts and array of intergers given by the user with no more than 32 integers in the arary
the program will sort the array 3 times using Merge Sort, Insertion Sort, and Quick Sort
during each sorting algorithem the array being sorted will be printed to screen  and a txt document

RECURSIVE FUNCTIONS - all sorting functions for this program can be found above main() in main.cpp
INPUT HANDLING - will be found in Globals.h
*/


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


/*
void MergeSort();
//L = the left array which was split from the main array
//R = the right array which was split from the main array
//A = the main array
void Merge(int *L, int *R, int *A);
//SubMerge, does the job of an interative merge, recursively
//those submerge must hold the values for I and J
//this variableswhich hold the index of the next value which must be merged
void SubMerge(int *L, int *R, int *A, int i, int j);


void merge(int *L, int *R, int *A){
	int i, j, nL, nR;
	nL = 
	if
}



void MergeSort(){

}
*/


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
//Partition A will find the pivot point, then swap with pIndex and pivot
//after all lesser values have been placed behind pindex
int PartitionA(int *A, int start, int end, ofstream &file, int size){
	int pivot = A[end];
	int pIndex = start;
	int temp;
	int i = start;
	pIndex = PartitionB(A, start, end, file, pivot, pIndex, i, size);
	//cout << "A";
	recursiveCP(A, size, file);
	temp = A[pIndex];
	A[pIndex] = A[end];
	A[end] = temp;
	//cout << "B";
	recursiveCP(A, size, file);

	return pIndex;
}
//Partition B is responsible for interating through the partitioned array
//When B makes a swap it is placing all values that are less than the pivot behind the pIndex
//the pindex and the point will then be swaped in partition A after the base case is called.
int PartitionB(int *A, int start, int end, ofstream &file, int pivot, int pIndex, int i, int size){
	if (i < end){
		int temp;
		if (A[i] <= pivot)
		{
			//cout << "C";
			recursiveCP(A, size, file);
			temp = A[i];
			A[i] = A[pIndex];
			A[pIndex] = temp;
			pIndex++;
			//cout << "D";
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
	cout << endl << "excellent! time to sort" << endl << endl;
	cout << "results will print to the terminal..." <<  endl;
	cout << "results will print to 'EC_Lab.txt' in current dir..." << endl << endl;
	cout << "press 'enter' to continue";
	cin.get();

	//open a file
	ofstream myfile;
	myfile.open("EC_Lab.txt");

	//print the document header to file
	myfile << "6/16/2017 - Manish Goel - Lab 5 EC - Recursive Sorting" << endl;
	myfile << endl << "Partners: Alexander McNulty, Clifford Smith" << endl;
	myfile << "this program sorts and array of intergers given by the user with no more than 32 integers in the arary" << endl;
	myfile << "the program will sort the array 3 times using Merge Sort, Insertion Sort, and Quick Sort" << endl;
	myfile << endl << "during each sorting algorithem the array being sorted will be printed to screen  and a txt document" << endl;
	myfile << "RECURSIVE FUNCTIONS - all sorting functions for this program can be found above main() in main.cpp" << endl;
	myfile << "INPUT HANDLING - will be found in Globals.h" << endl << endl;

	//CALL INSERTION SORT
	cout << endl << "printing - INSERTION SORT" << endl;
	myfile << endl << "printing - INSERTION SORT" << endl;
	insertionSort(A, size, myfile);

	//CALL QUICK SORT
	cout << endl << "printing - QUICK SORT" << endl;
	myfile << endl << "printing - QUICK SORT" << endl;
	QuickSort(B, 0, size-1, myfile, size);

	//CALL MERGE SORT
	//cout << endl << "printing - MERGE SORT" << endl;
	//myfile << endl << "printing - MERGE SORT" << endl;
	cout << endl << "MERGE SORT WAS NOT COMPLETED!! -  CHECK MAIN.CPP TO SEE UNFINISHED WORK" << endl;
	myfile << endl << "MERGE SORT WAS NOT COMPLETED!! -  CHECK MAIN.CPP TO SEE UNFINISHED WORK" << endl;


	myfile.close();

	cout << endl << "press 'enter' to exit" << endl;
	cin.get();
	return 0;
}


