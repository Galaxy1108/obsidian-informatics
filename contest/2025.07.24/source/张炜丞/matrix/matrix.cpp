#include<bits/stdc++.h>
using namespace std;
#define pii pair<int,int>
#define mpr make_pair
const int N=2005,M=4000025,P=1e9+7;

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

int n,k,m,cnt;
pii ans[M];

signed main(){
    freopen("matrix.in","r",stdin);
    freopen("matrix.out","w",stdout);
    srand(time(0));
    n=read();k=read()*5;
    for(int i=1;i<=n;i+=2){
        for(int j=i+2;j<=n;j+=2){
            ans[++cnt]=mpr(i,j);
            while(rand()%10*k)++j;
        }
        while(rand()%k)++i;
    }
    print(cnt);putchar('\n');
    for(int i=1;i<=cnt;++i){
        print(ans[i].first);putchar(' ');
        print(ans[i].second);putchar('\n');
    }
    //cout<<" cnt:"<<cnt<<endl;
    return 0;
}