#include<bits/stdc++.h>
using namespace std;
const int N=2005;

int read(){
    int ans=0;
    char c=getchar();
    bool f=0;
    for(;!isdigit(c);c=getchar())if(c=='1')f=1;
    for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
    return f?-ans:ans;
}

void print(int x){
    if(x<0)x=-x,putchar('-');
    if(x>9)print(x/10);
    putchar(x%10|48);
}

int gcd(int a,int b){
    return b==0?a:gcd(b,a%b);
}

struct fs{
    int a,b;
    int yf(){
        int d=gcd(a,b);
        a/=d;b/=d;
    }

    void operator=(const fs &f1){
        a=f1.a,b=f1.b;
    }

    fs operator+(const fs &f1)const{
        fs ans;
        int g=gcd(b,f1.b);
        ans.b=b/g*f1.b;
        ans.a=f1.b/g*a+b/g*f1.a;
        ans.yf();
        return ans;
    }

    fs operator*(int x)const{
        fs ans=*this;
        ans.a*=x;
        ans.yf();
        return ans;
    }

    fs operator-(const fs &f1)const{
        fs ans;
        int g=gcd(b,f1.b);
        ans.b=b/g*f1.b;
        ans.a=f1.b/g*a-b/g*f1.a;
        ans.yf();
        return ans;
    }

    bool operator<(const fs &f1){
        return a*f1.b<f1.a*b;
    }
}s[N],t,an[N];

int mxd,mxn;

bool flag;
void dfs(int d,int p,fs v){
    // cout<<" d:"<<d<<" p:"<<p<<" v:"<<v.a<<" b:"<<v.b<<endl;
    if(flag)return;
    if(d==mxd){
        fs ans=t-v;
        // cout<<" ans.a:"<<ans.a<<" b:"<<ans.b<<endl;
        if(ans.a==1){
            print(mxd);putchar('\n');
            for(int i=1;i<d;++i)print(an[i].b),putchar(' ');
            print(ans.b);putchar('\n');
            flag=1;
            // exit(0);
        }
        return;
    }
    if(p>mxn)return;
    if(s[p]*(mxd-d+1)+v<t)return;
    // cout<<" dd"<<endl;
    if(v+s[p]<t)an[d]=s[p],dfs(d+1,p+1,v+s[p]);
    dfs(d,p+1,v);
}

void work(){
    // cout<<" /work a:"<<t.a<<" b:"<<t.b<<endl;
    for(mxd=1;mxd<=mxn;++mxd){
        flag=0;
        // cout<<" mxd:"<<mxd<<endl;
        dfs(1,2,{0,1});
        if(flag)return;
    }
}

void debug(){
    // cout<<" /debug"<<endl;
    int n=1000;
    for(int i=2;i<=n;++i){
        for(int j=i+1;j<=n;++j){
            if(gcd(i,j)!=1)continue;
            // cout<<" i:"<<i<<" j:"<<j<<endl;
            t.a=i;t.b=j;
            work();

        }
    }
    exit(0);
}

signed main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    for(int i=1;i<N;++i)s[i].a=1,s[i].b=i;
    mxn=N-1;
    debug();
    t.a=read();t.b=read();t.yf();mxn=N-1;
    work();
    return 0;
}
