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
constexpr long long mod = 1e9 + 7 ;
struct matrix
{
	long long mat[10][10] ;
	inline matrix()
	{
		for(int i = 0 ; i < 10 ; ++i)
			for(int j = 0 ; j < 10 ; ++j)
				mat[i][j] = 0 ;
	}
	inline void init()
	{
		for(int i = 0 ; i < 10 ; ++i)
			mat[i][i] = 1 ;
	}
	inline matrix operator*(const matrix& b) const
	{
		matrix ret ;
		for(int i = 0 ; i < 10 ; ++i)
			for(int j = 0 ; j < 10 ; ++j)
				for(int k = 0 ; k < 10 ; ++k)
					(ret.mat[i][j] += mat[i][k] * b.mat[k][j] % mod) %= mod ;
		return ret ;
	}
	inline void operator*=(const matrix& b)
	{
		*this = *this * b ;
	}
}  ;
inline matrix qpow(matrix a , long long k)
{
	matrix res ;
	res.init() ;
	while(k)
	{
		if(k & 1)
			res *= a ;
		a *= a ;
		k >>= 1 ;
	}
	return res ;
}
matrix ans , base ;
long long k = 0 ;
int main()
{
	File("sam") ;
	qcin>>k ;
	for(int i = 0 ; i < 10 ; ++i)
		for(int j = 1 ; j < 10 ; ++j)
			ans.mat[i][j] = 1 ;
	for(int i = 0 ; i < 10 ; ++i)
		for(int j = 0 ; j < 10 ; ++j)
			if(i - j >= -2 && i - j <= 2)
				base.mat[i][j] = 1 ;
	ans *= qpow(base , k - 1) ;
	long long sum = 0 ;
	for(int i = 0 ; i < 10 ; ++i)
		(sum += ans.mat[0][i]) %= mod ;
	qcout<<sum<<'\n' ;
}
