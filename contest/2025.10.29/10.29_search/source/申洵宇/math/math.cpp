#include <bits/stdc++.h>
using namespace std;
class fraction{
private:
    static long long gcd(long long a,long long b){
        return b==0?a:gcd(b,a%b);
    }
    static long long lcm(long long a,long long b){
        return a/gcd(a,b)*b;
    }
public:
    long long fz,fm;
    fraction():fz(0),fm(1){}
    fraction(long long fz_,long long fm_):fz(fz_),fm(fm_){}
    friend void tf(fraction& x,fraction& y){
        long long g=lcm(x.fm,y.fm);
        x.fz=x.fz*(g/x.fm);
        y.fz=y.fz*(g/y.fm);
        x.fm=y.fm=g;
    }
    void yf(){
        long long g=gcd(fz,fm);
        fz/=g;
        fm/=g;
    }
    friend fraction operator-(fraction x,const fraction& y){
        long long g=lcm(x.fm,y.fm);
        x.fz=x.fz*(g/x.fm)-y.fz*(g/y.fm);
        x.fm=g;
        g=gcd(x.fz,x.fm);
        x.fz/=g;
        x.fm/=g;
        return x;
    }
    friend bool operator<(fraction x,fraction y){
        tf(x,y);
        return x.fz<y.fz;
    }
};
#define N 1000005
int maxd;
long long ans[N];
bool dfs(int x,int m,fraction f){
    // cerr<<x<<" "<<m<<' '<<f.fz<<","<<f.fm<<'\n';
    if(f.fz==0){
        cout<<maxd<<"\n";
        for(int i=1;i<=maxd;i++){
            cout<<ans[i]<<' ';
        }
         exit(0);
        return true;
    }
    if(x>maxd)return false;
    int maxn=1ll*(maxd-x+1)*f.fm/f.fz;
    int minn=max((long long)m,(f.fm+f.fz-1)/f.fz);
    // cerr<<f.fz<<' '<<f.fm<<','<<x<<' '<<maxd<<','<<minn<<"~"<<maxn<<'\n';
    for(int i=minn;i<=maxn;i++){
        ans[x]=i;
        if(dfs(x+1,i+1,f-fraction(1,i)))return true;
    }
    return false;
}
int main(){
    freopen("math.in","r",stdin);
    freopen("math.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    /*
    fraction f,g;
    while(true){
        cin>>f.fz>>f.fm;
        cin>>g.fz>>g.fm;
        cout<<(f-g).fz<<' '<<(f-g).fm<<'\n';
        cout.flush();
    }
    */
    fraction f;
    cin>>f.fz>>f.fm;
    f.yf();
    maxd=1;
    while(!dfs(1,2,f)){
        maxd++;
    }
    /*
    fraction f;
    time_t t1,dt,mt=0;
    for(int i=1;i<=1000;i++){
        for(int j=i+1;j<=1000;j++){
            f.fz=i,f.fm=j;
            cout<<i<<"/"<<j<<":\n";
            t1=clock();
            // cin>>f.fz>>f.fm;
            f.yf();
            maxd=1;
            while(!dfs(1,2,f)){
                maxd++;
                // cerr<<maxd<<' ';
            }
            dt=(clock()-t1);
            mt=max(mt,dt);
            cout<<"\nTI:"<<(double)dt/CLOCK_PER_SEC*1000<<'\n';
        }
    }
    cout<<"MAXT:"<<mt;
    */
    return 0;
}
