/*
赛场风云变幻间，
治程独步算法巅。
代码编织成胜网，
智慧花开满园春。
*/

# include <bits/stdc++.h>

const int N=100010,INF=0x3f3f3f3f;

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

int T;
int n;
int x[N];

inline void calc(int l,int r){
	for(int c=1;c<=10;++c){
		for(int a=0;a<=10;++a){
			for(int b=0;b<=10;++b){
				for(int i=l;i<=r;++i) if(x[i]!=(1ll*a*(i-l)+b)/c) goto END;
				printf("%d %d %d\n",a,b,c); return;
				END:;
			}
		}
	}
//	puts("no solution.");
		
	return;
}

inline void solve(void){
	n=read();
	for(int i=1;i<=n;++i) x[i]=read();
	int q=read();
	while(q--){
		int l=read(),r=read();
		calc(l,r);
	}
	return;
}

int main(void){
	freopen("d.in","r",stdin);
	freopen("d.out","w",stdout);
	
	T=read();
	while(T--) solve();
	

	return 0;
}