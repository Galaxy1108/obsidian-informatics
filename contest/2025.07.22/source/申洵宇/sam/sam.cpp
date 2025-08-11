#include <bits/stdc++.h>
using namespace std;
/*
f[i][j]:低i位Sam数，第i位为j的个数
f[i][j]->f[i+1][j-2~j+2]

*/
#define MOD 1000000007
template<typename T>
class matrix{
private:
	static constexpr int SIZE=15;
private:
	T mx[SIZE][SIZE];
public:
	int n,m;
	matrix(){memset(mx,0,sizeof(mx));}
	matrix(int _n,int _m):n(_n),m(_m){memset(mx,0,sizeof(mx));} 
	matrix(int _n){
		n=m=_n;
		memset(mx,0,sizeof(mx));
		for(int i=0;i<_n;i++){
			mx[i][i]=1;
		}
	}
	const T* operator[](int x)const{
		return mx[x];
	}
	T* operator[](int x){
		return mx[x];
	}
	friend matrix operator*(const matrix& a,const matrix& b){
		assert(a.m==b.n);
		matrix res(a.n,b.m);
		for(int i=0;i<a.n;i++){
			for(int j=0;j<a.m;j++){
				for(int k=0;k<b.m;k++){
					res[i][k]+=a[i][j]*b[j][k]%MOD;
					while(res[i][k]>=MOD){
						res[i][k]-=MOD;
						break;
					}
				}
			}
		}
		return res;
	}
	friend matrix mpow(matrix b,long long p){
		assert(b.n==b.m);
		matrix res(b.n);
		while(p){
			if(p&1)res=res*b;
			p>>=1;
			b=b*b;
		}
		return res;
	}
};
int main(){
	freopen("sam.in","r",stdin);
	freopen("sam.out","w",stdout);
	long long k;
	scanf("%lld",&k);
	static matrix<long long>f(1,10),trans(10,10);
	for(int i=0;i<=9;i++){
		f[0][i]=1;
	}
	for(int i=0;i<=9;i++){
		for(int j=0;j<=9;j++){
			if(abs(i-j)<=2){
				trans[i][j]=1;
			}
		}
	}
	f=f*mpow(trans,k-1);
	long long ans=0;
	for(int i=1;i<=9;i++){
		ans+=f[0][i];
		if(ans>=MOD)ans-=MOD;
	}
	printf("%lld",ans);
	return 0;
}

