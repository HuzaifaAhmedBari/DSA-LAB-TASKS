#include<iostream>
using namespace std;
#define N 4

int ans[N][N] = {0}, arr[N][N] = {{1,1,1,1},{0,0,0,1},{1,1,0,1},{1,1,1,1}};
int visited[N][N] {0};

bool isSafe(int x, int y) {
    return (x >= 0 && y >= 0 && y < N && x < N && arr[x][y] == 1 && !visited[x][y]);
}
bool maze(int x, int y) {
    if(x==0 && y==0)
    {
        ans[x][y] = 1;
        return true;
    }
    if(!isSafe(x,y))
        return false;
        
    ans[x][y] = 1;
    visited[x][y] = 1;
    
    if(maze(x+1,y))
        return true;
    if(maze(x,y+1))
        return true;
    if(maze(x-1,y))  
        return true;
    if(maze(x,y-1))
        return true;

    ans[x][y] = 0;
    return false;
}
int main() {
    maze(2,0);
    for(int i=0; i < N; i++)
    {
        for(int j=0; j < N; j++)
        {
            cout << ans[i][j] << " ";
        }
    cout << endl;
   }
}