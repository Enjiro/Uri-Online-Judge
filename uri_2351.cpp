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

const int MN=1e+5+35;
class segtree
{
	const static int N=MN;
	pll tr[4*N];
	ll lazy[4*N];
public:
	segtree(){};
	void clear()
	{
		memset(tr, 0, sizeof(tr));
		memset(lazy, 0, sizeof(lazy));
	}
	void propagate(int no, int l, int r)
	{
		if(!lazy[no])
			return;
		tr[no]=mp(tr[no].F+((r-l+1)*lazy[no]), tr[no].S+lazy[no]);
		if(l!=r)
		{
			int nxt=no*2;
			lazy[nxt]+=lazy[no];
			lazy[nxt+1]+=lazy[no];
		}
		lazy[no]=0;
	}
	void update(int no, int l, int r, int i, int j, ll x)
	{
		propagate(no, l, r);
		if(l>j || r<i)
			return;
		if(l>=i && r<=j)
		{
			lazy[no]=x;
			propagate(no, l, r);
			return;
		}
		int nxt=no*2;
		int mid=(l+r)/2;
		update(nxt, l, mid, i, j, x);
		update(nxt+1, mid+1, r, i, j, x);
		tr[no]=mp(tr[nxt].F+tr[nxt+1].F, min(tr[nxt].S,tr[nxt+1].S));
	}
	pll query(int no, int l, int r, int i, int j)
	{
		propagate(no, l, r);
		if(l>j || r<i)
			return mp(0, LINF);
		if(l>=i && r<=j)
			return tr[no];
		int nxt=no*2;
		int mid=(l+r)/2;
		pll ql=query(nxt, l, mid, i, j);
		pll qr=query(nxt+1, mid+1, r, i, j);
		return mp(ql.F+qr.F, min(ql.S, qr.S));
	}
};

int n, k;
segtree st;
vector<pll>data;

bool f(pll x, pll y)
{
	if(x.F!=y.F)
		return x.F>y.F;
	return x.S>y.S;
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
	scanf("%d %d", &n, &k);
	ll ans=0;
	for(int i=0; i<n; i++)
	{
		ll x;
		scanf("%lld", &x);
		data.pb({x, i});
		ans+=x;
		if(i>0)
			st.update(1, 0, n, i, n, 1);
	}
	st.update(1, 0, n, n, n, LINF);
	
	sort(ALL(data), f);
	for(int i=0; i<n; i++)
	{
		ll x=data[i].F;
		ll p=data[i].S;
		pll q1=st.query(1, 0, n, p, p);
		pll q2=st.query(1, 0, n, p+1, n);
		if((q1.F>=k) && ((q2.S-k-1)>=0))
		{
			ans-=x;
			st.update(1, 0, n, p, p, -k);
			st.update(1, 0, n, p+1, n, -k-1);
		}
	}
	printf("%lld\n", ans);
	return 0;
}