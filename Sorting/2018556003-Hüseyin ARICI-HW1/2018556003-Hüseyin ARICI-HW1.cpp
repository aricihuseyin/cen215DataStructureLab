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
	char name[] = "Hüseyin ARICI";

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
	return 0;
}
