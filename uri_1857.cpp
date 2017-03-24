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

inline int cmp(ll x, ll y=0)
{
	return (x<=y)?(x<y)?-1:0:1;
}

struct point
{
	ll x=0, y=0;
	point(){};
	point(ll _x, ll _y)
	{
		x=_x, y=_y;
	}
	point operator +(point q){return point(x+q.x, y+q.y);}
	point operator -(point q){return point(x-q.x, y-q.y);}
	point operator *(double t){return point(x*t, y*t);}
	point operator /(double t){return point(x/t, y/t);}
	ll operator *(point q){return x*q.x + y*q.y;}
	ll operator %(point q){return x*q.y - y*q.x;}
	
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
	return cmp((p - r) % (q - r));
}

double polar(ll x, ll y)
{
	return atan2(y, x);
}

bool polarCompare(point x, point y)
{
	if(ccw(x,y, point(0,0))==0)
		return (x.x*x.x)+(x.y*x.y)<(y.x*y.x)+(y.y*y.y);
	double a=polar(x.x, x.y);
	double b=polar(y.x, y.y);
	return a<b;
}

const int MN=101;
const int MN2=2001;
int n, m;
polygon data;
int dp[MN][MN][MN2];
int val[MN][MN];

int getArea(polygon P)
{
	int result=0, x1, y1, x2, y2;
	for (int i=0; i<(int)P.size()-1; i++)
	{
		x1 = P[i].x; x2 = P[i+1].x;
		y1 = P[i].y; y2 = P[i+1].y;
		result += (x1 * y2 - x2 * y1);
	}
	return abs(result);
}

int getValue(point a, point b, point c)
{
	polygon T;
	T.pb(a);
	T.pb(b);
	T.pb(c);
	T.pb(data[0]);
	return getArea(T);
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
	scanf("%d %d", &n, &m);
	n++;
	data.resize(n);
	for(int i=0; i<n; i++)
	{
		scanf("%lld %lld", &data[i].x, &data[i].y);
		if(i)
			data[i]=data[i]-data[0];
	}
	data[0]=point(0, 0);
	sort(data.begin(), data.end(), polarCompare);
	for(int i=0; i<n; i++)
		for(int j=i+1; j<n; j++)
			dp[i][j][0]=1;

	for(int i=1; i<n; i++)
		for(int j=i+1; j<n; j++)
			val[i][j]=getValue(data[0], data[i], data[j]);

	int ans=0;
	for(int i=0; i<n; i++)
	{
		for(int j=i+1; j<n; j++)
		{
			for(int k=j+1; k<n; k++)
			{
				if(ccw(data[j], data[k], data[i])<0)
					continue;
				int cst=val[j][k];
				for(int w=cst; w<=2*m; w++)
				{
					dp[j][k][w]|=dp[i][j][w-cst];
					if(dp[j][k][w])
						ans=max(ans, w);
				}
			}
		}
	}

	double dans=1.0L*ans/2.0L;
	printf("%g\n", dans);
	return 0;
}