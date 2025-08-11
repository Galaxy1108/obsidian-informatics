#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+5;

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

int n,k,s[N],a[N],b[N],ss[N],p;

bool check(){
    int ans=0;
    for(int i=1;i<=n;++i){
        int l=i;
        if(a[i]>b[i])return 0;
        while(i<n&&a[i+1]<b[l])++i;
        ++ans;
    }
    return ans<=k;
}

signed main(){
    freopen("transfer.in","r",stdin);
    freopen("transfer.out","w",stdout);
    srand(time(0));
    n=read();k=read();
    char c=getchar();
    while(c!='A'&&c!='B')c=getchar();
    for(int i=1,sa=0,sb=0;i<=n+n;++i){
        if(c=='A'){
            s[i]=1;a[++sa]=i;ss[i]=sa;
            //cout<<" i:"<<i<<" sa:"<<sa<<" ss:"<<ss[i]<<endl;
        }
        else s[i]=2,b[++sb]=i,ss[i]=sb;
        //cout<<" i:"<<i<<" ss:"<<ss[i]<<endl;
        c=getchar();
    }
    if(check()){
        puts("0");return 0;
    }
    for(int i=1;1;++i){
        int k=1;
        if(i&1)while(s[b[k]+1]!=1)++k;
        else{
            k=n;
            while(s[b[k]+1]!=1)--k;
        }
        int p=b[k];
        //cout<<" k:"<<k<<" p:"<<p<<" s:"<<s[p+1]<<" ss:"<<ss[p+1]<<endl;
        swap(b[k],a[ss[p+1]]);
        swap(ss[p],ss[p+1]);
        swap(s[p],s[p+1]);
        if(check()){
            print(i);putchar('\n');return 0;
        }
        //if(i>=10)break;
    }
}
