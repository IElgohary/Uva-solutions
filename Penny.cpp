#include <iostream>
#include <map>
using namespace std;

int main()
{

    int TC;
    map <string,int> m;



    cin>> TC;

    while(TC--)
    {
        m["TTT"] =  0;
        m["TTH"] =  0;
        m["THT"] =  0;
        m["THH"] =  0;
        m["HTT"] =  0;
        m["HTH"] =  0;
        m["HHT"] =  0;
        m["HHH"] =  0;

        int n;
        string in;
        cin >> n;
        cin>> in;

        for ( int i = 0; i < 38 ; i++)
        {
            m[in.substr(i,3)]++;
        }

        cout<< n<< " " <<m[ "TTT"]<< " " <<m["TTH"]<<" " << m["THT"]<< " " << m["THH"]<< " " << m["HTT"]<< " "<< m["HTH"]
        << " "<< m["HHT"]<< " "<< m["HHH"]<< '\n';


    }

    return 0;
}
