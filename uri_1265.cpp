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

int n, q;
inline int solve(int x)
{
	int b=1;
	int s=0;
	int p=0;
	while(x>=s)
	{
		x-=s;

		b*=n;
		s=b*(p+1);
		p++;
	}

	vector<int>ans(p);
	for(int y=x/p, j=p-1; y>0; y/=n, j--)
		ans[j]=(y%n);
	return ans[x%p];
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
	while(scanf("%d %d", &n, &q) && (n+q))
	{
		vector<string>data;
		char buff[100];
		for(register int i=0; i<n; i++)
		{
			scanf("%s", buff);
			data.pb(buff);
		}

		for(register int i=0; i<q; i++)
		{
			int x;
			scanf("%d", &x);
			printf("%s\n", data[solve(x-1)].c_str());
		}
		printf("\n");
	}
	return 0;
}