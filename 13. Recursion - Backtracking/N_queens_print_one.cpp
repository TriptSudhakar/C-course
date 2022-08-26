#include<iostream>
using namespace std;
bool isSafe(int board[][10],int i,int j,int n)
{
    // Check for column
    for(int row=0;row<i;row++)
    {
        if(board[row][j]==1) return false;
    }

    // Check for left diagonal
    int x = i,y=j;
    while (x>=0 && y>=0)
    {
        if(board[x][y]==1) return false;
        x--;y--;
    }

    // Check for right diagonal 4
    x = i,y=j;
    while (x>=0 && y<n)
    {
        if(board[x][y]==1) return false;
        x--;y++;
    }
    
    // The position is now safe, col and diagonals
    return true;
}
bool solveNqueen(int board[][10],int i,int n)
{
    // Base Case
    if(i==n)
    {
        // You have successfully place queens in n rows (0...n-1)
        // Print the board
        for (int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==1) cout<<"Q ";
                else cout<<"_ ";
            }
            cout<<'\n';
        }
        cout<<'\n';
        return true; 
        // return false; // to print all possibilities
    }

    // Recursive Case
    for(int j=0;j<n;j++)
    {
        // I have to check if i,j th postition is safe to place the queen or not
        if (isSafe(board,i,j,n))
        {
            // Place the Queen - Assuming i,j is the correct position
            board[i][j] = 1;
            bool nextQueen = solveNqueen(board,i+1,n);
            if(nextQueen)
            {
                return true;
            }
            // Means i,j is not the correct position - Assumption is wrong 
            board[i][j] = 0; // Backtracking
        }
    }
    // You have tried for all positions in a row but couldn't place a queen
    return false;
}
int main()
{
    int n;
    cin>>n;

    int board[10][10] = {0};
    bool x = solveNqueen(board,0,n);
    return 0;
}