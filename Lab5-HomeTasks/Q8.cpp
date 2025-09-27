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
            if(flags[x][y]=='F')
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
        flags[i][j] = 'F';
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

    int x = 0;

    for(int i=0;i<ans.size();i++)
    {
        for(int j=0;j<ans[i].size();j++)
        {
            if(ans[i][j]=='F')
                x++;
            cout << ans[i][j]<<" ";
        }
        cout<<endl;
    }

    cout << endl << x << " Flags can Be Placed" << endl;

    return 0;
}