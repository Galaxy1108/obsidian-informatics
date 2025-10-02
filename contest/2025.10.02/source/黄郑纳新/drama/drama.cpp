#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,h[2000010];
inline int find(){
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			int sum,len=0,maxn=0,minn=1000000010;
			for(int l=i;l<=j;l++){
				len++;
				maxn=max(maxn,h[l]);
				minn=min(minn,h[l]);
			}
			sum=minn*maxn*len;
			ans=max(ans,sum);
			
		}
	}
	return ans;
}
signed main(){
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
	scanf("%lld",&n);
	for(int i=1;i<=n;i++){
		scanf("%lld",&h[i]);
	}
	printf("%lld",find());
} 

