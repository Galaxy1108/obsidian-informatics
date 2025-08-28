#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=200005;
ll a[200005];
ll qz[200005];
long long read()
{
    long long x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    { 
        if (ch == '-') w = -1; 
        ch = getchar();
    }
    while (ch >= '0' and ch <= '9')
    {
        x = x * 10 + (ch - '0'); 
        ch = getchar();
    }
    return x * w; 
}
void write(long long x)
{
    static long long sta[35];
    long long top = 0;
    do 
    {
        sta[top++] = x % 10, x /= 10;
    }while (x);
    while(top) putchar(sta[--top] + 48);
}
long long n;
long long mx[N << 2], se[N << 2], cn[N << 2], tag[N << 2];
long long sum[N << 2];
void pushup(long long u) {
  const long long ls = u << 1, rs = u << 1 | 1;
  sum[u] = sum[ls] + sum[rs];
  if (mx[ls] == mx[rs]) {
    mx[u] = mx[rs];
    se[u] = max(se[ls], se[rs]);
    cn[u] = cn[ls] + cn[rs];
  } else if (mx[ls] > mx[rs]) {
    mx[u] = mx[ls];
    se[u] = max(se[ls], mx[rs]);
    cn[u] = cn[ls];
  } else {
    mx[u] = mx[rs];
    se[u] = max(mx[ls], se[rs]);
    cn[u] = cn[rs];
  }
}
void pushtag(long long u, long long tg) {
  if (mx[u] <= tg) return;
  sum[u] += (1ll * tg - mx[u]) * cn[u];
  mx[u] = tag[u] = tg;
}
void pushdown(long long u) {
  if (tag[u] == -1) return;
  pushtag(u << 1, tag[u]), pushtag(u << 1 | 1, tag[u]);
  tag[u] = -1;
}
void build(long long u = 1, long long l = 1, long long r = n) {
  tag[u] = -1;
  if (l == r) {
    sum[u] = mx[u] = a[l], se[u] = -1, cn[u] = 1;
    return;
  }
  long long mid = (l + r) >> 1;
  build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
  pushup(u);
}
void modify_min(long long L, long long R, long long v, long long u = 1, long long l = 1, long long r = n) {
  if (mx[u] <= v) return;
  if (L <= l and r <= R and se[u] < v) return pushtag(u, v);
  long long mid = (l + r) >> 1;
  pushdown(u);
  if (L <= mid) modify_min(L, R, v, u << 1, l, mid);
  if (mid < R) modify_min(L, R, v, u << 1 | 1, mid + 1, r);
  pushup(u);
}
long long query_sum(long long L, long long R, long long u = 1, long long l = 1, long long r = n) {
  if (L <= l and r <= R) return sum[u];
  long long mid = (l + r) >> 1;
  long long res = 0;
  pushdown(u);
  if (L <= mid) res += query_sum(L, R, u << 1, l, mid);
  if (mid < R) res += query_sum(L, R, u << 1 | 1, mid + 1, r);
  return res;
}
int main()
{
	freopen("easy.in","r",stdin);
	freopen("easy.out","w",stdout); 
	long long q;
	n=read(),q=read();
	for(long long i=1;i<=n;i++)
	{
		a[i]=read();
		qz[i]=qz[i-1]+a[i];
	}
	if(n*q<=100000000)
	{
		while(q--)
		{
			long long op;
			op=read();
			if(op==1)
			{
				ll v;
				v=read();
				for(long long i=1;i<=n;i++)
				{
					if(a[i]>v)
					{
						a[i]=v;	
					}
					qz[i]=qz[i-1]+a[i];
				}
			}
			else if(op==2)
			{
				for(long long i=1;i<=n;i++)
				{
					a[i]+=i; 
					qz[i]=qz[i-1]+a[i];
				}
			}
			else
			{
				long long l,r;
				l=read(),r=read();
				cout<<qz[r]-qz[l-1]<<'\n';
			}
		}
	}
	else
	{
		build();
		while(q--)
		{
			long long op;
			op=read();
			if(op==1)
			{
				ll v;
				cin>>v;
				modify_min(1,n,v);
			}
			else if(op==2)
			{
				for(long long i=1;i<=n;i++)
				{
					a[i]+=i;
				}
				build();
			}
			else
			{
				long long l,r;
				l=read(),r=read();
				printf("%lld\n",query_sum(l,r)); 
			}
		}
	}
	return 0;
} 
