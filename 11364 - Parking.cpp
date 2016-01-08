/*input
2
4
24 13 89 37
6
7 30 41 14 39 42
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	int t , n;
	int arr[25];
	cin >> t;
	while ( t--)
	{
		cin >> n;
		for ( int i = 0 ; i < n ; i++)
			cin >> arr[i];

		sort(arr , arr+n);

		int sum = 0;
		for ( int i = n-1 ; i > 0; i--)
		{
			sum += (arr[i] - arr[i-1]);
		}
		cout << 2* sum << endl;
	}

}