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

class node
{
public:
	int x, d, l;
	node(){};
	node(int _x, int _d, int _l)
	{
		x=_x, d=_d, l=_l;
	}
	bool operator <(const node &foo) const
	{
		if(x!=foo.x)
			return x<foo.x;
		if(d!=foo.d)
			return d<foo.d;
		return l<foo.l;
	}
};

int n, k;
int data[50];
int dist[35][8];

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
	int tt;
	scanf("%d", &tt);
	while(tt--)
	{
		scanf("%d %d", &n, &k);
		for(int i=0; i<n; i++)
			scanf("%d", &data[i]);
		sort(data, data+n);
		reverse(data, data+n);

		int ans=0;
		pq<node>heap;
		for(int i=0; i<n; i++)
			heap.push(node(data[i], 1, i+1));
		while(!heap.empty())
		{
			int x=heap.top().x;
			int d=heap.top().d;
			int l=heap.top().l;
			heap.pop();
			if(d==k)
				ans=max(ans, x);
			if(x<=ans)
				continue;
			for(int i=l; i<n; i++)
				heap.push(node(x&data[i], d+1, i+1));
		}
		printf("%d\n", ans);
	}
	return 0;
}