/*input
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
Smith, Peter
Brown, Anna
3 2
McBride, John
Smith, Peter
Brown, Anna
Brown, Anna
Smith, Peter
McBride, John
Smith, Peter
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

#define VISITED 1
#define UNVISITED 0
#define INF 1000000000

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}


map<string,int> mp;
vi adj[1005];

vi dfs_num4, dfs_low, S , visited ;
int dfsCount;
int numSCC;
void tarjanSCC(int u)
{
	dfs_low[u] = dfs_num4[u] = dfsCount++;
	S.push_back(u);
	visited[u] = 1;
	for ( int i = 0 ; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if ( dfs_num4[v] == UNVISITED)
			tarjanSCC(v);
		if (visited[v])
			dfs_low[u] = min(dfs_low[u], dfs_low[v]);
	}

	if ( dfs_num4[u] == dfs_low[u])
	{
		++numSCC;
		while (1)
		{
			int v = S.back(); 
			S.pop_back(); 
			visited[v] = 0;
			if ( u == v) break;
		}
	}

}

int main()
{
	int t , p;
	while( cin >> p >> t)
	{
		cin.ignore(1000,'\n');
		if ( p == 0 && t == p) break;
		FOR(i, p , 1) adj[i].clear();

		string name;
		FOR(i, p, 1)
		{
			getline(cin, name);
			mp[name] = i;
		}

		FOR(i, t, 1)
		{
			string s1,s2;
			getline(cin, s1);
			getline(cin, s2);
			int u , v;
			u = mp[s1];
			v = mp[s2];
			adj[u].pb(v);
		}

		dfs_num4.assign(p, UNVISITED);
		dfs_low.assign(p, 0);
		visited.assign(p, 0);
		numSCC = 0;
		for ( int i = 0 ; i < p; i++)
			if(dfs_num4[i] == UNVISITED)
				tarjanSCC(i);
		cout << numSCC << endl;
	}
}