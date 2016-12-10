#include <iostream>
using namespace std;

int main() {
 	int bars;
	int rate;
	cin>>bars>>rate;
	int sword =0;
	sword += bars;
	while(bars>0)
	{
		int times = 0;
		while((bars)>0&&(bars>rate))
        {


            bars=-rate;
            //cout<<"sss"<<bars<<endl;
            if (bars>=0)
            {times ++;}

        }
        //cout<<bars<<endl;
        sword+=times;
        bars += times;
        //cout<<"after<<"<<bars <<endl;

	}
	cout<<sword;
	return 0;
}
