#include<bits/stdc++.h> 
using namespace std;
int f[25005][25][2],n,m;
int id[8005],pos[8005],t[8005],sco[8005];
int getmx(int x,int y)
{
	int nmx=0;
	for(int i = y-2; i <= y+2; i++)
	{
		nmx=max(nmx,max(f[x-1][i][0],f[x-1][i][1]));
	}
	return nmx;
}
int main()
{
	freopen("sniper.in","r",stdin);
	freopen("sniper.out","w",stdout);
	sco[1]=100;
	sco[2]=100;
	sco[3]=97;
	sco[4]=96;
	sco[5]=95;
	sco[6]=90;
	sco[7]=85;
	sco[8]=80;
	sco[9]=82;//how?
	sco[10]=78;
	sco[11]=75;
	sco[12]=70;
	sco[13]=65;
	sco[14]=55;
	sco[15]=50;
	sco[16]=15;
	sco[17]=12;
	sco[18]=10;
	sco[19]=8;
	sco[20]=5;
	sco[21]=2;
	cin>>n;
	for(int i = 1; i <= n; i++)
	{
		cin>>id[i]>>pos[i]>>t[i];
		t[i]++;
	}
	int nowid=1;
	memset(f,-0x3f,sizeof(f));
	for(int i = 1; i <= 20; i++) f[0][i][0]=0;
	for(int i = 0; i <= 25003; i++)
	{
		//cout<<i<<" ";
		for(int j = 1; j <= 20; j++)
		{
			for(int k = -2; k <= 2; k++) 
			{
				if(j+k>=0&&j+k<=20)
				{
					f[i+1][j+k][0]=max(f[i+1][j+k][0],max(f[i][j][0],f[i][j][1]));
				}
			}
			//cout<<f[i][j][0]<<" ";
		}
		//cout<<endl;
		bool flg=0;
		int idd;
		while(nowid<=n&&t[nowid]<=i)
		{
			//cout<<i<<" "<<nowid<<endl;
			if(id[nowid]==15)
			{
				flg=1;
				idd=pos[nowid];
			}
			f[i+1][pos[nowid]][1]=max(f[i][pos[nowid]][0]+sco[id[nowid]],f[i+1][pos[nowid]][1]);
			nowid++;
		}
		if(flg)
		{
			//cout<<"flgg"<<endl<<endl<<endl<<idd<<endl<<endl<<endl; 
			for(int j = 0; j <= 20; j++)
			{
				if(j==idd) f[i+1][j][0]=-1000000000;
				else f[i+1][j][0]=f[i+1][j][1]=-1000000000;
			}
		}
	}
	int ans=0;
	for(int i = 1; i <= 20; i++)
	{
		ans=max(ans,f[25003][i][0]);
	}
	cout<<ans<<endl;
}
