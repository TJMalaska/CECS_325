// Name: Theodore Malaska
// Class (CECS 325-01)
// Project Name (Prog 3 – Sorting Contest)
// Due Date 10/14/24
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.
//
#include <iostream>
#include <fstream>

void bubble( int A[], int size)
{
	int spaces_left = size;
	std::cout << "Starting Array bubble sort with " << size << " items\n";
	for( int I = 0; I < size ; I++)
	{
		for(int II = 0; II < spaces_left - 1; II++)
		{
			if (A[II] > A[II + 1])
			{
				int temp = A[II];
				A[II] = A[II + 1];
				A[II + 1] = temp;
			}
			spaces_left --;
		}
	}
	std::cout << "Ending bubble sort";
	return;
}

int main(int argc, char * argv[]) // argument cout, argument vector
{
	if (argc != 3)//includes "generate"
	{
		std::cout << "Please enter 2 parameters:\n";
		std::cout << "	Parameter 1: file to read\n";
		std::cout << "	Parameter 2: file to write\n";
		std::cout << "Example: $ mysort numbers.dat mysort.out\n";
		exit(EXIT_SUCCESS);
	}
	const int MAX_SIZE = 1000000;
	int numbers[MAX_SIZE];
	std::ofstream fout;
	std::ifstream fin;
	int n;
	int count = 0;

	fin.open(argv[1]);
	fout.open(argv[2], std::ios::out | std::ios::trunc); // ::out specifies output file, trunc writes over
	
	while (fin >> n )
	{
		numbers[count] = n;
		count++;
	}
	bubble(numbers, count);
	
	for ( int I = 0; I < count; I++)
	{
		fout << numbers[I] << std::endl;
	}
	fin.close();
	fout.close();

	return 0;

	
}

