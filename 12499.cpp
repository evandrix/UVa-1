#include <bits/stdc++.h>

using namespace std;

int main()
{
	int x, y, i, cases, j;
	int arr[51];
	scanf("%d", &cases);
	for (i = 1; i < cases + 1; i++)
	{
		scanf("%d %d", &x, &y);
		for (j = 0; j < x; j++)
		{
			scanf("%d", &arr[j]);
		}
		arr[x] = y;
		int temp = 0;
		for (j = 0; j < x; j += 2)
		{
			temp ^= arr[j + 1] - arr[j];
		}
		printf("Case %d: ", i);
		if (temp != 0)
		{
			printf("First Player\n");
		}
		else
		{
			printf("Second Player\n");
		}
	}
	return 0;
}
