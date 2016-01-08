/*input
5
1 2
4 3
2 2
1 -2
-2 1
*/

#include <bits/stdc++.h>
using namespace std;

int t ,  a, b;
int main()
{
	cin >> t;
	while(t--)
	{
		cin >> a>> b;
		if ( a > b)
			cout << '>' << endl;
		else if ( a == b)
			cout << '=' << endl;
		else if ( a < b)
			cout << '<' << endl;
	}
}
