#include <stdio.h>
#include <malloc.h>

void Sift_Down(int i,int N, int a[N])
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
		a[index] -= x;
		Sift_Down(index, N, a);
	}
	for(k = 0; k < i; k++) 
	{
		printf(" %i", a[k]);
	}
	free(a);

	return 0;

}
