#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5,m=1e6;
typedef long long ll;
int n,a[N],s[N],b[N];
ll ans;
int get(int l,int r){
    return s[r]-s[l-1];
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++)scanf("%d",a+i),s[a[i]]++;
    for(int i=1;i<=m*2;i++)s[i]+=s[i-1];
    for(int i=1;i<=m;i++){
        int k=1;
        for(int j=i;j<=m;j+=i,k++)b[k]=get(j,j+i-1);
        k--;
        int cnt=0;
        for(int j=1;j<=k;j++)if(b[j]&1)cnt++;
        if(cnt>2)continue;
        if(cnt==1&&(b[1]&1))ans+=b[1];
        if(cnt==2){
            for(int j=1;j<k;j++)if((b[j]&1)&&(b[j+1]&1))ans+=b[j+1];
        }
    }
    printf("%lld\n",ans);
    return 0;
}
/*
每个人每次将所有石子个数除一个数，然后拿一颗石子
*/