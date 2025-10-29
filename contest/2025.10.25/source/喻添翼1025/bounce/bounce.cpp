#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+10;
int n,q;
bool t[mx];
void op1(int m)
{
    for(int i=1;i<=n;i+=m) t[i]=0;
}
void op2(int m)
{
    int cnt=0;
    for(int i=1;i<=n;i++) 
    {
        if(t[i]) 
        {
            cnt++;
            if(cnt%m==1) t[i]=0;
        }
    }
}
struct node
{
    int nxt,pre;
}nt[mx];
int op3(int m)
{
    for(int i=0;i<=n+1;i++) nt[i].pre=nt[i].nxt=-12;
    int ans=-1,lst=0;
    for(int i=1;i<=n;i++) 
    {
        if(t[i]) 
        {
            nt[i].pre=lst;
            nt[lst].nxt=i;
            lst=i;
        }
    }
    nt[lst].nxt=n+1;
    nt[n+1].pre=lst;
    int rd=0;
    while(nt[0].nxt!=n+1)
    {
        if(!rd)
        {
            int cnt=0;
            for(int i=0;i<=n;i=nt[i].nxt)
            {
                if(t[i]) cnt++;
                if(cnt%m==1)
                {
                    nt[nt[i].pre].nxt=nt[i].nxt;
                    nt[nt[i].nxt].pre=nt[i].pre;
                    ans=i;
                }
            }
        }
        else 
        {
            int cnt=0;
            for(int i=n+1;i;i=nt[i].pre)
            {
                if(t[i]) cnt++;
                if(cnt%m==1)
                {
                    nt[nt[i].pre].nxt=nt[i].nxt;
                    nt[nt[i].nxt].pre=nt[i].pre;
                    ans=i;
                }
            }
        }
        rd^=1;
    }
    return ans;
}
int ans[25];
int main()
{
    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>n>>q;
    for(int i=1;i<=n;i++) t[i]=1;
    for(int i=2;i<=20;i++) ans[i]=op3(i);
    bool flag=0;
    for(int i=1;i<=q;i++)
    {
        int tp,m;
        cin>>tp>>m;
        if(tp==1) flag=1,op1(m);
        if(tp==2) flag=1,op2(m);
        if(tp==3)
        {
            if(flag) cout<<op3(m)<<"\n";
            else cout<<ans[m]<<"\n";
        }
    }
    return 0;
}
