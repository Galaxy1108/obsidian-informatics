#include <bits/stdc++.h>
using namespace std;
int n,m,x,y,res=0,res1=0,t;
string s,s1;
int main(){
	freopen("bounce.in","r",stdin);
	freopen("bounce.out","w",stdout);
	cin>>n>>m;
	s='#';
	res=n;
	for(int i=1;i<=n;i++) s+='1';
	if(n>1000){
		int a[30];
		for(int k=1;k<=20;k++){
			s1=s;
			res1=res;
			int cnt=0;
			for(int i=1;res!=0;i++){
				if(i&1){
					cnt=y-1;
					for(int j=1;j<=n;j++){
						if(s1[j]=='1') cnt++;
						if(cnt==y){
							cnt=0;
							t=j;
							s1[j]='0';
							res1--;
						}
					}
				}
				else{
					cnt=y-1;
					for(int j=n;j>=1;j--){
						if(s1[j]=='1') cnt++;
						if(cnt==y&&s1[j]!='0'){
							res1--;
							t=j;
							cnt=0;
							s1[j]='0';
						}
					}
				}
			}
			while(m--){
				cin>>x>>y;
				cout<<a[y]<<endl;
			}
		}
			
	}
	while(m--){
		cin>>x>>y;
		if(x==1){
			for(int i=1;i<=n;i+=y){
				s[i]='0';
				res--;
			}
		}
		else if(x==2){
			int cnt=y-1;
			for(int i=1;i<=n;i++){
				if(s[i]=='1') cnt++;
				//cout<<cnt<<" "<<i<<endl;
				if(cnt==y){
					cnt=0;
					s[i]='0';
					res--;
				}
			}
		}
		else{
			s1=s;
			res1=res;
			int cnt=0;
			t=-1;
			for(int i=1;res1!=0;i++){
				if(i&1){
					cnt=y-1;
					for(int j=1;j<=n;j++){
						if(s1[j]=='1') cnt++;
						if(cnt==y&&s1[j]!='0'){
							cnt=0;
							t=j;
							s1[j]='0';
							res1--;
						//	cout<<t<<endl;
						}
					}
				}
				else{
					cnt=y-1;
					for(int j=n;j>=1;j--){
						if(s1[j]=='1') cnt++;
						if(cnt==y&&s1[j]!='0'){
							res1--;
							t=j;
							cnt=0;
							s1[j]='0';
						//	cout<<t<<endl;
						}
					}
				}
			}
			cout<<t<<endl;
		}
		//cout<<s<<endl;
	}
	return 0;
} 
