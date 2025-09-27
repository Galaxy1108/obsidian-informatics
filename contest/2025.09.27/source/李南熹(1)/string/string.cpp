#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[405],b[5];
char s[405];
signed main(){
	freopen("string","r",stdin);
	freopen("string","w",stdout);
	cin>>s;
	int l=strlen(s),ans=0;
	for(int i=0;i<=l-1;i++){
		a[i+1]=s[i]-'0';
	}
	for(int i=1;i<=l;i++){
		b[a[i]]++;
		ans=max(ans,b[a[i]]);
	}
	if(ans>=2+l-ans){
		cout<<-1;
		return 0;
	}
	int flag=0;
	for(int i=1;i<=l;i++){
		if(a[i+1]==a[i]){
			flag=1;
			break;
		}
	}
	if(flag==0) cout<<0;
	else if(l>=3) cout<<b[0]+b[1]+b[2]-3;
	else cout<<0;
	return 0;
	fclose(stdin);
	fclose(stdout);
} 
