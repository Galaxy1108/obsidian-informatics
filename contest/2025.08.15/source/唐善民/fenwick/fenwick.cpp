//#include<bits/stdc++.h>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<iomanip>
#include<cstdio>
#include<string>
#include<vector>
#include<cmath>
#include<ctime>
#include<deque>
#include<queue>
#include<stack>
#include<list>
using namespace std;
typedef __int128 lll;
typedef unsigned long long ull;
constexpr const int N=1e7;
int n;
namespace fenwick{
	#define ull unsigned long long
	ull s1,s2;
	inline ull my_rand()
	{
	    ull s3=s1,s4=s2;
	    s1=s2^774527;
	    s3^=(s3<<47)^(s3>>13);
	    s2^=s3^(s4<<31)^(s4>>17);
	    return s2+s4;
	}
	inline void get_query(int &op,ull &num1,ull &num2)
	{
	    op=(my_rand()&1)+1;
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
	#undef ull
}
struct bit{
	struct bitInside{
		ull t[N+1];
		inline int lowbit(const int &x){
			return x&-x;
		} 
		inline void add(int x,const ull &k){
			while(x<=n){
				t[x]+=k;
//				x+=x&-x;
				x+=lowbit(x);
			}
		}
		inline ull query(int x){
			ull ans=0;
			while(x){
				ans+=t[x];
//				x-=x&-x;
				x-=lowbit(x);
			}
			return ans;
		}
	}t;
	inline int lowbit(const int &x){
		return x&-x;
	} 
	inline void add(int x,const ull &k){
		while(x<=n){
			t.add(x,k);
//			x+=x&-x;
			x+=lowbit(x);
		}
	}
	inline ull query(const int &l,const int &r){
		return t.query(r)-t.query(l-1);
	}
}t;
int main(){
	freopen("fenwick.in","r",stdin);
	freopen("fenwick.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	
	int q;
	cin>>n>>q>>fenwick::s1>>fenwick::s2;
	ull ans=0;
	for(int i=1;i<=q;i++){
		static int op;
		static ull a,b;
		fenwick::get_query(op,a,b); 
		switch(op){
			case 1:
				t.add(a,b);
				break;
			case 2:
				ans^=i*t.query(a,b);
				break;
		}
	}
	cout<<ans<<'\n';
//	cerr<<"Time: "<<1.0*clock()/CLOCKS_PER_SEC<<"s\n";
	
	cout.flush();
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
