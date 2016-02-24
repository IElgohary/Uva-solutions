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

int tc;
vi adj[100500], sorted_rev, vis;
int n , m;
int x , y;
int dfscount;
int num;

void dfs(int u) // Modified Topological sort
{
	vis[u] = VISITED;
	for ( int i = 0 ; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if(vis[v]== UNVISITED) // condition to count cycles only once
			dfs(v);
	}
	sorted_rev.push_back(u);
}

int main()
{
	cin >> tc;
	while ( tc --)
	{
		cin >> n >> m;
		FOR(i,n)adj[i].clear();
		sorted_rev.clear();
		vis.assign(n, 0);
		FOR(i , m)
		{
			cin >> x >> y;
			x--;y--;
			adj[x].pb(y);
		}

		for ( int i = 0 ; i < n; i++)
	 	{
	 		if (vis[i] == UNVISITED)
	 			dfs(i);
	 	}

	 	reverse(sorted_rev.begin(), sorted_rev.end());
	 	num = 0;
	 	vis.clear();
	 	vis.assign(n,UNVISITED);
	 	int lim = sorted_rev.sz();
	 	FOR(i,lim)
	 	{
	 		if(vis[sorted_rev[i]] == UNVISITED)
	 		{	
	 			dfs(sorted_rev[i]);
	 			num++;
 			}
	 	}
	 	cout << num << endl;

	}
}
