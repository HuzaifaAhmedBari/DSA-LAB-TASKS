#include<iostream>
#include<vector>
using namespace std;
int n;
vector<bool> col;
vector<pair<int,int>> dis;
vector<string> flags;
vector<string> ans;
bool can(int i,int j) {
    if(col[j])
        return false;
    for(int t=0;t<4;t++)
    {
        int dx = dis[t].first;
        int dy = dis[t].second;
        int x = i + dx;
        int y = j + dy;
        while(x>=0 and y>=0 and x<=n-1 and y<=n-1)
        {
            if(flags[x][y]=='Q')
                return false; 
            x+=dx;
            y+=dy;
        }
    }
    return true;
}
void recurse(int i=0,int j=0) {
    if(i==n)
    {
        ans = flags;
        return;
    }
    if(j==n)
        return;
    if(can(i,j))
    {
        flags[i][j] = 'Q';
        col[j] = true;
        recurse(i+1,0);
        flags[i][j] = '.';
        col[j] = false;
    }
    recurse(i,j+1); 
}
int main()
{
    n = 4;
    col.assign(10,false);
    dis = {{1,1},{-1,-1},{1,-1},{-1,1}};
    string d(n,'.');
    flags.assign(n,d);
    recurse();

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            cout << ans[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}