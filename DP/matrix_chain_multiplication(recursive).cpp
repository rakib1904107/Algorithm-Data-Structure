#include<bits/stdc++.h>
#define MAX_N 100
#define INF 1<<30
#define FIO() ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
typedef long long ll;
int mem[MAX_N][MAX_N];
struct matrix{
    int row,col;
};
vector<matrix>mats;
int mergeCost(int i,int k,int j){
    return mats[i].row*mats[k].col*mats[j].col;
}
int recursive_mcm(int i,int j)
{
    if(i>=j)
        return 0;
    if(mem[i][j]!=-1)
        return mem[i][j];
    int ans=INF;
    for(int k=i;k<j;k++){
        int res_left=recursive_mcm(i,k);
        int res_right=recursive_mcm(k+1,j);
        int cost=(res_left+res_right)+mergeCost(i,k,j);
        ans=min(ans,cost);
    }
    mem[i][j]=ans;
    return mem[i][j];
}
int main()
{
    FIO();
    int n;
    cin>>n;
    /// Dimension of the matrixs
    matrix ob;
    for(int i=0;i<n;i++){
        cin>>ob.row>>ob.col;
        mats.push_back(ob);
    }
    memset(mem,-1,sizeof(mem));
    ///print the minimun no. of operation needed to multiply all matrixs
    cout<<recursive_mcm(0,n-1);
}
