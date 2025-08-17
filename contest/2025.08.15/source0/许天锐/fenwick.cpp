#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
const int N=10005001;
int n,Q;
ull c[N];
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
inline void add(int x,ull y){
    ull k=y;
    for(;x<=n;x+=x&(-x),k+=y)c[x]+=k;
}
inline ull query(int x){
    ull ans=0;
    for(;x;x-=x&(-x))ans+=c[x];
    return ans;
}
int main(){
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    cin>>n>>Q>>s1>>s2;
    ull ans=0;
    for(int i=1;i<=Q;i++){
        int op;
        ull l,r;
        get_query(op,l,r);
        if(op==1){
            add(l,r);
        }
        else {
            ull cur=query(r)-query(l-1);
            ans^=cur*i;
        }
    }
    cout<<ans<<endl;
    // cerr<<clock()<<endl;
    return 0;
}