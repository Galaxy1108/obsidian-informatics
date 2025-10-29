#include<iostream>
#include<cstdio>
#define LL long long
using namespace std;
int n;
int a[(int)1e6+10];
int main(){
	freopen("game.in","r",stdin);
	freopen("game.out","w",stdout);
	scanf("%d",&n);	
	for(int i=1; i<=n; i++) scanf("%d",&a[n]);
	int f=0;
	for(int i=1; i<=n; i++) if(a[i]!=1) f=1;
	if(!f){
		if(n%2) cout<<n;
		else cout<<0;
		return 0;
	}
	cout<<0;
	return 0;
}
