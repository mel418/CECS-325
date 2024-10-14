// Melody Gatan
// (CECS325-02) 
// Prog 3 - Sort Contest
// Due 10/15/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

#include <iostream>
#include <fstream>
using namespace std;

void bubble(int A[], int size)
{
  for (int i = 1; i < size; i++) {
    for (int j = 0; j < size-1; j++) {
      if (A[j] > A[j+1]) {
        // swap(A[j], A[j+1]);
        int temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
      }
    }
  }
}


int main(int argc, char *argv[])
{
  if (argc != 3)
  {
    cout<<"Please enter 2 parameters: Input FileName and Output FileName\n";
    cout<<"Example: $ mysort numbers.dat mysort.out\n";
    exit(EXIT_SUCCESS);
  }

  std::ifstream fileIn(argv[1]);
  int numbers[1000000];
  size_t size = 0; //keep track of the number of elements read
  string num;
  while (getline(fileIn, num, '\n'))
  {
    if (size < 1000000)
    {
      numbers[size++] = stoi(num);
    }
  }

  cout << "Starting Array bubble sort with " << size << " items\n";

  bubble(numbers, size);

  cout << "Ending bubble sort\n";

  ofstream fout(argv[2]);
  for (size_t i = 0; i < size; ++i)
  {
    fout << numbers[i] << '\n';
  }
  fout.close();

  return 0;
}