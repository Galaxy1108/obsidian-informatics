#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 1000010;
int box[N],a[N],id[N];
vector <int> pun[N];
bool check(int x,int y,int i,int j){
	if(box[x]==1&&box[y]==1){
		return 1;
	}
	if(box[x]==1&&pun[y][id[j]-1]<=i&&id[j]==pun[y].size()-1){
		return 1;
	}
	if(box[y]==1&&pun[x][id[i]+1]>=j&&id[i]==0){
		return 1;
	}
	if(pun[y][id[j]-1]<=i&&pun[x][id[i]+1]>=j&&id[j]==pun[y].size()-1&&id[i]==0){
		return 1;
	}
	else return 0;
}
//bool check(int x,int y){
//	if(box[x]==1&&box[y]==1)return 1;
//	else return 0;
//}
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	int n,l,r;
	cin>>n>>l>>r;
	for(int i = 1;i<=n;i++){
		cin>>a[i];
		id[i] = box[a[i]];
		box[a[i]]++;
		pun[a[i]].push_back(i);
	}
	int len = r-l+3;int p = l-1;
	bool flag = 0;
	for(;len<=n;len++){
		p = l-1;
		while(p-1+len>=r+1&&p>=1){
			if(check(a[p],a[p-1+len],p,p-1+len)){
				flag = 1;
				break;
			}
			p--;
		}
		if(flag)break;
	}
	if(!flag)cout<<-1;
	else cout<<len<<endl;
	return 0;
}
