#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    vector<string> grid;
    while(cin>>s)
    {
        if(s[0]=='"' and s.back()=='"')
        {
            grid.push_back(s.substr(1,s.size()-2));
        }
    }
    
    int n=grid.size();
    if(n==0)
    {
        cout<<-1;
        return 0;
    }
    
    int m=grid[0].size();
    for(int i=0;i<n;i++)
    {
        if(grid[i].size()!=m)
        {
            cout<<-1;
            return 0;
        }
    }
    
    int ans=0;
    int cnt1=0;
    int cnt4=0;
    int cnt2b=0;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(grid[i][j]==' ')
            {
                continue;
            }
            int deg=0;
            if(i==0 or i==n-1 or j==0 or j==m-1)
            {
                deg++;
            }
            if(i>0 and grid[i-1][j]!=grid[i][j])
            {
                deg++;
            }
            if(i<n-1 and grid[i+1][j]!=grid[i][j])
            {
                deg++;
            }
            if(j>0 and grid[i][j-1]!=grid[i][j])
            {
                deg++;
            }
            if(j<m-1 and grid[i][j+1]!=grid[i][j])
            {
                deg++;
            }
            
            if(deg==1 or deg==3)
            {
                cnt1++;
            }
            else if(deg==4)
            {
                cnt4++;
            }
            else if(deg==2 and (i==0 or i==n-1 or j==0 or j==m-1))
            {
                cnt2b++;
            }
        }
    }
    ans=cnt1/2+cnt4+cnt2b;
    if(cnt1%2!=0)
    {
        cout<<-1;
    }
    else
    {
        cout<<ans;
    }
    
    return 0;
}