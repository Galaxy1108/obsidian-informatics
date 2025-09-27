#include<bits/stdc++.h>
#define ll long long
using namespace std;
char str[205];
ll ans;
int main(){
	ios::sync_with_stdio(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>str;
	ll len=strlen(str);
	bool flag=0;
	for(ll i=0;i<=len-1;i++){
		if(str[i]==str[i-1]){
			flag=1;
			break;
		}
	}
	if(!flag){
		cout<<0;
		return 0;
	}
	for(ll i=1;i<=len-2;i++){
		if(str[i]==str[i-1]&&str[i]!=str[i+1]){
			char t=str[i];
			str[i]=str[i+1];
			str[i+1]=t;
			ans++;
		}
		else if(str[i]==str[i+1]&&str[i]!=str[i-1]){
			char t=str[i];
			str[i]=str[i-1];
			str[i-1]=t;
			ans++;
		}
	}
	flag=0;
	for(ll i=0;i<=len-1;i++){
		if(str[i]==str[i-1]){
			flag=1;
			break;
		}
	}
	if(flag)
		cout<<-1;
	else
		cout<<ans;
	return 0;
}
