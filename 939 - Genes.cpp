/*input
17
Zara Elizabeth
Cooper dominant
Trong-Phe non-existent
Maya Aaraadhanaa
Albert Robert
Elizabeth Maya 
Suzanne Albert
John Alberta
Cooper Elizabeth
Suzanne Alberta
Elizabeth Robert
Suzanne dominant
John recessive
John Albert
Albert Maya
Trong-Phe Aaraadhanaa
Zara dominant
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
template<class T> inline string toString(T x) { ostringstream sout; sout << x; return sout.str();}

class Compare
{
public:
	bool operator() (ii t1 , ii t2){
		return t1>t2;
	}
	
};

#define R "recessive"
#define non "non-existent"
#define D "dominant"

map <string, pair<string, string> > parent;
map<string, string> gene;
set<string> children;

void get_gene(string s)
{
	pair <string, string> ps = parent[s];
	if(gene.count(ps.ft) && gene.count(ps.sd))
	{
		if ( gene[ps.ft] == D)
		{
			if(gene[ps.sd] != non) gene[s] = D;
			else	gene[s] = R;
		}
		else if( gene[ps.ft] == R)
		{
			if(gene[ps.sd] == non)	gene[s] = non;
			else if ( gene[ps.sd] == D) gene[s] = D;
			else	gene[s] = R; 
		}
		else
		{
			if (gene[ps.sd] == D) gene[s] = R;
			else	gene[s] = non;
		}
		return;
	}
	else if ( gene.count(ps.ft))
	{
		get_gene(ps.sd);
		get_gene(s);
		return;
	}
	else if(gene.count(ps.sd))
	{
		get_gene(ps.ft);
		get_gene(s);
		return;
	}
	else
	{
		get_gene(ps.ft);
		get_gene(ps.sd);
		get_gene(s);
		return;
	}
	

}

int main()
{
	int n;
	cin >> n;
	while(n--)
	{
		string s1 , s2;
		cin >> s1 >> s2;
		if ( s2 != R && s2 != D && s2 != non)
		{
			if(parent.count(s2))
			{	
				parent[s2].sd = s1 ;
			}
			else
			{
				parent[s2] = mp(s1, "");
				children.insert(s2);
			}
			
		}
		else
		{
			gene[s1] = s2;
		}

		
	}
		FOREACH(children)
		{
			string s = *it ;
			if(!gene.count(s))
			{
				get_gene(s);
			}
		}

		FOREACH(gene)
		{
			cout << it->ft<< " "<< it->sd << endl;
		}

}