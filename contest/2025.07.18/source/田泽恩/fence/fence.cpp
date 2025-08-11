#include <bits/stdc++.h>
using namespace std;
const __int128 mod=1e9+7;
__int128 n,h[114514],w[114514],pre[114514],lst[114514],ans;
int x;
bool sub2,sub3;
int main(){
	freopen("fence.in","r",stdin);
	freopen("fence.out","w",stdout);
	cin>>x;
	n=x;
	sub2=sub3=true;
	for(int i=1;i<=n;++i){
		cin>>x;
		h[i]=x;
		if(h[i]>2) sub2=false;
		if(h[i]<h[i-1]&&i<n) sub3=false;
	}
	if(sub2){
		int pos2=1,pos1=n;
		for(int i=1;i<=n;++i){
			if(h[i]==1) pre[i]=1;
			else{
				if(h[i-1]!=2) pos2=i;
				pre[i]=pos2;
			}
		}
		for(int i=n;i>0;--i){
			if(h[i]==1){
				if(h[i+1]<=1) pos1=i;
				lst[i]=pos1;
			}
			else{
				lst[i]=i;
			}
		}
	}
	else if(sub3){
		lst[n]=n;
		int pos=1;
		for(int i=n-1;i>0;--i){
			if(h[i+1]>h[i]) lst[i]=lst[i+1];
			else lst[i]=i;
		}
		for(int i=1;i<=n;++i){
			if(h[i]>h[i-1]) pos=i;
			pre[i]=pos;
		}
	}
	else{
		for(int i=1;i<=n;++i){
			int j=i;
			for(;j>0&&h[j]>=h[i];--j);
			pre[i]=j+1;
		}
		for(int i=n;i>0;--i){
			int j=i+1;
			for(;j<=n&&h[j]>h[i];++j);
			lst[i]=j-1;
		}
	}
	for(int i=1;i<=n;++i){
		cin>>x;
		w[i]=x;
		ans=((ans+(h[i]*(h[i]+1)/2)%mod*(w[i]*(w[i]+1)/2)%mod)%mod+mod)%mod;
		w[i]+=w[i-1];
	}
	for(int i=1;i<=n;++i){
		__int128 cnt=0,base=(h[i]*(h[i]+1)/2)%mod;
		cnt=base*(w[i]-w[i-1])%mod*(w[i-1]-w[pre[i]-1])%mod;
		cnt=(cnt+(base*(w[i]-w[i-1])%mod*(w[lst[i]]-w[i])%mod))%mod;
		cnt=(cnt+(base*(w[i-1]-w[pre[i]-1])%mod*(w[lst[i]]-w[i])%mod))%mod;
		ans=(ans+cnt)%mod;
	}
	x=ans;
	cout<<x;
	return 0;
}
