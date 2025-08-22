/*
赛场风云变幻间，
治程独步算法巅。
代码编织成胜网，
智慧花开满园春。
*/

# include <bits/stdc++.h>

const int N=5010,INF=0x3f3f3f3f;

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

int n,seed;
int a[N][N];

void gen(int n,int seed){
    std::mt19937 rng(seed);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n+1;++j){
            a[i][j]=j;
            std::swap(a[i][j],a[i][rng()%j+1]);
        }
    }
	return;
}

int ban[N];
int ch[N];
int val[N][N];

int ans[N];

inline int calc(void){
	int r=1;
	while(ban[r]) ++r;
	return r;
}

int main(void){
	freopen("c.in","r",stdin);
	freopen("c.out","w",stdout);
	
	n=read(),seed=read();
	if(seed==0){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n+1;++j) a[i][j]=read();
		}
	}else gen(n,seed);
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n+1;++j) val[i][a[i][j]]=j;
	}
	
	for(int i=n;i;--i){
		ch[i]=1;
		while(ban[val[i][ch[i]]]) ++ch[i];
		ban[val[i][ch[i]]]=true;
	}
	
//	printf("mysolver!\n");
	
	ans[1]=calc();
//	printf("uutt = %d\n",ans[1]);
	
	for(int l=1,r=n,t=1,nc;t<n;++t){
		ban[nc=val[r][ch[r]]]=false;
		l=(l==1)?n:l-1,r=(r==1)?n:r-1; // erase r. insert l
		
		for(int i=r;i!=l;i=(i==1)?n:i-1){
//			printf("i = %d\n",i);
			
			if(a[i][nc]<ch[i]){
//				printf("str changed. i = %d new = %d old = %d\n",i,nc,val[i][ch[i]]);
				
				int _new=nc,_old=val[i][ch[i]];
				
				ban[nc]=true;
				ban[val[i][ch[i]]]=false;
				
				ch[i]=a[i][nc];
				nc=_old;
				
			}
		}
		
//		for(int i=1;i<=n+1;++i) printf("%d",ban[i]); puts("");
//		printf("l = %d\n",l);
		
		ch[l]=1;
		while(ban[val[l][ch[l]]]) ++ch[l];
		ban[val[l][ch[l]]]=true;
		
//		printf("ch = %d\n",ch[l]);
		
		ans[l]=calc();
	}
	
	for(int i=1;i<=n;++i) printf("%d ",ans[i]); puts("");

	return 0;
}