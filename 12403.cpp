#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t, sum = 0, tmp;
	string input;
	cin >> t;
	cin.ignore(100, '\n');
	while (t--)
	{
		cin >> input;
		if (input == "donate")
		{
			cin >> tmp;
			sum += tmp;
		}
		else if (input == "report")
		{
			cout << sum << endl;
		}
	}
	return 0;
}
