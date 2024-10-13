#include <iostream>
#include <fstream>
using namespace std;

void bubble(int A[], int size)
{
  bool swapped;
  for (int i = 0; i < size - 1; i++) {
    swapped = false;
    for (int j = 0; j < size-i-1; j++) {
      if (A[j] > A[j+1]) {
        swap(A[j], A[j+1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}


int main(int argc, char *argv[])
{
  std::ifstream fileIn(argv[1]);

  int numbers[1000000];
  size_t size = 0;
  string num;
  while (getline(fileIn, num, '\n'))
  {
    if (size < 1000000)
    {
      numbers[size++] = std::stoi(num);
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

// const int SIZE = 10;
// int a[SIZE] = {1,2,10,4,5,9,7,3,2,1};
// bubble(a,SIZE);
// // int b[5] = {59,27,100};
 // print(a,SIZE);


// void print(int array[], int n)
// {
//   for (int i =0; i < n; i++)
//     cout<<array[i]<<", ";
//   cout<< endl;
// }