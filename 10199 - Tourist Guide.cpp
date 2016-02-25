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

vi adj[150];
vi dfs_num, dfs_low, dfs_parent;
int dfsRoot, rootChildren, dfsCount ;
vi articulation_vertex;
map<string,int> I;
map<int,string> K;
int N, routes,T = 0;
bool frst = true;
void articulation_point(int u )
{
	dfs_num[u] = dfs_low[u] = ++dfsCount;
	for ( int i = 0 ; i < adj[u].size(); i++)
	{
		int v = adj[u][i];
		if ( dfs_num[v] == UNVISITED)
		{
			dfs_parent[v] = u;
			if ( u == dfsRoot) rootChildren++;
			articulation_point(v);

			if (dfs_low[v] >= dfs_num[u])
				articulation_vertex[u] = true;
				
			
			dfs_low[u] = min(dfs_low[v], dfs_low[u]);
		}
		else if(v != dfs_parent[u] )
			dfs_low[u] = min(dfs_low[u], dfs_num[v]);
	}
}

int main()
{
	while(cin >> N)
	{
		FOR(i,N) adj[i].clear();
		dfsCount = 0 ;
		dfs_num.assign(N, UNVISITED);
		dfs_parent.assign(N, 0);
		dfs_low.assign(N, 0);
		articulation_vertex.assign(N,0);

		if( N == 0 ) break;
		vector<string> city;
		string tmp;
		FOR(i,N)
		{
			cin >> tmp;
			city.pb(tmp);
		}
		Sort(city);
		FOR(i,N)
		{
			I[city[i]] = i;
			K[i] = city[i];
		}

		cin >> routes;
		string A , B;
		FOR(i , routes)
		{
			cin >> A >> B;
			adj[I[A]].pb(I[B]);
			adj[I[B]].pb(I[A]);

		}

		for ( int i = 0 ; i < N ; i++)
		{
			if (dfs_num[i] == UNVISITED)
			{
				dfsRoot = i;
				rootChildren = 0;
				articulation_point(i);
				articulation_vertex[dfsRoot] = (rootChildren > 1); 
			}
		}

		vi sol;
		FOR(i , N)
			if(articulation_vertex[i])
				sol.pb(i);
		

		if(!frst) cout << endl;
		frst = false;
		cout<<"City map #"<<++T<<": "<<sol.sz()<< " camera(s) found"<< endl;
		FOR(i , sol.sz())
		{
			cout << K[sol[i]]<< endl;
		}
		
	}
}