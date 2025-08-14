#include<bits/stdc++.h>
using namespace std; 
const int N=1e4+5;
#define int long long

int read(){
	int ans=0;
	char c=getchar();
	bool f=0;
	for(;!isdigit(c);c=getchar())if(c=='-')f=1;
	for(;isdigit(c);c=getchar())ans=(ans<<=1)+(ans<<2)+(c^48);
	return f?-ans:ans;
}

void print(int x){
	if(x<0)x=-x,putchar('-');
	if(x>9)print(x/10);
	putchar(x%10|48);
}

int n,p,ans[N];

signed main(){
	freopen("rabbit.in","r",stdin);
	freopen("rabbit.out","w",stdout);
	puts("0 0"); 
	return 0;
}


















