#include<iostream>
using namespace std;
int sum(int **arr, int *cols, int dim)
{
    int ans=0;
    for(int i=0;i<dim;i++)
    {
        for(int j=0;j<cols[i];j++)
        {
            ans += arr[i][j];
        }
    }
    return ans;
}
int main()
{
    int **arr;
    int cols[3];
    arr = new int*[3];
    for(int i=0;i<3;i++)
    {
        arr[i] = new int[i+1];
        cols[i] = i+1;
        for(int j=0;j<i+1;j++)
        {
            arr[i][j] = i+j+1;
        }
    }
    cout<<sum(arr,cols,3)<<endl;

    return 0;
}