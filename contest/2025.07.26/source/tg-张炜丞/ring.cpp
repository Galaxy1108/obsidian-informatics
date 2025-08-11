#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=4e5+5,M=2005,K=2e6,inf=1e18;

int read(){
	int ans=0;
	char c=getchar();
	bool f=0;
	for(;!isdigit(c);c=getchar())c=getchar();
	for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
	return f?-ans:ans;
}

void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10|48);
}

int n,a[N],len[N],f[N],m,sum[M][M];
set<int> se;

void init(){
	for(int i=1;i<=n;++i){
		for(int j=len[i-1]+1;j<=len[i];++j){
			int an=K*K;
			se.clear();se.insert(0);se.insert(K);
			for(int k=j;k<=len[i];++k){
				int l=*se.lower_bound(a[k]),r=*prev(se.upper_bound(a[k]));
				an-=(r-a[k])*(a[k]-l)*2;
				se.insert(a[k]);
			}
			sum[j][len[i]]=an;
			for(int k=len[i]+1;k<=len[i+1];++k){
				int l=*se.lower_bound(a[k]),r=*prev(se.upper_bound(a[k]));
				an-=(r-a[k])*(a[k]-l)*2;
				sum[j][k]=an;
				se.insert(a[k]);
				//cout<<" j:"<<j<<" k:"<<k<<" sum:"<<sum[j][k]<<endl;
			}
		}
	}
}

signed main(){
	freopen("ring.in","r",stdin);
	freopen("ring.out","w",stdout);
	n=read();
	for(int i=1;i<=n;++i){
		len[i]=len[i-1]+read();
		for(int j=len[i-1]+1;j<=len[i];++j)a[j]=read();
	}
	for(int i=1;i<=len[1];++i){
		a[len[n]+i]=a[i];
	}
	m=len[n]+len[1];len[n+1]=m;
	init();int ans=inf;
	for(int i=1;i<=len[1];++i){
		for(int j=len[1]+1;j<=len[2];++j){
			f[j]=sum[i][j-1];
		}
		for(int j=3;j<=n+1;++j){
			for(int k=len[j-1]+1;k<=len[j];++k){
				f[k]=inf;
				for(int l=len[j-2]+1;l<=len[j-1];++l){
					f[k]=min(f[k],f[l]+sum[l][k-1]);
					//cout<<" /k:"<<k<<" l:"<<l<<" fl:"<<f[l]<<endl;
				}
				//cout<<" i:"<<i<<" k:"<<k<<" f:"<<f[k]<<endl;
			}
		}
		ans=min(ans,f[i+len[n]]);
	}
	print(ans);putchar('\n');
	return 0;
}



























