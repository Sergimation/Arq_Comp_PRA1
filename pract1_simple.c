#include <stdio.h>

int arr[100];
int arrp[100];
int keys[6];
int num_primes;

int readfile();
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void swap(int* a, int* b);
int separatePrimes(int arr[], int arrp[]);
int check_prime(int a);
void keyGenerator(int primes[], int keys[]);
void printArr(int arr[]);
void re_size(int n, int primes[]);

void main()
{
  printf("\nVector Ordenat:\n");
  readfile();
  quickSort(arr, 0, 99);
  printArr(arr);
  printf("\nVector nombres primers:\n");
  int n=separatePrimes(arr,arrp);
  int primes[n];
  re_size(n, primes);
  printf("\nVector de claus:\n");
  keyGenerator(primes, keys);
  printf("\n\n");
}

int readfile()
{
  int i;
    FILE *myFile;
    myFile = fopen("valors.txt", "r");
    for (i = 0; i < 100; i++)
    {
        fscanf(myFile, "%d", &arr[i]);
    }
    fclose(myFile);
}

void quickSort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    int i = (low - 1);
    int j;
    for ( j = low; j <= high- 1; j++)
    {
        if (arr[j] <= pivot)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

void printArr(int arr[])
{
  int i;
  for ( i = 0; i < 100; i++) {
    printf("%d, ", arr[i]);
  }
}

int separatePrimes(int arr[], int arrp[])
{
    num_primes=0;
    int i, lstprime=0, j=0;
    for (i = 0; i < 100; i++) {
        if (check_prime(arr[i])==1 && lstprime!=arr[i]) {
          arrp[j] = arr[i];
          lstprime = arr[i];
          num_primes++;
          printf("%d, ", arrp[j]);
          j++;
        }
    }
    return num_primes;
  }

void re_size(int n, int primes[])
{
    int i;
    for (i = 0; i < n; i++) {
        primes[i]=arrp[i];
    }
}

int check_prime(int a)
{
   int c;
   for ( c = 2 ; c <= a - 1 ; c++ )
   {
      if ( a%c == 0 )
     return 0;
   }
   if ( c == a )
      return 1;
}

void keyGenerator(int primes[], int keys[])
{
  int i=0;
  while(i<=(11-i)){
    keys[i]=primes[i]*primes[10-i];
    printf("%d, ", keys[i]);
    i++;
  }
}
