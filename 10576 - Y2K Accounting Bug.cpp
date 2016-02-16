
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

vector<ll> m;
ll sol, cur;

ll backtrack(ll s , ll d , int month)
{
	if(month == 12) return 0;
	m[month] =s;
	ll sur = s + backtrack(s,d,month+1);
	if(month >= 4 && m[month] + m[month-1]+m[month-2]+m[month-3]+m[month-4] > 0) sur = -INF;
	m[month] = -d;
	ll def = -d + backtrack(s,d,month +1);
	if(month >= 4 && m[month] + m[month-1]+m[month-2]+m[month-3]+m[month-4] > 0) def = -INF;
	
	return max(sur,def);
	
	
}

int main()
{
	ll s , d;
	while(cin >> s >> d)
	{
		m.assign(12,0);
		sol = 0;
		sol = backtrack(s,d,0);

		if ( sol > 0)
			cout << sol << endl;
		else cout << "Deficit" << endl;
	}
}