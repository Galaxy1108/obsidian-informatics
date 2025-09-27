#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e4+10;
int k,n,m,a[MAXN],b[MAXN];
inline int find(){
	int f[35]={},ans=50010;
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		int s=0,sum=0;
		for(int j=i;j<=n;j++){
			f[a[j]]=1;
			s++;
			sum=0;
			for(int l=1;l<=31;l++){
				if(f[l]) sum++;
			}
			if(sum==k) break;
		}
		if(sum==k)
		ans=min(ans,s);
	}
	return ans==50010?-1:ans;
}
signed main(){
	freopen("truth.in","r",stdin);
	freopen("truth.out","w",stdout);
	scanf("%lld%lld%lld",&n,&k,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	for(int i=1;i<=m;i++){
		int op;
		scanf("%lld",&op);
		switch(op){
			case 1:{
				int p,v;
				scanf("%lld%lld",&p,&v);
				a[p]=v;
				break;
			}
			case 2:{
				printf("%lld\n",find());
				break;
			}
		}
	}
}
