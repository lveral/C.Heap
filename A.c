#include <stdio.h>
#include <malloc.h>

int Sift_Up(int i,int N, int a[N])
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
	printf("%i\n", i + 1);
}

int main()
{

	int *a = NULL, i = 0, N, M, index, x, k = 0;
	
	scanf("%i", &N);
	
	for(i = 0; i < N; i++)
	{
		a = (int*)realloc(a, (i + 1) * sizeof(int));
		scanf("%i", &a[i]);
	}
	scanf("%i", &M);
	for(k = 0; k < M; k++)
	{
		scanf("%i", &index);
		scanf("%i", &x);
		index -= 1;
		a[index] += x;
		Sift_Up(index, N, a);
	}
	for(k = 0; k < i; k++) 
	{
		printf(" %i", a[k]);
	}
	free(a);

	return 0;

}

