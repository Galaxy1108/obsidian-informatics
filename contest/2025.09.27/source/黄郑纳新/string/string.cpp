#include<bits/stdc++.h>
#define int long long
using namespace std;
string s;
int a[410],s0=0,s1=0,s2=0,cnt=1;
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	int l=s.size();
	for(register int i=0;i<l;i++){
		a[i+1]=s[i]-'0';
	}
	for(register int i=1;i<=l;i++){
		if(a[i]==0) s0++;
		if(a[i]==1) s1++;
		if(a[i]==2) s2++;
		if(a[i]!=a[i-1]&&i>0)cnt++;
	}
	if(cnt==l){
		cout<<0<<endl;
		exit(0);
	}
	if(s1>(l+1)/2||s2>(l+1)/2||s0>(l+1)/2){
		cout<<-1<<endl;
		exit(0);
	}
	register int ans=0,sum=1; 
	a[l+1]=100;
	if(a[1]!=a[2]&&a[2]==a[3]) ans--;
	for(int i=1;i<=l+1;i++){
		if(a[i]==a[i-1]&&i!=1) sum++;
		else if(a[i]!=a[i-1]&&i!=1&&sum>1){
			a[i]=a[i-1];
			i=i+2-sum;
			ans+=sum-1;
			sum=1;
		}
	}
	cout<<ans<<endl;
}
