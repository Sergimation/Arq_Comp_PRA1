#include <stdio.h>

int arr[100];
int arrp[100];
int num_primes;
FILE *trace;

int openfile();
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
  openfile();
  printf("\nVector Ordenat:\n");
  readfile();
  quickSort(arr, 0, 99);
  printArr(arr);
  printf("\nVector nombres primers:\n");
  int n=separatePrimes(arr,arrp);
  /*P*/fprintf(trace,"%d %p\n",3,&n);
  int keys[n + 1];
  printf("\nVector de claus:\n");
  keyGenerator(arrp, keys);
  printf("\n\n");
  fclose(trace);

  printf("%d", n);
}

int openfile()
{
  trace = fopen("trace.txt", "w");
}

int readfile()
{
  int i;
    FILE *myFile;
    myFile = fopen("valors.txt", "r");
    for (i = 0; i < 100; i++)
    {
        /*P*/fprintf(trace,"%d %p\n",3,&i);
        fscanf(myFile, "%d", &arr[i]);
        /*P*/fprintf(trace,"%d %p\n",3,&arr[i]);
    }
    fclose(myFile);
}

void quickSort(int arr[], int low, int high)
{
    /*P*/fprintf(trace,"%d %p\n",2,&low);
    /*P*/fprintf(trace,"%d %p\n",2,&high);
    if (low < high)
    {
      /*P*/fprintf(trace,"%d %p\n",2,&low);
      /*P*/fprintf(trace,"%d %p\n",2,&high);
      int pi = partition(arr, low, high);
      /*P*/fprintf(trace,"%d %p\n",3,&pi);
      /*P*/fprintf(trace,"%d %p\n",2,&low);
      /*P*/fprintf(trace,"%d %p\n",2,&pi);
      quickSort(arr, low, pi - 1);
      /*P*/fprintf(trace,"%d %p\n",2,&pi);
      /*P*/fprintf(trace,"%d %p\n",2,&high);
      quickSort(arr, pi + 1, high);
    }
}

int partition (int arr[], int low, int high)
{
    int pivot = arr[high];    // pivot
    /*P*/fprintf(trace,"%d %p\n",3,&pivot);
    /*P*/fprintf(trace,"%d %p\n",2,&arr[high]);
    int i = (low - 1);
    /*P*/fprintf(trace,"%d %p\n",3,&i);
    /*P*/fprintf(trace,"%d %p\n",2,&low);
    int j;
    for ( j = low; j <= high- 1; j++)
    {
        /*P*/fprintf(trace,"%d %p\n",3,&j);
        /*P*/fprintf(trace,"%d %p\n",2,&i);
        /*P*/fprintf(trace,"%d %p\n",2,&low);
        /*P*/fprintf(trace,"%d %p\n",2,&high);
        /*P*/fprintf(trace,"%d %p\n",2,&arr[j]);
        /*P*/fprintf(trace,"%d %p\n",2,&pivot);
        if (arr[j] <= pivot)
        {
            i++;
            /*P*/fprintf(trace,"%d %p\n",3,&i);
            /*P*/fprintf(trace,"%d %p\n",2,&arr[i]);
            /*P*/fprintf(trace,"%d %p\n",2,&arr[j]);
            swap(&arr[i], &arr[j]);
        }
    }
    /*P*/fprintf(trace,"%d %p\n",2,&arr[i+1]);
    /*P*/fprintf(trace,"%d %p\n",2,&arr[high]);
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void swap(int* a, int* b)
{
    int t = *a;
    /*P*/fprintf(trace,"%d %p\n",3,&t);
    /*P*/fprintf(trace,"%d %p\n",2,&*a);
    *a = *b;
    /*P*/fprintf(trace,"%d %p\n",3,&*a);
    /*P*/fprintf(trace,"%d %p\n",2,&*b);
    *b = t;
    /*P*/fprintf(trace,"%d %p\n",3,&*b);
    /*P*/fprintf(trace,"%d %p\n",2,&t);
}

void printArr(int arr[])
{
  int i;
  for ( i = 0; i < 100; i++) {
      /*P*/fprintf(trace,"%d %p\n",3,&i);
      /*P*/fprintf(trace,"%d %p\n",2,&arr[i]);
      printf("%d, ", arr[i]);
  }
}

int separatePrimes(int arr[], int arrp[])
{
    num_primes=0;
    /*P*/fprintf(trace,"%d %p\n",3,&num_primes);
    int i, lstprime=0, j=0;
    /*P*/fprintf(trace,"%d %p\n",3,&j);
    /*P*/fprintf(trace,"%d %p\n",3,&lstprime);
    for (i = 0; i < 100; i++) {
        /*P*/fprintf(trace,"%d %p\n",3,&i);
        int is_prime = check_prime(arr[i]);
        /*P*/fprintf(trace,"%d %p\n",3,&is_prime);
        /*P*/fprintf(trace,"%d %p\n",2,&is_prime);
        /*P*/fprintf(trace,"%d %p\n",2,&lstprime);
        /*P*/fprintf(trace,"%d %p\n",2,&arr[i]);
        if (is_prime==1 && lstprime!=arr[i]) {
            arrp[j] = arr[i];
            /*P*/fprintf(trace,"%d %p\n",3,&arrp[j]);
            /*P*/fprintf(trace,"%d %p\n",2,&arr[i]);
            lstprime = arr[i];
            num_primes++;
            /*P*/fprintf(trace,"%d %p\n",3,&num_primes);
            /*P*/fprintf(trace,"%d %p\n",3,&lstprime);
            /*P*/fprintf(trace,"%d %p\n",2,&arr[i]);
            /*P*/fprintf(trace,"%d %p\n",2,&arrp[j]);
            printf("%d, ", arrp[j]);
            j++;
            /*P*/fprintf(trace,"%d %p\n",3,&j);
        }
    }
    return num_primes;
}

void re_size(int n, int primes[])
{
    int i;
    for (i = 0; i < n; i++) {
        /*P*/fprintf(trace,"%d %p\n",3,&i);
        /*P*/fprintf(trace,"%d %p\n",2,&arrp[i]);
        primes[i]=arrp[i];
        /*P*/fprintf(trace,"%d %p\n",3,&primes[i]);
    }
}

int check_prime(int a)
{
   int c;
   for ( c = 2 ; c <= a - 1 ; c++ )
   {
       /*P*/fprintf(trace,"%d %p\n",3,&c);
       /*P*/fprintf(trace,"%d %p\n",2,&a);
       /*P*/fprintf(trace,"%d %p\n",2,&c);
      if ( a%c == 0 )
     return 0;
   }
   /*P*/fprintf(trace,"%d %p\n",2,&a);
   /*P*/fprintf(trace,"%d %p\n",2,&c);
   if ( c == a ) return 1;
}

void keyGenerator(int primes[], int keys[])
{
  int i=0;
  /*P*/fprintf(trace,"%d %p\n",3,&i);
  while(i<=(11-i)){
      /*P*/fprintf(trace,"%d %p\n",2,&i);
      keys[i]=primes[i]*primes[10-i];
      /*P*/fprintf(trace,"%d %p\n",3,&keys[i]);
      /*P*/fprintf(trace,"%d %p\n",2,&primes[i]);
      /*P*/fprintf(trace,"%d %p\n",2,&primes[10-i]);
      printf("%d, ", keys[i]);
      /*P*/fprintf(trace,"%d %p\n",2,&keys[i]);
      i++;
      /*P*/fprintf(trace,"%d %p\n",3,&i);
  }
}
