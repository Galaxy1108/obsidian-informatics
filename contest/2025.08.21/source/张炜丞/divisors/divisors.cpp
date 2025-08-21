#include<bits/stdc++.h>
using namespace std;
// #define int long long
const int N=2505,M=11000;
// const signed P=1e9+7;

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

int n,a[N],p[N],cnt,val[N],f[N],e[N][2],tot,etot;
bool vis[N],evis[N][N];
stack<int> junk;
unordered_map<int,int> ma;

int find(int x){
    return x==f[x]?x:find(f[x]);
}

void ade(int u,int v){
    e[++etot][0]=u;e[etot][1]=v;
    f[find(u)]=find(v);
    evis[u][v]=evis[v][u]=1;
}

int newnode(int x){
    // cout<<" /newnode x:"<<x<<endl;
    val[++tot]=x;ma[x]=tot;
    f[tot]=tot;
    return tot;
}

void adde(int x,int y){
    if(ma[x]&&ma[y]&&evis[ma[x]][ma[y]]){
        return;
    }
    if(ma[x]){
        ade(ma[x],newnode(y));
    }
    else if(ma[y]){
        ade(ma[y],newnode(x));
    }
    else ade(newnode(x),newnode(y));
}

void init(){
    for(int i=2;i<=n;++i){
        if(!a[i])a[i]=i,p[++cnt]=i;
        for(int j=1;j<=cnt&&i*p[j]<=n;++j){
            a[i*p[j]]=p[j];
            if(i%p[j]==0)break;
        }
    }
}

void work(int n,int k){
    // cout<<" /work n:"<<n<<" k:"<<k<<endl;
    if(n==1)junk.push(k);
    else if(n==2){
        bool flag=1;
        adde(k,k*2);adde(k*2,k*4);
        vis[k]=vis[k*2]=1;
    }
    else if(n==3){
        bool flag=1;
        // int x=newnode(k*2,flag),y=newnode(k*6,flag),z=newnode(k*3,flag);
        adde(k*2,k*6);adde(k*6,k*3);
        vis[k]=vis[k*2]=vis[k*3]=1;
    }
    else if(n==4){
        bool flag=1;
        // int x=newnode(k*3,flag),y=newnode(k*6,flag),z=newnode(k*8,flag),l=newnode(k*12,flag);
        adde(k*3,k*6);adde(k*6,k*8);adde(k*8,k*12);
        vis[k]=vis[k*2]=vis[k*3]=vis[k*4]=1;
    }
    else if(n==5){
        bool flag=1;
        // int x=newnode(k*10,flag),y=newnode(k*15,flag),z=newnode(k*6,flag),p=newnode(k*8,flag),q=newnode(k*4,flag);
        adde(k*10,k*15);adde(k*15,k*6);adde(k*6,k*8);adde(k*8,k*4);
        vis[k]=vis[k*2]=vis[k*3]=vis[k*4]=vis[k*5]=1;
    }
    else{
        for(int i=1;i<=cnt&&p[i]<=n;++i){
            // cout<<" i:"<<i<<" p:"<<p[i<endl;
            work(n/p[i],k*p[i]);
        }
    }
    // cout<<" /workend n:"<<n<<" k:"<<k<<endl;
}

signed main(){
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    n=read();
    init();
    work(n,1);
    bool flag=0;
    int v=1;
    vector<int> s;
    while(!junk.empty()){
        int u=junk.top();junk.pop();
        // cout<<" /junk v:"<<v<<" u:"<<u<<endl;
        if(vis[u])continue;
        if(v*u<=M){
            v*=u;s.push_back(u);
        }
        else{
            for(int i:s){
                adde(v,i);
            }
            s.clear();
            v=u;s.push_back(u);
        }
    }
    for(int i:s){
        adde(v,i);
    }
    for(int i=1;i<n;++i){
        // cout<<" i:"<<i<<" find:"<<find(i)<<endl;
        if(find(i)!=find(i+1))ade(i,i+1);
    }
    for(int i=1;i<=n;++i)print(val[i]),putchar(' ');putchar('\n');
    for(int i=1;i<=etot;++i){
        print(e[i][0]);putchar(' ');print(e[i][1]);putchar('\n');
    }
    return 0;
}