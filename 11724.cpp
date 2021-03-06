#include <bits/stdc++.h>

using namespace std;

char exp_[1024], cond[1024];
int val[26], used[512][512];
long long dp[512][512];

int spfa(vector<int> g[])
{
	queue<int> Q;
	int inq[26] = {}, dist[26] = {}, cnt[26] = {}, u, v;
	for (int i = 0; i < 26; i++)
	{
		Q.push(i), dist[i] = 1;
	}
	while (!Q.empty())
	{
		u = Q.front(), Q.pop();
		inq[u] = 0;
		for (int i = 0; i < g[u].size(); i++)
		{
			v = g[u][i];
			if (dist[v] < dist[u] + 1)
			{
				dist[v] = dist[u] + 1;
				if (!inq[v])
				{
					inq[v] = 1, Q.push(v);
					if (++cnt[v] > 26)
					{
						return 0;
					}
				}
			}
		}
	}
	for (int i = 0; i < 26; i++)
	{
		val[i] = dist[i];
	}
	return 1;
}

long long dfs(int l, int r)
{
	if (used[l][r])
	{
		return dp[l][r];
	}
	if (l == r)
	{
		return val[exp_[l] - 'a'];
	}
	used[l][r] = 1;
	long long &ret = dp[l][r];
	ret = 1LL << 60;
	int p = 0, test = 0;
	for (int i = l; i <= r; i++)
	{
		if (exp_[i] == '(')
		{
			p++;
		}
		if (exp_[i] == ')')
		{
			p--;
		}
		if (p == 0 && exp_[i] == '+')
		{
			ret = min(ret, dfs(l, i - 1) + dfs(i + 1, r));
			test++;
		}
		if (p == 0 && exp_[i] == '*')
		{
			ret = min(ret, dfs(l, i - 1) * dfs(i + 1, r));
			test++;
		}
	}
	if (test == 0)
	{
		ret = min(ret, dfs(l + 1, r - 1));
	}
	return ret;
}

int main()
{
	int testcase, cases = 0;
	int n;
	scanf("%d", &testcase);
	while (testcase--)
	{
		scanf("%s", exp_);
		scanf("%d", &n);
		vector<int> g[26];
		for (int i = 0; i < n; i++)
		{
			scanf("%s", cond);
			g[cond[2] - 'a'].push_back(cond[0] - 'a');
		}
		printf("Case %d: ", ++cases);
		if (!spfa(g))
		{
			puts("-1");
		}
		else
		{
			memset(used, 0, sizeof(used));
			printf("%lld\n", dfs(0, strlen(exp_) - 1));
		}
	}
	return 0;
}
