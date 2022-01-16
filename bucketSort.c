// Algorithm for Bucket Sorting

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Array size nArray
// Number of buckets nBucket
// Each bucket capacity intervalo

// Function to sort the elements of each bucket

void myBubbleSort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n-i-1; j++)
        {
            if( arr[j] > arr[j+1])
            {
                // swap the elements
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            } 
        }
    }
}

int getBucketIndex(int value,int intervalo) {
  return value / intervalo;
}

void print(int ar[],int nARRAY) {
  int i;
  for (i = 0; i < nARRAY; ++i) {
    printf("%d ", ar[i]);
  }
  printf("\n");
}

// Sorting function
void BucketSort(int arr[],int nARRAY,int nBUCKET) {

  int intervalo = nARRAY/nBUCKET;
  int **n_Buckets = (int **)malloc(nBUCKET * sizeof(int *));
  int *n_Buckets_MAX = (int *)malloc(nBUCKET * sizeof(int));
  int *n_Buckets_ATUAL = (int *)malloc(nBUCKET * sizeof(int)); 
  int i, j;


  for (i = 0; i < nBUCKET ; ++i)
      n_Buckets[i] = (int *)malloc(intervalo * sizeof(int));
      n_Buckets_MAX[i] = intervalo;
      n_Buckets_ATUAL[i] = 0;
      
  for (i = 0; i < nARRAY; ++i) {
    int posBucket = getBucketIndex(arr[i],intervalo);
    int posAtual = n_Buckets_ATUAL[posBucket];
    int bucketMax = n_Buckets_MAX[posBucket];
    if (posAtual == bucketMax) {
      int aumento = bucketMax + (0.2 * intervalo);
      n_Buckets[posBucket] = realloc (n_Buckets[posBucket], sizeof(int) * (aumento));
      n_Buckets_MAX[posBucket] = bucketMax + (0.2 * intervalo);
    }
    n_Buckets[posBucket][posAtual] = arr[i]; 
    n_Buckets_ATUAL[posBucket]++;
  }

  for (i = 0; i < nBUCKET; i++) {
    for (j = 0; j < n_Buckets_ATUAL[i]; j++) {
      printf("Bucket[%d] = %d\n", i, n_Buckets[i][j]);
    }
    printf("\n");
  }

  for (i = 0; i < nBUCKET; i++) {
    for (j = 0; j < n_Buckets_ATUAL[i]; j++) {
      myBubbleSort(n_Buckets[i],n_Buckets_ATUAL[i]);
    }
  }

  printf("-------------\n");
  printf("Buckets after sorting\n");
  for (i = 0; i < nBUCKET; i++) {
    for (j = 0; j < n_Buckets_ATUAL[i]; j++) {
      printf("Bucket[%d] = %d\n", i, n_Buckets[i][j]);
    }
    printf("\n");
  }

  int k = 0;
  for (i = 0; i < nBUCKET; i++) {
    for (j = 0; j < n_Buckets_ATUAL[i]; j++) {
      arr[k++] = n_Buckets[i][j];
    }
  }

  return;
}


int main(int argc,char **argv) {
  const int nARRAY = atoi(argv[1]);
  const int nBUCKET = atoi(argv[2]);
  int *array_Mega;
  array_Mega = malloc(nARRAY*sizeof(int));
  for (int i = 0; i < nARRAY; i++) array_Mega[i] = rand() % nARRAY;

  printf("Initial array: ");
  print(array_Mega,nARRAY);
  printf("-------------\n");

  BucketSort(array_Mega,nARRAY,nBUCKET);
  printf("-------------\n");
  printf("Sorted array: ");
  print(array_Mega,nARRAY);
  return 0;
}