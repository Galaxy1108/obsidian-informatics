#include <bits/stdc++.h>
using namespace std;
#define N 10000005 
typedef unsigned long long ull;
int n,q;
ull s1,s2;
ull my_rand(){
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
void get_query(int &op,ull &num1,ull &num2){
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
class BIT{
#define lowbit(x) ((x)&(-(x)))
public:
	ull a[N]={0};
//	void add(int x,ull k){
//		for(;x<=n;x+=lowbit(x)){
//			a[x]+=k;
//		}
//	}
	void update(int x,ull k){
		for(register ull cnt=1;x<=n;x+=lowbit(x),++cnt){
			a[x]+=cnt*k;
//			add(x,k);
		}
	}
	ull query(int x){
		ull res=0;
		for(;x>=1;x-=lowbit(x)){
			res+=a[x];
		}
		return res;
	}
#undef lowbit 
}st;
//class BIT2{
//#define lowbit(x) ((x)&(-(x)))
//public:
//	ull a[N]={0};
//	void update(int x,ull k){
//		for(;x<=n;x+=lowbit(x)){
//			a[x]+=k;
//		}
//	}
//	ull query(int x){
//		ull res=0;
//		for(;x>=1;x-=lowbit(x)){
//			res+=a[x];
//		}
//		return res;
//	}
//#undef lowbit 
//}st2;
int main(){
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>q>>s1>>s2;
	int op;
	ull num1,num2,ans=0;
	for(register int i=1;i<=q;++i){
		get_query(op,num1,num2);
//		cerr<<op<<","<<num1<<","<<num2<<endl;
		if(op==1){
			st.update(num1,num2);
//			st2.update(num1,num2);
//			for(int j=1;j<=n;j++){
//				cerr<<st.query(j)-(j>0?st.query(j-1):0)<<" ";
//			}
//			cerr<<"\n";
//			for(int j=1;j<=n;j++){
//				cerr<<st2.a[j]<<" ";
//			}
//			cerr<<'\n';
		}
		else{
			ans^=((ull)i)*(st.query(num2)-(num1<=1ull?0ull:st.query(num1-1ull)));
		}
	}
	cout<<ans;
	return 0;
}
