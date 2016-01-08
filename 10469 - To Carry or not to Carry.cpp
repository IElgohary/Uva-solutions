/*input
4 6
6 9 
*/

#include <bits/stdc++.h>

using namespace std;

unsigned int a , b;

int main()
{
//	unsigned long x = bitset<32>(a) ^ bitset<32>(b);
	while (cin >> a >> b)
	{
		cout << (a ^ b) << endl;
	}
}