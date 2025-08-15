#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
int n;
ull s1,s2;
inline ull my_rand(){
    ull s3=s1,s4=s2;
    s1=s2^774527;
    s3^=(s3<<47)^(s3>>13);
    s2^=s3^(s4<<31)^(s4>>17);
    return s2+s4;
}
inline void get_query(int &op,ull &num1,ull &num2){
    op=my_rand()%2+1;
    if(op==1){
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
    }
    else{
        num1=my_rand()%n+1;
        num2=my_rand()%n+1;
        if(num1>num2)
             swap(num1,num2);
    }
}
int Q,opt;
ull l,r,ans,t[4097][4097],T[4097],ad;
inline ull lowbit(ull x){
	return x&(-x);
}
inline void add(ull i,ull j,ull k){
	while(j<=4096){
		t[i][j]+=k;
		j+=lowbit(j);
	}
}
inline void Add(ull i,ull k){
	while(i<=(n+4095)/4096){
		T[i]+=k;
		i+=lowbit(i);
	}
}
inline ull sum(ull i,ull j){
	ull res=0;
	while(j){
		res+=t[i][j];
		j-=lowbit(j);
	}
	return res;
}
inline ull Sum(ull i){
	ull res=0;
	while(i){
		res+=T[i];
		i-=lowbit(i);
	}
	return res;
}
int main(){
    freopen("fenwick.in","r",stdin);
    freopen("fenwick.out","w",stdout);
    cin>>n>>Q>>s1>>s2;
    for(register int i=1;i<=Q;++i){
    	get_query(opt,l,r);
    	if(opt&1){
    		ad=0;
    		int pos=(l+4095)/4096;
    		int x=l-(pos-1)*4096;
    		while(l<=n&&(l+4095)/4096==pos){
    			x=l-(pos-1)*4096;
    			add(pos,x,r);
    			ad+=r;
    			l+=lowbit(l);
			}
			Add(pos,ad);
    		while(l<=n){
    			pos=(l+4095)/4096;
    			x=l-(pos-1)*4096;
    			add(pos,x,r);
    			Add(pos,r);
    			l+=lowbit(l);
			}
		}
		else{
			ull res=0;
			int posl=(l+4095)/4096,posr=(r+4095)/4096;
			l-=(posl-1)*4096;
			r-=(posr-1)*4096;
			if(posl==posr){
				res=sum(posr,r)-sum(posl,l-1);
			}
			else{
				res=Sum(posr-1)-Sum(posl-1);
				res-=sum(posl,l-1);
				res+=sum(posr,r);
			}
			ans^=res*i;
		}
	}
	cout<<ans;
    return 0;
}
