#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    bool yes = false;
    for(int i = 0 ; i < s.length(); i++)
    {
        if ( s[i] == 'H' || s[i] == 'Q' || s[i] == '9' )
        {
            yes = true;
            break;
        }
    }

    if ( yes)
        cout<< "YES";
    else
        cout<< "NO";
    return 0;
}
