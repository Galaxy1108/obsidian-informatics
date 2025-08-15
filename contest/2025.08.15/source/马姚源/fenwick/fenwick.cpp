#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define endl '\n'
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

int Q;
ull b[(int)1e7+10],c[int(1e7)+10];
//const ull mod = (1<<64)-1;
ull lowbit(ull x){return x&(-x);}
inline void add(ull x,ull y){
	int cnt=1;
    while(x<=n){
        b[x]=(__int128)b[x]+y*cnt;
        cnt++;
        x+=(x&(-x));
    }
}

inline ull query(ull x){
    ull res=0;
    while(x){
        res=(__int128)res+b[x];
//        res=(__int128)res%mod;
        x-=(x&(-x));
    }
    return res;
}
inline void write(ull x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x<10)putchar(x+'0');
	else {
		write(x/10);
		putchar(x%10+'0');
	}
}
int main()
{	
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    scanf("%d%d%llu%llu",&n,&Q,&s1,&s2);
    ull ans=0;
    for(int i=1;i<=Q;i++){
        int op;ull x,y;
    	get_query(op,x,y);
//        cout << op << " " << x << " " << y << endl;
        if(op==1){
            add(x,y);
        }
        else{
//          ans=(__int128)ans^((query(y)-query(x-1))%mod*i)%mod;
			ans=(__int128)ans^((query(y)-query(x-1))*i);  
        }
	} 
    write(ans);
    return 0;
}
#undef ull
