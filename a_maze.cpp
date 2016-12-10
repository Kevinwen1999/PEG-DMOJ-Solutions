#include<iostream>
using namespace std;
int curmin = 999999;
char**maze;
int**visited;
int rowx;
int colx;
bool isPossible = false;
void bfs(int i, int j,int counter,int layer)
{
    if (i<rowx&&j<colx&&i>=0&&j>=0&&visited[i][j]>layer)
    {


    if (maze[i][j]=='*')
    {
        return;
    }
    if (maze[i][j]=='+')
    {
        counter++;
        layer++;
        visited[i][j]=layer;
        if (i==(rowx-1)&&j==(colx-1))
        {
            isPossible = true;
            if (counter<curmin)
            {
                curmin = counter;
            }
            return;
        }
        bfs(i+1,j,counter,layer);
        bfs(i,j+1,counter,layer);
        bfs(i-1,j,counter,layer);
        bfs(i,j-1,counter,layer);
    }
    if (maze[i][j]=='-')
    {
        counter++;
        layer++;
        visited[i][j]=layer;
        if (i==(rowx-1)&&j==(colx-1))
        {
            isPossible = true;
            if (counter<curmin)
            {
                curmin = counter;
            }
            return;
        }
        bfs(i,j+1,counter,layer);
        bfs(i,j-1,counter,layer);
    }
    if (maze[i][j]=='|')
    {
        counter++;
        layer++;
        visited[i][j]=layer;
       if (i==(rowx-1)&&j==(colx-1))
        {
            isPossible = true;
            if (counter<curmin)
            {
                curmin = counter;
            }
            return;
        }
        bfs(i+1,j,counter,layer);
        bfs(i-1,j,counter,layer);
    }


    }
    else
    {
        return;
    }
}
int main()
{
    int times;
    cin>>times;
    for (int i = 0; i < times; i++)
    {

        cin>>rowx;
        cin>>colx;
        maze = new char*[rowx];
        for (int i = 0; i < rowx; i++)
        maze[i] = new char [colx];
        visited = new int*[rowx];
        for (int i = 0; i < rowx; i++)
        visited[i] = new int [colx];
        for (int i = 0; i < rowx; i++)
        {

            for (int j = 0; j < colx; j++)
            {
                cin>>maze[i][j];
            }
        }
        for (int i = 0; i < rowx; i++)
        {

            for (int j = 0; j < colx; j++)
            {
                visited[i][j]=999;
            }
        }
        bfs(0,0,0,0);
        if (isPossible==true)
        {
            cout<<curmin<<endl;
        }
        else
        {
            cout<<-1<<endl;
        }
        curmin = 99999;
        isPossible = false;
        free(maze);
        free(visited);


    }

    return 0;
}
