/*input
3
 
3 2
1 2 2 5
2 3 3 6
2
1 3
1 3
 
4 2
1 2 5 2
2 3 6 3
1
1 4
 
5 5
1 2 2 3
1 2 2 4
2 3 5 1
2 3 3 6
4 5 6 7
20
1 2
1 3
1 4
1 5
2 1
2 3
2 4
2 5
3 1
3 2
3 4
3 5
4 1
4 2
4 3
4 5
5 1
5 2
5 3
5 4
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

int t;
pair<ll,ll> mat[100][100];

int main()
{
	cin >> t;
	cin.ignore();
	while ( t--)
	{
		FOR(i , 100)FOR(j,100)
		{
			if(i == j) mat[i][j] = mp(0,0);
			else	mat[i][j] = mp(INF, INF);
		}
		int places , roads;
		cin >> places >> roads;

		FOR(i, roads)
		{
			int a , b , c , d;
			cin >> a >> b >> c >>d;
			if( a > places || b > places) continue;
			if(c < mat[a-1][b-1].ft || (c == mat[a-1][b-1].ft && d < mat[a-1][b-1].sd))
				mat[a-1][b-1] = mat[b-1][a-1] = mp(c , d);
			
		}

	for (int k = 0; k < places; k++) 
 		for (int i = 0; i < places; i++) 
 			for (int j = 0; j < places; j++)
 			{
 				if(mat[i][j].ft > mat[i][k].ft + mat[k][j].ft)
 				{
 					mat[i][j].ft = mat[i][k].ft + mat[k][j].ft;
 					mat[i][j].sd = mat[i][k].sd + mat[k][j].sd;

 				}
 				else if(mat[i][j].ft == mat[i][k].ft + mat[k][j].ft && mat[i][j].sd >mat[i][k].sd + mat[k][j].sd)
 				{
 					mat[i][j].sd = mat[i][k].sd + mat[k][j].sd;
 				}
 				
 			}

		int query;
		cin >> query;
		FOR(i , query)
		{
			int a , b;
			cin >> a>>b;
			a--;b--;
			if(mat[a][b].ft != INF && mat[a][b].sd != INF)
				cout << "Distance and time to reach destination is "<< mat[a][b].sd<<" & "<< mat[a][b].ft<<'.'<< endl;
			else
				cout << "No Path."<<endl;
		}
		if(t)cout << endl;
	}
	
}