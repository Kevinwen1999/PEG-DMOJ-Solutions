#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main()
{
    int total;
    cin>>total;
    float score[total];
    vector <string> names;
    for (int i = 0; i < total; i++)
    {

        string temp;
        cin.ignore(1024, '\n');
        getline(cin,temp,' ');
        names.push_back(temp);
        cin>>score[i];
    }
    float recorder = 0.00;
    int index = 0;
    for (int j = 0; j < total; j++)
    {
        if (score[j]>recorder)
        {
            recorder = score[j];
            index = j;

        }
    }

    cout<<names[index];

    return 0;
}
