#include<bits/stdc++.h>
//#pragma GCC optimize(2)
using namespace std;
const int mx=100;
int h[mx],hh[mx];
map<int,int> m;
int fread()
{
    int x=0,f=1; char ch=getchar();
    while(ch<'0'||ch>'9') f=ch=='-'?-1:1,ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+ch-'0',ch=getchar();
	return x*f;
}
int main()
{
	freopen("lineup.in","r",stdin);
	freopen("lineup.out","w",stdout);
	int n=fread();
	for(int i=1;i<=n;i++) h[i]=fread(),hh[i]=h[i];
	sort(hh+1,hh+n+1);
	for(int i=1;i<=n;i++)
		if(!m[hh[i]]) m[hh[i]]=i;
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		ans+=abs(i-m[h[i]]);
		m[h[i]]++;
	}
	cout<<ans;
	return 0;
}


