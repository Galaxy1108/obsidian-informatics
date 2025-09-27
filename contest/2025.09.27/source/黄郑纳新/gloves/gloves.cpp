#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+10;
int n,m,a[MAXN],b[MAXN];
inline int check(){
	int maxn=0;
	bool use[n+10]={};
	if(m<=n)
	for(int i=1;i<=m;i++){
		int minn=1000000010,flag;
		for(int j=1;j<=n;j++){
			if(abs(a[j]-b[i])<minn&&!use[j]){
				minn=abs(a[j]-b[i]);
				flag=j;
			}
		}
		use[flag]=1;
		if(minn!=1000000010)
		maxn=max(maxn,minn);
	}
	else
	for(int i=1;i<=n;i++){
		int minn=1000000010,flag;
		for(int j=1;j<=m;j++){
			if(abs(b[j]-a[i])<minn&&!use[j]){
				minn=abs(b[j]-a[i]);
				flag=j;
			}
		}
		use[flag]=1;
		if(minn!=1000000010)
		maxn=max(maxn,minn);
	}	
	return maxn;
}
inline bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("gloves.in","r",stdin);
	freopen("gloves.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1,cmp);
	for(int i=1;i<=m;i++){
		scanf("%lld",&b[i]);
	}
	sort(b+1,b+n+1,cmp);
	printf("%lld\n",check());
}
