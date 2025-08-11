#include<bits/stdc++.h>
#define int __int128
using namespace std;
const int p=1e9+7,N=3e6;
int f[N],maxx=-1,a[N],d[N],ans,s;
void build(int s, int t, int p) 
{
 	if (s == t)
	{
    	d[p] = a[s];
   	 	return ;
 	}
  	int m = (s+t)/2;
  	build(s, m, p * 2), build(m + 1, t, p * 2 + 1);
  	d[p] = max(d[p * 2],d[(p * 2) + 1]);
}
int getmax(int l, int r, int s, int t, int p) 
{
  	if (l <= s && t <= r)
   	 	return d[p];
 	int m = (s+t)/2,maxx=-1;
 	if (l <= m) maxx = max(maxx,getmax(l, r, s, m, p * 2));
 	if (r > m) 	maxx = max(maxx,getmax(l, r, m + 1, t, p * 2 + 1));
 	return maxx;
}
void read(int &x) 
{
  bool neg = false;
  x = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') neg = true;
    ch = getchar();
  }
  if (neg) {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + ('0' - ch);
      ch = getchar();
    }
  } else {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + (ch - '0');
      ch = getchar();
    }
  }
}
void write(int x)
{
  bool neg = false;
  if (x < 0) {
    neg = true;
    putchar('-');
  }
  static int sta[40];
  int top = 0;
  do {
    sta[top++] = x % 10;
    x /= 10;
  }
   while (x);
  if (neg)
    while (top) putchar('0' - sta[--top]);
  else
    while (top) putchar('0' + sta[--top]);
}
int quick(int a, int b) 
{
  	int res = 1;
 	 while (b > 0)
  	 {
  	  if (b & 1) res = res * a;
  	  a = a * a;
  	  b >>= 1;
  	}
 	 return res;
}
signed main()
{
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	memset(f,0x3f,sizeof(f));
	f[0]=0;
	int n,k;
	read(n),read(k);
	for(int i=1;i<=n;i++) read(a[i]);
	build(1,n,1);
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j>=max((int)1,i-k+1);j--)
		{
			f[i]=min(f[i],f[j-1]+getmax(j,i,1,n,1));
		}
	}
	for(int i=1;i<=n;i++)
	{
		s=f[i]*quick(23,n-i);
		ans=(ans+s)%p;
	}
	write(ans);
	return 0;
}

