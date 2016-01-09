/*input
3
6 2 SULTAN
6 1 MAHBUB
6 2 MAHBUB
*/

#include <iostream>
#include <string.h>

using namespace std;

int t , n , k, sol;
int arr[27];
string s;

int main()
{
	cin >> t;

	for ( int q = 1 ; q <= t ; q++)
	{
		
		for ( int i = 0 ; i < 27 ; i++)
			arr[i] = -1;
		
		sol = 0;
		cin >> n >> k>>s;

		for ( int i = 0 ; i < n ;i++)
		{
			char c = s[i];
			int index = c - 'A';
			//cout<< c<<" : "<< index <<" "<< arr[index]<< endl;
			
			if ( i != 0 && arr[index] > -1&& (i- arr[index]) <= k)
			{	
				sol++;
				//cout << arr[index]<<" " << i <<  endl;
				//cout << (i-index) << " "<< sol << " " << i<< endl;
			}
			
			//cout << sol << " "<< i << endl;	
			
			arr[index] = i;
		}

		cout << "Case "<< q << ": " <<  sol << endl;
	}
}