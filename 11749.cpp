#include <bits/stdc++.h>

using namespace std;

struct UnionFindDisjointSets
{
	UnionFindDisjointSets(int size);
	int findSet(int a);
	bool isSameSet(int a, int b);
	void unionSet(int a, int b);
	int numDisjointSets();
	int sizeOfSet(int a);

	int size;
	vector<int> pset;
	vector<int> set_size;
};

UnionFindDisjointSets::UnionFindDisjointSets(int size)
{
	this->size = size;
	set_size.assign(size, 1);
	pset.assign(size, 0);
	for (int i = 0; i < size; i++)
	{
		pset[i] = i;
	}
}

int UnionFindDisjointSets::findSet(int a)
{
	return pset[a] == a ? a : (pset[a] = findSet(pset[a]));
}

bool UnionFindDisjointSets::isSameSet(int a, int b)
{
	return findSet(a) == findSet(b);
}

void UnionFindDisjointSets::unionSet(int a, int b)
{
	if (isSameSet(a, b))
	{
		return;
	}
	size--;
	set_size[findSet(b)] += set_size[findSet(a)];
	pset[findSet(a)] = findSet(b);
}

int UnionFindDisjointSets::numDisjointSets()
{
	return size;
}

int UnionFindDisjointSets::sizeOfSet(int a)
{
	return set_size[findSet(a)];
}

int main()
{
	int n, m;
	int a, b, c;
	int best;
	vector<pair<int, int>> v;
	while (cin >> n >> m)
	{
		if (!n && !m)
		{
			break;
		}
		v.clear();
		UnionFindDisjointSets ds(n + 1);
		best = -2147483648;
		while (m--)
		{
			cin >> a >> b >> c;
			if (c > best)
			{
				best = c;
				v.clear();
				v.push_back(make_pair(a, b));
			}
			else if (c == best)
			{
				v.push_back(make_pair(a, b));
			}
		}
		best = 0;
		for (int i = 0, sz = v.size(); i < sz; i++)
		{
			ds.unionSet(v[i].first, v[i].second);
			if (ds.sizeOfSet(v[i].first) > best)
			{
				best = ds.sizeOfSet(v[i].first);
			}
		}
		cout << best << endl;
	}
	return 0;
}
