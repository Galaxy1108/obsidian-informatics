#include<bits/stdc++.h>
#define gc getchar()
#define ll long long
#define I inline int
#define V inline void
#define LL inline long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,b,a) for(int i=b;i>=a;--i)
using namespace std;
LL read(){
	ll x=0;bool fl=0;char s=gc;
	while('0'>s||s>'9'){fl|=(s=='-');s=gc;}
	while('0'<=s&&s<='9'){x=x*10+s-48;s=gc;}
	return fl?-x:x;
}

const int N=211,A=201*200/2;
int n;
ll Mod,ans,f[N*N][3][2];

int main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout); 
	
	n=read(),Mod=read();
	f[A][0][0]=1;
	FOR(i,0,n-1){
		int p=(i&1),L=-i*(i+1)/2,R=i*(i+1)/2;
		FOR(j,L,R)FOR(k,0,2)f[A+j][k][p^1]=0;
		FOR(j,L,R){
			FOR(k,-i,i){
				if(k<0){
					FOR(now,0,2)f[A+j+k][1][p^1]=(f[A+j+k][1][p^1]+f[A+j][now][p]*(i+k+1))%Mod;
				}
				if(k>0){
					FOR(now,0,2)f[A+j+k][2][p^1]=(f[A+j+k][2][p^1]+f[A+j][now][p]*(i-k+1))%Mod;
				}
				if(k==0){
					FOR(now,0,2)f[A+j][now][p^1]=(f[A+j][now][p^1]+f[A+j][now][p]*(i+1))%Mod;
				}		
			}
		}
	}	
	FOR(j,1,n*(n-1)/2)ans=(ans+f[A+j][1][n&1])%Mod;
	cout<<ans;
	
	//cerr<<endl<<(double)clock()/CLOCKS_PER_SEC;
	return 0;
}
/*
4 403458273

48 296791782

140212446

97 348267369

297317240


#include<bits/stdc++.h>
#define gc getchar()
#define ll long long
#define I inline int
#define V inline void
#define LL inline long long
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,b,a) for(int i=b;i>=a;--i)
using namespace std;
LL read(){
	ll x=0;bool fl=0;char s=gc;
	while('0'>s||s>'9'){fl|=(s=='-');s=gc;}
	while('0'<=s&&s<='9'){x=x*10+s-48;s=gc;}
	return fl?-x:x;
}

const int N=211,A=211*210/2;
int n;
ll Mod,ans,f[N*N][3][2],add1[N*N][3],add2[N*N][3];

int main(){
	n=read(),Mod=read();
	f[A][0][0]=1;
	FOR(i,0,n-1){
		int p=(i&1),L=-i*(i+1)/2,R=i*(i+1)/2;
		FOR(j,L,R)FOR(k,0,2)f[A+j][k][p^1]=0;
		FOR(j,L,R)FOR(k,1,2)add1[A+j][k]=add2[A+j][k]=0;
		
		FOR(j,L,R){
			FOR(now,0,2)
				add1[A+j-1][1]=(add1[A+j-1][1]-(i+1)*f[A+j][now][p]+Mod)%Mod,
				add1[A+j-i-1][1]=(add1[A+j-i-1][1]+(i+1)*f[A+j][now][p]+Mod)%Mod;
			FOR(now,0,2)
				add2[A+j-1][1]=(add2[A+j-1][1]-f[A+j][now][p]+Mod)%Mod,
				add2[A+j-i-1][1]=(add2[A+j-i-1][1]+f[A+j][now][p]+Mod)%Mod,
				add3[A+j-i-1][1]=(add3[A+j-i-1][1]+i*f[A+j][now][p])%Mod;
			
			
			FOR(now,0,2)
				add1[A+j+1][2]=(add1[A+j+1][2]+(i+1)*f[A+j][now][p])%Mod,
				add1[A+j+i+1][2]=(add1[A+j+i+1][2]-(i+1)*f[A+j][now][p])%Mod,			
			FOR(now,0,2)
				add2[A+j+1][1]=(add2[A+j+1][2]+f[A+j][now][p])%Mod,
				add2[A+j-i+1][2]=(add2[A+j+i+1][2]-f[A+j][now][p])%Mod,
				add3[A+j-i-1][2]=(add3[A+j-i-1][2]-i*f[A+j][now][p])%Mod;
			
			FOR(now,0,2)f[A+j][now][p^1]=(f[A+j][now][p^1]+f[A+j][now][p])%Mod;
		}	
		
		ROF(j,R,L)add2[A+j][1]=(add2[j][1]+add2[A+j+1][1])%Mod;	
		ROF(j,R,L){
			add1[A+j][1]=(add1[A+j][1]+add1[A+j+1][1])%Mod,
			add2[A+j][1]=(add2[A+j][1]+add2[A+j+1][1])%Mod;
			f[A+j][1][p^1]=(f[A+j][1][p^1]+add1[A+j][1]+add2[A+j][1])%Mod;
		}
		
		FOR(j,L,R)add2[A+j][2]=(add2[j][2]+add2[A+j-1][2])%Mod;	
		FOR(j,L,R){
			add1[A+j][2]=(add1[A+j][2]+add1[A+j-1][2])%Mod,
			add2[A+j][2]=(add2[A+j][2]+add2[A+j-1][2])%Mod;
			f[A+j][2][p^1]=(f[A+j][1][p^1]+add1[A+j][2]+add2[A+j][2])%Mod;
		}		
	}	
	FOR(j,1,n*(n-1)/2)ans=(ans+f[A+j][1][n&1])%Mod;
	cout<<ans;
	
	cerr<<endl<<(double)clock()/CLOCKS_PER_SEC;
	return 0;
}
/*
4 403458273

48 296791782

140212446

97 348267369

297317240
*/ 



