/*input
3
1 2 0
2 2 0
3 1 2 0
0
2 1 2
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
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )
#define sz()  size()
#define printArr(array,n) for(int i = 0 ; i < n ; i++) cout << array[i]<<" ";
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)
#define count(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a,d) memset(a,d,sizeof(a))


#define VISITED 1
#define UNVISITED 0

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

vi visited;
vi adj[105];

void dfs(int u)
{
 	
 	FOR(0, adj[u].size())
	{
 		int v = adj[u][i];
 		if ( visited[v] == UNVISITED)
 			visited[v] = VISITED, dfs(v); 

	}
}


int main()
{
	int n;
	cin >> n;
	
	while (true)
	{
		if ( n == 0)
			break;
		
		FOR(0,n)
			adj[i].clear();	

		int i;
		cin >> i;
		while (i)
		{
			int j;
			cin >> j;
			while(j)
			{
				adj[i-1].push_back(j-1);
				cin >> j;
			}
			cin >> i;
		}

		int num;
		cin >> num;
		while (num--)
		{	
			visited.assign(n , UNVISITED);

			int u;
			cin >> u;
			dfs(u-1);
			vi sol;

			FOR(0, n)
				if(visited[i] == UNVISITED)
					sol.push_back(i+1);
					
			cout << sol.size();
			FOR(0, sol.size())
				cout << ' '<< sol[i];
			
			cout << endl;
		}

		cin >> n;
	}

	
}