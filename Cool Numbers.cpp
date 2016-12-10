#include <bits/stdc++.h>
using namespace std;

int main()
{
	int a, b;
	cin>>a>>b;
	int count = 0;
	int croot = pow(a, 1.0/3);
	int cube = croot * croot * croot;
	while (cube <= b)
	{
		if (cube >= a)
		{
			int sqr = sqrt(cube);
			int sq = sqr * sqr;
			if (sq == cube)
				count++;
		}
		croot++;
		cube = croot * croot * croot;
	}
	cout<<count<<"\n";
}
