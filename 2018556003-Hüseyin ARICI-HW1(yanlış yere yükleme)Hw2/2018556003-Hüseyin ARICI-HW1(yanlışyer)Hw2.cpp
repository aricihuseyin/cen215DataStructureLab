#include <stdio.h>
#include <time.h>

void bubbleSort(int array[], int size) {
  int step,i;
  for (step=0 ; step < size - 1; ++step) {
    for (i = 0; i < size - step - 1; ++i) {

      if (array[i] > array[i + 1]) {

        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}

void merge(int array[], int left, int middle, int right) {

  int lsize = middle - left + 1;
  int rsize = right - middle;

  int Left[lsize];
  int Right[rsize];
  int i, j;


  for (i = 0; i < lsize; ++i)
  {
    Left[i] = array[left + i];
  }
    
  for (j = 0; j < rsize; ++j)
  {
    Right[j] = array[middle + 1 + j];
  }
  
  i = 0;
  j = 0;
  int org = left;

  while (i < lsize && j < rsize) {
    if (Left[i] <= Right[j]) {
      array[org] = Left[i];
      i++;
    }
    else {
      array[org] = Right[j];
      j++;
    }
    org++;
  }

  while (i < lsize) {
    array[org] = Left[i];
    i++;
    org++;
  }

  while (j < rsize) {
    array[org] = Right[j];
    j++;
    org++;
  }
}

void mergeSort(int array[], int left, int right) {
  if (left < right) {

    int middle = left + (right - left) / 2;

    mergeSort(array, left, middle);
    mergeSort(array, middle + 1, right);

    merge(array, left, middle, right);
  }
}

void insertionSort(int array[], int size) {
  int step;
  for (step = 1; step < size; step++) {
    int key = array[step];
    int j = step - 1;


    while (key < array[j] && j >= 0) {
      array[j + 1] = array[j];
      --j;
    }
    array[j + 1] = key;
  }
}

void selectionSort(int array[], int size) {
  int step,i;
  for (step = 0; step < size - 1; step++) {
    int min_idx = step;
    for (i = step + 1; i < size; i++) {

      if (array[i] < array[min_idx])
        min_idx = i;
    }
  }
}
void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void quickSort(int number[],int first,int last){
   int i, j, pivot, temp;

   if(first<last){
      pivot=first;
      i=first;
      j=last;

      while(i<j){
         while(number[i]<=number[pivot]&&i<last)
            i++;
         while(number[j]>number[pivot])
            j--;
         if(i<j){
            temp=number[i];
            number[i]=number[j];
            number[j]=temp;
         }
      }

      temp=number[pivot];
      number[pivot]=number[j];
      number[j]=temp;
      quickSort(number,first,j-1);
      quickSort(number,j+1,last);

   }
}
void heapify(int array[], int size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
  
    if (left < size && array[left] > array[largest])
      largest = left;
  
    if (right < size && array[right] > array[largest])
      largest = right;
  
    if (largest != i) {
      swap(&array[i], &array[largest]);
      heapify(array, size, largest);
    }
  }
  
  void heapSort(int array[], int size) {
    for (int i = size / 2 - 1; i >= 0; i--)
      heapify(array, size, i);
  
    for (int i = size - 1; i >= 0; i--) {
      swap(&array[0], &array[i]);
  
      heapify(array, i, 0);
    }
  }

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}

int main(int argc, char const *argv[])
{
  int num[] = { 2,0,1,8,5,5,6,0,0,3 };
  char name[] = "HUSEYIN ARICI";

  clock_t start, end;
    double cpu_time_used;
     
  int size = sizeof(num) / sizeof(num[0]);
start = clock();
  bubbleSort(num, size);
    printf("Array in Ascending Order by Bubble Sort:\n");
  printArray(num, size);
  end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort time= %f\n",cpu_time_used);
  
  start = clock();
  insertionSort(num, size);
    printf("Array in Ascending Order by InsertionSort:\n");
  printArray(num, size);
  end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("insertion Sort time= %f\n",cpu_time_used);
  
  start = clock();
  selectionSort(num, size);
  printf("Array in Ascending Order by SelectionSort:\n");
  printArray(num, size);
  end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("selection Sort time= %f\n",cpu_time_used);
  
  start = clock();
  mergeSort(num, 0, size - 1);
  printf("Array in Ascending Order by mergesort:\n");
  printArray(num, size);
  end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("merge Sort time= %f\n",cpu_time_used);
    
    start = clock();
  quickSort(num, 0, size - 1);
    printf("Array in Ascending Order by quickSort:\n");
  printArray(num, size);
  end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("quick Sort time= %f\n",cpu_time_used);
    
    start = clock();
  heapSort(num, size);
  printf("Array in Ascending Order by heapSort:\n");
  printArray(num, size);
  end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("heap Sort time= %f\n",cpu_time_used);

  return 0;
}
