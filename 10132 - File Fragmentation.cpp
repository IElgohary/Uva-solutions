/*input
1

11
0
11111111111111111111111111111
0111111111111111111111111111
*/


#include <stdio.h>
#include <cmath>
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <stack>
#include <map>
#include <cstring>
#include <algorithm>
#include <iomanip>
using namespace std;

#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )
#define sz()  size()
#define printArr(array,n) for(int i = 0 ; i < n ; i++) cout << array[i]<<" ";

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	while (tc--)
	{
		string arr[150];
		map<string, int> mp;
		
		string tmp;
		int k = 0;
		while (getline(cin, tmp) && tmp != "")
			arr[k++] = tmp;
		

		// printArr(arr,k);
		// cout << endl;

		FOR(0, k)
		{
			FOR2(0, k)
			{
				if (i == j)
					continue;
				string s = arr[i] +""+ arr[j];
				if (mp.count(s)) mp[s] ++;
				else	mp[s] = 1;
				//cout << "string: " << s<<": "<<mp[s]<<endl;

			}
		}

		int curmax = -1000;
		string keymax;
		for(auto it= mp.begin();it != mp.end(); ++it)
		{
			if ( it->second >= curmax)
			{
				curmax= it->second;
				keymax= it->first;
			}
		}

		cout << keymax << endl;
		if(tc) cout << endl;
		
	}
}