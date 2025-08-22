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
long long n = 0 , m = 0 , mod = 0 ;
//long long dp[10000005] = {} ;
//inline get_id(int x , int l , int r)
//{
//	return (x - 1) * m * m + (l - 1) * m + r ;
//}
//int main()
//{
//	qcin>>n>>m>>mod ;
//	for(int l = 1 ; l <= m ; ++l)
//		for(int r = l ; r <= m ; ++r)
//			dp[get_id(1 , l , r)] = 1 ;
//	for(int i = 2 ; i <= n ; ++i)
//	{
//		for(int l = 1 ; l <= m ; ++l)
//		{
//			for(int r = l ; r <= m ; ++r)
//			{
//				for(int l1 = l ; l1 <= r ; ++l1)
//					for(int r1 = l1 ; r1 <= r ; ++r1)
//						(dp[get_id(i , l , r)] += dp[get_id(i - 1 , l1 , r1)]) %= mod ;
//				for(int l1 = l - 1 ; l1 >= 1 ; --l1)
//					for(int r1 = l ; r1 <= m ; ++r1)
//						(dp[get_id(i , l , r)] += dp[get_id(i - 1 , l1 , r1)]) %= mod ;
//				for(int r1 = r + 1 ; r1 <= m ; ++r1)
//					for(int l1 = l ; l1 <= r ; ++l1)
//						(dp[get_id(i , l , r)] += dp[get_id(i - 1 , l1 , r1)]) %= mod ;
//			}
//		}
//	}
//	long long ans = 0 ;
//	for(int l = 1 ; l <= m ; ++l)
//		for(int r = l ; r <= m ; ++r)
//			(ans += dp[get_id(n , l , r)]) %= mod ;
//	qcout<<ans<<'\n' ;
//	return 0 ;
//}
//最朴素的O(nm^4)
int dp[10000005][2] = {} ;
//dp[i][j][0]表示到i时以j为左端点的合法方案数,1表示右端点
int sum[10000005][2] = {} ;
//发现下面的转移可以前缀和优化
int sumk[10000005][2] = {} ;
//转移的第一部分需要另一个前缀和
//注意long long会爆内存
inline int get_id(int x , int y)
{
	return (x - 1) * m + y ;
}
int main()
{
	File("a") ;
	qcin>>n>>m>>mod ;
	for(int i = 1 ; i <= m ; ++i)
	{
		dp[get_id(1 , i)][0] = m - i + 1 , dp[get_id(1 , i)][1] = i ;
		sum[get_id(1 , i)][0] = (1ll * sum[get_id(1 , i - 1)][0] + m - i + 1) % mod , sum[get_id(1 , i)][1] = (1ll * sum[get_id(1 , i - 1)][1] + i) % mod ;
		sumk[get_id(1 , i)][0] = (1ll * sumk[get_id(1 , i - 1)][0] + 1ll * (m - i + 1) * (m - i + 1) % mod) % mod , sumk[get_id(1 , i)][1] = (1ll * sumk[get_id(1 , i - 1)][1] + 1ll * i * i % mod) % mod ;
	}
	for(int i = 2 ; i <= n ; ++i)
	{
		for(int l = 1 ; l <= m ; ++l)
		{
//			for(int k = l ; k <= m ; ++k)
//				(dp[get_id(i , l)][0] += dp[get_id(i - 1 , k)][0] * (m - k + 1) % mod) %= mod ;
			(dp[get_id(i , l)][0] += (1ll * sumk[get_id(i - 1 , m)][0] - 1ll * sumk[get_id(i - 1 , l - 1)][0] + mod) % mod) %= mod ;
//			for(int k = 1 ; k < l ; ++k)
//				(dp[get_id(i , l)][0] += dp[get_id(i - 1 , k)][0] * (m - l + 1) % mod) %= mod ;
			(dp[get_id(i , l)][0] += (1ll * sum[get_id(i - 1 , l - 1)][0] - 1ll * sum[get_id(i - 1 , 0)][0] + mod) % mod * (m - l + 1) % mod) %= mod ;
//			for(int k = 1 ; k < l ; ++k)
//				((dp[get_id(i , l)][0] -= dp[get_id(i - 1 , k)][1] * (m - l + 1) % mod) += mod) %= mod ;
			((dp[get_id(i , l)][0] -= (1ll * sum[get_id(i - 1 , l - 1)][1] - 1ll * sum[get_id(i - 1 , 0)][1] + mod) % mod * (m - l + 1) % mod) += mod) %= mod ;
		}
		for(int r = 1 ; r <= m ; ++r)
		{
//			for(int k = r ; k >= 1 ; --k)
//				(dp[get_id(i , r)][1] += dp[get_id(i - 1 , k)][1] * k % mod) %= mod ;
			(dp[get_id(i , r)][1] += (1ll * sumk[get_id(i - 1 , r)][1] - 1ll * sumk[get_id(i - 1 , 0)][1] + mod) % mod) %= mod ;
//			for(int k = r + 1 ; k <= m ; ++k)
//				(dp[get_id(i , r)][1] += dp[get_id(i - 1 , k)][1] * r % mod) %= mod ;
			(dp[get_id(i , r)][1] += (1ll * sum[get_id(i - 1 , m)][1] - 1ll * sum[get_id(i - 1 , r)][1] + mod) % mod * r % mod) %= mod ;
//			for(int k = r + 1 ; k <= m ; ++k)
//				((dp[get_id(i , r)][1] -= dp[get_id(i - 1 , k)][0] * r % mod) += mod) %= mod ;
			((dp[get_id(i , r)][1] -= (1ll * sum[get_id(i - 1 , m)][0] - 1ll * sum[get_id(i - 1 , r)][0] + mod) % mod * r % mod) += mod) %= mod ;
		}
		for(int j = 1 ; j <= m ; ++j)
		{
			sum[get_id(i , j)][0] = (1ll * sum[get_id(i , j - 1)][0] + 1ll * dp[get_id(i , j)][0]) % mod , sum[get_id(i , j)][1] = (1ll * sum[get_id(i , j - 1)][1] + 1ll * dp[get_id(i , j)][1]) % mod ;
			sumk[get_id(i , j)][0] = (1ll * sumk[get_id(i , j - 1)][0] + 1ll * dp[get_id(i , j)][0] * (m - j + 1) % mod) % mod , sumk[get_id(i , j)][1] = (1ll * sumk[get_id(i , j - 1)][1] + 1ll * dp[get_id(i , j)][1] * j % mod) % mod ;
		}
	}
	long long ans = 0 ;
	for(int i = 1 ; i <= m ; ++i)
		(ans += dp[get_id(n , i)][0]) %= mod ;
	qcout<<ans<<'\n' ;
//	ans = 0 ;
//	for(int i = 1 ; i <= m ; ++i)
//		(ans += dp[get_id(n , i)][1]) %= mod ;
//	qcout<<ans<<'\n' ;
	return 0 ;
}
//只关注左端点或者右端点即可做到O(nm^2)
