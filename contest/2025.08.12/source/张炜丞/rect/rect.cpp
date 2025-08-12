#include<bits/stdc++.h>
using namespace std;
const int N=505;

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

int n,m,sum[N][N],ans[N][N],cnt;
bool a[N][N],vis[N][N];

int jc(int i,int j,int k,int l){
    return sum[l][k]-sum[i-1][k]-sum[l][j-1]+sum[i-1][j-1];
}

signed main(){
    freopen("rect.in","r",stdin);
    freopen("rect.out","w",stdout);
    n=read();m=read();
    char c=getchar();
    for(int i=1;i<=n;++i){
        while(c!='C'&&c!='B')c=getchar();
        for(int j=1;j<=m;++j){
            a[i][j]=c=='C';
            c=getchar();
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)sum[i][j]=sum[i][j-1]+a[i][j];
    }
    for(int j=1;j<=m;++j){
        for(int i=1;i<=n;++i)sum[i][j]+=sum[i-1][j];
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(!a[i][j]||ans[i][j])continue;
            int k=j;
            while(a[i][k+1])++k;
            int l=i;
            while(jc(i,j,k,l+1)==(k-j+1)*(l-i+2))++l;
            ++cnt;
            //cout<<" i:"<<i<<" j:"<<j<<" k:"<<k<<" l:"<<l<<endl;
            for(int p=i;p<=l;++p){
                for(int q=j;q<=k;++q){
                    ans[p][q]=cnt;
                }
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            print(ans[i][j]);putchar(' ');
        }
        putchar('\n');
    }
    return 0;
}