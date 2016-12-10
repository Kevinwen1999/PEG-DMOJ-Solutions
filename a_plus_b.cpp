#include <iostream>
#include <string>
using namespace std;
string a;
string b;
int main()
{
    cin>>a>>b;
    int bl = b.length();
    int al = a.length();
    if (bl>al)
    {
        swap(a,b);
        bl = b.length();
        al = a.length();
    }
        for (int i = bl ; i>=0; i--)
        {

            if ( (int)b[i]+ (int)a[al] <10 )
            {
                char* temp;
                itoa(((int)b[i]+ (int)a[al]),temp,10);
                a[al] = *temp;
                bl--;
                al--;
            }
            else
            {
                a[al] = (char)((int)b[i]+ (int)a[al]-10);
                if (al==0)
                {
                    a = "0"+a;
                    al++;
                }
                a[al-1] = (char)((int)a[al-1] +1);

            }
        }
    cout<<a<<endl;
    return 0;
}
