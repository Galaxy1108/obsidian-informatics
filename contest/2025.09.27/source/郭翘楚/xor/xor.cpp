#include <bits/stdc++.h>
using namespace std; 
int a[100005];
long long ans;
int read()
{
    int x = 0, w = 1;
    char ch = 0;
    while (ch < '0' || ch > '9')
    { 
        if (ch == '-') w = -1; 
        ch = getchar();
    }
    while (ch >= '0' && ch <= '9')
    {
        x = x * 10 + (ch - '0'); 
        ch = getchar();
    }
    return x * w; 
}
void write(int x)
{
    static int sta[35];
    int top = 0;
    do 
    {
        sta[top++] = x % 10, x /= 10;
    }while (x);
    while(top) putchar(sta[--top] + 48);
}
int main()
{
	freopen("xor.in","r",stdin);
	freopen("xor.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		a[i]=read(); 
	}
	ans+=n;
	for(int i=1;i<=n;i++)
	{
		int sum=a[i],maxa=a[i];
		for(int j=i+1;j<=n;j++)
		{
			sum^=a[j];
			if(a[j]>maxa)
			{
				maxa=a[j];
			}
			if(sum<=maxa)
			{
				ans++;
			}
		}
	}
	write(ans);
	return 0;
}
