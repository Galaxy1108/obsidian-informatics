#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,a[N];
int main(){
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    int op,l,r;
    while(m--){
        cin>>op;
        if(op==1){
            cin>>l;
            a[l]^=1;
        }
        else{
            cin>>l>>r;
            long long ans=0;
            int cnt=0,len,rp,lp;
            for(int i=l;i<=r;i++){
                cnt=0;
                for(int j=i;j<=r;j++){
                    cnt+=a[j];
                    len=j-i+1;
                    lp=max(-cnt,cnt-len-(len&1));
                    rp=min(cnt,len-(len&1)-cnt);
                    if(rp-lp+1>=6){
                        ans++;
                        continue;
                    }
                    lp=(lp%6+6)%6;
                    rp=(rp%6+6)%6;
                    if(lp<=rp){
                        if((3*(cnt&1))>=lp&&(3*(cnt&1))<=rp){
                            ans++;
                        }
                    }
                    else{
                        if((3*(cnt&1))<=rp||(3*(cnt&1))>=lp){
                            ans++;
                        }
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
/*another
#include <bits/stdc++.h>
using namespace std;
#define N 100005
int n,m,a[N];
int main(){
    freopen("binary.in","r",stdin);
    freopen("binary.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    cin>>m;
    int op,l,r;
    while(m--){
        cin>>op;
        if(op==1){
            cin>>l;
            a[l]^=1;
        }
        else{
            cin>>l>>r;
            long long ans=0;
            int cnt=0,len,rp,lp;
            for(int i=l;i<=r;i++){
                cnt=0;
                for(int j=i;j<=r;j++){
                    cnt+=a[j];
                    len=j-i+1;
                    lp=max(-cnt,cnt-len-(len&1));
                    rp=min(cnt,len-(len&1)-cnt);
                    for(int k=lp;k<=rp;k++){
                        if((k-cnt)%2==0&&k%3==0){
                            ans++;
                            break;
                        }
                    }
                }
            }
            cout<<ans<<'\n';
        }
    }
    return 0;
}
*/