#include <bits/stdc++.h>

using namespace std;

// (A, B, C, D) => (D, C, B, A)
// #inverse pair = x => 6-x
// final state #inverse pair = 0, in a time delta = 6-2x, is even.
// then, init #inverse pair must even.

int BIT[1024];

void upd(int x, int val, int L)
{
	while (x <= L)
	{
		BIT[x] += val;
		x += x & (-x);
	}
}

int query(int x)
{
	int ret = 0;
	while (x)
	{
		ret += BIT[x];
		x -= x & (-x);
	}
	return ret;
}

int main()
{
	int T, N, A[1024];
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		for (int i = 0; i < N; i++)
		{
			scanf("%d", &A[i]);
			A[i + N] = A[i];
		}
		int ret = 0;
		for (int i = 0; i < N; i++)
		{
			int inv = 0;
			memset(BIT, 0, sizeof(BIT));
			for (int j = i; j < i + N; j++)
			{
				inv += query(N - A[j]);
				upd(N - A[j] + 1, 1, N);
			}
			if (inv % 2 == 0)
			{
				ret = 1;
				break;
			}
		}
		printf(ret ? "possible\n" : "impossible\n");
	}
	return 0;
}
