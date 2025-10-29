#include <bits/stdc++.h>
//namespace Fread {
//	const int SIZE=1<<21;char buf[SIZE],*S,*T;
//	inline char getchar() {if(S==T){T=(S=buf)+fread(buf,1,SIZE,stdin);if(S==T)return '\n';}return *S++;}
//}
//namespace Fwrite {
//	const int SIZE=1<<21;
//	char buf[SIZE],*S=buf,*T=buf+SIZE;
//	inline void flush(){fwrite(buf,1,S-buf,stdout);S=buf;}
//	inline void putchar(char c){*S++=c;if(S==T)flush();}
//	struct POPOSSIBLE{~POPOSSIBLE(){flush();}}ztr;
//}
//#define getchar Fread :: getchar
//#define putchar Fwrite :: putchar
//namespace Fastio{
//	struct Reader{
//	    template<typename T>
//    	Reader& operator >> (T& x) {
//        	char c=getchar();T f=1;
//        	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}x=0;
//        	while(c>='0'&&c<='9'){x=x*10+(c-'0');c=getchar();}x*=f;
//	        return *this;
//    	}
//	    Reader(){}
//	}cin;
//	struct Writer{
//	    template<typename T>
//	    Writer& operator << (T x) {
//	        if(x==0){putchar('0');return *this;}
//	        if(x<0){putchar('-');x=-x;}
//	        static int sta[45];int top=0;
//	        while(x){sta[++top]=x%10;x/=10;}
//	        while(top){putchar(sta[top]+'0');--top;}
//	        return *this;
//    	}
//    	Writer& operator << (char c) {putchar(c);return *this;}
//    	Writer(){}
//	}cout;
//}
//#define endl '\n'
//#define cin Fastio :: cin
//#define cout Fastio :: cout
#define il inline
#define W while
#define pii std::pair<int,int>
#define fi first
#define se second
#define Fu(i,a,b) for(int i=a;i<=b;i++)
#define max(a,b) ((a>b)?a:b)
#define min(a,b) ((a<b)?a:b)
#define lowb(x) ((x)&(-x))

const int N=1e6+2;
const int inf=2e8+7;

il int read () {
	int x=0; bool flag=0; char ch=getchar();
	while (!isdigit(ch)) flag=ch=='-', ch=getchar();
	while (isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48), ch=getchar();
	return flag?-x:x;
}

int n, _;
bool a[N];
struct BIT {
    int tr[N];
    il void modify (int u) {
        W (u<=n)
            tr[u]++,
            u+=lowb(u);
    }
    int an;
    il int query (int u) {
        an=0;
        W (u)
            an+=tr[u],
            u-=lowb(u);
        return u;
    }
} L;
struct vector {
    int pre, nxt;
} p[N];

signed main () {
freopen("bounce.in", "r", stdin);
freopen("bounce.out", "w", stdout);

    n=read(), _=read();

    Fu (i, 0, n)
        p[i].pre=i-1, p[i].nxt=i+1;

	std::cout<<rand()%15;
//    int op, m;
//    W (_--) {
//        op=read(), m=read();
//        if (op==1) {
//            for (int u=1; u<=n; u+=m)
//                if (!a[u]) {
//                    a[u]=true,
//                    p[p[u].pre].nxt=p[u].nxt,
//                    p[p[u].nxt].pre=p[u].pre;
//                    L.modify(u);
//                }
//        } else if (op==2) {
//
//        }
//    }

}
/*

*/
