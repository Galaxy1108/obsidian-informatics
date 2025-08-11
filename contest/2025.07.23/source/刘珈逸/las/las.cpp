#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],b[N],vis[N],id[N],f[N];
bool cmp(int x,int y){
	return f[x]>f[y];
}
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
int nxt(int x){return x==n?1:x+1;}
int pre(int x){return x==1?n:x-1;}
void work(int x){
	bool fl=0;
	if(a[x]/2>=f[nxt(x)]&&!b[x])b[x]=x,fl^=1;
	if(a[x]/2>=f[pre(x)]&&!b[pre(x)])b[pre(x)]=x,fl^=1;
	if(fl){
		f[x]=a[x]/2;
		work(pre(x));
		work(nxt(x));
	}
}
int main(){
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i],a[i]*=2,f[i]=a[i];
	for(int i=1;i<=n;i++)work(i);
	for(int i=1;i<=n;i++)id[i]=i;sort(id+1,id+1+n,cmp);
	for(int i=1;i<=n;i++){
		int x=id[i];
		if(!b[x])b[x]=x;
		else if(!b[x==1?n:x-1])b[x==1?n:x-1]=x;
	}
	for(int i=1;i<=n;i++)cout<<b[i]<<' ';
	return 0;
}
/*
若a_i>=2_a_i+1
则必定选a_i+1
否则每个人选一个没选的即可 
*/
