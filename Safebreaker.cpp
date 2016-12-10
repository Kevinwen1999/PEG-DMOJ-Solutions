#include <bits/stdc++.h>
using namespace std;
int N;
string s[11], o[11];
multiset <int> t;
int arr[11], cur[11];
int main()
{
    int T; cin>>T;
    while (T--)
    {
        cin>>N;
        for (int i = 0; i < N; i++)
        {
            cin>>s[i]>>o[i];
        }
        int solution = 0;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 0; j < 10; j++)
            {
                for (int k = 0; k < 10; k++)
                {
                    for (int l = 0; l < 10; l++)
                    {
                        bool ok = true;
                        arr[0] = i; arr[1] = j; arr[2] = k; arr[3] = l;
                        for (int m = 0; m < N; m++)
                        {
                            t.clear();
                            t.insert(i);t.insert(j);t.insert(k);t.insert(l);
                            int correct = 0, misplace = 0;
                            for (int n = 0; n < 4; n++)
                            {
                                int d = s[m][n] - '0';
                                if (d == arr[n])
                                {
                                    correct++;
                                }
                            }
                            for (int n = 0; n < 4; n++)
                            {
                                int d = s[m][n] - '0';
                                if (t.count(d) > 0)
                                {
                                    misplace++;
                                    multiset <int> :: iterator it = t.lower_bound(d);
                                    t.erase(it);
                                }
                            }
                            /*if (i == 3 && j == 4 && k == 1 && l == 1)
                            {
                                cout<<correct<<"/"<<misplace<<endl;
                            }*/
                            if (correct != o[m][0]-'0' || misplace- correct!= o[m][2]-'0')
                                ok = false;
                        }
                        if (ok)
                        {
                            solution++;
                            for (int i = 0; i < 4; i++)
                                cur[i] = arr[i];
                        }
                    }
                }
            }
        }
        if (solution==0)
            cout<<"impossible\n";
        else if (solution == 1)
        {
            for (int i = 0; i < 4; i++)
                cout<<cur[i];
            cout<<"\n";
        }
        else
            cout<<"indeterminate\n";
    }
}
