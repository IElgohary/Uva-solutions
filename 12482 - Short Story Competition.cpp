/*input
14 4 20
Se mana Piedade tem casado com Quincas Borba apenas me daria uma esperanca colateral
16 3 30
No dia seguinte entrou a dizer de mim nomes feios e acabou alcunhando me Dom Casmurro
5 2 2
a de i de o
5 2 2
a e i o u
*/

#include <cmath>
#include <string.h>
#include <iostream>
using namespace std;

#define FOR(a , b) for (int i = a ; i < b ; i++)


int n  , c,l;
string word;
int len[1005];

int main()
{
	while ( cin >> n >> l >> c)
	{
		for ( int i = 0 ; i < n ;i++)
		{
			cin >> word;
			len[i] = word.size();
		}

		int size;
		double lines = 0;

		for ( int i = 0 ; i < n ;)
		{	
			size = 0;	
			while (i< n && size + len[i] <= c)
			{
				size += len[i] + 1;
				i++;
			}
			lines++;
			//cout <<"line: "<< lines<< endl;
	
		}

		cout << ceil(lines/l) << endl;
	
		
	}
}
