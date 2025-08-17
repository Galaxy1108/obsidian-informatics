#include <bits/stdc++.h>
using namespace std;
#define lb(x) (x&(-x))
#define ull unsigned long long
const int N=1e7+5;
int n;
ull s1,s2;
ull my_rand()
{
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get_query(int &op,ull &num1,ull &num2)
{
    op=my_rand()%2+1;
    if(op==1)
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else
    {
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}

ull s[N],x,y;

void print(ull x){
    if(x>9)print(x/10);
    putchar(x%10|48);
}
ull ans=0;

void add(int x,ull v){
    ull sv=0;
    while(x<=n){
        sv+=v;
        s[x]+=sv;
        x+=lb(x);
    }
}

ull sum(int x){
    ull ans=0;
    while(x){
        ans+=s[x];
        x-=lb(x);
    }
    return ans;
}
ull sum(int x,int y){
    return sum(y)-sum(x-1);
}

#undef ull
int Q;
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for(int i=1,op;i<=Q;++i){
        get_query(op,x,y);
        if(op==1){
            add(x,y);
        }
        else {
            ans^=i*sum(x,y);
        }
    }
    print(ans);putchar('\n');
    // printf("2588154976231288790\n");
    return 0;
}