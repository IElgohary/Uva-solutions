/*input

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


int main()
{
	priority_queue<ii, vector<ii>, Compare> pq;
	map<int , int> m;
	m.clear();
	while(!pq.empty()) pq.pop();

	string s;
	int x , y;
	while(cin >> s)
	{
		if ( s == "#") break;
		cin >> x >> y;
		ii p = mp(y , x);
		m[x] = y;
		pq.push(p);
	}

	int n;
	cin >> n;
	while(n--)
	{
		ii p = pq.top(); pq.pop();
		cout << p.sd << endl;
		p.ft = p.ft + m[p.sd];
		pq.push(p);

	}

}