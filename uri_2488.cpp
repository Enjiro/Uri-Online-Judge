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
#define SET(a,b) memset(a, b, sizeof(a))
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

class sparse_table
{
public:
	static const int MN=1000000;
	static const int LMN=22;
	double data[MN][LMN];

	int t;
	int lt;
	sparse_table(){};
	void build(vector<double>&aux)
	{
		t=aux.size();
		lt=lbit(t);
		for(int i=0; i<t; i++)
			data[i][0]=aux[i];

		for(int j=1; j<=lt; j++)
			for(int i=0; i<t-(1<<j)+1; i++)
				data[i][j]=max(data[i][j-1], data[i+(1<<(j-1))][j-1]);
	}

	inline double query(int l, int r)
	{
		int d=abs(l-r)+1;
		int q=lbit(d);
		return max(data[l][q], data[r-(1<<q)+1][q]);
	}
};

sparse_table spt;
map<pii,int>remap;
vector<double>data;

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
	int n, q;
	scanf("%d %d", &n, &q);

	int lx, ly;
	data.pb(0);
	for(int i=0; i<n; i++)
	{
		int x, y;
		scanf("%d %d", &x, &y);
		if(i)
			data.pb(hypot(x-lx, y-ly));
		remap[mp(x, y)]=i;
		lx=x;
		ly=y;
	}

	spt.build(data);
	for(int i=0; i<q; i++)
	{
		int x[2], y[2];
		for(int j=0; j<2; j++)
			scanf("%d %d", &x[j], &y[j]);
		int l=remap[mp(x[0], y[0])];
		int r=remap[mp(x[1], y[1])];
		if(l>r)
			swap(l, r);
		printf("%.2f\n", spt.query(l+1, r));
	}
	return 0;
}