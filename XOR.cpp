#include <iostream>
using namespace std;
int cnt;
int main()
{
    int N;
    cin>>N;
    while (N--)
    {
      long long  S, F;
      cin>>S>>F;
      if (S==F)
      {
          cout<<S<<endl;
          continue;
      }
      int rep = S;
      if (rep%2==0)
      {
          for (int i = 1; i <=3; i++)
          rep = rep^(S+i);
          cnt = (F+1) - (S+3);
      }
      else
      {
          for (int i = 1; i <=2; i++)
          rep = rep^(S+i);
          cnt = (F+1) - (S+2);
      }
      int place = cnt%4;
      if (place == 0) place = 4;
      int start = F - place +1;
      for (int i = 0 ; i < place-1; i++)
      {
          start+=1;
          rep = rep^start;
      }
      cout<<rep<<endl;
    }
    return 0;
}
