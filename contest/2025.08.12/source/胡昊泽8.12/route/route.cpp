#include<iostream>
#include<cstring>
#include<vector>
#include<ext/pb_ds/assoc_container.hpp>
#include<ext/pb_ds/hash_policy.hpp>
using namespace std ;
#define File(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)
namespace IO
{
	#define isdigit(ch) (ch >= '0' && ch <= '9')
	#define SIZE (1 << 16)
	namespace Read
	{
		char buf[SIZE] , *_now = buf , *_end = buf ;
		inline char getchar()
		{
			if(_now == _end)
			{
				_now = _end = buf ;
				_end += fread(buf , 1 , SIZE , stdin) ;
				if(_now == _end)
					return EOF ;
			}
			return *(_now++) ;
		}
		template<typename T>
		inline void read(T& w)
		{
			w = 0 ;
			short f = 1 ;
			char ch = getchar() ;
			while(!isdigit(ch))
			{
				if(ch == '-')
					f = -1 ;
				ch = getchar() ;
			}
			while(isdigit(ch))
				w = (w << 1) + (w << 3) + (ch ^ 48) , ch = getchar() ;
			w *= f ;
		}
		inline void read(char& c)
		{
			char tmp = getchar() ;
			while(tmp == ' ' || tmp == '\n')
				tmp = getchar() ;
			c = tmp ;
		}
		#define sb(ch) (ch == ' ' || ch == '\n')
		inline void read(char* s)
		{
			char ch = getchar() ;
			while(sb(ch) && ch != EOF)
				ch = getchar() ;
			int len = 0 ;
			while(!sb(ch) && ch != EOF)
				s[len++] = ch , ch = getchar() ;
			s[len] = '\0' ;
		}
		inline void read(string& s)
		{
			s.clear() ;
			char ch = getchar() ;
			while(sb(ch) && ch != EOF)
				ch = getchar() ;
			while(!sb(ch) && ch != EOF)
				s.push_back(ch) , ch = getchar() ;
		}
		class qistream
		{
			public:
			template<typename T>
			inline qistream& operator>>(T& a)
			{
				read(a) ;
				return *this ;
			}
			inline qistream& operator>>(char* s)
			{
				read(s) ;
				return *this ;
			}
		} qcin ;
	}
	namespace Write
	{
		#define SIZE (1 << 16)
		char buf[SIZE] , *p = buf ;
		inline void flush()
		{
			fwrite(buf , 1 , p - buf , stdout) ;
			p = buf ;
		}
		inline void putchar(char ch)
		{
			if(p == buf + SIZE)
				flush() ;
			*p = ch ;
			++p ;
		}
		class Flush{public:~Flush(){flush() ;};}_;
		template<typename T>
		inline void write(T x)
		{
			char st[50] ;
			int len = 0 ;
			if(x < 0)
				putchar('-') , x = -x ;
			do
			{
				st[++len] = x % 10 + '0' ;
				x /= 10 ;
			} while(x) ;
			while(len)
				putchar(st[len--]) ;
		}
		inline void write(char c)
		{
			putchar(c) ;
		}
		inline void write(const char* s)
		{
			int siz = strlen(s) ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		inline void write(char* s)
		{
			int siz = strlen(s) ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		inline void write(string& s)
		{
			int siz = s.size() ;
			for(int i = 0 ; i < siz ; ++i)
				putchar(s[i]) ;
		}
		class qostream
		{
			public:
			template<typename T>
			inline qostream& operator<<(T x)
			{
				write(x) ;
				return *this ;
			}
			inline qostream& operator<<(const char* s)
			{
				write(s) ;
				return *this ;
			}
		} qcout ;
	}
	using Read::qcin ;
	using Write::qcout ;
}
using namespace IO ;
constexpr int N = 95 ;
constexpr long long inf = 1e15 ;
int A[N * N] = {} , B[N * N] = {} ;
long long S = 0 , L[N * N] = {} , C[N * N] = {} ;
int n = 0 , m = 0 ;
__gnu_pbds::gp_hash_table<long long , long long> dp[N][N][N] ;
// dp[ed][i][las][t] 表示从t时刻的点i出发到达终点ed的最短用时(上一个点是las) 
int q = 0 ;
struct edg
{
	int to ;
	long long w ;
	int id ;
} ;
vector<edg> edge[N] ;
bool vis[N] = {} ;
long long dfs(int ed , int now , int las , long long t)
{
	if(now == ed)
		return 0 ;
//	vis[now] = true ;
	long long& dp_now = dp[ed][now][las][t] ;
	if(dp_now)
		return dp_now ;
	dp_now = inf ;
	int siz = edge[now].size() , to = 0 , id = 0 ;
	long long w = 0 , tmp = 0 ;
	for(int i = 0 ; i < siz ; ++i)
	{
		to = edge[now][i].to , w = edge[now][i].w , id = edge[now][i].id ;
//		if(vis[to])
//			continue ;
		if(to == las)
			continue ;
		if(t > C[id] - w)
		{
			tmp = dfs(ed , to , now , 0) ;
			if(tmp != inf)
				dp_now = min(dp_now , tmp + S - t + w) ;
		}
		else
		{
			tmp = dfs(ed , to , now , (t + w) % S) ;
			if(tmp != inf)
				dp_now = min(dp_now , tmp + w) ;
		}
	}
//	vis[now] = false ;
	return dp_now ;
}
int main()
{
	File("route") ;
	qcin>>n>>m>>S>>q ;
	for(int i = 1 ; i <= m ; ++i)
	{
		qcin>>A[i]>>B[i]>>L[i]>>C[i] ;
		edge[A[i]].push_back((edg){B[i] , L[i] , i}) ;
		edge[B[i]].push_back((edg){A[i] , L[i] , i}) ;
	}
	int u = 0 , v = 0 ;
	long long t = 0 , tmp = 0 ;
	while(q--)
	{
		qcin>>u>>v>>t ;
		tmp = dfs(v , u , n , t) ;
		qcout<<tmp<<'\n' ;
	}
	return 0 ;
}
