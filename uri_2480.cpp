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

class node
{
public:
	int x, y, i;
	node(){};
	node(int _x, int _y, int _i)
	{
		x=_x, y=_y, i=_i;
	}
	bool operator <=(const node &foo) const
	{
		if(y!=foo.y)
			return y<foo.y;
		return x<=foo.x;
	}
};

const int MN=1e+5+35;
const int MN2=25;
int n, m;
char aux[]={'S', 'G', 'W', 'R'};
node data[MN][MN2], tdata[MN2];
int pos[MN2], tpos[MN2];

inline int getValue(char x)
{
	for(int i=0; i<4; i++)
		if(x==aux[i])
			return i;
}

inline ll mergeSort(int p, int l, int r)
{
	if(abs(l-r)<=1)
		return 0;
	int mid=(l+r)/2;
	ll ret=mergeSort(p, l, mid)+mergeSort(p, mid, r);
	for(int i=l; i<r; i++)
		tdata[i]=data[p][i];
	for(int i=l, j=l, k=mid; j<mid || k<r; i++)
	{
		node x=j<mid?tdata[j]:node(INF, INF, INF);
		node y=k<r?tdata[k]:node(INF, INF, INF);
		if(x<=y)
		{
			data[p][i]=x;
			j++;
		}
		else
		{
			data[p][i]=y;
			k++;
			ret+=(ll)(mid-j);
		}
	}
	return ret;
}

inline ll solve()
{
	for(int i=0; i<n; i++)
		pos[i]=i;
	ll ret=0;
	for(register int i=0; i<m; i++)
	{
		if(i)
		{
			for(int j=0; j<n; j++)
				tpos[j]=pos[j];
			for(int j=0; j<n; j++)
				pos[j]=tpos[ data[i-1][j].i ];

			for(int j=0; j<n; j++)
				tdata[j]=data[i][j];
			for(int j=0; j<n; j++)
			{
				data[i][j]=tdata[ pos[j] ];
				data[i][j].i=j;
			}
		}
		ret+=mergeSort(i, 0, n);
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
	int tt=0;
	while(scanf("%d %d", &n, &m)!=EOF)
	{
		if(tt)
			printf("\n");
		ll ans=0;
		for(register int i=0; i<n; i++)
		{
			for(register int j=0; j<m; j++)
			{
				int x;
				char y;
				scanf(" [%d]%c", &x, &y);
				ans+=(ll)(y=='R')*x;
				data[j][i]=node(x, getValue(y), i);
			}
		}
		printf("Instance %02d:\n", ++tt);
		printf("%lld %lld\n", solve(), ans);
	}
	return 0;
}