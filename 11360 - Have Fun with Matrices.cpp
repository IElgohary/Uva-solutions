/*input
2
4
1234
5678
1234
5678
1
transpose
3
120
129
120
1
col 1 2
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
template<class T> inline char toString(T x) { ostringstream sout; sout << x; return sout.str()[0];}

class Compare
{
public:
	bool operator() (ii t1 , ii t2){
		return t1>t2;
	}
	
};

vector<string> mat;
int n;

void inc()
{
	FOR(i , n)
	{
		FOR(j , n)
		{
			char tmp = mat[i][j];
			if(tmp == '9') tmp = '0';
			else tmp++; 
			mat[i][j] = toString(tmp);
		}
	}
}
void dec()
{
	FOR(i , n)
	{
		FOR(j , n)
		{
			char tmp = mat[i][j];
			if(tmp == '0') tmp = '9';
			else tmp--;

			mat[i][j] = toString(tmp);
		}
	}
}
void row(int a, int b)
{
	a--;b--;
	string tmp = mat[a];
	mat[a] = mat[b];
	mat[b] = tmp;
}
void col(int a, int b)
{
	a--;b--;
	FOR(i , n)
	{
		char tmp = mat[i][a];
		mat[i][a] = mat[i][b];
		mat[i][b] = tmp;
	}
}

void trans()
{
	bool t[20][20] = {0};
	FOR(i , n)
	{
		FOR(j , n)
		{
			
			if(i == j) {t[i][j] = true;continue;}
			if(!t[i][j])
			{
				char tmp = mat[i][j];
				mat[i][j] = mat[j][i];
				mat[j][i] = tmp;
			}

			t[i][j] = true;
			t[j][i] = true;

		}
	}
}

int main()
{
	int t;
	cin >> t;
	FOR(c, t)
	{
		cin >> n;
	 	mat.clear();

		FOR(i , n)
		{
			string tmp;
			cin >> tmp;
			mat.pb(tmp);
		}

		int m;
		cin >> m;
		FOR(i , m)
		{
			string order;
			cin >> order;
			if(order == "transpose")
			{
				trans();
			}
			else if(order == "row")
			{
				int a , b;
				cin >> a >> b;
				row(a, b);
			}
			else if(order == "col")
			{
				int a , b;
				cin >> a >> b;
				col(a,b);

			}
			else if(order == "inc")
			{
				inc();
			}
			else
			{
				dec();
			}
		}

		cout <<"Case #"<< (c+1)<< endl;
		FOR(i , n)
			cout << mat[i] << endl;
			cout << endl;

	}
}