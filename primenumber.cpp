// Example program
#include <iostream>
#include <cmath>
int main(){
    int i = 7;
    int j = 0;
    int result = 0;
	bool istrue = false;
    while(1)
    {
        i++;
		for (int k =2; k <= sqrt(i) ;k++)
     {
	 if (i%k !=0)
     {istrue = true;}
	 else if (i%k == 0)
	 {istrue = false;break;}
	 }
	 if (istrue == true)
	 {result = i; j++;}
	 istrue = false;
     if(j == 9997){break;}
    }
   std::cout<<result;
    return 0;
}
