/*input
5 4
1 2
2 3
1 3
1 5
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
vi sorted_rev;
vi dfs_num2;
vector<bool> vis;

void topological_dfs(int u)
{
	dfs_num2[u] = VISITED;
	for ( int i = 0 ; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		topological_dfs(v);
	}
	if(!vis[u])
	{
		sorted_rev.pb(u+1);
		vis[u] = true;
	}

}

int main()
{
	int n ,m;
	cin >> n >>m;
	while(n != 0 || m != n)
	{
		FOR(i,n,1)
			adj[i].clear();
		sorted_rev.clear();
		dfs_num2.assign(n, UNVISITED);
		vis.assign(n, false);
		FOR(i,m,1)
		{
			int a , b;
			cin >> a >> b;
			adj[a - 1].pb(b - 1);
		}
		for ( int i = 0 ; i < n; i++)
	 	{
	 		if ( dfs_num2[i] == UNVISITED)
	 			topological_dfs(i);
	 	}

	 	reverse(sorted_rev.begin(), sorted_rev.end());
	 	cout << sorted_rev[0];
	  	for ( int i = 1 ; i < sorted_rev.size(); ++i)
  			cout << " "<<sorted_rev[i] ;
  		cout<< endl;
  		cin >> n >> m;
	}
}
