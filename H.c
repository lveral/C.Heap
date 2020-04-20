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

int Extract_Max(int N, int a[N], int last)
{
	int j, b, index, i;
		b = a[0];
		a[0] = a[last];
		a = (int *) realloc(a, (last)*sizeof(int));
		Build_Heap(0, last, a);
		for (i = 0; i < last; i++) printf ("%i ", a[i]);
		printf("\n");
	return b;
}

int main(void)
{
	int *a; int *asort;
	int N;
	
	scanf("%i", &N);
	int i = N;
	a = (int*)malloc(N * sizeof(int));
	asort = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) scanf ("%i", &a[i]);
	while (i>=0)
	{
		Build_Heap(i,N, a);
		i--;
	}
	for (i = 0; i < N; i++) printf ("%i ", a[i]);
	printf("\n");
	for(i = 0; i < N; i++) asort[i] = Extract_Max(N, a, (N-i-1)); 
	i--;
	while (i>=0)
	{
		printf("%i ", asort[i]);
		--i;
	}
	return 0;
}
