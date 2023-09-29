#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include "myhead.h"
FILE *fp=NULL;

int main()
{
    fp=fopen("filecc.txt","w");
    FILE * file = NULL;
    int i,max=6000,k=0,n=0;
    clock_t t,c;
    for(i=1;i<=20;i++)
    {
        n=(rand() % max) + 1;
        fprintf(fp,"%d\n",n);
    }
    fclose(fp);
    file = fopen("filecc.txt", "r");
    char ch;
    while ((ch=fgetc(file))!=EOF)
    {
        if (ch == ' ' || ch == '\n')
        {
            k++;
        }
    }
    printf("The Total Data is %d\n", k);
    rewind(file);
    int *arr;
    arr = (int *)malloc(k * (sizeof(int)));
    int *dup=(int *)malloc(k * (sizeof(int)));
    for (i = 0; i < k; i++)
    {
        fscanf(file, "%d", &arr[i]);
    }
    /*Insertion sorting*/
    copy(dup,arr,k);
    printf("\n un sorted array :\t");
    printArray(dup,k);
    t=clock();
    insertion(dup,k);
    t=clock()-t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n The time taken...\t%f", time_taken);

    /*Bubble sort*/
    copy(dup,arr,k);
    printf("\n un sorted array :\t");
    printArray(dup,k);
    c=clock();
    bubble_sort(dup, k);
    c=clock()-c;
    double taken = ((double)c)/CLOCKS_PER_SEC;
    printf("\nThe time taken...\t%f", taken);

    /*Heap Sort*/
    t=clock();
    copy(dup,arr,k);
    printf("\n un sorted array :\t");
    printArray(dup,k);
    printf("\n Heap Sort :\t");
    heapSort(dup, k);
	printArray(dup, k);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n The time taken...\t%f", time_taken);

    /*Selection sort*/
    copy(dup,arr,k);
    printf("\n un sorted array :\t");
    printArray(dup,k);
    t=clock();
    printf("\n Selection Sort :\t");
    Selection_sort(dup,k);
    printArray(dup,k);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n The time taken...\t%f", time_taken);

    /*Merge Sort*/
    copy(dup,arr,k);
    printf("\n un sorted array :\t");
    printArray(dup,k);
    t=clock();
    printf("\nMerge Sort :\t");
    mergeSort(dup, 0, k - 1);
    printf("\nSorted array: \t");
    printArray(dup, k);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n The time taken...\t%f", time_taken);

    /*Quick sort*/
    copy(dup,arr,k);
    printf("\n un sorted array :\t");
    printArray(dup,k);
    t=clock();
    printf("\n Quick Sort :\t");
    Quick_sort(dup,0,k-1);
    printArray(dup,k);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n The time taken...\t%f", time_taken);

    /*Shell Sort*/
    copy(dup,arr,k);
    printf("\n un sorted array :\t");
    printArray(dup,k);
    t=clock();
    printf("\n Shell Sort :\t");
    shell(dup, k);  
    printArray(dup, k);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n The time taken...\t%f", time_taken);

    /* Counting Sort */
    copy(dup,arr,k);
    printf("\n un sorted array :\t");
    printArray(dup,k);
    t=clock();
    printf("\n Counting Sort : \t");
    countingSort(dup, k);
    printArray(dup, k);
    t=clock()-t;
    time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("\n The time taken...\t%f", time_taken);
}
