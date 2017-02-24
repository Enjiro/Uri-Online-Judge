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

const int MN=1300;
int lp[MN+1];
vector<ll>pr;
void sieve()
{
	for(int i=2; i<=MN; i++)
	{
		if(lp[i]==0)
		{
			lp[i]=i;
			pr.pb((ll)i);
		}
		for(int j=0; j<pr.size() && pr[j]<=lp[i] && i*pr[j]<=MN; j++)
			lp[ i*pr[j] ]=pr[j];
	}
}

inline ll powmod(ll a, ll b, ll m)
{
	ll ret=1;
	while(b)
	{
		if(b&1)
			ret=(ret*a)%m, --b;
		else
			a=(a*a)%m, b>>=1;
	}
	return ret;
}

inline bool millerRabin(ll n)
{
	ll b=2;
	for(ll g; (g=gcd(n, b))!=1; b++)
		if(n>g)
			return false;
	ll p=0, q=n-1;
	while((q&1)==0)
		p++, q>>=1;
	ll rem=powmod(b, q, n);
	if(rem==1 || rem==n-1)
		return true;
	for(ll i=1; i<p; i++)
	{
		rem=(rem*rem)%n;
		if(rem==n-1)
			return true;
	}
	return false;
}

inline bool isPrime(ll x)
{
	int k=50; //trivial limit
	for(int i=0; i<k && pr[i]<x; i++)
		if(x%pr[i]==0)
			return false;
	if(pr[k-1]*pr[k-1]>=x)
		return true;
	return millerRabin(x);
}

inline ll solve(ll x)
{
	if(x==2)
		return 1;
	if(x%2==0)
		return x-2;
	if(isPrime(x))
		return x-1;
	if(isPrime(x-1))
		return x-2;
	for(int i=0; i<pr.size() && x-pr[i]>0; i++)
	{
		ll y=x-pr[i];
		if(isPrime(y))
			return x-2;
	}
	return x-3;
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
	sieve();
	ll x;
	while(scanf("%lld", &x)!=EOF)
		printf("%lld\n", solve(x));
	return 0;
}