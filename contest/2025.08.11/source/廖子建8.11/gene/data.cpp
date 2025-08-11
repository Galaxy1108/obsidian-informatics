#include<bits/stdc++.h>
#define int long long
#define N 1000000
using namespace std;
mt19937 a;
int rd(int l,int r){
	return a()%(r-l+1)+l;
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
	freopen("gene.in","w",stdout);
	a.seed(time(0));
	int n=N,l=n-1,r=n-1;
	print(n),putchar(' ');
	print(l),putchar(' ');
	print(r),putchar('\n');
	for(int i=1;i<=n;i++)print(rd(1,N)),putchar(' ');
	return 0;
}
