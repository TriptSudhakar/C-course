#include<iostream>
using namespace std;
bool rat_in_a_maze(char maze[10][10],int soln[][10],int i,int j,int m,int n)
{
    if(i==m && j==n)
    {
        soln[m][n] = 1;
        for(int i=0;i<=m;i++)
        {
            for(int j=0;j<=n;j++)
            {
                cout<<soln[i][j]<<" ";
            }
            cout<<'\n';
        }
        cout<<'\n';
    }

    // Rat should be inside grid
    if(i>m || j>n) return false;

    if(maze[i][j]=='X') return false;

    // Assume solution through current cell
    soln[i][j] = 1;

    // Recursive Case
    bool rightSuccess = rat_in_a_maze(maze,soln,i,j+1,m,n);
    bool downSuccess = rat_in_a_maze(maze,soln,i+1,j,m,n);

    soln[i][j] = 0;

    if(rightSuccess||downSuccess) return true;
    return false;
}
int main()
{
    char maze[10][10] = {
        "0000",
        "00X0",
        "000X",
        "0X00"
    };
    int soln[10][10] = {0};
    int m = 4,n=4;
    bool ans = rat_in_a_maze(maze,soln,0,0,m-1,n-1);
    if(ans==false)
    {
        cout<<"Path doesn't exist!";
    }
    return 0;
}