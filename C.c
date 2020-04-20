#include <stdio.h>
#include <malloc.h>

void Extract_Max(int N, int a[N])
{
	int j, b[2], index;
	for (j = 1; j < N; j++)
	{
		b[0] = a[0];
		a[0] = a[N - j];
		a = (int *) realloc(a, (N-j)*sizeof(int));
		b[1] = Sift_Down(0, N - j, a);
		printf("%i %i\n", b[1], b[0]);	
	}
}

int Sift_Down(int i,int N, int a[N])
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
	return (i + 1);
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
	
	Extract_Max(N, a);
	free(a);

	return 0;

}
