/*input
this is a test of some words to try out
a bee see dee
the of and to a in that is i it with for as
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

vi word_val;
int c , n;

bool C()
{
	FOR(i,n)
	{	
		for ( int j = i + 1; j < n ;j++)
		{
			int wi , wj;
			wi = (c/word_val[i]) % n;
			wj = (c / word_val[j]) % n;
			if ( wi == wj)
			{
				int ctmp1, ctmp2;
				ctmp1 = (c/word_val[i] + 1)* word_val[i];
				ctmp2 = (c/word_val[j] + 1) * word_val[j];
				c = min(ctmp1,ctmp2);
				return false;
			}
		}
	}
	return true;
}

int val(string word)
{
	int out = 0;
	FOR(i,word.sz())
		out = (out << 5) +(word[i] - 'a' + 1);
	return out;
}

int main()
{
	string line;
	while(getline(cin , line))
	{	
		word_val.clear();
		istringstream sin(line);
		string word;
		while(sin >> word)
			word_val.pb(val(word));
		c = 1;
		n = word_val.sz();

		while(!C());

		cout << line << endl;
		cout << c << endl;
		cout << endl;
			
	}
}