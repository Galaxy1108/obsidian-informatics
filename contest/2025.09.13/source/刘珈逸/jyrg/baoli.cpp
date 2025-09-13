#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e3+5,mx=1e18;
int n,a[N],b[N];
int solve(){
    scanf("%lld",&n);
    for(int i=1;i<=n;i++)scanf("%lld",a+i),a[i]-=i,b[i]=a[i];
    sort(b+1,b+1+n);
    for(int i=1;i<n;i++)if(b[i]==b[i+1]){
        puts("-1");
        return 0;
    }
    int res=0;
    for(int i=1;i<=n;i++){
        int x;
        for(int j=1;j<=n;j++)if(a[j]==b[i])x=j;
        for(int j=x;j<=n-i;j++){
            res=max(res,2*j+1+a[j]+a[j+1]);
            swap(a[j],a[j+1]);
        }
    }
    printf("%lld\n",res);
    return 0;
}
mt19937_64 rd(time(0));
signed main(){
    freopen("jyrg.in","w",stdout);
    // freopen("jyrg.out","w",stdout);
    int t=20;printf("%lld\n",t);
    for(int i=1;i<=t;i++){
        int n=1e5;
        printf("%lld\n",n);
        for(int j=1;j<=n;j++)printf("%lld ",rd()%mx+n);
    }
    return 0;
}
/*
每个数到每个位置的值是确定的
即求每一对逆序对被交换的位置
每次把最小的向后交换即可？
用平衡树维护
*/
