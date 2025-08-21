#include<bits/stdc++.h>
#define int long long
#define N 2500
#define M 11000
using namespace std;
int n,lcm=1;
int read(){
    int f=1,g=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while('0'<=ch&&ch<='9'){
        g=g*10+ch-'0';
        ch=getchar();
    }
    return f*g;
}
void print(int x){
    if(x<0){
        putchar('-');
        x*=-1;
    }
    if(x>9)print(x/10);
    putchar(x%10+'0');
    return;
}
main(){
    freopen("divisors.in","r",stdin);
    freopen("divisors.out","w",stdout);
    n=read();
    for(int i=1;i<=n;i++)lcm=lcm*i/__gcd(lcm,i);
    print(lcm),putchar(' ');
    for(int i=2;i<=n;i++)print(i),putchar(' ');
    putchar('\n');
    for(int i=2;i<=n;i++)print(1),putchar(' '),print(i),putchar('\n');
    return 0;
}
