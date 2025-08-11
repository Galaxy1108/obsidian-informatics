#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5,M=1e5+5,P=1e9+7;

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

int a[N],n,k;

int count(int x){
    int ans=1;
    while(x){
        ans*=x%10;
        x/=10;
    }
    return ans;
}

bool cmp(int x,int y){
    return x>y;
}

struct node{
    int v,x,p;
    node(int x,int p):x(x),p(p){
        v=x*a[p];
        //cout<<" /node x:"<<x<<" p:"<<p<<" a:"<<a[p]<<" v:"<<v<<endl;
    }
    bool operator<(const node &n1)const{
        return v<n1.v;
    }
};

signed main(){
    freopen("gold.in","r",stdin);
    freopen("gold.out","w",stdout);
    n=read();k=read();
    for(int i=1;i<=n;++i){
        //cout<<" i:"<<i<<" co:"<<count(i)<<endl;
        ++a[count(i)];
    }
    sort(a+1,a+n+1,cmp);
    priority_queue<node> q;
    for(int i=1;i<=min(n,k);++i){
        //cout<<" //i:"<<a[i]<<endl;
        q.push(node(a[i],1));
    }
    int ans=0;
    //for(int i=1;i<=n;++i)cout<<" i:"<<i<<" a:"<<a[i]<<endl;
    for(int i=1;i<=k;++i){
        ans=(ans+q.top().v)%P;
        node a(q.top().x,q.top().p+1);
        q.pop();q.push(a);
    }
    print(ans);putchar('\n');
    return 0;
}