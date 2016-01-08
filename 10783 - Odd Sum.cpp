/*input 
2
1
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	int a , b , t;
	cin >> t;
	for ( int i = 1 ; i <= t ; i++)
	{
		int sum = 0;
		cin >> a >> b;
		for ( int j = a ; j <= b ; j++)
			if ( j % 2 != 0) sum += j;
		cout << "Case "<< i<<": "<< sum << endl;
		
	}
}