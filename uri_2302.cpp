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

enum {West, East, North, South};
int mi[] = {0, 0, 1, -1, -1, 1, 1, -1};
int mj[] = {1, -1, 0, 0, 1, 1, -1, -1};

int n, m, x, y;
bool valid(int i, int j)
{
	return (i>=x-1 && i<=x+1 && j>=y-1 && j<=y+1);
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
	scanf("%d %d %d %d", &n, &m, &x, &y);

	int q, i=0, j=0, ans=0;
	scanf("%d", &q);
	for(int tt=0; tt<q; tt++)
	{
		int s;
		scanf("%d", &s); s--;
		if(valid(i, j) && valid(i+mi[s], j+mj[s]))
			ans++;
		i+=mi[s];
		j+=mj[s];
		if(valid(i, j))
			ans++;
	}
	printf("%d\n", ans);
	return 0;
}