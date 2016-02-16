/*input
3
82
73
8
49
120
44
242
58
2
1
1
1
1
4
1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
*/
#include <stdio.h>
#include <cmath>
#include <set> 
#include <vector>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string.h>
#include <cstring>
#include <stack>
#include <map>
#include <cstring>
#include <algorithm>
#include <iomanip>
#include <queue>
#include <functional>
#include <bitset>

using namespace std;

#define r(input) freopen("input.txt","r",stdin)
#define w(output) freopen("output.txt","w",stdout)

#define FOR(i, a) for ( int i = 0 ; i < a ; i++ )
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)

#define BitCount(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a, d) memset(a,d,sizeof(a))
#define remove(v,e) v.erase(std::find(v.begin(),v.end(),e))
#define is_in(container, element) (container.find(element) != container.end())
#define SWAP(a,b) a= a^b, b=a^b, a=a^b

#define sz size
#define pb push_back
#define mp make_pair
#define ft first
#define sd second

#define VISITED 1
#define UNVISITED 0
#define INF 1000000000

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef pair<int,ii> triple;

inline int toint(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
template<class T> inline char toChar(T x) { ostringstream sout; sout << x; return sout.str()[0];}

vi corner,sum;
int main()
{
	int n;
	while ( cin >> n)
	{
		corner.clear();sum.clear();
		int nCorners = pow(2,n);
		FOR(i,nCorners)
		{
			int tmp;
			cin >> tmp;
			corner.pb(tmp);
		}
		
		FOR(i,nCorners)
		{
			int sofar = 0;
			FOR(j , n)
			{
				int tmp = i ^ (1<<j);
				sofar += corner[tmp];
			}
			sum.pb(sofar);
		}
		int out = 0;
		FOR(i , nCorners)
		{
			FOR(j , n)
			{
				int tmp = i ^ (1 << j);
				out = max ( out , sum[i] + sum[tmp]);
			}
		}

		cout << out << endl;

	}
}