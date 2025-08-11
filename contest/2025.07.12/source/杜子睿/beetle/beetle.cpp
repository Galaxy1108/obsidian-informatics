#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,k,s[2500005],t[10000005];
long long p[2500005],ans;
void build(int p,int l,int r){
	if(l==r){
		t[p]=s[l];
		return;
	}
	int mid=(l+r)>>1;
	build(p*2,l,mid);
	build(p*2+1,mid+1,r);
	t[p]=max(t[p*2],t[p*2+1]);
} 
void init(){
	p[0]=1;
	for(int i=1;i<n;i++)
		p[i]=p[i-1]*23%mod;
}
int query(int p,int s,int t,int l,int r){
	if(l<=s&&t<=r)
		return ::t[p];
	int mid=(s+t)>>1,maxx=0;
	if(l<=mid)
		maxx=query(p*2,s,mid,l,r);
	if(r>mid)
		maxx=max(maxx,query(p*2+1,mid+1,t,l,r));
	return maxx;
}
int Qread()
{
	int x=0;char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') x=x*10+(ch^48),ch=getchar();
	return x;
}
int main(){
	freopen("beetle.in","r",stdin);
	freopen("beetle.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	n=Qread();
	k=Qread();
	init();
	for(int i=1;i<=n;i++)
		s[i]=Qread();
	build(1,1,n);
	for(int i=1;i<=n;i++){
		int cnt=i/k;
		long long sum=0;
		if(!(i%k)){
			for(int j=0;j<cnt;j++)
				 sum+=query(1,1,n,j*k+1,(j+1)*k);
			ans+=sum*p[n-i]%mod;
			ans=ans%mod;
		}
		else{
			if(cnt==0){
				ans+=query(1,1,n,1,i)*p[n-i]%mod;
				ans=ans%mod;
			}
			else{
				long long minn=INT_MAX;
				for(int j=0;j<=cnt;j++){
					sum=0;
					sum+=query(1,1,n,j*k+1,j*k+cnt%k);
					for(int l=0;l<j;l++)
						sum+=query(1,1,n,l*k+1,(l+1)*k);
					for(int l=j;l<cnt;l++)
						sum+=query(1,1,n,l*k+1+cnt%k,(l+1)*k+cnt%k);
					minn=min(minn,sum);
				}
				ans+=minn*p[n-i]%mod;
				ans=ans%mod;
			}
		}
	}
	cout<<ans;
	return 0;
}

