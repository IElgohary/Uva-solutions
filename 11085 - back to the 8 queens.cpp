/*input
7 3 2 1 4 6 5 8
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

int row[8],cur[8];

bool place(int r, int c) 
{
  for (int prev = 0; prev < c; prev++)
    if (cur[prev] == r || (abs(cur[prev] - r) == abs(prev - c)))
      return false;
  return true; 
}

int check(int c)
{
	if ( c == 8) return 0;

	int res = INF;

	for (int r = 0; r < 8; r++)                       
	    if (place(r,c)) 
	    {          
	      cur[c] = r;
	      if(row[c] == r)
	      	res = min(res,check(c+1));
	      else
	      	res = min(res,1 + check(c+1));
	  	}
	return res;
}

int main()
{
	int t = 1;
	string line;
	while (getline(cin , line))
	{
		istringstream sin(line);
		for(int i = 0 ; i < 8; i++)
		{ 
			sin >> row[i];
			row[i]--;
			cur[i] = row[i];
		}
		
		int out = check(0);
		cout << "Case "<< t++ << ": "<< out << endl;
	}
}
