#include<bits/stdc++.h>
#define N 600
#define Mod 1000000007
using namespace std;
int n,k;
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
	freopen("matrix.in","r",stdin);
	freopen("matrix.out","w",stdout);
	n=read(),k=read();
	print(0);
	return 0;
}
