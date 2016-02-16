/*input
3

1 A 2:33 Y 
2 B 2:33 Y 
1 A 2:33 N 
2 A 2:33 N 

1 A 2:33 Y 
2 A 2:33 Y 
1 A 2:33 N 
2 A 2:32 N 

1 A 2:33 N
1 A 2:33 Y
1 A 2:44 Y
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

inline int toint(string s){int v; istringstream sin(s);sin>>v;return v;}
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

struct submission
{
	int team;
	char p_letter;
	int time;
	char status;

	
};

struct entry
{
	int team;
	int probs;
	int time;
	entry()
	{
		probs = 0;
		time = 0;
	}
};

bool compare_time(const submission &a, const submission &b)
{
	if(a.time > b.time) return false;
	else if ( a.time != b.time) return true;
	else return a.status < b.status;

	//else	return a.team > b.team;
}

bool Compare_rank(const entry &a, const entry &b)
{
	if(a.probs < b.probs) return false;
	else if (a.probs != b.probs) return true;
	else if(a.time > b.time) return false;
	else if (a.time != b.time)	return true;
	else return a.team < b.team;
}

int split_t(string s)
{
	int out = (s[0] - '0') * 60;
	out += (s[2] - '0') * 10;
	out += (s[3] - '0');
	return out;
}

vector<submission> sub;
int teams[30][20];
bool done[30][20];

int main()
{
	int testcases;
	cin >> testcases;
	cin.ignore(10000, '\n');
	while(testcases--)
	{
		int num;
		char p, st;
		string t;
		cover(teams, 0);
		cover(done, 0);
		bool arr[50] ={0};
		sub.clear();

		int mx = 0;
		//cin.ignore(10000,'\n');
		string in;
		bool fst = true;

		while(getline(cin,in))
		{
			if(in == "" && !fst) break;
			fst = false;
			if ( in != "")
			{	istringstream sin(in);
				sin >> num >> p >> t >> st;
				//cout << num << endl;
				int tm = split_t(t);
				submission tmp;
				tmp.team = num;
				tmp.p_letter = p;
				tmp.time = tm;
				tmp.status = st;
				sub.pb(tmp);
				mx = max(mx, num);
				arr[num - 1] = true;
			}
		}

		sort(sub.begin(), sub.end(), compare_time);

		FOR(i,sub.sz())
		{
			int x = sub[i].p_letter - 'A';
			int y = sub[i].team;
			if(done[y-1][x])
				continue;
			
			if(sub[i].status == 'Y')
			{
				done[y-1][x] = 1;
				teams[y-1][x] += sub[i].time;
			}
			else
			{
				teams[y-1][x] += 20;
			}

		}

		vector<entry> ran;
		FOR(i, mx)
		{
			int total = 0;
			int probs = 0;
			FOR(j , 7)
			{
				if(done[i][j])
				{
					total += teams[i][j];
					probs++;

				}
			}
			
			entry tmp;
			tmp.team = i+1;
			tmp.time =	total;
			tmp.probs = probs;
			ran.pb(tmp);
		}
		

		sort(ran.begin(), ran.end(), Compare_rank);

		cout << "RANK TEAM PRO/SOLVED TIME" << endl;
		int prevtime = 0, prevrank = 1 , prevprob = 0;;
		FOR(i , ran.sz())
		{
			entry tmp = ran[i];
			if(tmp.probs == prevprob && prevtime == tmp.time)
			{
				cout << setw(4) << prevrank<< " " << setw(4) << tmp.team;
				if(tmp.probs)cout <<" "<< setw(4) << tmp.probs<< " "<< setw(10)<< tmp.time << endl;
				else cout << endl;
			}
			else
			{
				prevrank = i+1;
				cout << setw(4) << prevrank<< " " << setw(4) << tmp.team;
				if(tmp.probs)cout <<" "<< setw(4) << tmp.probs<< " " << setw(10)<< tmp.time << endl;
				else cout << endl;
			}
			prevtime = tmp.time;
			prevprob = tmp.probs;
			
		}
		if(testcases) 
			cout << endl;
	}


}