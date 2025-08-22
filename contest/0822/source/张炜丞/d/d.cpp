#include<bits/stdc++.h>
using namespace std;
#define int long long
// #define lb(x) (x&(-x))
const int N=1e5+5,inf=1e9;

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

int n,y[N],s[N],Q;

int gcd(int x,int y){
    if(y==0)return x;
    else return gcd(y,x%y);
}

bool check(int l,int r,int a,int b,int c){
    // cout<<" /check a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
    for(int i=l;i<=r;++i){
        int v=(a*(i-l)+b)/c;
        // cout<<" /check v:"<<v<<" y:"<<y<<endl;
        if(v<y[i])return 0;
    }
    return 1;
}

bool check2(int l,int r,int a,int b,int c){
    // cout<<" /check a:"<<a<<" b:"<<b<<" c:"<<c<<endl;
    for(int i=l;i<=r;++i){
        int v=(a*(i-l)+b)/c;
        // cout<<" /check v:"<<v<<" y:"<<y<<endl;
        if(v!=y[i])return 0;
    }
    return 1;
}

void work(){
    n=read();
    for(int i=1;i<=n;++i)y[i]=read(),s[i]=s[i-1]+y[i];
    Q=read();
    for(int i=1;i<=Q;++i){
        int l=read(),r=read();
        if(l==r){
            print(0);putchar(' ');
            print(y[l]);putchar(' ');
            print(1);putchar('\n');
            continue;
        }
        int a=y[r]-y[l],c=r-l,d=gcd(a,c);
        // cout<<" l:"<<l<<" r:"<<r<<" a:"<<a<<" c:"<<c<<endl;
        a/=d;c/=d;
        if(c==1){
            int b=y[l];
            print(a);putchar(' ');
            print(b);putchar(' ');
            print(c);putchar('\n');
        }
        // else if(c<a){
        //     int ll=y[l]*c,rr=y[r]*c,mid;
        //     while(ll<rr){
        //         mid=ll+rr>>1;
        //         if(check(l,r,a,mid,c))rr=mid;
        //         else ll=mid+1;
        //     }
        //     print(a);putchar(' ');
        //     print(ll);putchar(' ');
        //     print(c);putchar('\n');
        // }
        else{
            int aa=a;
            for(int a=0;a<=aa;++a){
                // cout<<" a:"<<a<<endl;
                int anb=0,anc=0;
                for(int i=c;i>0;--i){
                    if(abs(((a*c)/i)-aa)>1)continue;
                    int ll=y[l]*i,rr=y[r]*i,mid;
                    while(ll<rr){
                        mid=ll+rr>>1;
                        if(check(l,r,a,mid,i))rr=mid;
                        else ll=mid+1;
                    }
                    if(check2(l,r,a,ll,i)){
                        anb=ll;anc=i;
                    }
                }
                if(anc){
                    print(a);putchar(' ');
                    print(anb);putchar(' ');
                    print(anc);putchar('\n');
                    break;
                }
            }
        }
    }
}

signed main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    int T=read();
    while(T--){
        work();
    }
    return 0;
}