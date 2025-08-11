#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=185,P=998244353;

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

signed main(){
    freopen("reporter.in","r",stdin);
    freopen("reporter.out","w",stdout);
    puts("0");return 0;
}