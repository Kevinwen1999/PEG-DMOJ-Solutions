#include<iostream>
#include<string>
using namespace std;
bool check (string inputx)
{
    bool isTrue = false;
    if(inputx.length()==1)
    {
        if (inputx=="A")
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
    if (inputx[0]=='B'&&inputx[inputx.size()-1]=='S')
    {
        int startx = inputx.find("B");
        int endx = inputx.find_last_of("S");
        if (check(inputx.substr(startx+1,endx-startx-1))==true)
        {
            isTrue=true;
        }

    }
    if (inputx.find("N") != string::npos)
    {
        std::string::size_type startpo = 0;
        while (string::npos !=( startpo = inputx.find( "N", startpo) ) )
        {
            if (check(inputx.substr(0,startpo))==true&&check(inputx.substr(startpo+1,string::npos))==true)
            {
            isTrue = true;
            }
            ++startpo;
        }

    }
    if (isTrue == true)
    {
        return true;
    }
    else
    {
        return false;
    }
    }

}
int main()
{
    while(1)
    {
    string inputx;
    cin>>inputx;
    if(inputx=="X")
    {
        return 0;
    }
    if (check(inputx)==true)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    }
    return 0;
}
