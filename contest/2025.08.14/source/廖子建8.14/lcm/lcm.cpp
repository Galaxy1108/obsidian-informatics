#include<bits/stdc++.h>
#define int __int128
#define N 1000000
using namespace std;
int t,n,p,ans,lcm,ux,uy,uz,cnt;
struct Num{
	int a,b;
	Num friend operator*(Num const &x,Num const &y){return {(x.a*y.a+2*x.b*y.b),(x.a*y.b+x.b*y.a)};}
};
const Num e={1,0};
Num u;
Num fpow(Num x,int y){
	if(!y)return e;
	if(y&1)return fpow(x*x,y>>1)*x;
	return fpow(x*x,y>>1);
}
int gcd(int x,int y){
	if(!y)return x;
	return gcd(y,x%y);
}
int read(){
	int f=1,g=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		g=g*10+ch-'0';
		ch=getchar();
	}
	return f*g;
}
void print(int x){
	if(x<0){
		putchar('-');
		x*=-1;
	}
	if(x>9)print(x/10);
	putchar(x%10+'0');
	return;
}
main(){
	freopen("lcm1.in","r",stdin);
	freopen("lcm.out","w",stdout);
	t=read();
	while(t--){
		n=read(),p=read();
		ans=0,lcm=1,u=e;
		for(int i=1,j;i<=n;i++){
			u=u*(Num){1,1};
//			cout<<(long long)i<<" "<<(long long)n<<" "<<(long long)lcm<<" "<<(long long)u.b<<" for\n";
			ux=u.b,uy=lcm,uz=gcd(u.b,lcm),lcm=1;
			j=2;
			while(ux>1&&uy>1&&uz>1){
//				cout<<(long long)ux<<" "<<(long long)uy<<" "<<(long long)uz<<" "<<(long long)j<<" while\n";
				cnt=0;
				while(uz%j==0)uz/=j,cnt++;
				if(!cnt){
					j++;
					continue;
				}
				while(ux%j==0){
					if(cnt<=0)lcm*=j;
					ux/=j,cnt--;
				}
//				cout<<(long long)j<<" aa\n";
				while(uy%j==0){
					if(cnt<=0)lcm*=j;
					uy/=j,cnt--;
				}
				j++;
			}
			lcm*=ux*uy;
//			cout<<(long long)lcm<<" "<<(long long)u.b<<" for\n";
			ans=(ans+lcm%p*i%p)%p;
		}
		print(ans),putchar('\n');
	}
	return 0;
}
