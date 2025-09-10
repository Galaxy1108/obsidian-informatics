#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,t1[N],t2[N],h[N];
class per{
public:
    int a[N],book[N]={0},cnt=0;
    pair<int,int> siz[N];
    int& operator[](int x){
        return a[x];
    }
    const int& operator[](int x)const{
        return a[x];
    }
    void getloop(){
        for(int i=1;i<=n;i++){
            if(!book[i]){
                cnt++;
                siz[cnt].second=i;
                for(int j=i;!book[j];
                    book[j]=cnt,siz[cnt].first++,j=a[j]);
            }
        }
    }
}p,q;
int main(){
    freopen("permutation.in","r",stdin);
    freopen("permutation.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>p[i];
    }
    for(int i=1;i<=n;i++){
        cin>>q[i];
    }
    p.getloop();
    q.getloop();
    sort(p.siz+1,p.siz+n+1);
    sort(q.siz+1,q.siz+n+1);
    for(int i=1;i<=n;i++){
        if(p.siz[i].first!=q.siz[i].first){
            cout<<"NO";
            return 0;
        }
    }
    for(int c=1;c<=n;c++){
        if(p.siz[c].first==0)continue;
        static int i,j;
        i=p.siz[c].second,j=q.siz[c].second;
        do{
            h[j]=i;
            i=p[i];
            j=q[j];
        }while(i!=p.siz[c].second&&j!=q.siz[c].second);
    }
    cout<<"YES\n";
    for(int i=1;i<=n;i++){
        cout<<h[i]<<' ';
    }
    return 0;
}