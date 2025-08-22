/*
赛场风云变幻间，
治程独步算法巅。
代码编织成胜网，
智慧花开满园春。
*/

# include <bits/stdc++.h>

const int N=2010,INF=0x3f3f3f3f;

typedef long long ll;

inline int read(void){
	int res,f=1;
	char c;
	while((c=getchar())<'0'||c>'9')
		if(c=='-') f=-1;
	res=c-48;
	while((c=getchar())>='0'&&c<='9')
		res=res*10+c-48;
	return res*f;
}
int n,w[N][N];
int minw[N];

bool ok[N];
ll dis[N];

int S,T;

inline void dijkstra(int s){
	memset(dis,INF,sizeof(dis)),dis[s]=0;
//	minw[s]=;
	
	for(int i=1,x;i<=n;++i){
		x=0;
		for(int j=1;j<=n;++j) if(!ok[j]&&dis[j]<dis[x]) x=j;
		if(!x) break;
		ok[x]=true;
		
//		printf("x = %d dis = %lld\n",x,dis[x]);
		
		for(int y=1;y<=n;++y){
			if(y==x) continue;
			
			ll len=std::min(2ll*minw[y],1ll*w[x][y]);
			
//			printf("%d -> %d len = %lld\n",x,y,len);
			
			if(dis[y]>dis[x]+len) dis[y]=dis[x]+len;
		}
	}
	
	return;
}

int main(void){
	freopen("b.in","r",stdin);
	freopen("b.out","w",stdout);
	
	n=read();
	
	if(n==1) puts("0"),exit(0);
	
	for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) w[i][j]=w[j][i]=read();
	
	int mx=INF;
	for(int i=1;i<=n;++i) for(int j=i+1;j<=n;++j) mx=std::min(mx,w[i][j]);
	for(int i=1;i<=n;++i) for(int j=1;j<=n;++j) if(i!=j) w[i][j]-=mx;
	
//	for(int i=1;i<=n;++i,puts("")) for(int j=1;j<=n;++j) printf("%d ",w[i][j]);
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j) if(i!=j&&w[i][j]==0) S=i,T=j;
		
	}
	
	for(int i=1;i<=n;++i){
		minw[i]=INF;
		for(int j=1;j<=n;++j){
			if(i!=j) minw[i]=std::min(minw[i],w[i][j]);
		}
//		printf("i = %d minw = %d\n",i,minw[i]);		
	}
	
//	printf("s = %d t = %d\n",S,T);
	
	dijkstra(S);
	
	for(int i=1;i<=n;++i) printf("%lld\n",dis[i]+1ll*(n-1)*mx);

	return 0;
}