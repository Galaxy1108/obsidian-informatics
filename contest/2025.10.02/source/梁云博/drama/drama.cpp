#include <bits/stdc++.h>
#define N 2000006
using namespace std;
int stk[N],top,n,a[N];
int l[N],r[N],st[N][21];
int x,y;

void init()
{
    for(int i=1;i<=n;i++)st[i][0]=a[i];
    for(int j=1;j<=20;j++)
    {
        for(int i=1;i+(1<<j)<=n;i++)
        {
            st[i][j]=max(st[i][j-1],st[i+(1<<j-1)][j-1]);
        }
    }
}
int get()
{
    int len=log2(y-x+1);
    return max(st[x][len],st[y-(1<<len)+1][len]);
}
void print(__int128 x)
{
    char tmp[N],tot=0;
    while(x)
    {
        tmp[++tot]=char(x%10+'0');
        x/=10;
    }
    for(int i=tot;i>=1;i--)cout<<tmp[i];
}

int main()
{
    freopen("drama.in","r",stdin);
    freopen("drama.out","w",stdout);
    ios::sync_with_stdio(nullptr);
    cin.tie(0),cout.tie(0);
	cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    init();
    for(int i=1;i<=n;i++)
    {
        while(top && a[i]<a[stk[top]])
        {
            r[stk[top]]=i;
            top--;
        }
        stk[++top]=i;
    }
    
    while(top)r[stk[top--]]=n+1;
    for(int i=n;i>=1;i--)
    {
        while(top && a[i]<a[stk[top]])
        {
            l[stk[top]]=i;
            top--;
        }
        stk[++top]=i;
    }
    while(top)l[stk[top--]]=0;
    __int128 maxn=-1e18;
    for(int i=1;i<=n;i++)x=l[i]+1,y=r[i]-1,maxn=max(maxn,(__int128)(y-x+1)*get()*a[i]);
    print(maxn);
	return 0;
}