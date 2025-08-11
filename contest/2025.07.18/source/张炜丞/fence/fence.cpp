#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lb(x) (x&(-x))
const int N=1e5+5,P=1e9+7;

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

int C(int x){
    return x*(x+1)/2%P;
}

int n,ans,h[N],w[N],st[N],sum[N];

void work1(){
    ans=0;
    for(int i=1;i<=n;++i)ans=(ans+C(h[i])*C(w[i])%P)%P;
    //cout<<" /main ans:"<<ans<<endl;
    for(int i=1;i<=n;++i){
        int mih=h[i];
        for(int j=i-1;j>=1;--j){
            mih=min(mih,h[j]);
            ans=(ans+w[i]*w[j]%P*C(mih)%P)%P;
            //cout<<" mih:"<<mih<<endl;
        }
        //cout<<" i:"<<i<<" ans:"<<ans<<endl;
    }
    print(ans);putchar('\n');
}

void work2(){
    ans=0;
    for(int i=1;i<=n;++i)ans=(ans+C(h[i])*C(w[i])%P)%P;
    for(int i=1;i<=n;++i)sum[i]=(sum[i-1]+w[i])%P;
    int top=0,ss=0;
    for(int i=1;i<=n;++i){
        while(top>0&&h[i]<h[st[top]]){
            ss=((ss-(sum[st[top]]-sum[st[top-1]])*C(h[st[top]])%P)%P+P)%P;
            //cout<<" top:"<<top<<" st:"<<st[top]<<" sum:"<<sum[top]<<endl;
            --top;
        }
        st[++top]=i;
        ss=((ss+(sum[st[top]]-sum[st[top-1]])*C(h[i])%P)%P+P)%P;
        //cout<<" /2top:"<<top<<" st:"<<st[top]<<" sum:"<<sum[top]<<endl;
        ans=(ans+ss*w[i]%P)%P;
        ans=((ans-C(h[i])*w[i]%P*w[i]%P)+P)%P;
        //cout<<" /i:"<<i<<" ans:"<<ans<<" ss:"<<ss<<endl;
    }
    print(ans);putchar('\n');
}

signed main(){
    freopen("fence.in","r",stdin);
    freopen("fence.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i)h[i]=read();
    for(int i=1;i<=n;++i)w[i]=read();
    if(n<=1000){
        //work2();
        work1();
        return 0;
    }
    else work2();
    return 0;
}
/*
3
3 2 4
1 1 1
*/