#include<iostream>
#include<cstdio>
using namespace std;
int n,m;
bool num[(int)1e5+10];
int a[(int)1e5+10];
void ask(int l,int r){
	int ans=0,cnt0,cnt1;
	for(int i=l; i<=r; i++){
		for(int j=i; j<=r; j++){
			cnt1=a[j]-a[i-1];
			cnt0=j-i+1-cnt1;
			if(cnt1%2==0||(cnt0>=2&&cnt1<21)||(cnt0>=3&&cnt1<=64)) ans++;
		}
	}
	cout<<ans<<endl;
} 
int main(){
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		scanf("%d",&num[i]);
		a[i]=num[i]+a[i-1];
	} 
	scanf("%d",&m);
	int op,l,r;
	while(m--){
		scanf("%d",&op);
		if(op==1){
			scanf("%d",&l);
			num[l]=!num[l];
			for(int i=1; i<=n; i++) a[i]=num[i]+a[i-1];
		}
		else{
			scanf("%d%d",&l,&r);
			ask(l,r);
		}
	}
	return 0;
}
