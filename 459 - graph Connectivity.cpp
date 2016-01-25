/*input
7

E
AB
CE
DB
EC

G
AB
CE
DB
EC
EF
GG

Z
AC
AD
AE
AI
AL
AM
AN
AO
AQ
AS
AV
AW
AX
AY
BF
BH
BJ
BK
BL
BM
BN
BO
BP
BQ
BR
BU
BV
BW
BY
CE
CG
CI
CJ
CM
CP
CT
CU
CV
CY
DF
DG
DJ
DK
DL
DM
DN
DO
DQ
DV
DX
EF
EH
EK
EL
EM
EN
EO
ER
ES
ET
EU
EY
EZ
FG
FH
FI
FJ
FM
FN
FO
FP
FR
FU
FW
FY
FZ
GH
GL
GM
GP
GQ
GR
GS
GZ
HI
HJ
HK
HL
HQ
HR
HS
HV
HW
HY
IK
IM
IO
IP
IR
IU
IV
IX
IY
IZ
JK
JL
JM
JN
JR
JW
KM
KO
KP
KR
KS
KX
KY
KZ
LO
LP
LQ
LR
LY
MN
MO
MP
MR
MT
MU
MV
MX
MZ
NP
NR
NT
NV
NY
OQ
OV
OW
OX
PR
PS
PT
PV
PW
PX
PY
PZ
QR
QT
QV
QY
RT
RU
RW
RY
RZ
ST
SV
SZ
TX
TY
TZ
UW
UY
UZ
VW
WZ
XY
XZ

E
AE
EC
CB
BD

F
AB
BC
CA
DE
EF
FD

Z

C
AB

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
#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )
#define sz()  size()
#define printArr(array,n) for(int i = 0 ; i < n ; i++) cout << array[i]<<" ";
#define FOREACH(l) for (auto it = l.begin(); it != l.end(); it++)
#define count(i) __builtin_popcount(i)
#define Sort(v) sort(v.begin(),v.end())
#define cover(a,d) memset(a,d,sizeof(a))


#define VISITED 1
#define UNVISITED 0

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<int> vi;

vector<char> adj[27];
vi visited;

void dfs(int u)
{
	visited[u] = VISITED;
	for( int i = 0 ; i < adj[u].size(); ++i)
	{
		int v = adj[u][i];
		if ( visited[v] == UNVISITED)
			dfs(v);
	}

}

int main()
{
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();

	while ( tc--)
	{
		char largest;
		cin >> largest;
		
		string edge;
		FOR(0, 28)
			adj[i].clear();
		cin.ignore();
		visited.assign(26, UNVISITED);
		
		while(getline(cin , edge) && edge != "")
		{

			int u , v;
			u = edge[0] - 'A';
			v = edge[1] - 'A';
			adj[u].push_back(v);
			adj[v].push_back(u);

		}

		int lim = largest - 'A';
		int count = 0;
		FOR(0, lim+1)
		{
			if(visited[i] == UNVISITED)
			{
				count++;
				dfs(i);
			}
		}	
		cout << count << endl;
		if(tc)cout << endl;
	}	
}