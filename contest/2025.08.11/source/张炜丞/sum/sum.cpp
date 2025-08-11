#include<bits/stdc++.h>
using namespace std;
#define lb(x) (x&(-x))
#define int long long
const int N=1e6+5,M=1e3+5,inf=1e18;

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

int T,n,k;
bool vis[N];
vector<int> nums;

void work(){
    for(int i=1;i<=n;++i)vis[i]=0;nums.clear();
    for(int i=2;i<n;++i){
        if(n%i==0)continue;
        bool flag=1;
        for(int j=i;j<n;j+=i)if(vis[j]){flag=0;break;}
        if(!flag)continue;
        for(int j=i;j<n;j+=i){
            nums.push_back(j);
            vis[j]=1;vis[n-j]=1;
        }
    }
    if(k>nums.size()){puts("-1");return ;}
    sort(nums.begin(),nums.end());
    print(nums[k-1]);putchar('\n');
    // for(auto i:nums){
    //     cout<<i<<" ";
    // }cout<<endl;
    // cout<<" len1:"<<nums.size()<<endl;
}

void setn(int x){    
    for(int j=x;j<n;j+=x)if(vis[j])return;
    for(int j=x;j<n;j+=x){
        nums.push_back(j);
        vis[j]=1;vis[n-j]=1;
    }
}

void work2(){
    for(int i=1;i<=n;++i)vis[i]=0;nums.clear();
    for(int i=2;i<n;++i){
        if(n%i==0){
            vis[i]=1;
            setn(n-i);
            continue;
        }
        setn(i);
    }
    if(k>nums.size()){puts("-1");return ;}
    sort(nums.begin(),nums.end());
    print(nums[k-1]);putchar('\n');
    //cout<<" len2:"<<nums.size()<<endl;
}

signed main(){
    freopen("sum.in","r",stdin);
    freopen("sum.out","w",stdout);
    T=read();
    while(T--){
        n=read();k=read();
        if(n&1){
            print(k*2<n?k*2:-1);putchar('\n');
        }
        else {
            if(n<=1e6){work();}
            else puts("-1");
        }
    }
    return 0;
}