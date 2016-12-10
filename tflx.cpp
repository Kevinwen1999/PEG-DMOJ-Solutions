#include <iostream>
#include <cmath>

using namespace std;

int main()
{
        int i, n;
        cin >> n >> i;
        for (int a = 0; a < n; a++)
        {
            if (i < 192)
                cout << 192<<endl;
            else
            {
                cout<<(192 +  ceil(( i - 192 ) / 250.0 ) * 250) << endl;
                cin >> i;
            }

        }
        return 0;
}
