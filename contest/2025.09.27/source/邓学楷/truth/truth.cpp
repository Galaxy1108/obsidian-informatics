#include <cstdio>
#include <cstring>
#define lowbit(x) ((x) & (-(x)))

int n,k,m,a[50010];
bool f[50];

struct BIT
{
	int t[50010];
	void add(int x,int k)
	{
		while (x<=n)
			t[x]+=k,x+=lowbit(x);
	}
	int query(int x)
	{
		int ans=0;
		while (x)
			ans+=t[x],x-=lowbit(x);
		return ans;
	}
} t[50];

bool check(int l,int r)
{
    int sum=0;
    for (int i=1;i<=k;i++)
        sum+=((t[i].query(r)-t[i].query(l-1))!=0);
    return sum==k;
}

int solve()
{
    for (int len=k;len<=n;len++)
        for (int l=1;l+len-1<=n;l++)
            if (check(l,l+len-1))
                return len;
    return -1;
}

int main()
{
    freopen("truth.in","r",stdin);
    freopen("truth.out","w",stdout);
    int op,p,v;
    scanf("%d%d%d",&n,&k,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",a+i);
        t[a[i]].add(i,1);
    }
    while (m--)
    {
        scanf("%d",&op);
        if (op==1)
        {
            scanf("%d%d",&p,&v);
            t[a[p]].add(p,-1);
            t[v].add(p,1);
            a[p]=v;
        }
        else
            printf("%d\n",solve());
    }
    return 0;
}
// O(n^2*k*log(n))?
