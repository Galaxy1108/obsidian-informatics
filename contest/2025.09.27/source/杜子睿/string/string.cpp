#include<bits/stdc++.h>
using namespace std;
string s;
int a[405],p[405],t,tt,ttt,n;
int minn=INT_MAX;
void dfs(int x){
	if(x==n){
		int cnt=0;
		for(int i=0;i<n-1;i++)
			for(int j=i+1;j<n;j++)
				cnt+=(p[i]>p[j]);
		minn=min(minn,cnt);
	}
	int k=int(s[x]-'0');
	for(int i=1;i<=n;i++){
		if(a[i]!=-1)
			continue;
		if(i==1){
			if(a[2]==-1||a[2]!=k){
				a[1]=k;
				p[x]=1;
				dfs(x+1);
			}
		}
		else if(i==n){
			if(a[n-1]==-1||a[n-1]!=k){
				a[n]=k;
				p[x]=n;
				dfs(x+1);
			}
		}
		else{
			if((a[i-1]==-1||a[i-1]!=k)&&(a[i+1]==-1||a[i+1]!=k)){
				a[i]=k;
				p[x]=i;
				dfs(x+1);
			}
		}
		a[i]=-1;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>s;
	n=s.size();
	for(int i=0;i<s.size();i++){
		if(s[i]=='0')
			t++;
		else if(s[i]=='1')
			tt++;
		else
			ttt++;
	}
	int kkk=n/2;
	if(n%2)
		kkk++;
	if(t>kkk||tt>kkk||ttt>kkk){
		cout<<-1;
		return 0;
	}
	if(n==1){
		cout<<0;
		return 0;
	}
	else if(n<=20){
		for(int i=1;i<=n;i++)
			a[i]=-1;
		dfs(0);
		if(minn!=INT_MAX)
			cout<<minn;
		else
			cout<<-1;
	}
	else
		cout<<0;
	return 0;
}

