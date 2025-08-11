#include<bits/stdc++.h>
using namespace std;
const int mx=1e6+100;
int s[mx]; 
int n,l,r;
int h[mx],t[mx],hh[mx],tt[mx];
bool check(int len)
{
	bool flag=0;
	if(len<r-l+3) return 0;
	for(int i=1;i<=n-len+1;i++)
	{
		int j=i+len-1;
		if(i>=l||j<=r) continue;
		if(s[i]==s[j]) continue;
		else
		{
			if(i!=h[s[i]]||hh[s[i]]<j) continue;
			if(j!=t[s[j]]||tt[s[j]]>i) continue;
			flag=1;
		}
	}
	return flag;
}
int main()
{
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	cin>>n>>l>>r;
	memset(h,0x3f,sizeof(h));
	memset(t,0,sizeof(t));
	memset(hh,0x3f,sizeof(hh));
	memset(tt,0,sizeof(tt));
	for(int i=1;i<=n;i++) cin>>s[i];
	for(int i=1;i<=n;i++)
	{
		tt[s[i]]=t[s[i]];
		t[s[i]]=i;
	} 
	for(int i=n;i;i--)
	{
		hh[s[i]]=h[s[i]];
		h[s[i]]=i;
	} 
	int L=2,R=n+1;
	while(L<R)
	{
		int mid=(L+R)/2;
		//cout<<mid<<' '<<check(mid)<<endl;
		if(check(mid)) R=mid;
		else L=mid+1;
		
	}
	if(L==n+1) cout<<-1;
	else cout<<L;
	return 0;  
}
