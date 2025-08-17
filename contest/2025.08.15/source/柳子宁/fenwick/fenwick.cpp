#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n,Q,op;
ull s1,s2,x,y,ans,Ans;
ull tree[10000010];
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
void Add(int x,ull val){
    ull k=0;
    while(x<=n) k+=val,tree[x]+=k,x+=(x&(-x));
    return;
}
ull Query(int x){
    ull ans=0;
    while(x) ans+=tree[x],x-=(x&(-x));
    return ans;
}
#undef ull
int main()
{
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    for(int i=1;i<=Q;++i){
        get_query(op,x,y);
        if(op==1) Add(x,y);
        else{
            ans=Query(y)-Query(x-1);
            Ans=Ans^(ans*i);
        }
    }
    printf("%llu\n",Ans);
    return 0;
}
