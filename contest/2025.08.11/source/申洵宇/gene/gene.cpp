#include <bits/stdc++.h>
using namespace std;
/*
找到i<l,j>r，使得i<x<n只有一个sx=sj，1<x<j只有一个sx=si，si!=sj，要求最小的j-i+1 
*/
#define N 1000005 
int n,l,r,s[N],le[N],ri[N];//le:左边的出现次数，ri:右边的出现次数 
int main(){
	freopen("gene.in","r",stdin);
	freopen("gene.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>l>>r;
	for(int i=1;i<=n;i++){
		cin>>s[i];
	}
	int ans=N,_t,_lst,_l,_r;
	priority_queue<int>pq;
	for(int j=1;j<=r;j++){
		while((!pq.empty())&&le[s[pq.top()]]>1)pq.pop();
		if(le[s[j]]==0&&j<l){
			pq.emplace(j);
		}
		le[s[j]]++;
	}
	while((!pq.empty())&&le[s[pq.top()]]>1)pq.pop();
	for(int i=n;i>pq.top();i--){
		ri[s[i]]++;
	}
	for(int j=r+1;j<=n;j++){//确定右边界j 
		if(!pq.empty())_lst=pq.top();
		while((!pq.empty())&&le[s[pq.top()]]>1)pq.pop();
		if(pq.empty())break;
		for(int i=_lst;i>pq.top();i--){
			ri[s[i]]++;
		}
		if(ri[s[j]]==1){
			if(s[j]==s[pq.top()]){
				_lst=_t=pq.top();
				pq.pop();
				while((!pq.empty())&&le[s[pq.top()]]>1)pq.pop();
				if(!pq.empty()){
					for(int i=_lst;i>=pq.top()+1;i--){
						ri[s[i]]++;
					}
					if(ri[s[j]]==1){
						if(ans>j-pq.top()+1){
							ans=j-pq.top()+1;
							_l=pq.top();
							_r=j;
						}
					}
					for(int i=_lst;i>=pq.top()+1;i--){
						ri[s[i]]--;
					}
				}
				pq.emplace(_t);
			}
			else{
				if(ans>j-pq.top()+1){
					ans=j-pq.top()+1;
					_l=pq.top();
					_r=j;
				}
			}
		}
		le[s[j]]++;
	}
	if(ans==N){
		cout<<"-1";
	}
	else{
		cout<<ans;
//		cerr<<s[_l]<<","<<s[_r]<<endl;
//		for(int i=1;i<=n;i++){
//			if(s[_l]==s[i])cerr<<i<<' '; 
//		}
//		cerr<<endl;
//		for(int i=1;i<=n;i++){
//			if(s[_r]==s[i])cerr<<i<<' '; 
//		}
//		cerr<<_l<<"~"<<_r;
	}
/*
	for(int i=l-1;i>=1;i--){
		if(le[s[i]]==0){
			le[s[i]]=i;
		}
		else{
			le[s[i]]=-1;
		}
	}
	for(int i=r+1;i<=n;i++){
		if(ri[s[i]]==0){
			ri[s[i]]=i;
		}
		else{
			ri[s[i]]=-1;
		}
	}
	le[0]=0;
	ri[n+1]=N;
	int lm=0,lsm=0,rm=n+1,rsm=n+1;
	for(int i=1;i<=1000000;i++){
		if(le[i]!=0&&le[i]!=-1){
			if(le[i]>le[lm]){
				lsm=lm;
				lm=i;
			}
			else if(le[i]>le[lsm]){
				lsm=i;
			}
		}
		if(ri[i]!=0&&ri[i]!=-1){
			if(ri[i]<ri[rm]){
				rsm=rm;
				rm=i;
			}
			else if(ri[i]<ri[rsm]){
				rsm=i;
			}
		}
	}
	if(lm==0||rm==n+1){
		cout<<"-1";
	}
	else if(le[lm]!=ri[rm]){
		cout<<ri[rm]-le[lm]+1;
		cerr<<"DE:"<<le[lm]<<"~"<<ri[rm];
	}
	else if(lsm==0&&rsm==n+1){
		cout<<"-1";
	}
	else{
		assert(lsm==0||ri[rm]!=le[lsm]);
		assert(rsm==n+1||ri[rsm]!=le[lm]);
		cout<<min(lsm==0?N:(ri[rm]-le[lsm]+1),rsm==n+1?N:(ri[rsm]-le[lm]+1));
	}
*/
	return 0;
}

