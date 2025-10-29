#include<iostream>
#include<vector>
using namespace std;
int cnt[45];
int step[45];
string s[45];
vector<int> Qi[45];
int n;
inline bool check()
{
    for(int i=1;i<=n;i++)
    {
        if(abs(Qi[i][0]-Qi[i][1])!=i+1) return 0;
    }
    return 1;
}
inline void DFS(int x)
{
    if(x==2*n+1)
    {
        if(check())
        {
            for(int i=1;i<=2*n;i++)
            {
                cout<<s[step[i]]<<endl;
            }
            exit(0);
        }
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(cnt[i]<2)
        {
            if(cnt[i]==1)
            {
                if(x-Qi[i][0]!=i+1) continue;
            }
            if(cnt==0)
            {
                if(2*n-x<i+1) continue;
            }
            cnt[i]++;
            step[x]=i;
            Qi[i].push_back(x);
            DFS(x+1);
            cnt[i]--;
            step[x]=0;
            Qi[i].pop_back();
        }
    }
    return ;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>s[i];
    }
    DFS(1);
    return 0;
}