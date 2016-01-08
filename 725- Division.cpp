/*input
50
29
2
46
44
80
80
75
3
27
14
33
46
67
5
79
27
73
3
60
74
66
25
14
74
26
17
23
27
47
0
*/
#include <bits/stdc++.h>

using namespace std;
int n;
int a;
int b;
bool flag;
bool first = true;

int main()
{
	while(true)
	{
		cin>> n;
		if(n == 0)
			break;
		if (!first) cout << endl;
		flag = true;
		for (a = 1234; a <= 98765/n; a++)
		{
			b = a * n;
			int tmp, used = (a < 10000);
			tmp = a;
			while(tmp){used |= 1 << (tmp%10) ; tmp/=10;}
			tmp = b;
			while(tmp){used |= 1 << (tmp%10); tmp /= 10;}

			if(used == (1<<10)-1) 
			{
				printf("%0.5d / %0.5d = %d\n", b, a, n);
				flag = false;
				
			}
		}
		first = false;
		if (flag)
		{
			cout <<"There are no solutions for "<<n<<'.'<<endl;
		} 
	}

}
