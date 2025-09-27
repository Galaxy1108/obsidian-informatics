#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int a[N],n;
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
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++) read(a[i]);
	int ans=n;
	for(int i=1;i<=n;i++)
	{
		int maxx=a[i],xorr=a[i];
		for(int j=i+1;j<=n;j++)
		{
			if(maxx<a[j]) maxx=a[j];
			xorr^=a[j];
			if(xorr<=maxx) ans++;
		}
	}
	write(ans);
	return 0;
} 
