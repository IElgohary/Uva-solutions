/*input
10 3 4
0 2 1
1 3 5
1 2 7
2 3 10
10 5 4
3 5 10
2 4 9
0 2 5
2 5 8
0 0 0
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

#define FOR(i, a) for ( int i = 0 ; i < a ; i++ )
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)

#define BitCount(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a, d) memset(a,d,sizeof(a))
#define remove(v,e) v.erase(std::find(v.begin(),v.end(),e))

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

inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

triple arr[30]; 
int orders, n;

int bk(int i, int curr[])
{
	if ( i == orders) return 0;
	triple tmp = arr[i];

	int leave = bk(i+1,curr);
	int take = -INF;
	bool can = true;

	for ( int j = tmp.sd.ft; can && j < tmp.sd.sd; j++)
		if(curr[j] + tmp.ft > n)
			can = false;
    
    int b[10];
    	FOR(i , 10){
	    b[i]=curr[i];
	}
	if (can)
	{
		for ( int j = tmp.sd.ft; j < tmp.sd.sd; j++)
			curr[j] += tmp.ft;
		take = (tmp.ft * (tmp.sd.sd - tmp.sd.ft)) + bk(i+1, curr);
	}
	
	FOR(i , 10){
	    curr[i]=b[i];
	}
	
	return max(take,leave);
}

int main()
{
	int b;
	while(cin >> n >> b >> orders)
	{
		if ( n == 0 && b == n && orders == n) break;
		FOR(i , orders)
		{
			int st , end , num;
			cin >> st >> end >> num;
			arr[i] = mp(num,mp(st,end)); 
		}

		int curr [10] = {0};
		cout << bk(0 , curr)<< endl;


	}	
}