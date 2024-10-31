// Melody Gatan
// (CECS325-02) 
// Prog 4 - Sorting Contest (thread)
// Due 10/31/2024
//
// I certify that this program is my own original work. I did not copy any part of this program from
// any other source. I further certify that I typed each and every line of code in this program.

// compile line: g++ mysort.cpp -o mysort -pthread

#include <iostream>
#include <fstream>
#include <thread>
#include <mutex>
using namespace std;

mutex mtx; // Mutex for protecting the global swap count
unsigned long long globalSwapCount = 0; // Global variable for all swaps

void bubble(int A[], int size, const string& processName, unsigned long long& processSwapCount) {
  for (int i = 0; i < size-1; i++) {
    for (int j = 0; j < size-i-1; j++) {
      if (A[j] > A[j+1]) {
        // swap(A[j], A[j+1]);
        int temp = A[j];
        A[j] = A[j+1];
        A[j+1] = temp;
        processSwapCount++; // count each swap for this segment
      }
    }
  }

  // Lock the mutex
  mtx.lock();
  globalSwapCount += processSwapCount;
  cout << processName<< " swap count: " << processSwapCount << endl;
  // Unlock the mutex
  mtx.unlock();
}

void merge(int A[], int start, int mid, int end) {
  // Sizes of two segments
  int n1 = mid - start + 1;
  int n2 = end - mid;

  // Temporary arrays to hold each segment
  int* left = new int[n1];
  int* right = new int[n2];

  // Copy data to temp arrays left[] and right[]
  for (int i = 0; i < n1; i++) {
    left[i] = A[start + i];
  }
  for (int i = 0; i < n2; i++) {
    right[i] = A[mid + 1 + i];
  }
  // Merge the two segments back into A[start..end]
  int i = 0, j = 0, k = start;
  while (i < n1 && j < n2) {
    if (left[i] <= right[j]) {
      A[k++] = left[i++];
    } else {
      A[k++] = right[j++];
    }
  }
  // Copy any remaining elements of left[], if any
  while (i < n1) {
    A[k++] = left[i++];
  }
  // Copy any remaining elements of right[], if any
  while (j < n2) {
      A[k++] = right[j++];
  }
  // Free dynamically allocated memory
  delete[] left;
  delete[] right;
}

int main(int argc, char *argv[])
{
  if (argc < 3 || argc > 4)
  {
    cout << "Please enter 2 or 3 parameters: Input FileName, Output FileName, and optionally -test\n";
    cout << "Example: $ mysort numbers.dat mysort.out -test\n";
    exit(EXIT_SUCCESS);
  }
 
  bool testCheck = (argc == 4 && string(argv[3]) == "-test");
  int expectedNums = testCheck ? 10000:  1000000;
  int* numbers = new int[expectedNums];
  size_t size = 0; 
  
  ifstream fileIn(argv[1]);
  string num;
  while (getline(fileIn, num, '\n'))
  {
    if (size < expectedNums)
    {
      numbers[size++] = stoi(num);
    }
  }
  fileIn.close();

  // cout << "Starting Array bubble sort with " << size << " items\n";

  // Define the number of threads (16) and calculate segment size
  int segmentSize = size / 16;
  thread threads[16];
  unsigned long long swapCounts[16] = {0}; // Swap counts for each process

  // Launch 16 threads, each sorting a specific segment
  for (int i = 0; i < 16; ++i) {
    int start = i * segmentSize;                   // Start of segment

    // Create a thread for each segment, passing the segment boundaries
    threads[i] = thread(bubble, numbers + start, segmentSize, "Process " + to_string(i + 1), ref(swapCounts[i]));
  }

  // join all threads to the main thread
  for (int i = 0; i < 16; ++i) {
    threads[i].join();
  }

  // Perform iterative merging of sorted segments
  int step = segmentSize;  // Initial step size is one segment
  while (step < size) {
    for (int i = 0; i < size; i += 2 * step) {
      int mid = min(i + step - 1, static_cast<int>(size) - 1);       // End of first segment
      int end = min(i + 2 * step - 1, static_cast<int>(size) - 1);   // End of second segment

      // Merge the two segments defined by start (i), mid, and end
      merge(numbers, i, mid, end);
    }
    step *= 2; // Double the step to merge progressively larger sections
  }

  // cout << "Ending bubble sort\n";

  ofstream fout(argv[2]);
  for (size_t i = 0; i < size; ++i)
  {
    fout << numbers[i] << '\n';
  }
  fout.close();

  cout << "Total Swaps:" << globalSwapCount << endl;
  
  delete[] numbers;
  return 0;
}