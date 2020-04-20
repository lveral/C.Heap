#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


void Build_Heap(int i, int N, int a[N])
{
	int j, t, r;
	while (2*i + 1 < N)
	{
		r = 2*i + 2;
        j = 2*i + 1;
        if (r < N && a[r] > a[j]) j = r;
        if (a[i] >= a[j]) break;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i = j;
	}
}

int main(void)
{
	int *a;
	int N;
	
	scanf("%i", &N);
	int i = N;
	a = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) scanf ("%i", &a[i]);
	while (i>=0)
	{
		Build_Heap(i,N, a);
		i--;
	}
	//for(i = 0; i < N; i++) printf("%i\n", i); 
	for (i = 0; i < N; i++) printf ("%i ", a[i]);
	free(a);
	return 0;
}
