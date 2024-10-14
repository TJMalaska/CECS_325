// Name: Theodore Malaska
// Class (CECS 325-01)
// Project Name (Prog 3 – Sorting Contest)
// Due Date 10/14/24
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.include <iostream>
#include <fstream>
#include <iostream>
int main(int argc, char * argv[]) // argument cout, argument vector
{

	if (argc != 4)//includes "generate"
	{
		std::cout << "Please enter 3 parameters:\n";
		std::cout << "	Parameter 1: total count of numbers you want.\n";
		std::cout << "	Parameter 2: min value\n";
		std::cout << "	Parameter 3: max value.\n";
		std::cout << "Example: $ generate 10000000 100000 999999\n";
		exit(EXIT_SUCCESS);
	}
	
	for (int i =0; i<argc; i++)
	{
		std::cout << "arcv[" << i << "]:" << argv[i] << std::endl;
	}
	int COUNT = std::stoi(argv[1]);
	int MIN = std::stoi(argv[2]);
	int MAX = std::stoi(argv[3]);

	std::ofstream fout;
	fout.open("numbers.dat", std::ios::out );
	for (int i = 0; i < COUNT; i++)
	{
		fout << (rand() % ( MAX- MIN + 1) + MIN) << std::endl;
	}
	fout.close();
	return 0;
}
