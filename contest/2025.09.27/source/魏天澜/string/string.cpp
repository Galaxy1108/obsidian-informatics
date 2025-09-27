#include<bits/stdc++.h>
using namespace std;
int n;
int solver(int x,int num,int cnt,char g,string &q);
int solvel(int x,int num,int cnt,char g,string &q){
	if(x==0)return INT_MAX;
	int step;
	for(step = x-1;step>=0;step--){
		if(q[step]!=g&&q[step+1]!=g)break; 
	}
	if(q[step]==g||q[step+1]==g)return INT_MAX;
	for(int i = step+1;i<=x;i+=2){
		swap(q[i],q[i+1]);
	}
	//cout<<x<<":"<<step<<";"<<num<<"sb"<<endl;
	cnt+=(x-step)/2;
	if(num==2)return cnt;
	string o,p;
	int y1 = solvel(x+1,num-1,cnt,g,o);
	int y2 = solver(x+num-1,num-1,cnt,g,p);
	if(y1==y2&&y2==INT_MAX)return INT_MAX; 
	if(y1<y2){
		q = o;
		cnt = y1;
	}
	else q = p,cnt = y2;
	return cnt;
}
int solver(int x,int num,int cnt,char g,string &q){
	if(x==n-1)return INT_MAX;
	int step;
	for(step = x+1;step<n;step++){
		if(q[step]!=g&&q[step-1]!=g)break; 
	}
	if(q[step]==g||q[step-1]==g)return INT_MAX;
	for(int i = step-1;i>=x;i-=2){
		swap(q[i],q[i-1]);
	}
	//cout<<x<<":"<<step<<";"<<num<<"sb"<<endl;
	cnt+=(step-x)/2;
	if(num==2)return cnt;
	string o,p;
	int y1 = solvel(x-num+1,num-1,cnt,g,o);
	int y2 = solver(x-1,num-1,cnt,g,p);
	if(y1==y2&&y2==INT_MAX)return INT_MAX;
	if(y1<y2){
		cnt = y1;
		q = o;
	}
	else q = p,cnt = y2;
	return cnt;
}	
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	string s;
	cin>>s;
	int cnt0 = 0,cnt1 = 0,cnt2 = 0;
	
	n = s.size();
	for(int i = 0;i<s.size();i++){
		if(s[i]=='0')cnt0++;
		if(s[i]=='1')cnt1++;
		if(s[i]=='2')cnt2++;
	}
	//cout<<cnt0<<" "<<cnt1<<" "<<cnt2<<endl;
	if(cnt0>(n+1)/2||cnt1>(n+1)/2||cnt2>(n+1)/2){
		cout<<-1;
		return 0;
	}
	int cnt = 1;
	int bgn = 0;
	int i = 1;
	int ans = 0;
	while(i<=n){
		if(i==n&&cnt>=2){
			string p,q;
			p = s,q = s;
			int q1 = solvel(bgn,cnt,0,s[i-1],p);
			int q2 = solver(i-1,cnt,0,s[i-1],q);
			if(q1<q2){
				s = p;
				ans+=q1;
			}
			else s = q,ans+=q2;
			i = 1;
			bgn = 0;
			cnt = 1;
			//cout<<ans<<endl;
			//cout<<s<<endl;
			continue;
		}
		if(s[i]==s[i-1])cnt++;
		else{
			if(cnt>=2){
				string p,q;
				p = s,q = s;
				int q1 = solvel(bgn,cnt,0,s[i-1],p);
				int q2 = solver(i-1,cnt,0,s[i-1],q);
				if(q1<q2){
					s = p;
					ans+=q1;
				}
				else s = q,ans+=q2;
				i = 1;
				bgn = 0;
				cnt = 1;
				//cout<<ans<<endl;
				//cout<<s<<endl;
				continue;
			}
			else bgn = i;
		}
		i++;
	}
	cout<<ans;
	return 0;
}
