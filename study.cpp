#include <iostream>
using namespace std;

void printArray (int n[], int size)
{
  for(int i=0; i <size; i++)
  cout << n[i];
}

int main()
{
  int nums[10] = {1,2,3,4,5,6,7,8,9,10};
  printArray(nums,5);
}

