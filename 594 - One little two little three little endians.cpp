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

inline int toint(string s){ll v; istringstream sin(s);sin>>v;return v;}
inline ll toll(string s){ll v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}
template<class T> inline char toChar(T x) { ostringstream sout; sout << x; return sout.str()[0];}


class Compare
{
public:
	bool operator() (ii t1 , ii t2){
		return t1>t2;
	}
	
};


int main()
{
	int n;
	while(cin >> n)
	{
		bitset<32> b1(n) , b2;
		FOR(i , 8)
			b2[i] = b1[24 +i];
		FOR(i , 8)
			b2[8 + i] = b1[16 + i];
		FOR(i, 8)
			b2[16 + i] = b1[8 +i];
		FOR(i , 8)
			b2[24+i] = b1[i];

		int o1,o2;
		o1 = static_cast<int>(b1.to_ulong());
		o2 = static_cast<int>(b2.to_ulong());	
		cout << o1 << " converts to "<< o2<< endl;
		
	}
}
