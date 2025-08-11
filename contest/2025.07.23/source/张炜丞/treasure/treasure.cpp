#include<bits/stdc++.h>
using namespace std;
#define int long long
#define lb(x) (x&(-x))
const int N=205,M=10,K=32800,P=1e9+7;

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

int n,k,b[N],f[N][K],a[M];
vector<int> s[M];

int count(int x){
    int ans=0;
    while(x)++ans,x-=lb(x);
    return ans;
}

void dfs(int d,int state){
    if(d==k+1){
        s[count(state)].push_back(state);
        return;
    }
    dfs(d+1,state<<1);
    dfs(d+1,state<<1|1);
}

int count_2(int x){
    //cout<<" count_2 x:"<<x;
    int ans=0;
    for(int i=1;i<=k;++i){
        a[i]=x%(1<<k-i+1);
        x>>=(k-i+1);
        ans+=a[i]>>(k-i);
        a[i]-=a[i]&(1<<(k-i));
    }//cout<<" ans:"<<ans<<endl;
    return ans;
}

int nxt(int x){
    int ans=0;
    for(int i=k-1;i>=1;--i){
        //cout<<" /nxt i:"<<i<<" a:"<<a[i]<<endl;
        ans|=a[i];
        ans<<=(k-i+1);
    }
    ans|=x;
    return ans;
}

void output(int x){
    for(int i=k;i>=1;--i){
        for(int j=1;j<=i;++j){
            putchar((x&1)+'0');
            x>>=1;
        }
        putchar('\n');
    }
}

signed main(){
    freopen("treasure.in","r",stdin);
    freopen("treasure.out","w",stdout);
    n=read();k=read();int m=k*(k+1)/2,mm=1<<m;
    for(int i=1;i<=n;++i){
        b[i]=read();
        if(b[i]>(k*(k+1)/2)-(i>=k?0:(k-i)*(k-i+1)/2)){puts("0");return 0;}
    }
    dfs(1,0);
    for(int i:s[b[1]]){
        f[1][i]=1;
    }
    for(int i=1;i<n;++i){
        for(int j=0;j<mm;++j){
            if(!f[i][j])continue;
            int cnt=b[i+1]-b[i]+count_2(j);
            if(cnt<0||cnt>k)continue;
            //cout<<" i:"<<i<<" j:"<<j<<" f:"<<f[i][j]<<endl;output(j);
            for(int l:s[cnt]){
                int nx=nxt(l);
                //cout<<" j:"<<j<<" l:"<<l<<" nx:"<<nx<<endl;output(nx);
                f[i+1][nx]=(f[i+1][nx]+f[i][j])%P;
            }
        }
    }
    int ans=0;
    for(int j=0;j<mm;++j){
        ans=(ans+f[n][j])%P;
    }
    print(ans);putchar('\n');
    return 0;
}