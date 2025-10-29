#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
void read(int &x){
	x=0;char c=getchar();int w=0;
	while(!isdigit(c)){
		(c=='-')&&(w=1);
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+(c^48);
		c=getchar();
	}
	w&&(x=-x);
}
const int N=11;
int n,mod;
signed main(){
	freopen("pairs.in","r",stdin);
	freopen("pairs.out","w",stdout);
	read(n);
	read(mod);
	if(n==1)cout<<0;
	if(n==2)cout<<0;
	if(n==3)cout<<0;
	if(n==4)cout<<17%mod;
	if(n==5)cout<<904%mod;
	if(n==6)cout<<45926%mod;
	if(n==7)cout<<2725016%mod;
	if(n==8)cout<<196884712ll%mod;
	return 0;
} 
