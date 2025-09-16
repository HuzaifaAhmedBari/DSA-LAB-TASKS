#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n=4;
    int arr[4][4] = {{1,1,1,1},{0,0,0,1},{1,1,0,1},{1,1,1,1}}, sol[4][4]={0};
    bool visited[4][4] = {{0,0,0,0},{0,0,0,0},{0,0,0,0},{0,0,0,0}};
    function<bool(int,int)>fine = [&](int x,int y) {
        if(x<n and y<n and arr[x][y]==1 and not visited[x][y])
            return true;
        return false;
    };
    pair<int,int> ds[4] = {{1,0},{-1,0},{0,1},{0,-1}};
    function<bool(int,int)>recurse = [&](int x,int y) {
        if(x==2 and y==0)
        {
            sol[x][y] = 1;
            return true;
        }
        for(auto [dx,dy]:ds)
        {
            if(fine(x+dx,y+dy))
            {
                visited[x+dx][y+dy] = true;
                sol[x+dx][y+dy] = 1;
                if(recurse(x+dx,y+dy))
                    return true;
                sol[x+dx][y+dy] = 0;
                return false;
            }
        }
        return false;
    };
    recurse(-1,0);
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cout<<sol[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
    return 0;
}
