/*input
10
3
3 1 1 2
2 4 5
3 4 2 6
3
3 2 2 2
2 4 4
3 5 5 5
3
3 0 1 0
2 4 10000
3 4 2 2
0
1
0
1
1 1
3
3 1 1 2
2 4 4
3 4 2 6
4
0
0
0
1 444
4
10 2 2 2 2 2 2 2 2 2 3
2 2 2
3 2 2 2
1 2
5
2 1 5
2 2 4
2 3 3
2 4 2
2 5 1
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
#define is_in(container, element) (container.find(element) != container.end())

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

inline int toint(string s){ll v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

class Compare
{
public:
	bool operator() (ii t1 , ii t2){
		return t1>t2;
	}
	
};

int un[15000];
vi arr[60];
int main()
{
	int k;
	cin >> k;
	FOR(c , k)
	{
		vector<float> sol;
		int n;
		cin >> n;

		FOR(i , n) arr[i].clear();
		cover(un, 0);

		FOR(i , n)
		{
			int m;
			cin >> m;
			set<int> st;
			FOR(j , m)
			{
				int tmp;
				cin >> tmp;
				arr[i].pb(tmp);

				if(!is_in(st,tmp))	
				{
					st.insert(tmp);
					un[tmp]++;
				}
				
			}
		}

		double unique = 0;
		FOR(i , n)
		{
			int cnt = 0;
			set<int> st;
			FOR(j, arr[i].sz())
			{	
				if(un[arr[i][j]] == 1)
				{
					if(!is_in(st, arr[i][j]))
					{	
						cnt++;
						unique++;
						st.insert(arr[i][j]);
					}
				}
			}
			sol.pb(cnt);
		}

		int k = c+1;
		printf("Case %d:",k);
		FOR(i , n)
		{
			double per = sol[i] * 100.0 / unique;
			printf(" %.6lf%%", per);

		}
		cout << endl;
	}
}