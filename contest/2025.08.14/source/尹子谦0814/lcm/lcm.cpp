#include<bits/stdc++.h>
#define int unsigned __int128
using namespace std;
const int N=1e3+100;
int T;
int yh[N][N],anss[N],inv[N];
void read(int &x) {
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

void write(int x) {
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
  } while (x);
  if (neg)
    while (top) putchar('0' - sta[--top]);
  else
    while (top) putchar('0' + sta[--top]);
}
signed main()
{
	freopen("lcm.in","r",stdin);
	freopen("lcm.out","w",stdout);
	read(T);
	while(T--)
	{
		int n,p;
		read(n),read(p);
		yh[1][1]=1;
		for(longl i=2;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				yh[i][j]=(yh[i-1][j]+yh[i-1][j-1]);
			}
		}
		int ans=0,lcm=1;
		for(int i=2;i<=n+1;i=)
		{
			int sum=0;
			for(int j=2;j<=i;j+=2) sum=(sum+(yh[i][j]*(1<<(j/2-1))));
			lcm=sum*lcm/__gcd(sum,lcm);
			ans=(ans+lcm*(i-1))%p;
		}
		write(ans);
		cout<<endl;
	}
	return 0;
}
