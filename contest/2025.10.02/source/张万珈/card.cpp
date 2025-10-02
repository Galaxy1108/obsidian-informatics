#include <bits/stdc++.h>
using namespace std;
int a[10010],cnt[2];
int tot0,tot1,tot2;
int n,m,q,hd,tl;
int read()
{
    int ret=0;char c=getchar();
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9'){ret = (ret<<3) + (ret<<1) + (c-'0');c=getchar();}
    return ret;
}
void write(int x)
{
    if(x<10)putchar(x+'0');
    else
    {
        write(x/10);
        putchar((x%10)+'0');
    }
}
priority_queue<int,vector<int>,greater<int> > s0,s1,ss0,ss1;
void solve(int T)
{
    int lst = 0;
    for(int i=1;i<=n;i++)
    {
        if(a[i]!=-1)
        {
            if(lst == 0)
            {
                if(a[i]==1)
                {
                    tot1++;
                    ss1.push(i-1);
                }
                else
                {
                    tot0++;
                    ss0.push(i-1);
                }
            }
            else
            {
                if(a[lst] == a[i] && a[i] == 1)
                {
                    tot1+=2;
                    s1.push(i-lst-1);
                }
                else if(a[lst] == a[i] && a[i] == 0)
                {
                    tot0+=2;
                    s0.push(i-lst-1);
                }
                else
                {
                    tot2++;
                }
            }
            lst = i;
        }
    }
    if(lst != n)
    {
        if(a[lst]==1)
        {
            tot1++;
            ss1.push(n-lst-1);
        }
        else
        {
            tot0++;
            ss0.push(n-lst-1);
        }
    }
}
int main()
{
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(),m=read(),q=read();
    for(int i=1,x;i<=n;i++)
    {
        x=read();
        cnt[x&1]++;
        a[i] = -1;
    }
    for(int i=1,x,y;i<=m;i++)
    {
        x=read(),y=read();
        a[x] = y&1;
    }
    for(int i=1,tp,x,y;i<=q;i++)
    {
        tp=read();
        if(tp == 1)
        {
            x=read();
            a[x] = -1;
        }
        else
        {
            x=read(),y=read();
            a[x] = y&1;
        }
        int ncnt1=cnt[1],ncnt0=cnt[0];
        for(int i=1;i<=n;i++)
        {
            if(a[i]==1)
            {
                ncnt1--;
            }
            else if(a[i]==0)
            {
                ncnt0--;
            }
        }
        tot0=tot1=tot2=0;
        solve(i);
        while(!s0.empty())
        {
            if(ncnt0 >= s0.top())
            {
                ncnt0 -= s0.top();
                tot0-=2;
            }
            s0.pop();
        }
        while(!ss0.empty())
        {
            if(ncnt0 >= ss0.top())
            {
                ncnt0 -= ss0.top();
                tot0--;
            }
            ss0.pop();
        }
        while(!s1.empty())
        {
            if(ncnt1 >= s1.top())
            {
                ncnt1 -= s1.top();
                tot1-=2;
            }
            s1.pop();
        }
        while(!ss1.empty())
        {
            if(ncnt1 >= ss1.top())
            {
                ncnt1 -= ss1.top();
                tot1--;
            }
            ss1.pop();
        }
        write(tot0+tot1+tot2);
        putchar('\n');
    }
}