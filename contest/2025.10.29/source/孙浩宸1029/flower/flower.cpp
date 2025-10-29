#include<bits/stdc++.h>
#define vector deque
using namespace std;
//string a[50];/*
/*int n;
vector<int> ans[41];
bool po[89];
bool check(vector<int> ve){
	memset(po,0,sizeof(po));
	ve.push_front(0);
	for(int i=1;i<=2*n;i++){
		if(po[i]){
			continue;
		}
		if(ve[i] + 1+i > 2*n){
//			cout<<"bid"<<endl<<i<<endl;
			return 0;
		}
		if(ve[ve[i]+1+i]!=ve[i]){
//			cout <<"dkshf"<<" \n"<<i;
			return 0;
		} else {
//			cout<<i<<endl;
			po[ve[i]+1+i]=1;
		}
	}
	return 1;
}
bool checkqj(vector<int> ve,int len){
	memset(po,0,sizeof(po));
	ve.push_front(0);
	for(int i=1;i<len;i++){
		if(po[i]){
			continue;
		}
		if(ve[i] + i+1>len){
			continue;
		}
		else
		{
			if(ve[ve[i]+i+1]!=ve[i]){
				return 0;
			} else {
				po[ve[i]+i+1]=1;
			}
		}
	}
	return 1;
}
void merge_ans(vector<int> an){
	if(!ans[n].empty()){
		return;
	}
	for(int i = 1;i <= 2*n;i++){
		ans[n].push_back(an[i - 1]);
	}
	return;
}
void dfs(int dep,vector<int> ve){
	if(!checkqj(ve,dep)){
		return ;
	}
	int tong[50];
	memset(tong,0,sizeof(tong));
	vector<int> cho;
	if(dep == 2*n){
		if(check(ve)){
			merge_ans(ve);
			return;
		} else {
			return;
		}
	} else {
		for(int fk:ve){
			tong[fk] ++;
		}
		for(int i = 1;i <= n;i++){
			if(tong[i] != 2){
				cho.push_back(i);
				tong[i]++;
			}
		}
		for(auto fk:cho){
			ve.push_back(fk);
			dfs(dep + 1,ve);
			ve.pop_back();
		}
	}
	return;
}*/
vector<int> vee;
vector<int> ve[10];
string a[1009];
void work(){
	ve[4]={2, 3, 4, 2, 1, 3, 1, 4};
	ve[7]={1, 4, 1, 5, 6 ,7, 4, 2, 3 ,5 ,2, 6, 3, 7};
	int n;
	cin >> n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n==3){
		cout<<a[2]<<endl<<a[3]<<endl<<a[1]<<endl<<a[2]<<endl<<a[1]<<endl<<a[3];
		return ;
	} 
	return ;
}
int main()
{
	work();
	freopen("flower.in","r",stdin);
	freopen("flower.out","w",stdout);
//	ios::sync_with_stdio(NULL);
//	cin.tie(0),cout.tie(0);
//	cin >> n;
/*	for(int i = 1;i <= n;i++){
		cin >> a[n];
	}*/
//	n = 3;
//	n = 4;
//	vector<int> test={2 ,3, 4, 2, 1, 3, 1, 4};
//	cout<<check(test)  <<endl;
/*	for(int i = 1;i <= 9;i ++){
		n = i;
		dfs(0,vee);
		cout << "ans of " << n << endl;
		for(auto fk : ans[n]){
			cout << fk << ' ';
		}
		cout << endl;
	}*/
//	freopen("flower.out","w",stdout);
	return 0;
}
/*
ans of 1

ans of 2

ans of 3
2 3 1 2 1 3
ans of 4
2 3 4 2 1 3 1 4
ans of 5

ans of 6

ans of 7
1 4 1 5 6 7 4 2 3 5 2 6 3 7
ans of 8
1 3 1 6 7 3 8 5 2 4 6 2 7 5 4 8
ans of 9
*/
