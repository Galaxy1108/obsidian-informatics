#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5,M=21;
int val[M][N];
int siz[N<<2];
int fl[N];
void build(int p,int l,int r){
    siz[p]=r-l+1;
    if(l==r)return;
    int mid=l+r>>1;
    build(p<<1,l,mid);
    build(p<<1|1,mid+1,r);
}
int query(int p,int l,int r,int k){
    if(l==r)return l;
    int mid=l+r>>1;
    if(k<=siz[p<<1])return query(p<<1,l,mid,k);
    return query(p<<1|1,mid+1,r,k-siz[p<<1]);
}
void change(int p,int l,int r,int k){
    siz[p]--;
    if(l==r)return;
    int mid=l+r>>1;
    if(k<=mid)change(p<<1,l,mid,k);
    else change(p<<1|1,mid+1,r,k);
}
int n,m;
bool tp1[M];
namespace Fread {
	const int SIZE=1<<21;char buf[SIZE],*S,*T;
	inline char getchar() {if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return '\n';}return *S++;}
}
namespace Fwrite {
	const int SIZE=1<<21;
	char buf[SIZE],*S=buf,*T=buf+SIZE;
	inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}
	inline void putchar(char c){*S++=c;if(S==T)flush();}
	struct POPOSSIBLE{~POPOSSIBLE(){flush();}}ztr;
}
#define getchar Fread :: getchar
#define putchar Fwrite :: putchar
namespace Fastio{
	struct Reader{
	    template<typename T>
    	Reader& operator >> (T& x) {
        	char c=getchar();T f=1;
        	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}x=0;
        	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}x*=f;
	        return *this;
    	}
	    Reader(){}
	}cin;
	struct Writer{
	    template<typename T>
	    Writer& operator << (T x) {
	        if(x==0){putchar('0');return *this;}
	        if(x<0){putchar('-');x=-x;}
	        static int sta[45];int top=0;
	        while(x){sta[++top]=x%10;x/=10;}
	        while(top){putchar(sta[top]+'0');--top;}
	        return *this;
    	}
    	Writer& operator << (char c) {putchar(c);return *this;}
    	Writer(){}
	}cout;
}
#define endl '\n'
#define cin Fastio :: cin
#define cout Fastio :: cout
int main(){
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout); 
    cin>>n>>m;
    for(int i=1;i<=n;i++)val[1][i]=i;
    for(int i=2;i<=20;i++){
        val[i][1]=1;
        for(int j=2;j<=n;j++){
            int y=j-(j-1)/i-1;
            if(val[i][y]<=(j-1)%i)val[i][j]=j+1-val[i][y];
            else val[i][j]=j+1-(val[i][y]+(val[i][y]-(j-1)%i-1)/(i-1)+1);
        }
    }
    build(1,1,n);
    while(m--){
        int tp,m;cin>>tp>>m;
        if(tp==1){
            if(tp1[m])continue;
            tp1[m]=1;
            for(int j=1;j<=n;j+=m)if(!fl[j]){
                fl[j]=1;
                change(1,1,n,j);
            }
        }
        if(tp==2){
            for(int j=1;j<=siz[1];j+=m-1){
                int x=query(1,1,n,j);
                fl[x]=1;
                change(1,1,n,x);
            }
        }
        if(tp==3){
            if(siz[1]==0)cout<<-1<<endl;
            else cout<<query(1,1,n,val[m][siz[1]])<<endl;
        }
    }
    return 0;
}
/*
修改是可以均摊的
只用求出n=k时的询问即可
*/
