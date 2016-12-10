    #include <iostream>
    #include <string>
    #include <algorithm>
    /*
    3
    k+2 = 5
    i+2, i+3
    100011
    010011
    1000000011
    0111000000
    */
    using namespace std;
    int N, n, k;
    int main()
    {
        cin>>N;
        while(N--)
        {
            cin>>n>>k;
            cout<<"The bit patterns are:"<<endl;
            string nbit;
            for (int i = 0 ; i < n; i++)
            {
                if (i<k)
                    nbit.push_back('1');
                else
                    nbit.push_back('0');
            }
            bool isten = true;
            string sample = "10";
            cout<<nbit<<endl;
            while(1)
            {
                bool isone = false;
                if (nbit[n-1]=='1')
                    isone = true;
                size_t found = nbit.rfind(sample);
                if (found!=string::npos)
                {
                    swap(nbit[found],nbit[found+1]);
                    if (isone)
                    {
                        for (int i = 1; i<=k-1&&(found+1+i)<n-1; i++)
                        {
                            swap(nbit[found+1+i],nbit[n-i]);
                        }
                        cout<<nbit<<endl;
                    }
                    else
                        cout<<nbit<<endl;
                }
                else
                    break;
            }
            cout<<endl;
        }
    }
