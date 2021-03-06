/*input
2 26 6
4 10
16 14
10 6 37
20 4
19 20
19 2
8 4
7 19
7 14
3 17
1 19
18 1
15 19

*/

#include <stdio.h>
#include <cmath>
#include <stdlib.h>
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
	
double Eps = 1e-7;	

struct interval
{
	double ft,rg;
};

bool Compare1(const interval &a ,const interval &b)
{
	if (a.ft +Eps < b.ft ) return true;
	else if ( abs(a.ft - b.ft) > Eps) return false;
	else return a.rg > b.rg +Eps; 

}

vector<interval> spr;

int main()
{
	int n , l , w;
	while ( cin >> n >> l >> w)
	{
		spr.clear();
		double dw = (double(w*w)/4.0), dx = 0;
		int x , r;
		FOR(i , n)
		{
			cin >> x >> r;	
			double d = (double)(r)*r - dw;
			if(d > 0)
				dx=sqrt((double)(r)*r - dw);
			else dx = 0;
			interval tmp;
			tmp.ft = x - dx; tmp.rg = x + dx;
			//cout << x <<" "<<r <<" "<<dx<<" "<<tmp.ft << " "<<tmp.rg <<endl;
			spr.pb(tmp);
		}

		sort(spr.begin(), spr.end(),Compare1);
		//cout << spr[0].ft << " "<< spr[0].rg<<endl;
		double end = 0.0, far = 0.0;
		int res = 0,j = 0;
		for(int i = 0 ; i < n;i =j)
		{	
			//cout << i << " " << j<< endl;
			far = 0;
			while( j < n && spr[j].ft < end+ Eps )
			{
				//cout << j << endl;
				if(spr[j].rg > far+ Eps )
				{
					far = spr[j].rg;
				}
				j++;
			}
			end = far;
			res++;
			if(j == i || l  < end +Eps) break;
			
		}
		
		if ( end +Eps> l )
			cout << res << endl;
		else	cout << -1<< endl;

	}
}