/*input
4
1 2
1 3
1 4
2 3
2 4
3 4
0 0
6
1 2
1 3
1 6
2 3
2 5
3 4
4 5
4 6
5 6
0 0
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
typedef pair<int,ii> iii;

inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

vi adj[350];
int v;
vi color;

bool Bipartite_bfs(int source)
 {
 	
 	queue<int> q;
 	q.push(source);
 	color[source] = 0;

 	while ( !q.empty() )
 	{
 		int u = q.front();
 		q.pop();
 		for ( int i = 0 ; i < adj[u].size(); i++)
 		{
 			int v = adj[u][i];
 			if (color[v] == INF)
 			{
 				color[v] = color[u] ^ 1;
 				q.push(v);
 			}
 			else if( color[v] == color[u])
 				return false;
 		}
 	}
 	return true;

 }

int main()
{
	
	while (cin >> v)
	{
		FOR(i, v) adj[i].clear();

		if (!v) break;
		int x ,y;
		while(cin >> x >> y)
		{
			if(x == 0 && y == x) break;
			adj[x-1].pb(y-1);
			adj[y-1].pb(x-1);
		}
		
		color.assign(v, INF);
		bool bi = true;

		FOR(i , v)
		{
			if(color[i] == INF)
			{
				bi = bi && Bipartite_bfs(i);
			}
		}

		if(bi) cout << "YES"<< endl;
		else	cout << "NO"<< endl;

	}
	
}