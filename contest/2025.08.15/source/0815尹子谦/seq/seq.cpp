#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+10;
int cnt,a[N],b[N],ch[N],n,m,cntt[N];
map<int,bool> mp;
bool check(int len)
{
	for(int i=1;i<=min(m,len);i++)
	{
		if(ch[i]>b[i]) return 0;
		else if(ch[i]<b[i]) return 1; 
	}
	if(m>len) return 1;
	else return 0;
}
void dfs(int pos,int len)
{
	if(len)
	{
		int sum=0;
		for(int i=1;i<=len;i++) sum=sum*20+ch[i];
		if(mp[sum]) return ;
		if(check(len)) cnt++;
		else return ;
		//cout<<sum<<endl;
		mp[sum]=1;
	}
	for(int i=pos;i<=n;i++) 
	{
		ch[len+1]=a[i];
		dfs(i+1,len+1);
	}
}
signed main()
{
    freopen("seq.in","r",stdin);
    freopen("seq.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	} 
	cnt=0;
    cin>>m;
    for(int i=1;i<=m;i++) cin>>b[i];
    dfs(1,0);
    cout<<cnt+1;
	return 0;
}
