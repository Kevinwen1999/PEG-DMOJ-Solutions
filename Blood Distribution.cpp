#include <bits/stdc++.h>
/*
 __          _________ ______   _       _   _     _                       _     _                  ___
 \ \        / /__   __|  ____| (_)     | | | |   (_)                     | |   | |                |__ \
  \ \  /\  / /   | |  | |__     _ ___  | |_| |__  _ ___   _ __  _ __ ___ | |__ | | ___ _ __ ___      ) |
   \ \/  \/ /    | |  |  __|   | / __| | __| '_ \| / __| | '_ \| '__/ _ \| '_ \| |/ _ \ '_ ` _ \    / /
    \  /\  /     | |  | |      | \__ \ | |_| | | | \__ \ | |_) | | | (_) | |_) | |  __/ | | | | |  |_|
     \/  \/      |_|  |_|      |_|___/  \__|_| |_|_|___/ | .__/|_|  \___/|_.__/|_|\___|_| |_| |_|  (_)
                                                         | |
                                                         |_|

*/
using namespace std;
int blood[10], need[10];
int t1[10], t2[10];
int tot1, tot2, tot3;
int useblood(int a, int b)
{
    int limit = min(blood[a], need[b]);
    blood[a] -= limit; need[b]-=limit;
    return limit;
}
int main()
{
    // O+ O- A+ A- B+ B- AB+ AB-
    // 0  1  2  3  4  5  6   7
    cin>>blood[1]>>blood[0]>>blood[3]>>blood[2]>>blood[5]>>blood[4]>>blood[7]>>blood[6];
    cin>>need[1]>>need[0]>>need[3]>>need[2]>>need[5]>>need[4]>>need[7]>>need[6];
    //O+ and O-
    tot1 += useblood(1,1) + useblood(0,0) + useblood(1,0);
    //A- and B-
    tot1 += useblood(3,3) + useblood(5,5) + useblood(1,5) + useblood(1,3);
    memcpy(t1,blood, sizeof blood); memcpy(t2,need, sizeof need);
    //A+ and B+
    tot2 += useblood(2,2) + useblood(3,2) + useblood(0,2) + useblood(1,2);
    tot2 += useblood(4,4) + useblood(5,4) + useblood(0,4) + useblood(1,4);
    //AB+ and AB-
    tot2 += useblood(7,7) + useblood(5,7) + useblood(3,7) + useblood(1,7);
    tot2 += useblood(6,6) + useblood(7,6)+ useblood(5,6)+ useblood(4,6)+ useblood(3,6)+ useblood(2,6)+ useblood(1,6)+ useblood(0,6);
    cout<<tot1+tot2<<"\n";
}
