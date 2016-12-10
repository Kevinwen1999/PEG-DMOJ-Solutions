#include <iostream>

using namespace std;

bool isTrue = false;
int num2;
/*
bool rec(int index, int k){
    if(index == N) return false;
    if(k == 0) return true;
    return rec(index+1,k) || rec(index+1, k-arr[index]);
}


(0+1+2)+3
(0+1)+2  (0+1)+3         (1+2)+3
(0)+1 (0)+2 (0)+3          1+2 1+3     2+3
[0] [1] [2] [3]             1           2         3
*/
void checksum(int ary[],int m,int n,int recorder)
{
    if (recorder == num2)
            {
                isTrue=true;
            }
    for (int i = m+1; i <= n; i++)
    {
        int num = recorder;
        if (i==n)
        {
            num +=ary[i];
            if (num == num2)
            {
                isTrue=true;
            }
        }
        if (i < n)
        {
            num +=ary[i];
            if (num == num2)
            {
                isTrue=true;
            }
            checksum(ary,i,n,num);
        }
    }
}

int main()
{
    int num1;
    cin>>num1;
    cin>>num2;
    int n = num1 - 1;

    int* ary = new int[num1];
    for (int i = 0;i <=n;i++)
    {
        cin>>ary[i];
    }
        if (num2 == 0)
    {
        cout<<"Y";
        return 0;

    }
    for (int j = 0; j <=n; j++)
    {
        checksum(ary,j,n,ary[j]);
    }
if (isTrue==true)
           {cout<<"Y";}
           else
           {cout<<"N";}
    return 0;
}
