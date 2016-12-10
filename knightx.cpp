#include <iostream>
#include <queue>
#include <utility>
using namespace std;
int row;
int col;
int pr;
int pc;
int kr;
int kc;
int ary[100][100];
int main()
{
	int turns;
	cin>>turns;
	for (int i = 0 ; i < turns; i++)
	{
		cin>>row>>col>>pr>>pc>>kr>>kc;
		pr-=1;
		pc-=1;
		kr-=1;
		kc-=1;
		bool win = false;
		bool stale = false;
		int km = 0;
		for (int i = 0 ; i < row; i++)
		{
			for (int j = 0 ; j < col; j++)
			{
				ary[i][j] = -1;
			}
		}
		int pmove = 0;
		int kwin = 0;
		int kstale = 0;
        queue < pair <int,int> > buff1;
        queue < pair <int,int> > buff2;
        buff2.push(make_pair(kr,kc));
        ary[kr][kc] = 1;
        while(true)
        {
        if (pr == row-1)
        {
            break;
        }
        if (ary[pr+1][pc] == 1)

        {
            if (stale == false)
            {
                stale = true;
                kstale = km;
            }
        }
        pr++;
        pmove++;
        if (pr == row-1)
        {
            break;
        }
        for (int i = 0 ; i < row; i++)
		{
			for (int j = 0 ; j < col; j++)
			{
				ary[i][j] = -1;
			}
		}
        buff1 = buff2;
        while(!buff2.empty())
        {
            buff2.pop();
        }
        km++;
        while(!buff1.empty())
        {
            pair < int , int > v = buff1.front();
            int x = v.first;
            int y = v.second;
            buff1.pop();

            if((x+1)<row&&(y+2)<col&&ary[x+1][y+2]==-1)
            {
                ary[x+1][y+2] = 1;
                buff2.push(make_pair(x+1,y+2));
            }
            if((x+1)<row&&(y-2)>=0&&ary[x+1][y-2]==-1)
            {
                ary[x+1][y-2] = 1;
                buff2.push(make_pair(x+1,y-2));
            }
            if((x-1)>=0&&(y+2)<col&&ary[x-1][y+2]==-1)
            {
                ary[x-1][y+2] = 1;
                buff2.push(make_pair(x-1,y+2));
            }
            if((x-1)>=0&&(y-2)>=0&&ary[x-1][y-2]==-1)
            {
                ary[x-1][y-2] = 1;
                buff2.push(make_pair(x-1,y-2));
            }
            if((x+2)<row&&(y+1)<col&&ary[x+2][y+1]==-1)
            {
                ary[x+2][y+1] = 1;
                buff2.push(make_pair(x+2,y+1));
            }
            if((x+2)<row&&(y-1)>=0&&ary[x+2][y-1]==-1)
            {
                ary[x+2][y-1] = 1;
                buff2.push(make_pair(x+2,y-1));
            }
            if((x-2)>=0&&(y+1)<col&&ary[x-2][y+1]==-1)
            {
                ary[x-2][y+1] = 1;
                buff2.push(make_pair(x-2,y+1));
            }
            if((x-2)>=0&&(y-1)>=0&&ary[x-2][y-1]==-1)
            {
                ary[x-2][y-1] = 1;
                buff2.push(make_pair(x-2,y-1));
            }
        }
        if (ary[pr][pc]==1)
                {
                    if (win == false)
                    {
                        win = true;
                        kwin = km;
                        break;
                    }
                }
         if (ary[pr+1][pc] == 1)

                {
                    if (stale == false)
                    {
                        stale = true;
                        kstale = km;
                    }
                }





        }




        if (win==true)
        {
            cout<<"Win in "<<kwin<<" knight move(s)."<<endl;
        }
        else if (stale==true)
        {
            cout<<"Stalemate in "<<kstale<<" knight move(s)."<<endl;
        }
        else
        {

            cout<<"Loss in "<<km<<" knight move(s)."<<endl;

        }
	}

	return 0;
}
