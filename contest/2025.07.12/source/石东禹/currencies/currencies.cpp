#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int maxn=2e5+10;
ll n,m,q;
ll head[maxn],v[maxn],w[maxn],nxt[maxn],u[maxn],cnt;
ll s[maxn],t[maxn],x[maxn],y[maxn];

void add(int uu,int vv){
	nxt[++cnt]=head[uu];head[uu]=cnt;v[cnt]=vv;u[cnt]=uu;//w[cnt]=ww;
	return;
}

ll path[maxn],l;
int vis[maxn];


bool dfs(ll now,ll des){
//	path[++l]=now;
	if(now==des){
		return true;
	}
	vis[now]=1;
//	printf("%d\n",now);
	for(ll i=head[now];i;i=nxt[i]){
		if(vis[v[i]]==0)
			if(dfs(v[i],des)){
				path[++l]=i;return true;
			}
			
	}
	return false;
}

bool cmp(int a,int b){
	return w[a]<w[b];
}


int main(){
//	freopen("currencies.in","r",stdin);
//	freopen("currencies.out","w",stdout);
	
	scanf("%lld%lld%lld",&n,&m,&q);
	ll aa, bb;
	
//	printf("-------\n");
	
	
	for(int i=1;i<n;i++){
		scanf("%lld%lld",&aa,&bb);
		add(aa,bb);//add(bb,aa);
	}
	ll p,c;
	
//	printf("----7777---\n");
	
	for(int i=1;i<=m;i++){
		scanf("%lld%lld",&p,&c);
		w[p]=c;
//		w[p*2-1]=c;w[p*2]=c;
	}
	
	
//	printf("---&&&&&&----\n");
	
	for(int i=1;i<=q;i++){
		scanf("%lld%lld%lld%lld",&s[i],&t[i],&x[i],&y[i]);
	}
	
	
//	printf("-------\n");
//	printf("%lld\n",q);
	
	for(int tt=1;tt<=q;tt++){
		
//		printf("----!!!!!!!!!!!!!!!!!!!!!!---\n");
		
		l=0;
		memset(vis,0,sizeof(vis));
		memset(path,0,sizeof(vis));
		bool ghj=dfs(s[tt],t[tt]);
		
//		printf("-----784578573775475--\n");
		
//		for(int i=1;i<=l;i++){
//			printf("%d ",path[i]);
//		}
//		printf("\n");
		
		sort(path+1,path+l+1,cmp);
		ll sum=0;p=0;
		
//		printf("-----784578573775475--\n");
		
		for(int i=1;i<=l;i++){
			sum+=w[path[i]];
			if(sum<=y[tt]){
				p=i;
			}else{
				break;
			}
		}
		
//		printf("-----784578573775475--\n");
		
		if(l-p>x[tt])printf("-1\n");
		else printf("%lld\n",x[tt]-l+p);
	}
	return 0;
}
