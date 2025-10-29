#include<iostream>
using namespace std;
int n,p[101],fst[55],flag,v[55];
string s[45];
void dfs(int k)
{
    if(k>n*2)
    {
    	/*flag=0;
    	//cout<<"fuck";
        for(int i=1;i<=n*2;i++)
        {
        	if(fst[p[i]]==0)
        	    fst[p[i]]=i;
        	else
        	    if(i-fst[p[i]]!=p[i]+1)
        	    {
        	    	flag=1;
        	    	break;
				}
		}
        if(flag==0)
            cout<<666<<endl;
        //flag=1;
        for(int i=1;i<=n;i++)
            fst[i]=0;*/
        flag=1;
        return ;
    }
    for(int i=1;i<=n;i++)
    {
        if(fst[i]==0)
        {
            fst[i]=k;
            p[k]=i;
            dfs(k+1);
            fst[i]=0;
            if(flag)
                return ;
        }
        else
        {
            //cout<<k<<" "<<fst[i]<<endl;
            if(k-fst[i]==i+1)
            {
                p[k]=i;
                dfs(k+1);
                if(flag==1)
                    return ;
            }
        }
        /*if(v[i]<=1)
        {
            p[k]=i;
            v[i]++;
            dfs(k+1);
            v[i]--;
        }*/
    }
    return ;
}
int main()
{
    freopen("flower.in","r",stdin);
    freopen("flower.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>s[i];
    dfs(1);
    for(int i=1;i<=n*2;i++)
        cout<<s[p[i]]<<"\n";
    return 0;
}

