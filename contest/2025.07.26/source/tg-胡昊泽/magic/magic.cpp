#include<iostream>
#include<cstring>
#include<queue>
#include<algorithm>
#define File(s) freopen(s".in" , "r" , stdin) , freopen(s".out" , "w" , stdout)
using namespace std ;
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
int n = 0 , q = 0 ;
int p[2][200005] = {} ;
int tot = 0 ;
queue<int> q1 , q2 ;
int now = 0 , las = 1 ;
inline bool check()
{
	for(int i = 1 ; i <= n ; ++i)
		if(p[now][i] != p[las][i])
			return false ;
	return true ;
}
int all = 0 ;
struct query
{
	int t , i , id , ans ;
} ques[1000005] ;
int ques_now = 1 ;
inline bool cmp1(const query& a , const query& b)
{
	return a.t < b.t ;
}
inline bool cmp2(const query& a , const query& b)
{
	return a.id < b.id ;
}
int main()
{
	File("magic") ;
	qcin>>n>>q ;
	for(int i = 1 ; i <= n ; ++i)
		qcin>>p[0][i] ;
	for(int i = 1 , t , x ; i <= q ; ++i)
	{
		qcin>>t>>x ;
		ques[i].t = t , ques[i].i = x , ques[i].id = i ;
	}
	sort(ques + 1 , ques + q + 1 , cmp1) ;
	do
	{
		while(ques_now <= q && ques[ques_now].t == all)
		{
			ques[ques_now].ans = p[now][ques[ques_now].i] ;
			++ques_now ;
		}
		if(ques_now > q)
			break ;
		tot = 0 ;
		now ^= 1 , las ^= 1 ;
		for(int i = 1 ; i <= (n >> 1) ; ++i)
			q1.push(p[las][i]) ;
		for(int i = (n >> 1) + 1 ; i <= n ; ++i)
			q2.push(p[las][i]) ;
		while(!q1.empty() && !q2.empty())
		{
			if(q1.front() < q2.front())
				p[now][++tot] = q1.front() , q1.pop() ;
			else
				p[now][++tot] = q2.front() , q2.pop() ;
		}
		while(!q1.empty())
			p[now][++tot] = q1.front() , q1.pop() ;
		while(!q2.empty())
			p[now][++tot] = q2.front() , q2.pop() ;
//		for(int i = 1 ; i <= n ; ++i)
//			qcout<<p[now][i]<<' ' ;
//		qcout<<'\n' ;
		++all ;
	} while(!check()) ;
//	qcout<<all<<'\n' ;
	if(ques[ques_now].t >= all)
		while(ques_now <= q)
			ques[ques_now].ans = p[now][ques[ques_now].i] , ++ques_now ;
	sort(ques + 1 , ques + q + 1 , cmp2) ;
	for(int i = 1 ; i <= q ; ++i)
		qcout<<ques[i].ans<<'\n' ;
	return 0 ;
}
