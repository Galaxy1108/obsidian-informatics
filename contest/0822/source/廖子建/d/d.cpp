#include<bits/stdc++.h>
#define int long long
#define N 100000
#define A 10
using namespace std;
int t,n,q,a[N+5],ul,ur,b[N+5],pre[N+5];
bool flag;
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
bool check(int x,int y,int z,int l,int r){
    for(int i=l;i<=r;i++){
        if(a[i]!=(x*(i-l)+y)/z)return 0;
    }
    return 1;
}
bool check(int x,int y,int z,int l,int r,int i){return (a[i]==(x*(i-l)+y)/z);}
main(){
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
    t=read();
//    cout<<"sdffs\n";
    while(t--){
        n=read();
        for(int i=1;i<=n;i++)a[i]=read(),b[i]=a[i]-a[i-1];
        pre[1]=1;
        for(int i=2;i<=n;i++){
            if(b[i]==b[i-1])pre[i]=pre[i-1];
            else pre[i]=i;
        }
        q=read();
        for(int i=1;i<=q;i++){
            ul=read(),ur=read(),flag=0;
            if(ul==ur){
                print(0),putchar(' ');
                print(a[ul]),putchar(' ');
                print(1),putchar('\n');
                continue;
            }
            if(pre[ur]<=ul+1){
                print(a[ul+1]-a[ul]),putchar(' ');
                print(a[ul]),putchar(' ');
                print(1),putchar('\n');
                continue;
            }
            for(int j=1;j<=A;j++){
                for(int k=0;k<=A;k++){
                    for(int s=0;s<=A;s++){
                        if(check(k,s,j,ul,ur)){
                            print(k),putchar(' ');
                            print(s),putchar(' ');
                            print(j),putchar('\n');
                            flag=1;
                            break;
                        }
                    }
                    if(flag)break;
                }
                if(flag)break;
            }
        }
    }
    return 0;
}
