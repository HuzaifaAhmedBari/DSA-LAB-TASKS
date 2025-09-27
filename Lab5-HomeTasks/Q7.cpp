#include<iostream>
using namespace std;
const int N = 5;

bool isSafe(int maze[N][N], int x, int y) {
    return (x >= 0 && x < N && y >= 0 && y < N && maze[x][y] == 1);
}

bool solveMaze(int maze[N][N], int x, int y, int solution[N][N]) {
    if(x==N-1 and y==N-1)
    {
        solution[x][y] = 1;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                cout << solution[i][j]<<" ";
            }
            cout << endl;
        }
        return true;
    }
    if(isSafe(maze, x, y))
    {
        solution[x][y] = 1;
        if (solveMaze(maze, x, y + 1, solution))
            return true;
        if (solveMaze(maze, x + 1, y, solution))
            return true;
        solution[x][y] = 0;
        return false;
    }
    return false;
}
void solve(int maze[N][N]) {
    int solution[N][N] = {0};
    if(solveMaze(maze, 0, 0, solution))
        ;
    else
        cout << "No Maze Path" << endl;
}
int main()
{
    int maze[N][N] = {
        {1, 0, 1, 0, 1},
        {1, 1, 1, 1, 1},
        {0, 1, 0, 1, 1},
        {1, 0, 0, 1, 1},
        {1, 1, 1, 0, 1}
    };
    solve(maze);

    return 0;
}