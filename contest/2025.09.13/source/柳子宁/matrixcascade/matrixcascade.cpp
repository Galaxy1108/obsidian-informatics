#include<bits/stdc++.h>
using namespace std;
int T,n;
long long X,Y,x,y;
int p[100010],q[100010],pl[100010];
int tag[110][110];
int check1(){
	int t=1;
	long long X=0,Y=0;
	for(int i=1;i<=n*n;++i){
		q[t]=p[i],t+=n;
		if(t>n*n) t-=n*n,++t;
	}
	for(int i=1;i<=n*n;++i){
		for(int j=i+1;j<=n*n;++j){
			if(p[i]>p[j]) ++X;
			if(q[i]>q[j]) ++Y;
		}
	}
	if((::X)==X&&(::Y)==Y) return 1;
	return 0;
}
long long check(){
	int t=1;
	long long X=0,Y=0;
	for(int i=1;i<=n*n;++i){
		q[t]=p[i],t+=n;
		if(t>n*n) t-=n*n,++t;
	}
	for(int i=1;i<=n*n;++i){
		for(int j=i+1;j<=n*n;++j){
			if(p[i]>p[j]) ++X;
			if(q[i]>q[j]) ++Y;
		}
	}
	x=X,y=Y;
	return 0;
}
void move1(){
	int t=1;
	for(int i=1;i<=n*n;++i){
		q[t]=p[i],t+=n;
		if(t>n*n) t-=n*n,++t;
		pl[p[i]]=i;
	}
	for(int i=1;i<=n*n;++i){
		for(int j=i+1;j<=n*n;++j){
			tag[i][j]=1;
		}
	}
	for(int i=1;i<=n*n;++i){
		int vp=n*n+1,vq=n*n+1;
		for(int j=i+1;j<=n*n;++j){
			if(p[i]>p[j]) tag[p[j]][p[i]]=0;
			else if(vp<p[j]) tag[p[i]][p[j]]=0;
			if(q[i]>q[j]) tag[q[j]][q[i]]=0;
			else if(vq<q[j]) tag[q[i]][q[j]]=0;
			
			if(p[j]>p[i]) vp=min(vp,p[j]);
			if(q[j]>q[i]) vq=min(vq,q[j]);
		}
	}
	for(int i=1;i<=n*n;++i){
		for(int j=i+1;j<=n*n;++j){
			if(tag[i][j]){
				swap(p[pl[i]],p[pl[j]]);
				return;
			}
		}
	}
	return;
}
void move2(){
	int t=1;
	for(int i=1;i<=n*n;++i){
		q[t]=p[i],t+=n;
		if(t>n*n) t-=n*n,++t;
		pl[p[i]]=i;
	}
	for(int i=1;i<=n*n;++i){
		for(int j=i+1;j<=n*n;++j){
			tag[i][j]=1;
		}
	}
	for(int i=1;i<=n*n;++i){
		int vp=n*n+1,vq=0;
		for(int j=i+1;j<=n*n;++j){
			if(p[i]>p[j]) tag[p[j]][p[i]]=0;
			else if(vp<p[j]) tag[p[i]][p[j]]=0;
			
			if(q[i]<q[j]) tag[q[i]][q[j]]=0;
			else if(vq>q[j]) tag[q[j]][q[i]]=0;
			
			if(p[j]>p[i]) vp=min(vp,p[j]);
			if(q[i]>q[j]) vq=max(vq,q[j]);
		}
	}
	for(int i=1;i<=n*n;++i){
		for(int j=i+1;j<=n*n;++j){
			if(tag[i][j]){
				swap(p[pl[i]],p[pl[j]]);
				return;
			}
		}
	}
	return;
}
void solven10(){
	for(int i=1;i<=n*n;++i) p[i]=i;
	check();
	while(x+y<X+Y){
		move1();
		++x,++y;
	}
	while(x<X){
		move2();
		++x,--y;
	}
}
int main()
{
	freopen("matrixcascade.in","r",stdin);
	freopen("matrixcascade.out","w",stdout);
	
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		scanf("%lld%lld",&X,&Y);
		long long v1=1ll*n*n*(n-1)*(n-1)/4;
		long long v2=1ll*n*n*(n*n-1)-v1;
		int Tag=1;
		Tag&=(X+Y>=v1);
		Tag&=(X+Y<=v2);
		Tag&=(((X+Y)&1)==(v1&1));
		Tag&=(X-Y<=v1);
		Tag&=(X-Y>=-v1);
		if(!Tag){
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		if(n<=3){
			for(int i=1;i<=n*n;++i) p[i]=i;
			do{
				if(check1()) break;
			}while(next_permutation(p+1,p+n*n+1));
			for(int i=1;i<=n;++i){
				for(int j=i*n-n+1;j<=i*n;++j){
					printf("%d ",p[j]);
				}
				printf("\n");
			} 
		}
		else if(X==0){
			for(int i=1;i<=n;++i){
				for(int j=i*n-n+1;j<=i*n;++j){
					printf("%d ",j);
				}
				printf("\n");
			} 
		}
		else if(Y==0){
			for(int i=1;i<=n;++i){
				for(int j=i;j<=n*n;j+=n){
					printf("%d ",j);
				}
				printf("\n");
			} 
		}
		else{
			if(n<=10){
				solven10();
				for(int i=1;i<=n;++i){
					for(int j=i*n-n+1;j<=i*n;++j){
						printf("%d ",p[j]);
					}
					printf("\n");
				} 
				check();
			} 
			else{
				for(int i=1;i<=n;++i){
					for(int j=i*n-n+1;j<=i*n;++j){
						printf("%d ",j);
					}
					printf("\n");
				} 
			}
		}
	} 
	return 0;
}
