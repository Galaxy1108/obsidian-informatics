#include<bits/stdc++.h>
#define db double
#define pb push_back
#define fi first
#define se second
#define mkp make_pair
#define pii pair<int,int>
#define int long long
using namespace std;
inline int read(){
    int x=0,f=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-')f=-f;c=getchar();}
    while(c>='0'&&c<='9'){x=x*10+c-'0';c=getchar();}
    return x*f; 
}
const int mxn=1e7+10;
int n,m,md,l[mxn],r[mxn],sl[mxn],sr[mxn],s2l[mxn],s2r[mxn];
signed main(){
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
   	n=read(),m=read(),md=read();
   	for(int i=1;i<=m;i++)
   		l[i]=m-i+1,r[i]=i;
   	for(int p=2;p<=n;p++){
   		int s=0;
   		for(int i=1;i<=m;i++)
   			sr[i]=(sr[i-1]+r[i])%md,s2r[i]=(s2r[i-1]+sr[i])%md,s=(s+r[i])%md;
   		for(int i=m;i>=1;i--) 
   			sl[i]=(sl[i+1]+l[i])%md,s2l[i]=(s2l[i+1]+sl[i])%md;
   		for(int i=1;i<=m;i++){
   			r[i]=(s*i%md-s2r[i-1]-sl[i+1]*i%md+2*md)%md;
   			l[i]=(s*(m-i+1)%md-s2l[i+1]-sr[i-1]*(m-i+1)%md+2*md)%md;
   		}
   	}
   	int ans=0;
   	for(int i=1;i<=m;i++)
   		ans=(ans+l[i])%md;
   	printf("%lld\n",ans);
    return 0;
}