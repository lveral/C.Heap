#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>


void Build_Heap(int i, int a[i])
{
	int j, t;
	while (i > 0 && a[i] > a[(i - 1)/2])
	{
		j = (i - 1)/2;
		t = a[i];
		a[i] = a[j];
		a[j] = t;
		i = j;
	}
	
}

int main(void)
{
	int *a;
	int i = 0, N;
	
	scanf("%i", &N);
	a = (int*)malloc(N * sizeof(int));
	for (i = 0; i < N; i++) scanf ("%i", &a[i]);
	for(i = 1; i < N; i++) Build_Heap(i, a);
	for (i = 0; i < N; i++) printf ("%i ", a[i]);
	free(a);
	return 0;
}
