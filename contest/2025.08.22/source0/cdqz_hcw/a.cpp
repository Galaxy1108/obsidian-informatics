#include<bits/stdc++.h>
#define F(i,x,y) for(int i=(x);i<=(y);i++)
using namespace std;

const int N=1e7+5;
int f1[N],g1[N],f2[N],g2[N],f3[N],g3[N],n,m,mod;
inline int SM(int x){
	return x>mod?x-mod:x;
}
void add(int c[N],int x,int y){
	while (x<=m+1){
		c[x]=SM(c[x]+y);
		x+=x&-x;
	}
}
int query(int c[N],int x){
	int ans=0;
	while (x){
		ans=SM(ans+c[x]);
		x-=x&-x;
	}
	return ans;
}
int main() {
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie (0);
	cin>>n>>m>>mod;
	F(i,1,m){
		f1[i]=1ll*(m-i+1)*(m-i+2)/2%mod;
		g1[i]=1ll*i*(i+1)/2%mod;
	}
	F(i,1,n-1){
		F(j,1,m+2)f3[j]=g3[j]=0;
		F(j,1,m){
			add(f3,j,1ll*f1[j+1]*j%mod);
			f2[j]=(f2[j-1]+f1[j+1])%mod;
			add(g3,j,1ll*g1[j-1]*j%mod);
			g2[j]=(g2[j-1]+g1[j-1])%mod;
		}
		int tot=g1[m];
		F(j,1,m){// lol bound
			f1[j]=1ll*(m-j+2)*(m-j+1)/2%mod*tot%mod;
			f1[j]+=(mod-(query(f3,m)+mod-query(f3,j-1))%mod+1ll*(j-1)*(f2[m]+mod-f2[j-1])%mod)%mod;
			f1[j]%=mod;
			f1[j]+=(mod-1ll*(m+1)*(g2[m]+mod-g2[j-1])%mod+(query(g3,m)+mod-query(g3,j-1))%mod)%mod;
			f1[j]%=mod; 
			
			g1[j]=1ll*(j+1)*j/2%mod*tot%mod;
			g1[j]+=mod-query(f3,j);
			g1[j]%=mod;
			g1[j]+=(mod-1ll*(j+1)*g2[j]%mod+query(g3,j))%mod;
			g1[j]%=mod;
		}
	}
	cout<<g1[m]<<"\n";
	return 0;
}
