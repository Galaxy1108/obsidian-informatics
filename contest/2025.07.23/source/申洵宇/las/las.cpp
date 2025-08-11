#include <bits/stdc++.h>
using namespace std;
#define N 1000005
int n,a[N];
long long c[N];
void checker(){
#ifdef MIKE_DEBUG
	for(int i=1;i<=n;i++){
		int la=i-1,nx=i+1;
		if(i==1)la=n;
		if(i==n)nx=1;
		long long le=(a[la]==i?c[i]:(c[i]<<1)),
				  ri=(a[nx]==nx?c[nx]:(c[nx]<<1));
//		cerr<<i<<":"<<le<<","<<ri<<endl;
		if((a[i]==i&&le<ri)||(a[i]==nx&&le>ri)){
			if(le<ri){
				cerr<<"WA-wrong choose "<<i;
				exit(0); 
			}
		}
		else if(a[i]!=i&&a[i]!=nx){
			cerr<<"WA-can't choose";
			exit(0);
		}
	}
	cerr<<"AC";
#endif
	exit(0);
}
void check(int x){
	a[0]=x;
	for(int i=1;i<n;i++){
		if((a[i-1]==i?c[i]:(c[i]<<1))<(c[i+1]<<1)){
			a[i]=i+1;
		}
		else{
			a[i]=i;
			int j=i-1;
			while(j>=1&&(a[j-1]==j?c[j]:(c[j]<<1))>=(a[j+1]==j+1?c[j+1]:(c[j+1]<<1))){
				a[j]=j;
				j--;
			}
		}
	}
	if((a[n-1]==n?c[n]:(c[n]<<1))<(a[1]==1?c[1]:(c[1]<<1))){
		a[n]=1;
	}
	else{
		a[n]=n;
		int j=n-1;
		while(j>=1&&(a[j-1]==j?c[j]:(c[j]<<1))>=(a[j+1]==j+1?c[j+1]:(c[j+1]<<1))){
			a[j]=j;
			j--;
		}
	}
	if(a[n]==a[0]){
		for(int i=1;i<=n;i++){
			cout<<a[i]<<' ';
		}
		checker();
	}
}
int main(){
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>c[i];
	}
	c[n+1]=c[1];
	check(1);
	memset(a,0,sizeof(a));
	check(n);
	printf("NIE");
	return 0;
}

