#include<bits/stdc++.h>
using namespace std;
const int N=55;

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

int a[N],b[N],cnt[N],ma[205],ans,n;
vector<int> nums;

signed main(){
    freopen("lineup.in","r",stdin);
    freopen("lineup.out","w",stdout);
    n=read();
    for(int i=1;i<=n;++i)a[i]=read(),nums.push_back(a[i]);
    sort(nums.begin(),nums.end());
    for(int i=n;i>=1;--i){
        ma[nums[i-1]]=i;
    }
    for(int i=1;i<=n;++i){
        b[i]=ma[a[i]]+cnt[ma[a[i]]];
        ++cnt[ma[a[i]]];
        ans+=abs(i-b[i]);
        // cout<<" i:"<<i<<" b:"<<b[i]<<" ans:"<<ans<<endl;
    }
    print(ans);putchar('\n');
    return 0;
}
