/*input
3 2
0 1
1 2
15 16
0 2
1 2
2 3
3 4
3 5
4 6
5 7
6 8
7 8
7 9
8 10
9 11
10 12
11 12
10 13
12 14
0 0
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

vi adj[50];
bool vis[30][30];
int dfs_depth;

int dfs(int u)
{
	int mx = 0;
	for( int i = 0 ; i < adj[u].size(); ++i)
	{
		int v = adj[u][i];
		if (!vis[u][v])
		{
			vis[u][v] = vis[v][u] = true;
			mx = max(mx , 1 + dfs(v));
			vis[u][v] = vis[v][u] = false;

		}
	}
	return mx;
}
int main()
{
	int n , m;
	while ( cin >> n >> m)
	{
		if ( n == 0 && m == 0) break;
		FOR(i , n) adj[i].clear();
		dfs_depth = 0;
		FOR(i , m)
		{
			int x , y;
			cin >> x >> y;
			adj[x].pb(y);
			adj[y].pb(x);

		}

		FOR(i , n)
		{
			cover(vis, false);
			dfs_depth = max(dfs_depth, dfs(i));
			
		}
		cout << dfs_depth << endl;
	}
}