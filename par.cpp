// Example program
#include <iostream>
#include <algorithm>   
#include <vector>  
#include <string>
#include <sstream> 
using namespace std;
int main()
{
    int result = 0;
for (int i = 999; i >100; i--)
{
    for (int j = 999; j > 100; j--)
    {
        int ii = i*j;
    string bo ;
    ostringstream convert;
    convert << ii;
    bo =convert.str();
    string ob =string(bo.rbegin(),bo.rend());
    if (bo == ob)
    
    {if(ii > result)
        {result =ii ; break;}
        }
    }
    }
    cout << result;
    return 0;
}