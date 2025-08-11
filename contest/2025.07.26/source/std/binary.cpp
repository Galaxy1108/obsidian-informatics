#include <bits/stdc++.h>
using namespace std;
const int len[10]={1,2,5,11,23,47,95,191,383,767};
bool Tree[1025];
int m,n,top,x,y,i,j,k;
void cover(int k)
{
	Tree[k]=true;
	if(2*k<=top) cover(2*k);
	if(2*k+1<=top) cover(2*k+1);
	return;
}
void kg(int k)
{
	for(int i=0;i<k;i++)
	    cout<<' ';
	return;
}
int main()
{
	freopen("binary.in","r",stdin);
	freopen("binary.out","w",stdout);

	cin>>m>>n;
	top=1<<m;
	for(i=0;i<n;i++)
	{
		cin>>x>>y;
		cover((1<<(x-1))+y-1);
	}
	top=1;
	for(i=m-1;i>=0;i--)
	{
	    for(j=0;j<top;j++)
	    {
	    	if(i+j!=0) kg(len[i]);
	    	if(Tree[top+j]) cout<<' ';
	    	else cout<<'o';
	    	if(i==0&&j%2==1);
			else
			{
				kg(len[i]);
			    if(j!=top-1) cout<<' ';	
			}
		}
		cout<<endl;
		for(k=1;k<=len[i-1];k++)
	    {
	    	for(j=0;j<top;j++)
    		{
	    		kg(len[i]-k);
	    		if(Tree[2*(top+j)]) cout<<' ';
	    		else cout<<'/';
	    		kg(2*k-1);
	    		if(Tree[2*(top+j)+1]) cout<<' ';
	    		else cout<<'\\';
	    		kg(len[i]-k);
	    		if(j!=top-1);
	    		cout<<' ';
	    	}
	    	cout<<endl;
		}
	    top<<=1;
	}
	return 0;
}