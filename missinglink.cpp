#include<iostream>
#include<string>
#include<sstream>
#include<cmath>
using namespace std;
char pref[10] = {'0','1','2','3','4','5','6','7','8','9'};
int main()
{
    string in;
    for (int i = 0; i < 5; i++)
    {
        cin>>in;
        size_t found = in.find("_");
        int index = found;
        int number;
        bool possible = false, isprime = true;
        for (int i = 0 ; i < 10; i++)
        {
            if (index == 0 && i == 0) continue;
            if (in.size()==1 && i == 1) continue;
            in[index] = pref[i];
            string::size_type sz;
            number = stoi(in,&sz);
            isprime = true;
            for (int j = 2;j < number; j++)
            {
                if (number%j==0)
                {
                    isprime = false;
                    break;
                }
            }
            if (isprime)
            {
                possible = true;
                cout<<pref[i]<<" ";
            }
        }
        if (!possible)
        {
            cout<<"Not possible";
        }
        cout<<endl;
    }
    return 0;
}
