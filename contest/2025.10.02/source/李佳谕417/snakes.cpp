#include<iostream>
using namespace std;
int a[3000005],b[3000005];
int n;
inline void solve(){
    while(1){
        int maxi=1,mini=1;
        while(b[maxi]==-1){
            maxi++,mini++;
        }
        for(int i=maxi+1;i<=n;i++){
            if(b[i]==-1)continue;
            if(b[maxi]<b[i])maxi=i;
            if(b[mini]>b[i])mini=i;
        }
        b[maxi]-=b[mini];
        int temp=b[mini],tempi=mini;
        b[mini]=-1;
        mini=1;
        int maxii=1;
        while(b[mini]==-1){
            maxii++,mini++;
        }
        for(int i=mini+1;i<=n;i++){
            if(b[i]==-1)continue;
            if(b[maxii]<b[i])maxii=i;
            if(b[mini]>b[i])mini=i;
        }
        if(mini==maxi){
            if(maxii==mini)break;
            mini=tempi;
            b[mini]=temp;
            break;
        }
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(b[i]!=-1)cnt++;
    }
    cout<<cnt<<'\n';
}
int main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("snakes.in","r",stdin); 
    freopen("snakes.out","w",stdout); 
    int T;
    cin>>T;
    T--;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        b[i]=a[i];
    }
    solve();
    while((T--)>0){
        int k;
        cin>>k;
        for(int i=1;i<=k;i++){
            int x,y;
            cin>>x>>y;
            a[x]=y;
        }
        for(int i=1;i<=n;i++){
            b[i]=a[i];
        }
        solve();
    }
    return 0;
}
