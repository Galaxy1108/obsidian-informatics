#include<bits/stdc++.h>
using namespace std;
const long long M=9999973;
int n,m;
long long f[101][101][101];
long long finds(int wi,int fi,int si){
	if(wi==n+1) return 1;
	if(fi+si==0) return 1;
	if(f[wi][fi][si]>0){return f[wi][fi][si];}
	f[wi][fi][si]=(f[wi][fi][si]+finds(wi+1,fi,si))%M;
	if(fi>0) f[wi][fi][si]=(f[wi][fi][si]+finds(wi+1,fi-1,si)*fi)%M;
	if(si>0) f[wi][fi][si]=(f[wi][fi][si]+finds(wi+1,fi+1,si-1)*si)%M;
	if(fi+si>=2){
		if(fi>1) f[wi][fi][si]=(f[wi][fi][si]+finds(wi+1,fi-2,si)*fi*(fi-1)/2)%M;
		if(fi>0&&si>0) f[wi][fi][si]=(f[wi][fi][si]+finds(wi+1,fi,si-1)*fi*si)%M;
		if(si>1) f[wi][fi][si]=(f[wi][fi][si]+finds(wi+1,fi+2,si-2)*si*(si-1)/2)%M;
	}
	return f[wi][fi][si]%M;
}
int main(){
	freopen("chess.in","r",stdin);
	freopen("chess.out","w",stdout);
	scanf("%d%d",&n,&m);
	printf("%lld",finds(1,0,m));
	return 0;
}
