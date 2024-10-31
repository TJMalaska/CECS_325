// Name: Theodore Malaska
// Class (CECS 325-01)
// Project Name (Prog 4 – Sorting Contest thread)
// Due Date 10/30:/24
//
// I certify that this program is my own original work. I did not copy any part
// of this program from any other source. I further certify that I typed each
// and every line of code in this program.include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include <iostream>
#include <mutex>
#include <thread>

long long num_swaps; // keeps track of total swaps
std::mutex mtx;


void bubble(int A[], int size, int process_number) {
    int swaps = 0;
	int spaces_left = size;
    // std::cout << "Starting Array bubble sort with " << size << " items\n";
    for (int I = 0; I < size; I++)
    {

        for (int II = 0; II < spaces_left - 1; II++)
        {
            if (A[II] > A[II + 1]) 
            {
                int temp = A[II];
                A[II] = A[II + 1];
                A[II + 1] = temp;
                swaps++;
            }
        }
        spaces_left--;
    }
    mtx.lock();
    std::cout << "Process " << process_number << " swap count: " << swaps << " \n";
    num_swaps += swaps;
    mtx.unlock();
    return;
}

void merge_arrays(int A1[], int A2[], int sizeA, int sizeB) //merges two ajacent arrays
{
    int newindex = 0;
    int index1 = 0;
    int index2 = 0;
    int* new_array =  new int[sizeA + sizeB];
    while (index1 < sizeA and index2 < sizeB)
    {
        int value1 = A1[index1]; 
        int value2 = A2[index2]; 

        if (value2 > value1)
        {
            new_array[newindex] = value1;
            newindex++;
            index1++;
        }else if (value2 < value1)
        {
            new_array[newindex] = value2;
            newindex++;
            index2++;
        }else
        {
            new_array[newindex] = value2;
            newindex++; 
            new_array[newindex] = value1;
            newindex++;
            index2++;
            index1++;
        }

    }
    if(index1 < sizeA)
    {
        while(index1 < sizeA)
        {
            new_array[newindex] = A1[index1];
            newindex++;
            index1++;
        }
    }
    if(index2< sizeB)
    {
        while(index2 < sizeB)
        {
            new_array[newindex] = A2[index2];
            newindex++;
            index2++;
        }
    }
    for(int I = 0; I < sizeB + sizeA; I++){
        A1[I] = new_array[I];
    }
    delete[] new_array;

}

int main(int argc, char *argv[]) // argument cout, argument vector
{
    if (!(argc == 3 or argc == 4)) // includes "generate"
    {
        std::cout << "Please enter 2 or 3 parameters:\n";
        std::cout << "	Parameter 1: file to read\n";
        std::cout << "	Parameter 2: file to write\n";
        std::cout << "	Parameter 3: '-test' if test mode\n";
        std::cout << "Example: $ mysort numbers.dat mysort.out\n";
        exit(EXIT_SUCCESS);
    }
    int array_size;
    if (argc == 4 and strcmp(argv[3], "-test") == 0) 
    {
        array_size = 10000;
    } else 
    {
    array_size = 1000000;
    }
    int increment_size = array_size / 16;
    int *numbers = new int[array_size]; 
    //int numbers[10000];
    std::ofstream fout;
    std::ifstream fin;
    int n;
    int count = 0;
    
    fin.open(argv[1]);
    fout.open(
    argv[2],
    std::ios::out |
    std::ios::trunc); // ::out specifies output file, trunc writes over

    while (fin >> n)
    {
        numbers[count] = n;
        count++;
    }
    std::thread thread1(bubble, numbers, increment_size, 1); 
    std::thread thread2(bubble, numbers + increment_size * 1, increment_size, 2); 
    std::thread thread3(bubble, numbers + increment_size * 2 , increment_size, 3);
    std::thread thread4(bubble, numbers + increment_size * 3, increment_size, 4);
    std::thread thread5(bubble, numbers + increment_size * 4, increment_size, 5);
    std::thread thread6(bubble, numbers + increment_size * 5, increment_size, 6);
    std::thread thread7(bubble, numbers + increment_size * 6, increment_size, 7);
    std::thread thread8(bubble, numbers + increment_size * 7, increment_size, 8);
    std::thread thread9(bubble, numbers + increment_size * 8, increment_size, 9);
    std::thread thread10(bubble, numbers + increment_size * 9, increment_size, 10);
    std::thread thread11(bubble, numbers + increment_size * 10, increment_size, 11);
    std::thread thread12(bubble, numbers + increment_size * 11, increment_size, 12);
    std::thread thread13(bubble, numbers + increment_size * 12, increment_size, 13);
    std::thread thread14(bubble, numbers + increment_size * 13, increment_size, 14);
    std::thread thread15(bubble, numbers + increment_size * 14 , increment_size, 15);
    std::thread thread16(bubble, numbers + increment_size * 15, increment_size, 16);

    thread1.join(); 
    thread2.join();
    thread3.join();
    thread4.join();
    thread5.join();
    thread6.join();
    thread7.join();
    thread8.join();
    thread9.join();
    thread10.join();
    thread11.join();
    thread12.join();
    thread13.join();
    thread14.join();
    thread15.join();
    thread16.join();

    std::cout << "Total swaps: " << num_swaps << std::endl;
   

    merge_arrays(numbers, numbers + increment_size * 1, increment_size, increment_size);  
    merge_arrays(numbers + increment_size * 2, numbers + increment_size * 3, increment_size, increment_size);     
    merge_arrays(numbers + increment_size * 4, numbers + increment_size * 5, increment_size, increment_size); 
    merge_arrays(numbers + increment_size * 6, numbers + increment_size * 7, increment_size, increment_size); 
    merge_arrays(numbers + increment_size * 8, numbers + increment_size * 9, increment_size, increment_size); 
    merge_arrays(numbers + increment_size * 10, numbers + increment_size * 11, increment_size, increment_size); 
    merge_arrays(numbers + increment_size * 12, numbers + increment_size * 13, increment_size, increment_size); 
    merge_arrays(numbers + increment_size * 14, numbers + increment_size * 15, increment_size, increment_size); 


    merge_arrays(numbers, numbers + increment_size * 2, increment_size* 2, increment_size *2);  
    merge_arrays(numbers + increment_size * 4, numbers + increment_size * 6, increment_size * 2, increment_size * 2); 
    merge_arrays(numbers + increment_size * 8, numbers + increment_size * 10, increment_size * 2, increment_size * 2); 
    merge_arrays(numbers + increment_size * 12, numbers + increment_size * 14, increment_size * 2, increment_size * 2); 

    merge_arrays(numbers, numbers + increment_size * 4, increment_size* 4, increment_size * 4); 
    merge_arrays(numbers + increment_size * 8, numbers + increment_size * 12, increment_size * 4, increment_size * 4); 

    merge_arrays(numbers, numbers + increment_size * 8, increment_size* 8, increment_size * 8); 

    // merge  be done
    //fout << sizeof(numbers + increment_size * 15);
    for (int I = 0; I < count; I++) {
        fout << numbers[I] << std::endl;
    }
    fin.close();
    fout.close();
    delete[] numbers;
    return 0;
}
