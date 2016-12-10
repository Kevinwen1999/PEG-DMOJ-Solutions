#include <iostream>
#include <cmath>
using namespace std;
double sx, sy, b, slope, y, dist;
int w, h;
int main()
{
    cin>>w>>h>>sx>>sy;
    slope = sy/(w-sx);
    b = -slope * sx;
    for (int x = 2 * w; ; x += w)
    {
        y = slope*x+b;
        if (y - (floor(y / h) * h)==sy)
        {
            cout<<"0"<<endl;
            return 0;
        }
        dist = y - (floor(y / h)) * h;
        if (dist < 5.0)
        {
            if (dist == 0.0)
            {
                cout<<(x/w) + floor(y / h)-2<<endl;
            }
            else
            {
                cout<<(x/w) + floor(y / h)-1<<endl;
            }
            break;
        }
    }
    return 0;
}
