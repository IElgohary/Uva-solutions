/*input
1

8
2 4 5
2 1 3
0
0
0
1 3
0
1 5

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


#define FOR(i,a , b) for ( int i = 0 ; i < a ; i+=b )
#define sz()  size()
#define printArr(array,n) for(int i = 0 ; i < n ; i++) cout << array[i]<<" ";
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)

#define count(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a,d) memset(a,d,sizeof(a))


#define VISITED 1
#define UNVISITED 0
#define INF 1000000000

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}


vi adj[200];
vi color;
vector<bool> used;

int n;
int Bipartite_bfs(int source)
 {
 	queue<int> q;
 	color[source] = 1;
 	q.push(source);
 	bool Bipartite = true;
 	
 	while ( !q.empty() )
 	{
 		int u = q.front();
 		q.pop();
 		for ( int i = 0 ; i < adj[u].size(); i++)
 		{
 			int v = adj[u][i];
 			if (color[v] == INF)
 			{
 				color[v] = 1- color[u];
 				q.push(v);
 			}
 			else if( color[v] == color[u])
 				Bipartite = false;
 		}
 	}
 	
 	int blue = 0;
 	int red = 0;

 	FOR(i,n,1)
 	{
 		if(color[i] != INF && !used[i])
 		{
 			used[i] = 1;
 			if(color[i])
 				blue++;
 			else
 				red++;
 		}
 	}

 	if(!Bipartite)
 		return 0;
 	return max(blue, red);

 }


int main()
{
	int tc;
	cin >> tc;
	while(tc--)
	{
		cin >> n;
		
		FOR(i,200,1)
			adj[i].clear();
		
		FOR(i,n,1)
		{
			int num;
			cin >> num;
			FOR(j,num , 1)
			{
				int tmp;
				cin >> tmp;
				if ( tmp > n)
					continue;

				adj[i].push_back(tmp - 1);
				adj[tmp - 1].push_back(i);
			}
		}

		color.assign(n, INF);
		used.assign(n,0);
		int cnt = 0;
		FOR(i,n, 1)
			if(color[i] == INF)
				cnt += Bipartite_bfs(i);

		cout << cnt<< endl;

	}
}
	
