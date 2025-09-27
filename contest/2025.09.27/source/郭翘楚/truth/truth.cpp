#include <bits/stdc++.h>
using namespace std;
vector<int> a;
int n,k;
int minl;
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
void update()
{
	vector<int> cnt(k+1,0);
	int l=0,v=0;
	minl=INT_MAX;
	for(int r=0;r<n;r++)
	{
		int x=a[r];
		if(cnt[x]==0) v++;
		cnt[x]++;
		while(v==k)
		{
			minl=min(minl,r-l+1);
			int y=a[l];
			cnt[y]--;
			if(cnt[y]==0) v--;
			l++;
		}
	}
	if(minl==INT_MAX)
	{
		minl=-1;
	}
}
int main()
{
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout); 
	int m;
	cin>>n>>k>>m;
	a.resize(n);
	for(int i=0;i<n;i++)
	{
		a[i]=read();
	}
	update();
	while(m--)
	{
		int op;
		op=read();
		if(op==1)
		{
			int p,v;
			p=read(),v=read();
			p--;
			a[p]=v;
			update(); 
//			for(int i=0;i<n;i++)
//			{
//				cout<<a[i]<<" "; 
//			}
//			cout<<endl;
		}
		else
		{
			write(minl);
			cout<<'\n';
		}
	}
}
