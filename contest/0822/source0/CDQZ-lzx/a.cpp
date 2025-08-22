/*
赛场风云变幻间，
治程独步算法巅。
代码编织成胜网，
智慧花开满园春。
*/

# include <bits/stdc++.h>

const int N=10000010,INF=0x3f3f3f3f;

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

int Ldp[2][N],Rdp[2][N];

int n,m,mod;

inline int adc(int a,int b){
	return (a+b>=mod)?(a+b-mod):(a+b);
}
inline int dec(int a,int b){
	return (a<b)?(a-b+mod):(a-b);
}
inline int mul(int a,int b){
	return 1ll*a*b%mod;
}
inline int qpow(int d,int p){
	int ans=1;
	while(p){
		if(p&1) ans=1ll*ans*d%mod;
		d=1ll*d*d%mod,p>>=1;
	}
	return ans;
}

// Ldp[x]: sum of (r <= x)
// Rdp[x]: sum of (l >= x)

int main(void){
	freopen("a.in","r",stdin);
	freopen("a.out","w",stdout);
	
	n=read(),m=read(),mod=read();
	
	int c=0;
	
	int sum=0;
	
	for(int i=1;i<=n;++i){
		c^=1;
		sum=(i==1?1:Ldp[c^1][m]);
		
		assert(Ldp[c^1][m]==Rdp[c^1][1]);
		
//		printf("sum = %d\n",sum);

//		memset(Ldp[c],0,sizeof(Ldp[c]));
//		memset(Rdp[c],0,sizeof(Rdp[c]));
		
		for(int i=0;i<=m;++i) Ldp[c][i]=Rdp[c][i]=0;
		
		int cur=0;
		
		for(int r=1;r<=m;++r){ // calc Ldp[i]
			int ret=mul(r,sum);
			if(i==1) Ldp[c][r]=ret;
			else{
				cur=adc(cur,Ldp[c^1][r-1]);
				Ldp[c][r]=dec(ret,adc(cur,mul(Rdp[c^1][r+1],r)));
			}			
//			printf("rascal = %d\n",adc(Ldp[c^1][r-1],mul(Rdp[c^1][r+1],r)));
			Ldp[c][r]=adc(Ldp[c][r],Ldp[c][r-1]);
		}
		cur=0;
		
		for(int l=m;l;--l){
			int ret=mul(m-l+1,sum);
			if(i==1) Rdp[c][l]=ret;
			else{
				cur=adc(cur,Rdp[c^1][l+1]);
				Rdp[c][l]=dec(ret,adc(cur,mul(Ldp[c^1][l-1],(m-l+1))));
			}
			Rdp[c][l]=adc(Rdp[c][l],Rdp[c][l+1]);
		}
		
//		printf("%d\n",Ldp[c][m]);
	}
	
	printf("%d",Ldp[c][m]);

	return 0;
}