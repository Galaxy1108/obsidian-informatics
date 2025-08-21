#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5005;
const signed P=1e9+7;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='-')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int n,a[N],ans;
int power(int x,int y){
    int ans=1;
    while(y){
        if(y&1)ans=ans*x%P;
        x=x*x%P;
        y>>=1;
    }
    return ans;
}

bool cmp(int x,int y){return x>y;}

signed main(){
    freopen("dice.in","r",stdin);
    freopen("dice.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i){
        a[i]=read();
    }
    sort(a+1,a+n+1,cmp);
    // for(int i=1;i<=n;++i)iv[i]=power(a[i],P-2);
    int ans=0,iv=1;
    for(int i=1;i<=n;++i){
        iv=iv*power(a[i],P-2)%P;
        for(int j=a[i];j>a[i+1];--j){
            int s=(j-1)*power(j,P-2)%P;
            int s2=(power(s,i)-1)%P*power(s-1,P-2)%P;
            int s3=power(j,i)*s2%P;
            ans=((ans+s3*iv)%P+P)%P;
        }
    }
    print(ans);putchar('\n');
    return 0;
}
