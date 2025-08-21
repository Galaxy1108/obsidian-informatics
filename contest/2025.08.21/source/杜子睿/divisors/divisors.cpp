#include<bits/stdc++.h>
using namespace std;
int n;
int a[105][105]={{},{},{},{2,6,3},
{3,6,8,12},
{10,15,6,8,4},
{5,15,12,6,8,4},
{7,35,15,12,6,8,4},
{8,56,35,15,12,6,8,4},
{9,72,56,35,15,12,6,8,4},
{9,72,56,35,15,12,30,10,4,8},
{99,72,56,35,15,12,30,10,4,8}};
int main(){
	freopen("divisors.in","r",stdin);
	freopen("divisors.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)
		cout<<a[n][i]<<" ";
	cout<<endl;
	for(int i=1;i<n;i++)
		cout<<i<<" "<<i+1<<endl;
	return 0;
}

