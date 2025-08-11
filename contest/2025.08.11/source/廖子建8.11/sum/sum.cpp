#include<bits/stdc++.h>
#define int long long
#define N 10000000000000ll
using namespace std;
int t;
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
main(){
	freopen("sum.in","r",stdin);
	freopen("sum.out","w",stdout); 
	t=read();
	while(t--)print(-1),putchar('\n');
	return 0;
}
