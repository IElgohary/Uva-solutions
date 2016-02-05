/*input
7 10
1 2
1 3
2 4
3 4
4 5
4 6
5 7
6 7
2 5
3 6
7 9
1 2
1 3
1 4
2 4
3 4
4 5
5 6
5 7
7 6
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


#define FOR(i, a, b) for ( int i = 0 ; i < a ; i+=b )
#define printArr(array, n) for(int i = 0 ; i < n ; i++) cout << array[i]<<" ";
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)

#define BitCount(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a, d) memset(a,d,sizeof(a))
#define remove(v,e) v.erase(std::find(v.begin(),v.end(),e))

#define sz() size()
#define pb push_back
#define mp make_pair
#define VISITED 1
#define UNVISITED 0
#define INF 1000000000

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

vi adj[1005];
vi dfs_num4;
vi dfs_low;
vi dfs_parent2;
int dfsCount ;
vector<ii> res;
bool mat[1005][1005];

void bridge(int u )
{
	dfs_num4[u] = dfs_low[u] = ++dfsCount;
	for ( int i = 0 ; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if ( dfs_num4[v] == UNVISITED)
		{
			mat[u][v]=1;
			dfs_parent2[v] = u;
			bridge(v);
			if(dfs_low[v] > dfs_num4[u])
			{
				mat[u][v] = 1;
				mat[v][u] = 1;
			}
			dfs_low[u] = min(dfs_low[v], dfs_low[u]);
		}
		else if(v != dfs_parent2[u] )
		{	
			mat[u][v] = 1;
			remove(adj[v],u);
			dfs_low[u] = min(dfs_low[u], dfs_num4[v]);
		}


	}
}


int main()
{
	int n,m, test = 0;
	while(cin >> n >> m)
	{
		if( n == m && m == 0) break;
		
		FOR(i, n, 1) adj[i].clear();
		FOR(i , n, 1)
			FOR(j , n , 1)
				mat[i][j] = 0;

		FOR(i, m,1)
		{
			int x , y;
			cin >> x >> y;
			adj[ x - 1].pb( y - 1);
			adj[ y - 1].pb( x - 1);
		}

		dfsCount = 0 ;
		dfs_num4.assign(n, UNVISITED);
		dfs_parent2.assign(n, 0);
		dfs_low.assign(n, 0);

		cout << ++test << endl << endl;
		for ( int i = 0 ; i < n ; i++)
			if (dfs_num4[i] == UNVISITED)
				bridge(i);
		
		FOR(i , n, 1)
			FOR(j , n, 1)
				if(mat[i][j])
					cout << i+1 << ' '<< j+1 << endl;
		cout << '#' << endl;
		
	}
}

