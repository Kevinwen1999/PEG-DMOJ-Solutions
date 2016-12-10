#include<iostream>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
//<2><4><2><3><1><4><4><4><1><3><2>
int main()
{
  int input1 = 0;
  cin>>input1;
  for (int a =0; a < input1; a++)
  {
    int input2 = 0;
	cin>>input2;
	stack<int> ary;
	vector<int> finall;
	stack<int> branch;
	bool isSorted = false;
	for (int b = 0; b < input2; b++)
	  {
	  int c;
	  cin>>c;
	  ary.push(c);
	  }
	int smallest = 0;
	while (!ary.empty())
	  {
	    smallest++;
		if (ary.top()==smallest)
		  {
		    finall.push_back(ary.top());
			ary.pop();
		  }
		else if (!branch.empty()&&branch.top()==smallest)
		  {
		    finall.push_back(branch.top());
			branch.pop();
		  }
		else 
		  {
		    branch.push(ary.top());
			ary.pop();
			smallest--;
		  }
	  }
	  if (!branch.empty())
	    {
		  while(!branch.empty())
		    {
			  finall.push_back(branch.top());
			  branch.pop();
			}
		}
	  for (int k = 0; k < input2-1;k++)
        {
          if (finall[k]<=finall[k+1])
		    {
			  isSorted=true;
			}
		  else
            {
              isSorted = false; break;
            }			
        }		
     if (isSorted) 
      {
        cout<<"Y"<<endl;
      }
    else if (!isSorted)
      {
        cout<<"N"<<endl;
      }
   } 
  
return 0;
}
