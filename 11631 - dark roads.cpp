/*input
7 11
0 1 7
0 3 5
1 2 8
1 3 9
1 4 7
2 4 5
3 4 15
3 5 6
4 5 8
4 6 9
5 6 11
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

#define sz size
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

class UnionFind{

private: vi p, rank;
public:
	UnionFind(int n)
	{
		rank.assign(n, 0);
		p.assign(n, 0);
		for( int i = 0 ; i < n ; i++)
			p[i] = i;
	}

	int findSet(int i)
	{ return (p[i] == i)?i:(p[i] = findSet(p[i]));}

	bool isSameSet(int i, int j)
	{return (findSet(i) == findSet(j));}

	void unionSet(int i, int j)
	{
		if(!isSameSet(i, j))
		{
			int x = findSet(i);int y = findSet(j);
			if(rank[x] > rank[y]) p[y] = x;
			else
			{
				p[x] = y;
				if(rank[x] == rank[y]) rank[y]++;
			}
		}
	}
};


int main()
{

	int m , n;
	while (cin >> m >> n)
	{

		if ( m == 0 && n == 0) break;

		int total = 0;
		vector<pair<int , ii> > edges;
		for( int i = 0; i < n ; i++)
		{
			int v , u , w;
			cin >> u >> v >> w;
			total += w;
			edges.pb(mp(w, mp(u,v)));
			//cout << edges[i].first <<' '<< edges[i].second.first <<' '<<edges[i].second.second << endl;
		}

		Sort(edges);

		int mst_cost = 0;
		UnionFind UF(m);

		for(int i = 0 ; i < n ; i++)
		{
			pair<int, ii> front = edges[i];
			if (!UF.isSameSet(front.second.first, front.second.second))
			{
				mst_cost += front.first;
				UF.unionSet(front.second.first, front.second.second);
			}
		}

		cout << total - mst_cost << endl;
	}
}