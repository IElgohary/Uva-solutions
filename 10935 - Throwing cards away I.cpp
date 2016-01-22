/*input
1
8
11
13
22
27
36
39
44
47
50
0
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
#include <deque>
#include <queue>
using namespace std;


#define SSTR( x ) dynamic_cast< std::ostringstream & >( \
       ( std::ostringstream() << std::dec << x ) ).str()
#define FOR(a , b) for ( int i = a ; i < b ; i++ )
#define FOR2(a , b) for ( int j = a ; j < b ; j++ )


typedef long long ll;
typedef std::pair<int,int> ii;

int main()
{
	queue<int> deck;
	int n;
	cin >> n;
	while(n != 0)
	{

		while(!deck.empty())
			deck.pop();
		cout << "Discarded cards:";
		for ( int i = 1 ; i <= n ; i++)
			deck.push(i);
	if(deck.size() >= 2){
		
		
		cout << " "<< deck.front();
		deck.pop();
		
		deck.push(deck.front());
		deck.pop();
		for (int i = 0 ; i < n-2 ; i++)
		{
			cout << ", " << deck.front();
			deck.pop();
			deck.push(deck.front());
			deck.pop();
		}
		cout << endl;
		string s = SSTR(deck.front());
		
		cout << "Remaining card: "<< s<< endl;
		deck.pop();
	}
	else
	{
		cout << "\nRemaining card: "<< deck.front()<< endl;
	}
		cin >>n;
	}
	


}