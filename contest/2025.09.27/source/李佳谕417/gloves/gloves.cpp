#include<iostream>
#include<algorithm>
using namespace std;
int a[100005],b[100005];
int n,m;
bool flag;
void dfs(int a[],int b[],int sb,int tb,int sa,int ta,int ans){
    if(flag)return;
    if(sa>ta){
        flag=1;
        return;
    }
    for(int nowb=sb;nowb<=tb;nowb++){
        if(a[sa]-b[nowb]>ans){
            continue;
        }else if(a[sa]-b[nowb]<=ans&&a[sa]-b[nowb]>=(-ans)){
            dfs(a,b,nowb+1,tb,sa+1,ta,ans);
        }else{
            break;
        }
    }
}
bool check(int ans){
    flag=0;
    if(n<m){
        dfs(a,b,1,m,1,n,ans);
    }else{
        dfs(b,a,1,n,1,m,ans);
    }
    if(flag){
        return 1;
    }
    return 0;
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("gloves.in","r",stdin);
    freopen("gloves.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }

    sort(a+1,a+1+n);
    sort(b+1,b+1+n);

    int l=0,r=1e9+5,ans=-1;
    while(l<=r){
        int mid=(l+r)/2;
        if(check(mid)){//cout<<mid<<" ok"<<endl;
            ans=mid;
            r=mid-1;
        }else{//cout<<mid<<" no\n";
            l=mid+1;
        }
    }
    cout<<ans;
    return 0;
}