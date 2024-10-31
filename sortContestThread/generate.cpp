// Melody Gatan
// (CECS325-02) 
// Prog 4 - Sorting Contest (thread)
// Due 10/31/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main(int argc, char *argv[])
{
  if (argc != 4)
  {
    cout<<"Please enter 3 parameters: \n";
    cout<<"   Parameter 1: total count of numbers you want \n";
    cout<<"   Parameter2: min value. \n";
    cout<<"   Parameter 3: max value. \n";
    cout<<"Example: $ generate 10000000  100000 999999\n";
    exit(EXIT_SUCCESS);
  }

  //  cout << "Generating " << argv[1] << " random numbers\n";

  // for (int i=0; i<argc; i++)
  // {
  //   cout<< "argv["<<i<<"]:"<<argv[i]<<endl;
  // }
  int COUNT = stoi(argv[1]);
  int MIN = stoi(argv[2]);
  int MAX = stoi(argv[3]);

  srand(time(0));

  int* numbers = new int[COUNT];

  // Generate random numbers and fill the array
  for (int i = 0; i < COUNT; i++)
  {
    numbers[i] = rand() % (MAX - MIN + 1) + MIN;
  }

  ofstream fout;
  fout.open("numbers.dat", ios::out);
  for (int i = 0; i < COUNT; i++)
  {
    fout << numbers[i] << endl;
  }
  fout.close();

  delete[] numbers;
  return 0;
}

