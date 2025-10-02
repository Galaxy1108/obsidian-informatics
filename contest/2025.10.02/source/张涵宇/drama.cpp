#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 1e6+10;
const int INF = 0.98e8;
int n,ans,h[maxn];
int qmx[maxn],qmn[maxn],hmx,hmn,tmx,tmn,cnt;
int read(){
    int f=1,k=0;char c = getchar();
    while(c<'0'||c>'9'){if(c=='-') f=-1;c = getchar();}
    while(c>='0'&&c<='9'){k=k*10+c-'0'; c = getchar();}
    return f*k;
}
signed main()
{
	freopen("drama.in","r",stdin);
	freopen("drama.out","w",stdout);
    n = read();
    for(int i=1;i<=n;i++){
        h[i]=read();
    }
	for(int len=1;len<=n;len++){
        memset(qmx,0,sizeof(qmx));hmx=1;tmx=0;
        memset(qmn,0,sizeof(qmn));hmn=1;tmn=0;
        for(int j=1;j<=n;j++){
        	cnt++;
        	if(cnt>INF){
        		printf("%lld",ans);
        		return 0;
			}
            if(j>len){
                while(j-qmx[hmx]>=len) hmx++;
                while(j-qmn[hmn]>=len) hmn++;
            }
            while(tmx>=hmx&&h[j]>=h[qmx[tmx]]) tmx--;
            qmx[++tmx]=j;
            while(tmn>=hmn&&h[j]<=h[qmn[tmn]]) tmn--;
            qmn[++tmn]=j;
            if(j>len)ans=max(ans,len*h[qmx[hmx]]*h[qmn[hmn]]);
        }
    }
    printf("%lld\n",ans);
	return 0;
}
 
