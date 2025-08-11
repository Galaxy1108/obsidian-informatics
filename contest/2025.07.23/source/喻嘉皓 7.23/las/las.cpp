#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n;
int c[N];
int ans[N];
int res[N];
void solve(int op){
	ans[1]=op; res[1]=(op==1?c[1]:c[2]);
	for(int i=2;i<=n;i++){
		int op1=c[i],op2=c[i+1];
		if(ans[i-1]==2){//上一个选的右边 
			op1/=2;
		}	
 		if(ans[1]==1&&i==n) op2/=2;
 		if(op1>op2) ans[i]=1;
 		else ans[i]=2;
 		int it=i;
 		while(ans[it]==1&&ans[it-1]==2){//说明本次翻转会对上一次产生影响 
 			int l=c[it-1],r=c[it]/2;
 			if(ans[it-2]==2) l/=2;
 			if(l>r) ans[it-1]=1;
 			it--;
		}
	}
}
bool check(int op){
	int op1=c[1],op2=c[2];
	if(ans[n]==2) op1/=2;
	if(ans[2]==1) op2/=2;
	if(op==1&&op1<op2) return false;
	return true; 
}
void prin(){
	for(int i=1;i<=n;i++){
		int to=i+(ans[i]==1?0:1);
		if(to==n+1) to=1;
		cout<<to<<' ';
	}
}
void checkans(){
	ans[n+1]=ans[1]; ans[0]=ans[n];
	for(int i=1;i<=n;i++){
		int op1=c[i],op2=c[i+1];
		if(ans[i+1]==1) op2/=2;
		if(ans[i-1]==2) op1/=2;
		if(ans[i]==1&&op1<op2) cout<<i<<"caonima1\n\n";
		if(ans[i]==2&&op1>op2) cout<<i<<"caonima2\n\n";
	}
}
int main(){
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++) cin>>c[i];
	c[n+1]=c[1];  
	solve(1);
	if(check(1)) prin();
	else{
		solve(2);
		if(check(2)) prin();
		else cout<<"NIE";
	}
//	for(int i=1;i<=n;i++){
//		cin>>ans[i];
//		if(ans[n]==1) ans[i]=2;
//		else ans[i]=ans[i]-i+1;
//	}
//	checkans();
	return 0;
}

