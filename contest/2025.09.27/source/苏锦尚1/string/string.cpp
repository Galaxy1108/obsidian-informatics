#include<bits/stdc++.h>
using namespace std;
struct node{
	int a;
	int pos;
}f[4000];
int ans[4000];
int sb[4000];
int len;
queue <int> q[5];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string st;
	cin>>st;
	len=st.size();
	for(int i=0;i<st.size();i++){
		f[i+1].a=st[i]-'0';
		f[i+1].pos=i+1;
		q[f[i+1].a].push(i+1);
	
	}          
	
	ans[1]=q[f[1].a].front();
	q[f[1].a].pop();  
	sb[1]=f[1].a;      
	for(int i=2;i<=len;i++){
		if(sb[i-1]==0){
			if(q[1].empty()&&q[2].empty()){
				cout<<"-1";
				return 0;
			}
			else if(q[1].empty()){
		 		ans[i]=q[2].front();
				sb[i]=2;
				q[2].pop();
			}
			else if(q[2].empty()){
				ans[i]=q[1].front();
				sb[i]=1;
				q[1].pop();
			}
			else if(q[1].front()<q[2].front()){
				ans[i]=q[1].front();
				sb[i]=1;
				q[1].pop();
			}
			else{
				ans[i]=q[2].front();
				sb[i]=2;
				q[2].pop();
			}
		}
		else if(sb[i-1]==1){
			if(q[0].empty()&&q[2].empty()){
				cout<<"-1";
				return 0;
			}
			else if(q[0].empty()){
		 		ans[i]=q[2].front();
				sb[i]=2;
				q[2].pop();
			}
			else if(q[2].empty()){
				ans[i]=q[0].front();
				sb[i]=0;
				q[0].pop();
			}
		
			else if(q[0].front()<q[2].front()){
				ans[i]=q[0].front();
				sb[i]=0;
				q[0].pop();
			}
			else if(q[0].front()>q[2].front()){
				ans[i]=q[2].front();
				sb[i]=2;
				q[2].pop();
			}
			
		}
		 else if(sb[i-1]==2){
		 	if(q[1].empty()&&q[0].empty()){
				cout<<"-1";
				return 0;
			}
		 	else if(q[0].empty()){
		 		ans[i]=q[1].front();
				sb[i]=1;
				q[1].pop();
			}
			else if(q[1].empty()){
				ans[i]=q[0].front();
				sb[i]=0;
				q[0].pop();
			}
			else if(q[1].front()<q[0].front()){
				ans[i]=q[1].front();
				sb[i]=1;
				q[1].pop();
			}
			else{
				ans[i]=q[0].front();
				sb[i]=0;
				q[0].pop();
			}
		}
	}
	long long sum=0;
	for(int i=1;i<len;i++){
		for(int j=i+1;j<=len;j++){
			if(ans[j]<ans[i])
			sum++;
		}
	}      
	cout<<sum;
	return 0;       
}
