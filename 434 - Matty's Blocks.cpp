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

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		int k;
		cin >> k;
		int f[15], r[15];
		bool vis[2][15] = {0};
		FOR(i,k) cin >> f[i];
		FOR(i,k) cin >> r[i];
		int mn = 0;
		FOR(i ,k)
		{
			FOR(j , k)
			{
				if(f[i] == r[j] && !vis[0][i] && !vis[1][j])
				{
					mn += f[i];
					vis[0][i] = 1;
					vis[1][j] = 1;
				}
			}
		}
		FOR(i,k)
		{
			if(!vis[0][i]) mn+= f[i];
			if(!vis[1][i]) mn += r[i];
		}
		//cout << mn << endl;
		int mx = 0;
		FOR(i , k)
		{
			FOR(j , k)
			{
				mx += min(f[i], r[j]);
			}
		}	
		//cout << mx << endl;
		int add = mx - mn;
		cout << "Matty needs at least "<< mn <<" blocks, and can add at most "<< add <<" extra blocks."<< endl;
	}
}