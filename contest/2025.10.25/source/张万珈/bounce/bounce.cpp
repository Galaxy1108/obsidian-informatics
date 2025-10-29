#include <bits/stdc++.h>
using namespace std;
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
const int N = 1e6+10;
int n,q;
namespace BIT{
int t[N],size;
bool vis[N];
int lowbit(int x){return x&(-x);}
void init()
{
    for(int i=1;i<=n;i++) t[i] = lowbit(i);
    size = n;
}
void modify(int x){if(vis[x])return;vis[x]=1;size--;for(;x<=n;x+=lowbit(x))t[x]--;}
int kth(int k)
{
    if(k == 0) return -1;
    int now=0,s=0;
    for(int i=19;i>=0;i--)
    {
        if(s+(1<<i) > n) continue;
        if(now + t[s+(1<<i)] < k)
        {
            now += t[s+(1<<i)];
            s += (1<<i);
        }
    }
    return s+1;
}
int get(){return size;}
}
bool vis[21];
int dfn[21],ans[21],tot;
int solve(int n,int m)
{
    // cout << n << '\n';
    if(n <= 1) return n;
    int n1 = (n - (n-1)/m - 1);
    int i = n1 - solve(n1,m) + 1;
    return i + ((i-1)/(m-1)) + 1;
}

int main()
{
    freopen("bounce.in","r",stdin);
    freopen("bounce.out","w",stdout);
    cin >> n >> q;
    BIT::init();
    tot=1;
    for(int _=1;_<=q;_++)
    {
        int tp,m;
        cin >> tp >> m;
        if(tp == 1)
        {
            if(vis[m]) continue;
            vis[m] = 1;
            for(int i=1;i<=n;i+=m)
            {
                BIT::modify(i);
            }
            tot++;
        }
        if(tp == 2)
        {
            queue<int> q;
            for(int i=1;i<=BIT::size;i+=m)
            {
                q.push(BIT::kth(i));
            }
            while(!q.empty())
            {
                BIT::modify(q.front());
                q.pop();
            }
            tot++;
        }
        if(tp == 3)
        {
            if(dfn[m] == tot) cout << ans[m] << '\n';
            else
            {
                dfn[m] = tot;
                ans[m] = BIT::kth(solve(BIT::size,m));
                cout << ans[m] << '\n';
            }
        }
    }
}
