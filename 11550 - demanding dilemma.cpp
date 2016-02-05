/*input
1
4 3
1 1 1
1 0 0
0 1 0
0 0 0
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

inline int toInt(string s){int v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

int mat[10][30];
int arr[30];

int main()
{
	int tc;
	cin >> tc;
	while ( tc--)
	{
		bool inc = true;
		cover(arr, 0);
		
		int n , m;
		cin >>n >> m;
		FOR(i, n) cover(mat[i], 0);

		FOR(i , n)
		{
			FOR(j , m )
			{
				int tmp;
				cin >> tmp;
				mat[i][j] = tmp;
				arr[j]+= tmp;

			}
		}

		FOR(i, m)
		{
			if (arr[i] != 2 )
			{
				inc = false;
				break;
			}
		}

		bool ma[10][30];
		FOR(i,n) cover(ma[i], 0);

		if(inc)
		{
			FOR(i,m)
			{	
				int u , v;
				int ind = 0;
				while(mat[ind][i] != 1) ind++;
				u = ind;
				ind++;
				while(mat[ind][i] != 1) ind++;
				v = ind;

				if(ma[u][v]) inc = false;
				else
					ma[u][v] = ma[v][u] = 1;
				
			}
		}


		if (inc) cout << "Yes"<<endl;
		else	cout << "No" << endl;



	}
}
