#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int ans[N];
int n;
void checkans(){
	ans[n+1]=ans[1]; ans[0]=ans[n];
	for(int i=1;i<=n;i++){
		int op1=c[i],op2=c[i+1];
		if(ans[i+1]==1) op2/=2;
		if(ans[i-1]==2) op1/=2;
		if(ans[i]==1&&op1<op2) return 0;
		if(ans[i]==2&&op1>op2) return 0;
	}
	return 1;
}
int main(){
	//freopen(".in","r",stdin);
	//freopen(".out","w",stdout);
	while(cin>>ans[i]){
		n++;
		if(i==n&&ans[i]=1) ans[i]=2;
		else ans[i]=ans[i]-i+1;
	}
	checkans();
	return 0;
}

