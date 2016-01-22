/*input
1

Red Alder
Ash
Aspen
Basswood
Ash
Beech
Yellow Birch
Ash
Cherry
Cottonwood
Ash
Cypress
Red Elm
Gum
Hackberry
White Oak
Hickory
Pecan
Hard Maple
White Oak
Soft Maple
Red Oak
Red Oak
White Oak
Poplan
Sassafras
Sycamore
Black Walnut
Willow
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
using namespace std;


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )
#define sz()  size()

typedef long long ll;
typedef std::pair<int,int> ii;

map<string, int> mp;

int main()
{
	
	int tc;
	cin >> tc;
	cin.ignore();
	cin.ignore();
	string s="";

	while ( tc--)
	{
		mp.clear();
		int total = 0;
		string line;
		
		while(getline(cin , line) && line != "")
		{
			total ++;
			if (mp.count(line))
				mp[line] ++;
			else
				mp[line] = 1;
		}

		cout << s;
		s = '\n';
		for (map<string, int>::iterator iter = mp.begin(); iter != mp.end(); ++iter)
        {
        	cout << iter->first << ' '<< setprecision(4)<< fixed << iter->second * 100.0/total<< endl;
        }

	}
}