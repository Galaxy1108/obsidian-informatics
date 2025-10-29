#include<bits/stdc++.h>
using namespace std;
int flag1=1,root,cnt[1005];
int flag2=1;
int flag3=1;
int n,p;
int sqr[10005];
int main(){
	freopen("disease.in","r",stdin);
	freopen("disease.out","w",stdout);
    sqr[1]=0;
    int j=1;
    while(1){
        j*=2;
        sqr[j]=sqr[j]+1;
        if(j>1000) break;
    }
    cin>>n>>p;
    int tmp=0;
    for(int i=1;i<=p;i++){
        int x,y;
        cin>>x>>y;
        if(x>y) swap(x,y);
        if(x!=tmp&&i!=1) flag2=0;
        cnt[x]++;
        if(cnt[x]>=2) root=x;
        tmp=y;
    }
    //cout<<root;
    if(cnt[root]==n-1){
        if(root=1) cout<<n-1;
        else cout<<1;
        return 0;
    }
    else if(flag2){
        cout<<1;
        return 0;
    }
    else{
        cout<<n-sqr[n+1];
    }
    return 0;
}
