
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

vector<string> origin;
vector<string> req;

int main()
{
	int T;
	cin >> T;
	while(T--)
	{
		origin.clear();
		req.clear();
		int n;
		cin >> n;
		cin.ignore(10000,'\n');
		FOR(i,n)
		{
			string tmp;
			
			getline(cin,tmp);
		//	cout << tmp << endl;
			origin.pb(tmp);
		}
		FOR(i,n)
		{
			string tmp;
			getline(cin,tmp);
			req.pb(tmp);
		}

		int i, j; j=i= n-1;
		while(i >= 0)
		{
			if(j == -1)break;
			
			string o,r;
			o = origin[j]; r = req[i];
			if ( o == r)
			{
				i--;j--;
			}
			else
				j--;
		}
		while(i >=0)
		{	
			cout << req[i]<< endl;
			i--;
		}
		cout << endl;
	}
}