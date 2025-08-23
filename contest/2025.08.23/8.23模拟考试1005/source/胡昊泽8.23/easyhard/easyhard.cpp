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
//long long dp[2][3005][3005] = {} ;
//int n = 0 , m = 0 , mod = 0 ;
//int main()
//{
//	qcin>>n>>m>>mod ;
//	int now = 0 , las = 1 ;
//	for(int i = 0 ; i <= n ; ++i)
//	{
//		for(int j = 0 ; j <= n ; ++j)
//		{
//			if(i == 0 && j == 0)
//				dp[now][i][j] = 0 ;
//			else if(i == 0)
//				dp[now][i][j] = 2 ;
//			else if(j == 0)
//				dp[now][i][j] = 2 ;
//			else
//				dp[now][i][j] = 4 ;
//		}
//	}
//	for(int i = m - 1 ; i >= 1 ; --i)
//	{
//		now ^= 1 , las ^= 1 ;
//		for(int l = 0 ; l <= n ; ++l)
//			for(int r = 0 ; r <= n ; ++r)
//			{
//				dp[now][l][r] = 0 ;
//				if(l)
//				{
//					(dp[now][l][r] += dp[las][l][r]) %= mod ;
//					(dp[now][l][r] += dp[las][l - 1][r + 1]) %= mod ;
//				}
//				if(r)
//				{
//					(dp[now][l][r] += dp[las][l][r]) %= mod ;
//					(dp[now][l][r] += dp[las][l + 1][r - 1]) %= mod ;
//				}
//			}
//	}
//	long long ans = 0 ;
//	for(int i = 0 ; i <= n ; ++i)
//		(ans += dp[now][i][n - i]) %= mod ;
//	qcout<<ans<<'\n' ;
//	return 0 ;
//}
int n = 0 , m = 0 , mod = 0 ;
inline long long qpow(long long a , long long k)
{
	long long ret = 1 ;
	while(k)
	{
		if(k & 1)
			(ret *= a) %= mod ;
		(a *= a) %= mod ;
		k >>= 1 ;
	}
	return ret ;
}
int dp[3005][3005][2][2] = {} ;
bool vis[3005][3005][2][2] = {} ;
int dfs(int now , int x , bool f1 , bool f2)
{
	if(now == m + 1)
		return f1 || f2 ;
	if(vis[now][x][f1][f2])
		return dp[now][x][f1][f2] ;
	vis[now][x][f1][f2] = true ;
	long long res = 0 ;
	if(x < n)
		res += dfs(now + 1 , x + 1 , f1 || (x + 1 == 0) , f2 || (x + 1 == n)) ;
	if(x > 0)
		res += dfs(now + 1 , x - 1 , f1 || (x - 1 == 0) , f2 || (x - 1 == n)) ;
//	if(x < n)
//		(res += dfs(now + 1 , x , f1 || (x == 0) , f2 || (x == n))) %= mod ;
//	if(x > 0)
//		(res += dfs(now + 1 , x , f1 || (x == 0) , f2 || (x == n))) %= mod ;
	(res += dfs(now + 1 , x , f1 || (x == 0) , f2 || (x == n)) * ((x < n) + (x > 0))) %= mod ;
	return dp[now][x][f1][f2] = res ;
}
int main()
{
	File("easyhard") ;
	qcin>>n>>m>>mod ;
//	qcout<<qpow(2 , n + m)<<'\n' ;
	long long ans = 0 ;
	for(int i = 0 ; i <= n ; ++i)
		(ans += dfs(1 , i , 0 , 0)) %= mod ;
	qcout<<ans<<'\n' ;
	return 0 ;
}
