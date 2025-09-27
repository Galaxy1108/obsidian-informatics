#include <bits/stdc++.h>
using namespace std;
int n=0,ans=0;
string s;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	int x=0,y=0,z=0;
	n=s.size();
	for(int i=0;i<n;i++){
		if(i<=n-1&&s[i]==s[i+1]) ans=-1;
		if(s[i]=='0') x++;
		if(s[i]=='1') y++;
		if(s[i]=='2') z++;
	}
	if(x>(n+1)/2||y>(n+1)/2||z>(n+1)/2){
		cout<<"-1"<<endl;
		return 0;
	}
	if(ans!=-1) {
		cout<<0<<endl;
		return 0; 
	}
	int f1=0,f2=0;
	ans=0;
	for(int i=0;i<n-1;i++){
		f1=-1,f2=-1;
		if(s[i]==s[i+1]){
			for(int j=i-1;j>=0;j--){
				if((j==0||s[j+1]!=s[j-1])&&s[j]!=s[i]){
					f1=j;
					break;
				}
			}
			for(int j=i+1;j<n;j++){
				if(s[j]!=s[i]){
					f2=j;
					break;
				} 
			}
			if(f1!=-1&&abs(f1-i)<=abs(f2-i)||f2==-1){
				for(int j=f1;j<i;j++){
					swap(s[j],s[j+1]);
					ans++;
					if(s[i]!=s[i+1]) break;
				}
			}
			else{
				for(int j=f2;j>i;j--){
					swap(s[j],s[j-1]);
					ans++;
					if(s[i]!=s[i+1]) break;
				}
			}
		}
	}
	cout<<ans<<endl;
	return 0;
}
