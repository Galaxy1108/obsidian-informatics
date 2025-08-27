#include <bits/stdc++.h>
using namespace std;
long long n,s,t,x,y;
long long solve1(){
    constexpr int D=250;
    static int st[35][505];
    for(int i=-250;i<=250;i++){
        st[0][D+i]=(i<t?i+y:i-x);
    }
    for(int i=1;i<=30;i++){
        for(int j=-250;j<250;j++){
            st[i][D+j]=st[i-1][D+st[i-1][D+j]];
        }
    }
    int now=s;
    for(int i=30;i>=0;i--){
        if((n>>i)&1){
            now=st[i][D+now];
        }
    }
    return now;
}
long long solve2(){
    static long long ti;
    if(s>=t){
        ti=(s-t+x)/x;
        if(n<=ti){
            return s-n*x;
        }
        n-=ti;
        s-=ti*x;
        if(n&1)return s+y;
        else return s;
    }
    else{
        ti=(t-s+y-1)/y;
        if(n<=ti){
            return s+n*y;
        }
        n-=ti;
        s+=ti*y;
        if(n&1)return s-x;
        else return s;
    }
}
long long solve3(){
    static long long ti;
    while(n>0){
        if(s>=t){
            ti=(s-t+x)/x;
            if(n<=ti){
                return s-n*x;
            }
            n-=ti;
            s-=ti*x;
        }
        else{
            ti=(t-s+y-1)/y;
            if(n<=ti){
                return s+n*y;
            }
            n-=ti;
            s+=ti*y;
        }
    }
    return s;
}
void solve(){
    cin>>n>>s>>t>>x>>y;
    if(x<=100&&y<=100&&abs(s)<=100&&abs(t)<=100){
        cout<<solve1()<<'\n';
    }
    else if(x==y){
        cout<<solve2()<<'\n';
    }
    else{
        cout<<solve3()<<'\n';
    }
}
int main(){
    freopen("never.in","r",stdin);
    freopen("never.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;
    while(T--){
        solve();
    }
    /*test code
    srand(unsigned(time(NULL)));
    for(long long i=1;;i++){
        n=1ll*rand()*rand()%1000000000+1;
        s=rand()%201-100;
        t=rand()%201-100;
        x=y=rand()%100+1;
        if(solve1()!=solve2()){
            cerr<<n<<' '<<s<<' '<<t<<' '<<x<<' '<<y<<":"<<solve1()<<","<<solve2()<<'\n';
            return 0;
        }
        if(i==((i>>20)<<20))cerr<<i<<"\n";
    }
    */
    return 0;
}