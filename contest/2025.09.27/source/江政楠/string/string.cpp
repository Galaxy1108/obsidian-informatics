#include<bits/stdc++.h>
using namespace std;
int dp[405][405];
int total;
int cnt0,cnt1,cnt2;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++){
		if(s[i]=='0') cnt0++;
		else if(s[i]=='1') cnt1++;
		else if(s[i]=='2') cnt2++;
	}
	if(cnt0+cnt1<cnt2-1||cnt0+cnt2<cnt1-1||cnt1+cnt2<cnt0-1){
		cout<<-1;
		return 0;
	}
	for(int i=1;i<n;i++){
		if(s[i-1]==s[i]){
			int a1=0,a2=0,b1=0,b2=0;
			int stp1,stp2,stp3,stp4;
			int stp1_,stp2_,stp3_,stp4_;
			for(int j=i+1;j<n;j++){
				if(s[j]!=s[i]){
					a1+=j-i;
					stp1=j;
					stp2=i;
					break;
				}
			}
			for(int j=i;j<n;j++){
				if(s[j]!=s[i-1]){
					a2+=j-i+1;
					stp3=i-1;
					stp4=j;
					break;
				}
			}
			
			if(a1!=0||a2!=0){
				if(a1<a2) swap(s[stp1],s[stp2]);
				else swap(s[stp3],s[stp4]);
				/*for(int i=0;i<n;i++){
					cout<<s[i];
				}
				cout<<endl;*/
				total+=min(a1,a2);
				continue;
			} 
			for(int j=i-2;j>=0;j--){
				if(s[j]!=s[i-1]){
					b1+=i-j-1;
					stp1_=j;
					stp2_=i-1;
					break;
				}
			}
			for(int j=i-1;j>=0;j--){
				if(s[j]!=s[i]){
					b2+=i-j;
					stp3_=i;
					stp4_=j;
					break;
				}
			}
			if(b1!=0||b2!=0){
				if(b1<b2) swap(s[stp1_],s[stp2_]);
				else swap(s[stp3_],s[stp4_]);
				/*for(int i=0;i<n;i++){
					cout<<s[i];
				}
				cout<<endl;*/
				total+=min(b1,b2);
				continue;
			}
		}
	}
	cout<<total;
	return 0;
}
