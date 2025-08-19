#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=1000010;
const LL INF=1e18;
inline int Qread(){
    int sum=0,flag=1;char c=getchar();
    while(c<'0'||c>'9'){if(c=='-') flag=-1;c=getchar();}
    while(c>='0'&&c<='9')sum=(sum<<1)+(sum<<3)+(c^48),c=getchar();
    return sum*flag;
}
int n,l,r;
LL f[N],q[N];
LL x[N],p[N],c[N],sw[N],sp[N];
inline LL suan(int j){
    return sp[j-1]*x[j]-sw[j];
}
inline double dp(int j,int k){
    return 1.0*(f[j]-f[k]-suan(k+1)+suan(j+1))/(sp[j]-sp[k]);
}
int main(){
	freopen("storage.in","r",stdin);
	freopen("storage.out","w",stdout);
    n=Qread();
    for(int i=1;i<=n;i++){
        x[i]=Qread(),p[i]=Qread(),c[i]=Qread();
        sp[i]=sp[i-1]+p[i];
        sw[i]=sw[i-1]+sp[i-1]*(x[i]-x[i-1]);
    }
    for(int i=1;i<=n;i++){
        while(l<r&&dp(q[l],q[l+1])<(double)x[i])l++;
        f[i]=f[q[l]]+sw[i]+suan(q[l]+1)+c[i]-sp[q[l]]*x[i];
        while(l<r&&dp(q[r],i)<dp(q[r-1],q[r]))r--;
        q[++r]=i;
    }
    printf("%lld",f[n]);
    return 0;
}
