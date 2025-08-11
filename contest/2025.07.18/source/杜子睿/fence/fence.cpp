#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
const long long inv=25e7+2;
struct node{
	long long h,l,r;
}a[1000005];
int n,s[200005],idx;
long long rp[200005];
long long ans,cnt;
map<int,int> p;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i].h;
		s[i]=a[i].h;
	}
	for(int i=0;i<n;i++){
		a[i].l=cnt;
		cin>>a[i].r;
		cnt+=a[i].r;
		a[i].r=cnt;
	}
	sort(s,s+n);
	for(int i=0;i<n;i++){
		int t=s[i];
		p[t]=++idx;
		rp[idx]=t;
		while(t==s[i]&&i<n){
			i++;
		}
		i--;
	}
	for(int i=0;i<n;i++)
		a[i].h=p[a[i].h];
	for(int i=1;i<=idx;i++){
		for(int j=0;j<n;j++){
			if(a[j].h<i)
				continue;
			long long l=a[j].l;
			while(a[j].h>=i&&j<n)
				j++;
			j--;
			long long r=a[j].r;
			ans+=(rp[i]-rp[i-1])*(rp[i]+rp[i-1]+1)%mod*(r-l+1)%mod*(r-l)%mod*inv%mod;
			ans=ans%mod;
		}
	}
	cout<<ans;
	return 0;
} 

