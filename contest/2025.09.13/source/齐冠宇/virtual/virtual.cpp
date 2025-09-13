#include <bits/stdc++.h>
using namespace std;
constexpr int N=2e6+5;
int n,L,R;
string s;
int q;
int f[N];
int find(int x){return f[x]==x?x:f[x]=find(f[x]);}
void merge(int x,int y)
{
	x=find(x),y=find(y);
	if(x==y)return;
	f[y]=x;
}
int l=1,cnt;
int main()
{
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>L>>R>>s>>q;
	s=" "+s;
	for(int i=1;i<=n;i++)f[i]=i;
	for(int i=1;i<=n;i++)
	{
		cnt+=s[i]=='a';
//		if(cnt==L)
//			merge(l,i);
		if(L<=cnt && cnt<=R)
		{
			while(cnt-(s[l]=='a')>=L)
				merge(l,l+1),cnt-=s[l++]=='a';
			merge(l,i);
		}
		else if(cnt>R)
		{
			while(cnt>R)
				cnt-=s[l++]=='a';
			while(cnt-(s[l]=='a')>=L)
				merge(l,l+1),cnt-=s[l++]=='a';
			merge(l,i);
		}
	}
//	if(cnt>=L)
//	{
//		while(cnt-(s[l]=='a')>=L)
//			merge(l,l+1),cnt-=s[l++]=='a';
//		merge(l,n);
//	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		if(find(x)==find(y))
			cout<<"Yes\n";
		else
			cout<<"No\n";
	}
	return 0;
}
