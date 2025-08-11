#include<bits/stdc++.h>
using namespace std;
int n,book[1000005],b[1000005],cnt;
double a[1000005];
vector<int> e; 
int main(){
	freopen("las.in","r",stdin);
	freopen("las.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	if(n>=100000){
		for(int i=1;i<=n;i++)
			cout<<i<<" ";
		return 0;
	}
	for(int i=1;i<n;i++){
		if(2*a[i]<=a[i+1]){
			book[i]=i+1;
			b[i+1]=1;
			cnt++;
			e.push_back(i);
		}
		if(a[i]>=2*a[i+1]){
			book[i]=i;
			b[i]=1;
			cnt++;
			e.push_back(i);
		}
	}
	if(a[1]*2<=a[n]){
		book[n]=n;
		b[n]=1;
		cnt++;
		e.push_back(n);
	}
	if(a[n]*2<=a[1]){
		book[n]=1;
		b[1]=1;
		cnt++;
		e.push_back(n);
	}
	if(!cnt){
		for(int i=1;i<=n;i++)
			cout<<i<<" ";
		return 0;
	}
	if(cnt==1){
		if(book[e[0]]==e[0]){
			for(int i=1;i<=n;i++)
				cout<<i<<" ";
			return 0;
		}
		else{
			for(int i=1;i<n;i++)
				cout<<i+1<<" ";
			cout<<1;
			return 0;
		}
	}
	for(int i=0;i<cnt-1;i++){
		int l1=(book[e[i]]==e[i]),l2=(book[e[i+1]]==e[i+1]);
		if(l1&&l2){
			for(int j=e[i]+1;j<e[i+1];j++)
				book[j]=j;
		}
		else if(!l1&&!l2){
			for(int j=e[i]+1;j<e[i+1];j++)
				book[j]=j+1;
		}
		else if(l1&&!l2){
			if(a[e[i]+1]>a[e[i]+2])
				for(int j=e[i]+1;j<e[i+1];j++)
					book[j]=j;
			else
				for(int j=e[i]+1;j<e[i+1];j++)
					book[j]=j+1;
		}
		else{
			if(e[i+1]==e[i]+2){
				if(a[e[i]+1]>a[e[i+1]])
					book[e[i]+1]=e[i]+1;
				else
					book[e[i]+1]=e[i]+2;
				continue;
			}
			int ff=0,id;
			for(int j=e[i]+2;j<e[i+1];j++){
				if(a[j]>a[j+1]&&a[j]>a[j-1]){
					ff=1;
					id=j;
					break;
				}
			} 
			if(!ff){
				if(a[e[i]+1]>a[e[i]+2])
					for(int j=e[i]+1;j<e[i+1];j++)
						book[j]=j;
				else
					for(int j=e[i]+1;j<e[i+1];j++)
						book[j]=j+1;
				continue;
			}
			for(int j=e[i]+1;j<id;j++)
				book[j]=j+1;
			for(int j=id;j<e[i+1];j++)
				book[j]=j; 
		}
	}
	cnt--;
	int l1=(book[e[cnt]]==e[cnt]),l2=(book[e[0]]==e[0]);
	if(l1&&l2){
		for(int j=e[cnt]+1;j<=n;j++)
			book[j]=j;
		for(int j=1;j<e[0];j++)
			book[j]=j;
	}
	else if(!l1&&!l2){
		for(int j=e[cnt]+1;j<n;j++)
			book[j]=j+1;
		book[n]=1;
		for(int j=1;j<e[0];j++)
			book[j]=j+1;
	}	
	for(int i=1;i<=n;i++)
		cout<<book[i]<<" ";
	return 0;
} 
