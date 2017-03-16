/// David Mateus Batista <david.batista3010@gmail.com>
/// Computer Science - Federal University of Itajuba - Brazil

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define DINF (double)1e+30
#define EPS (double)1e-9
#define PI (double)acos(-1.0)
#define RAD(x) (double)(x*PI)/180.0
#define PCT(x,y) (double)x*100.0/y

#define pb push_back
#define mp make_pair
#define pq priority_queue
#define F first
#define S second

#define D(x) x&(-x)
#define SZ(x) (int)x.size()
#define ALL(x) x.begin(),x.end()
#define SET(a,b) memset(a, b, sizeof(a))

#define gcd(x,y) __gcd(x, y)
#define lcm(x,y) (x/gcd(x,y))*y

#define bitcnt(x) __builtin_popcountll(x)
#define lbit(x) 63-__builtin_clzll(x)
#define zerosbitll(x) __builtin_ctzll(x)
#define zerosbit(x) __builtin_ctz(x)

enum {North, East, South, West};
//{0, 1, 2, 3}
//{Up, Right, Down, Left}

int mi[] = {-1, 0, 1, 0, -1, 1, 1, -1};
int mj[] = {0, 1, 0, -1, 1, 1, -1, -1};

inline int cmp(double x, double y=0, double tol=EPS)
{
	return (x<=y+tol)?(x+tol<y)?-1:0:1;
}
struct point
{
	double x=0, y=0;
	point(){};
	point(double _x, double _y)
	{
		x=_x, y=_y;
	}
	point operator +(point q){return point(x+q.x, y+q.y);}
	point operator -(point q){return point(x-q.x, y-q.y);}
	point operator *(double t){return point(x*t, y*t);}
	point operator /(double t){return point(x/t, y/t);}
	double operator *(point q){return x*q.x + y*q.y;}//a*b = |a||b|cos(ang)
	double operator %(point q){return x*q.y - y*q.x;}//a%b = |a||b|sin(ang)
	double polar(){return((y>-EPS)?atan2(y, x) : 2*PI + atan2(y, x));}
	double mod(){return sqrt(x*x + y*y);}
	double mod2(){return (x*x + y*y);}
	point rotate(double t){return point(x*cos(t)-y*sin(t), x*sin(t)+y*cos(t));}
	int cmp(point q) const
	{
		if(int t=::cmp(x, q.x))
			return t;
		return ::cmp(y, q.y);
	}
	bool operator ==(point q) const{return cmp(q)==0;}
	bool operator !=(point q) const{return cmp(q)!=0;}
	bool operator <(point q) const{return cmp(q)<0;}
	static point pivot;
};

point point::pivot;
typedef vector<point>polygon;

inline int ccw(point p, point q, point r)
{
	return cmp((p-r)%(q-r));
}

double distPointPoint(point &x, point &y)
{
	return hypot(x.x-y.x, x.y-y.y);
}

double distPointLine(point p, point q, point r)
{
	point A = r - q, B = r - p, C = q - p;
	double a = A * A, b = B * B, c = C * C;
	return fabs(A % B) / sqrt(c);
}

polygon convexHull(polygon T)
{
	int n=T.size(), k=0;
	polygon H(2*n);

	sort(T.begin(), T.end());

	//lower_hull
	for(int i=0; i<n; i++)
	{
		while(k>=2 && ccw(H[k-1], T[i], H[k-2])<=0)
			k--;
		H[k++]=T[i];
	}
	//upper_hull
	for(int i=n-2, t=k+1; i>=0; i--)
	{
		while(k>=t && ccw(H[k-1], T[i], H[k-2])<=0)
			k--;
		H[k++]=T[i];
	}
	H.resize(k);
	return H;
}

double minimumWidth(polygon &ch)
{
	double ret=DINF;
	int sz=ch.size();
	int j=1;
	for(int i=0; i<sz; i++)
	{
		int nxt=(j+1)%sz;
		while(distPointLine(ch[i], ch[(i+1)%sz], ch[j])<distPointLine(ch[i], ch[(i+1)%sz], ch[nxt]))
		{
			j=(j+1)%sz;
			nxt=(j+1)%sz;
		}
		ret=min(ret, distPointLine(ch[i], ch[(i+1)%sz], ch[j]));
	}
	return ret;
}

void init()
{
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cout << "[FREOPEN]" << endl;
	return;
}

int main()
{
	//init();
	int n, tt=1;
	while(scanf("%d", &n) && n)
	{
		polygon temp;
		for(int i=0; i<n; i++)
		{
			double x, y;
			scanf("%lf %lf", &x, &y);
			temp.pb(point(x, y));
		}
		polygon ch=convexHull(temp);
		ch.pop_back();
		double ans=minimumWidth(ch);
		printf("Case %d: %.2f\n", tt++, ans+0.005);
	}
	return 0;
}