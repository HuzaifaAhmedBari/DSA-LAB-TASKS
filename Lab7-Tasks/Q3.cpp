#include<iostream>

using namespace std;

#define N 4

int ans[N][N] = {0}, arr[N][N] = {{1,1,1,1},{0,0,0,1},{1,1,0,1},{1,1,1,1}};
int visited[N][N] {0};
bool isSafe(int i, int j) {
    return i >= 0 && j >= 0 && j < N && i < N && arr[i][j] == 1 && !visited[i][j];
}
bool travel(int i, int j) {
    if(i==0 && j==0)
    {
        ans[i][j] = 1;
        return true;
    }
    if(!isSafe(i,j))
        return false;
    //Down
    ans[i][j] = 1;
    visited[i][j] = 1;
    
    if (travel(i+1,j))  return true;
    //Right
    if (travel(i,j+1)) return true;
    //Up
    if (travel(i-1,j))   return true;
    //Left
    if (travel(i,j-1))   return true;

    ans[i][j] = 0;
    return false;
}
int main() {
    travel(2,0);
   for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
        cout << ans[i][j] << " ";
    }
    cout << endl;
   }
}