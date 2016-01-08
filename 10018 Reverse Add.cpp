/*input
2
3
11
*/

#include <bits/stdc++.h>
using namespace std;



long long revm(long long a)
{
	int length = log10(a);
	long long rev=0;
	while ( a > 0)
	{
		rev += (a%10)*pow(10,length);
		length--;
		a/= 10;
	}
	return rev;
}

bool pal(long long n)
{
	long long rev = revm(n);
	if (n - rev)
		return false;
	return true;
}


int main()
{
	int n ;
	cin >> n;
	while(n--)
	{
		long long num,sum;
		cin >> num;
		int i = 1;
		while (true)
		{
			int length = log10(num);
			sum = 0; 
			long long rev = 0;
			
			rev = revm(num);
			//cout << rev << endl;
			sum = rev + num;
			if (pal(sum))
				break;
			num = sum;	
			i++;

		}
		cout << i << " "<< sum<<endl;

	}
	
}