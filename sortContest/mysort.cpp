#include <iostream>
using namespace std;

void bubble(int A[], int size)
{
  int n = size;
  bool swapped;
  for (int i = 0; i < n - 1; i++) {
    swapped = false;
    for (int j = 0; j < n-i-1; j++) {
      if (A[j] > A[j+1]) {
        swap(A[j], A[j+1]);
        swapped = true;
      }
    }
    if (!swapped)
      break;
  }
}

void print(int array[], int n)
{
  for (int i =0; i < n; i++)
    cout<<array[i]<<", ";
  cout<< endl;
}


int main()
{
  const int SIZE = 10;
  int a[SIZE] = {1,2,10,4,5,9,7,3,2,1};
  bubble(a,SIZE);
  // int b[5] = {59,27,100};
  print(a,SIZE);

  return 0;
}