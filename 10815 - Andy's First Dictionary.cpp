/*input
Adventures in Disneyland

Two blondes were going to Disneyland when they came to a fork in the
road. The sign read: "Disneyland Left."

So they went home.
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
#include <queue>
#include <functional>

using namespace std;

#define r(input) freopen("input.txt","r",stdin)
#define w(output) freopen("output.txt","w",stdout)
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )
#define sz()  size()
#define printArr(array,n) for(int i = 0 ; i < n ; i++) cout << array[i]<<" ";
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)
#define count(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a,d) memset(a,d,sizeof(a))

typedef long long ll;
typedef pair<int,int> ii;

int main()
{
	set<string> res;
	string s;
	while(cin >> s)
	{
		string p = "";
		int l = s.sz();
		for ( int i = 0 ; i <= l; i++)
		{
			if (isalpha(s[i]))
			{
				p+= tolower(s[i]);
			}
			else if(p != "")
			{
				res.insert(p);
				p = "";
			}

		}
		
	}
	for (std::set<string>::iterator it = res.begin(); it != res.end(); it++)
			cout << *it << endl;
	
}