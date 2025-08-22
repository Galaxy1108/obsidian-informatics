#include<iostream>
#include<cstring>
#include<queue>
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
long long w[2005][2005] = {} ;
long long val[2005] = {} ;
int n = 0 ;
bool vis[2005] = {} ;
inline void Prime(int st)
{
	for(int i = 1 ; i <= n ; ++i)
		val[i] = 1e9 + 7 , vis[i] = false ;
	int cnt = 0 ;
	priority_queue< pair<int , int> , vector< pair<int , int> > , greater< pair<int , int> > > Q ;
	Q.push(make_pair(0 , st)) ;
	while(!Q.empty())
	{
		int x = Q.top().second ;
		Q.pop() ;
		if(vis[x])
			continue ;
		vis[x] = true ;
		for(int i = 1 ; i <= n ; ++i)
			if(!vis[i])
				if(min(val[x] , w[x][i]) < val[i])
					val[i] = min(val[x] , w[x][i]) , Q.push(make_pair(val[i] , i)) ;
	}
	val[st] = 0 ;
}
int main()
{
	File("b") ;
	qcin>>n ;
	for(int i = 1 ; i < n ; ++i)
		for(int j = i + 1 ; j <= n ; ++j)
			qcin>>w[i][j] , w[j][i] = w[i][j] ;
	for(int i = 1 ; i <= n ; ++i)
		w[i][i] = 1e9 + 7 ;
	for(int t = 1 ; t <= n ; ++t)
	{
		Prime(t) ;
		long long ans = 0 ;
		for(int i = 1 ; i <= n ; ++i)
			ans += val[i] ;
		qcout<<ans<<'\n' ;
	}
	return 0 ;
}
