/*input
4
1 4 2 3
2 4
0
3
2 1 3
0
0
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

#define sz() size()
#define pb push_back

#define VISITED 1
#define UNVISITED 0
#define INF 1000000000

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

vi adj[105];
vi dfs_num4;
vi dfs_low;
vi dfs_parent2;
int dfsRoot;
int rootChildren;
int dfsCount ;
vector<bool> articulation_vertex;

void articulation_point(int u )
{
	dfs_num4[u] = dfs_low[u] = ++dfsCount;
	for ( int i = 0 ; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if ( dfs_num4[v] == UNVISITED)
		{
			dfs_parent2[v] = u;
			if ( u == dfsRoot) rootChildren++;
			articulation_point(v);

			if (dfs_low[v] >= dfs_num4[u])
				articulation_vertex[u] = true;
			dfs_low[u] = min(dfs_low[v], dfs_low[u]);
		}
		else if(v != dfs_parent2[u] )
			dfs_low[u] = min(dfs_low[u], dfs_num4[v]);
	}
}


int main()
{
	int N;
	while (cin >> N)
	{
		if(!N) break;
		cin.ignore();
		FOR(i, N, 1)
			adj[i].clear();

		string line;
		while(getline(cin, line))
		{
			stringstream ln (line);
			
			int x;
			ln >> x;
			if ( x == 0) break;

			int y;
			while(ln>>y)
			{
				adj[x - 1].pb(y - 1);
				adj[y - 1].pb(x - 1);
			}

		}

		dfsCount = 0 ;
		dfs_num4.assign(N, UNVISITED);
		dfs_parent2.assign(N, 0);
		dfs_low.assign(N, 0);
		articulation_vertex.assign(N, 0);

		for ( int i = 0 ; i < N ; i++)
		{
			if (dfs_num4[i] == UNVISITED)
			{
				dfsRoot = i;
				rootChildren = 0;
				articulation_point(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1); 
			}
		}

		int res = 0;
		FOR(i, N, 1)
			if(articulation_vertex[i]) res++;

		cout << res << endl;
	}
}

