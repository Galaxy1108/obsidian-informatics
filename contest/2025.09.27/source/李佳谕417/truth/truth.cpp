#include<iostream>
#include<algorithm>
#include<climits>
#include<cstring>
using namespace std;
int a[50005];
int num[35];
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    freopen("truth.in","r",stdin);
    freopen("truth.out","w",stdout);
    int n,k,m;
    cin>>n>>k>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    while(m--){
        int op;
        cin>>op;
        if(op==1){
            int p,v;
            cin>>p>>v;
            a[p]=v;
        }else{//滑动窗口
            memset(num,0,sizeof(num));
            int cnt=0,ans=-1;
            int f=1;
            int r;
            for(r=1;r<=n;r++){//cout<<m<<' '<<r<<endl;
                if(!num[a[r]])cnt++;
                num[a[r]]++;
                if(cnt==k)break;
            }
            if(r!=n+1){
                while(num[a[f]]>1){
                    num[a[f]]--;
                    f++;
                }
                ans=r-f+1;
            }
            while(r<n){
                r++;
                num[a[r]]++;
                while(num[a[f]]>1){
                    num[a[f]]--;
                    f++;
                }
                ans=min(ans,r-f+1);
            }
            cout<<ans<<endl;
        }
    }
    return 0;
}