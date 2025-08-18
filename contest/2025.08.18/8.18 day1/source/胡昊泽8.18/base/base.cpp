#include<iostream>
#include<cstring>
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
		#define sb(ch) (ch == ' ' || ch == '\n' || ch == '\r')
		inline void read(char& c)
		{
			char tmp = getchar() ;
			while(sb(tmp))
				tmp = getchar() ;
			c = tmp ;
		}
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
long long a[2005][2] = {} ;
long long sum[2005][2] = {} ;
int n = 0 ;
long long ans = -1e18 ;
long long dp[2005][2005][2][2][2] = {} ;
long long dfs(int l , int r , int kl , int kr , int i)
{
	if(l == r)
		return a[l][i] ;
	if(dp[l][r][kl][kr][i])
		return dp[l][r][kl][kr][i] ;
	dp[l][r][kl][kr][i] = sum[r][i] - sum[l - 1][i] ;
	dp[l][r][kl][kr][i] = min(dp[l][r][kl][kr][i] , dfs(l , r - 1 , kl , 1 , i) + a[r][i]) ;
	if(!kr)
		dp[l][r][kl][kr][i] = min(dp[l][r][kl][kr][i] , dfs(l , r - 1 , kl , kr , i)) ;
	dp[l][r][kl][kr][i] = min(dp[l][r][kl][kr][i] , dfs(l + 1 , r , 1 , kr , i) + a[l][i]) ;
	if(!kl)
		dp[l][r][kl][kr][i] = min(dp[l][r][kl][kr][i] , dfs(l + 1 , r , kl , kr , i)) ;
	return dp[l][r][kl][kr][i] ;
}
int main()
{
	File("base") ;
	qcin>>n ;
	for(int i = 0 ; i < 2 ; ++i)
		for(int j = 1 ; j <= n ; ++j)
			qcin>>a[j][i] , sum[j][i] = sum[j - 1][i] + a[j][i] ;
//	for(int i = 1 ; i <= n - 2 ; ++i)
//		for(int j = i + 2 ; j <= n ; ++j)
//			ans = max(ans , sum[j][0] - sum[i - 1][0] + a[i][1] + a[j][1]) ;
//	for(int i = 1 ; i <= n - 2 ; ++i)
//		for(int j = i + 2 ; j <= n ; ++j)
//			ans = max(ans , sum[j][1] - sum[i - 1][1] + a[i][0] + a[j][0]) ;


//	for(int i = 1 ; i <= n - 2 ; ++i)
//		for(int j = i + 2 ; j <= n ; ++j)
//			ans = max(ans , sum[j][0] - sum[i - 1][0] + sum[j][1] - sum[i - 1][1] - dfs(i + 1 , j - 1 , 0 , 0 , 1)) ;
	for(int i = 1 ; i <= n - 2 ; ++i)
		for(int j = i + 2 ; j <= n ; ++j)
			ans = max(ans , sum[j][1] - sum[i - 1][1] + sum[j][0] - sum[i - 1][0] - dfs(i + 1 , j - 1 , 0 , 0 , 0)) ;
	qcout<<ans<<'\n' ;
	return 0 ;
}
