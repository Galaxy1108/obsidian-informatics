#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,p,b;
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
	freopen("calc.in","r",stdin);
	freopen("calc.out","w",stdout);
	t=read(),p=read();
	while(t--){
		b=read();
		if(p==2)print(b%2==0?-1:1);
		else if(p==3)print(b%3<=1?-1:2);
		else print(b%p<=1?-1:b%p/2);
		putchar('\n');
	}
	return 0;
}
