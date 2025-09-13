#include <bits/stdc++.h>
using namespace std;
#define N 2000005
int n,lk,rk,q;
char s[N];
int f[N],siz[N],cnt[N];
int findf(int x){
	return f[x]==x?x:f[x]=findf(f[x]);
}
bool merge(int x,int y){
	x=findf(x),y=findf(y);
	if(x==y)return false;
	if(siz[x]>siz[y])swap(x,y);
	f[x]=y;
	siz[y]+=siz[x];
	siz[x]=0;
	return true;
}
int main(){
	freopen("virtual.in","r",stdin);
	freopen("virtual.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>lk>>rk>>(s+1);
	for(int i=1;i<=n;i++){
		f[i]=i;
		siz[i]=1;
		cnt[i]=cnt[i-1]+(s[i]=='a');
	}
	cnt[n+1]=cnt[n];
	if(lk==rk){
		for(int i=1,l=0,r=0;i<=n;i++){
			while(r<n&&cnt[r+1]-cnt[i-1]<=rk)r++;
			while(l<=n&&cnt[l]-cnt[i-1]<lk)l++;
			if(l<=r){
				merge(i,l);
			}
			if(s[i]=='a'){
				for(int j=l+1;j<=r;j++){
					merge(l,j);
				}
			}
			// cerr<<i<<":"<<l<<"~"<<r<<'\n';
		}
	}
	else{
		for(int i=1,l=0,r=0;i<=n;i++){
			while(r<n&&cnt[r+1]-cnt[i-1]<=rk)r++;
			while(l<=n&&cnt[l]-cnt[i-1]<lk)l++;
			if(l<=r){
				merge(i,l);
			}
		}
		int l=0;
		while(l<=n&&cnt[l]<lk)l++;
		for(int i=l+1;i<=n;i++){
			merge(l,i);
		}
	}
	cin>>q;
	int _u,_v;
	while(q--){
		cin>>_u>>_v;
		if(findf(_u)==findf(_v)){
			cout<<"Yes\n";
		}
		else{
			cout<<"No\n";
		}
	}
	return 0;
}