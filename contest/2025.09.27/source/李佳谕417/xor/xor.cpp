#include<iostream>
using namespace std;
int a[100005];
int main(){
    freopen("xor.in","r",stdin);
    freopen("xor.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            int x=a[i];
            int m=a[i];
            for(int k=i+1;k<=j;k++){
                x=(x^a[k]);
                m=max(m,a[k]);
            }
            if(x<=m){
                cnt++;
            }
        }
    }
    cout<<cnt;
    return 0;
}