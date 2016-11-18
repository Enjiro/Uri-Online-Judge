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
#define ALL(x) x.begin(),x.end()
#define RESET(a,b) memset(a, b, sizeof(a))
#define DEBUG(x,y) cout << x << y << endl
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

class point
{
public:
	double x, y;
	point(){};
	point(double _x, double _y)
	{
		x=_x, y=_y;
	}
};
typedef vector<point> polygon;

double area(polygon &data)
{
	double ret=0;
	for(int i=0; i<data.size()-1; i++)
	{
		double x1=data[i].x;
		double y1=data[i].y;
		double x2=data[i+1].x;
		double y2=data[i+1].y;
		ret+=(x1*y2-x2*y1);
	}
	return fabs(ret)/2.0;
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
	int n;
	scanf("%d", &n);
	polygon polygon;
	vector<int>data(n), aux(n);

	for(int i=0; i<n; i++)
		scanf("%d", &data[i]);
	sort(ALL(data));
	for(int i=0, j=n-1, p=0; p<n; p++)
	{
		if(p&1)
			aux[j--]=data[p];
		else
			aux[i++]=data[p];
	}

	double k=360.0/n;
	k=RAD(k);
	for(int i=0; i<n; i++)
		polygon.pb(point(cos(i*k)*aux[i], sin(i*k)*aux[i]));
	polygon.pb(polygon[0]);
	printf("%.3f\n", area(polygon));
	return 0;
}