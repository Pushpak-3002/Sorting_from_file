#include<stdio.h>
int partition(int*,int,int);
void insertion(int *arr,int n)
{
    FILE *fp=NULL;
    fp=fopen("filene.txt","w");
    int i=0, key, j=0;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
 
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    printf("\n Insertion Sort :\t");
    for (i = 0; i < n; i++)
    {
        printf("%d ",arr[i]);
    }
    printf("\n");
}

void bubble_sort(int *arr, int n)
{
    int c, d, swap;
    FILE *fp=NULL;
    fp=fopen("fleb.txt","w");
    for (c = 0; c < n - 1; c++)
    {
        for (d = 0; d < n - c - 1; d++)
        {
            if (arr[d] > arr[d + 1])
            {
                swap = arr[d];
                arr[d] = arr[d + 1];
                arr[d + 1] = swap;
            }
        }
    }
    printf("\n Bubble Sort :\t");
    for (int c = 0; c < n; c++)
    {
        printf("%d ",arr[c]);
    }
    printf("\n");
}

void swap(int* a, int* b)
{

	int temp = *a;

	*a = *b;

	*b = temp;
}

void heapify(int *arr, int N, int i)
{
	int largest = i;

	int left = 2 * i + 1;

	int right = 2 * i + 2;

	if (left < N && arr[left] > arr[largest])

		largest = left;

	if (right < N && arr[right] > arr[largest])

		largest = right;

	if (largest != i) {

		swap(&arr[i], &arr[largest]);

		heapify(arr, N, largest);
	}
}

void heapSort(int *arr, int N)
{

	for (int i = N / 2 - 1; i >= 0; i--)
    {

		heapify(arr, N, i);
    }
	for (int i = N - 1; i >= 0; i--) 
    {

		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

void printArray(int *arr, int N)
{
	for (int i = 0; i < N; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void print(int*A,int n)
{
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
void Selection_sort(int*A,int n)
{
    int i,j,min_index,temp;
    for(i=0;i<n-1;i++)
    {
        min_index=i;
        for(j=i+1;j<n;j++)
        {
            if(A[j]<A[min_index])
            {
                min_index=j;
            }
        }
        temp=A[i];
        A[i]=A[min_index];
        A[min_index]=temp;
    }
}

void merge(int arr[], int p, int q, int r) {

  int n1 = q - p + 1;
  int n2 = r - q;

  int L[n1], M[n2];

  for (int i = 0; i < n1; i++)
    L[i] = arr[p + i];
  for (int j = 0; j < n2; j++)
    M[j] = arr[q + 1 + j];

  
  int i, j, k;
  i = 0;
  j = 0;
  k = p;

 
  while (i < n1 && j < n2) {
    if (L[i] <= M[j]) {
      arr[k] = L[i];
      i++;
    } else {
      arr[k] = M[j];
      j++;
    }
    k++;
  }

  
  while (i < n1) {
    arr[k] = L[i];
    i++;
    k++;
  }

  while (j < n2) {
    arr[k] = M[j];
    j++;
    k++;
  }
}

void mergeSort(int arr[], int l, int r) {
  if (l < r) {

   
    int m = l + (r - l) / 2;

    mergeSort(arr, l, m);
    mergeSort(arr, m + 1, r);

    merge(arr, l, m, r);
  }
}

void printArr(int arr[], int size) 
{
  for (int i = 0; i < size; i++)
    printf("%d ", arr[i]);
  printf("\n");
}



void print2(int*A,int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}

/*Quick Sort*/

void Quick_sort(int* A,int low,int high)
{
    int partition_Index;
    if(low<high)
    {
        partition_Index=partition(A,low,high);
        Quick_sort(A,low,partition_Index-1);
        Quick_sort(A,partition_Index+1,high);
    }
}
int partition(int* A,int low,int high)
{
    int i,j,pivot,temp;
    i=low+1;
    j=high;
    pivot=low;
    do
    {
        while(A[i]<=A[pivot])
        {
            i++;
        }
        while(A[j]>A[pivot])
        {
            j--;
        }
        if(i<j)
        {
            temp=A[i];
            A[i]=A[j];
            A[j]=temp;
        }

    }while(i<j);

    temp=A[j];
    A[j]=A[pivot];
    A[pivot]=temp;
    
    return j;
}

int shell(int A[], int n)  
{  
    
    for (int interval = n/2; interval > 0; interval /= 2)  
    {  
        for (int i = interval; i < n; i++)  
        {  
            int temp = A[i];  
            int j;        
            for (j = i; j >= interval && A[j - interval] > temp; j -= interval)  
                A[j] = A[j - interval];  
              
            A[j] = temp;  
        }  
    }  
}  
void printrr(int A[], int n) 
{  
    int i;  
    for (i = 0; i < n; i++)
    {
       printf("%d ", A[i]);   
    }  
    printf("\n");  
}

void countingSort(int array[], int size) {
  int *output=(int*)malloc((size)*(sizeof(int)));

  // Find the largest element of the array
  int max = array[0];
  for (int i = 1; i < size; i++) {
    if (array[i] > max)
      max = array[i];
  }

  int *count=(int*)malloc((max+1)*(sizeof(int)));

  // Initialize count array with zero
  for (int i = 0; i <= max; ++i) {
    count[i] = 0;
  }

  // Store the count of each element
  for (int i = 0; i < size; i++) {
    count[array[i]]++;
  }

  // Store the cummulative count of each array
  for (int i = 1; i <= max; i++) {
    count[i] += count[i - 1];
  }

  for (int i = size - 1; i >= 0; i--) {
    output[count[array[i]] - 1] = array[i];
    count[array[i]]--;
  }

  // Copy the sorted elements into original array
  for (int i = 0; i < size; i++) {
    array[i] = output[i];
  }
}

// Function to print an array
void printray(int array[], int size) {
  for (int i = 0; i < size; ++i) {
    printf("%d  ", array[i]);
  }
  printf("\n");
}


void copy(int a[],int b[],int k)
{
    int i=0;
    for(i=0;i<k;i++)
    {
        a[i]=b[i];
    }
}