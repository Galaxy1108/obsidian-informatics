#include<iostream>
#include<vector>
using namespace std;
bool vis[105];
int cnt;
vector<int> Qi;
inline int GCD(int a,int b)
{
    if(a%b==0) return b;
    return GCD(b,a%b);
}
int a,b;
inline void DFS(int lstz,int lstm,int cz,int cm,int num)
{
    //cout<<lstz<<" "<<lstm<<" "<<cz<<" "<<cm<<" "<<num<<endl;
    if(cz*lstm>cm*lstz) return ;
    if(cz==lstz&&cm==lstm)
    {
        cout<<num<<endl;
        for(int i=0;i<Qi.size();i++)
        {
            cout<<Qi[i]<<" ";
        }
        exit(0);
    }
    for(int i=2;i<=107;i++)
    {
        if(vis[i]) continue;
        int ccz=cm*1+i*cz,ccm=cm*i;
        int gcd=GCD(ccz,ccm);
        ccz/=gcd,ccm/=gcd;
        vis[i]=1;
        Qi.push_back(i);
        DFS(lstz,lstm,ccz,ccm,num+1);
        vis[i]=0;
        Qi.pop_back();
    }
    return ;
}
int main()
{
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    cin>>a>>b;
    DFS(a,b,0,1,0);
    return 0;
}