#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
int n,l,r,s[1000005],book[1000005],id[1000005],cnt[1000005];
set<pair<int,int> > q;
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<l;i++){
		book[s[i]]++;
		if(book[s[i]]==1){
			id[s[i]]=i;
			q.insert({l-i,s[i]}); 
		}
		else if(book[s[i]]==2){
			auto it=q.find({l-id[s[i]],s[i]});
			q.erase(it);
		}
	}
	for(int i=l;i<=r;i++){
		book[s[i]]++;
		if(book[s[i]]==2&&id[s[i]]){
			auto it=q.find({l-id[s[i]],s[i]});
			q.erase(it);
		}
	}
	auto it=q.begin();
	pair<int,int> ttt=*it;
	for(int i=n;i>=l-ttt.fi;i--)
		cnt[s[i]]++;
	for(int i=r+1;i<=n;i++){
		book[s[i]]++;
		if(book[s[i]]==2&&id[s[i]]){
			auto it=q.find({l-id[s[i]],s[i]});
			pair<int,int> ttt=*it;
			q.erase(it);
			auto iti=q.begin();
			pair<int,int> kkk=*iti;
			for(int j=l-kkk.fi;j<l-ttt.fi;j++)
				cnt[s[j]]++; 
		}
		if(cnt[s[i]]==1){
			auto it=q.begin();
			if(it==q.end())
				continue;
			pair<int,int> ttt=*it;
			cout<<(i-l+ttt.fi+1);
			return 0;
		}
	}
	cout<<-1;
	return 0;
} 
