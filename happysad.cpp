#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main()
{

string str3;
getline(cin,str3);
string str1 = ":-)";
string str2 = ":-(";
int n = 0;
int n2 = 0;
string::size_type start1 = 0;
string::size_type start2 = 0;

while ((start1 = str3.find(str1, start1)) != string::npos) 
{
    n++;
	start1 += str1.length();
} 
while ((start2 = str3.find(str2, start2)) != string::npos) 
{
    n2++;
	start2 += str2.length();
} 
if (n > n2)
{cout<<"happy";}
 if (n < n2)
{cout<<"sad";}
 if (n==0&&n2==0)
{cout<<"none";}
 if (n == n2&&n != 0&&n2 != 0)
{cout<<"unsure";}
return 0;
}
