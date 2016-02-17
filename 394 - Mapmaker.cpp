/*input
3 4
ONE       1500 2 2 0 3 1 5
TWO       2000 4 3 1 4 0 5 5 10
THREE     3000 1 1 1 9
ONE       2 4
THREE     7
TWO       2 0 6
TWO       3 3 9
*/
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

map<string, int> m;
map<int,string> k;

struct ARR
{
	int B,D,CD,Co;
	ii arr[15];
	int cons[15];

};


int main()
{
	int n , r;
	string tmp;
	ARR tmpa;
	ii tmpp;
	cin >> n >> r;
	int cnt = 0;
	vector<ARR> va;

	FOR(i , n)
	{
		cin >> tmp;
		m[tmp] = cnt++;
		cin >> tmpa.B >>tmpa.CD >>tmpa.D;
		FOR(j , tmpa.D)
		{
			cin >> tmpp.ft >> tmpp.sd;
			tmpa.arr[j] = tmpp;
			tmpa.cons[j] = 0;
		}

		tmpa.cons[tmpa.D] = tmpa.CD;
		for (int j = tmpa.D -1 ; j > 0 ; j--)
			tmpa.cons[j] = tmpa.cons[j+1] * (tmpa.arr[j].sd - tmpa.arr[j].ft +1);
		
		tmpa.cons[0] = tmpa.B;

		for (int j = 1 ; j <= tmpa.D; j++)
			tmpa.cons[0] -= tmpa.cons[j] * tmpa.arr[j-1].ft;
		
		va.pb(tmpa);
	}

	FOR(i , r)
	{
		cin >> tmp;
		tmpa = va[m[tmp]];
		cout << tmp<<"[";
		int res = tmpa.cons[0];
		FOR(j,tmpa.D)
		{
			if(j) cout << ", ";
			int ind;
			cin >> ind;
			cout << ind;
			res += tmpa.cons[j+1] * ind;
		}	

		cout << "] = " << res <<endl;

	}

}