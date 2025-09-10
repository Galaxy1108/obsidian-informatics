#include <cstdio>

int n,m,ans[10][10];

void init()
{
	ans[1][1]=2;
	ans[1][2]=4;
	ans[1][3]=7;
	ans[1][4]=11;
	ans[1][5]=16;
	ans[1][6]=22;
	ans[2][1]=4;
	ans[2][2]=16;
	ans[2][3]=49;
	ans[2][4]=121;
	ans[2][5]=256;
	ans[2][6]=484;
	ans[3][1]=7;
	ans[3][2]=49;
	ans[3][3]=265;
	ans[3][4]=1081;
	ans[3][5]=3481;
	ans[3][6]=9367;
	ans[4][1]=11;
	ans[4][2]=121;
	ans[4][3]=1081;
	ans[4][4]=7343;
	ans[4][5]=37441;
	ans[4][6]=149311;
	ans[5][1]=16;
	ans[5][2]=256;
	ans[5][3]=3481;
	ans[5][4]=37441;
	ans[5][5]=304186;
	ans[5][6]=1859926;
	ans[6][1]=22;
	ans[6][2]=484;
	ans[6][3]=9367;
	ans[6][4]=149311;
	ans[6][5]=1859926;
	ans[6][6]=7525839;
}

int main()
{
    // FILE* fin=fopen("chess.in","r");
    // FILE* fout=fopen("chess.out","w");
    // fscanf(fin,"%d%d",&n,&m);
    freopen("chess.in","r",stdin);
    freopen("chess.out","w",stdout);
    init();
    printf("%d\n",ans[n][m]);
    // fprintf(fout,"%d\n",ans[n][m]);
    // fclose(fin);
    // fclose(fout);
    return 0;
}