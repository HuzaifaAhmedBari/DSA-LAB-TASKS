#include<iostream>
using namespace std;
#define n 4

bool col[n];
int disx[n] = {1,-1,1,-1}, disy[n] = {1,-1,-1,1};
char queens[n][n] = {{'.','.','.','.'},{'.','.','.','.'},{'.','.','.','.'},{'.','.','.','.'}};

bool can_place(int i,int j) {
    if(col[j])
        return false;
    for(int t=0;t<4;t++)
    {
        int dx = disx[t];
        int dy = disy[t];
        int x = i + dx;
        int y = j + dy;
        while(x>=0 and y>=0 and x<=n-1 and y<=n-1)
        {
            if(queens[x][y]=='Q')
                return false; 
            x+=dx;
            y+=dy;
        }
    }
    return true;
}
bool recurse(int i=0,int j=0) {
    if(i==n)
        return true;

    if(j==n)
        return false;

    if(can_place(i,j))
    {
        queens[i][j] = 'Q';
        col[j] = true;
        if(recurse(i+1,0))
            return true;
        queens[i][j] = '.';
        col[j] = false;
    }
    if(recurse(i,j+1))
        return true; 

    return false;
}
int main()
{
    recurse();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout << queens[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}