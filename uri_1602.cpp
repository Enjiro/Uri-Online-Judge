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

const int MN=2*1e+6+35;
int dp[MN];
vector<ll>primes;
bool isprime[MN];

void sieve(ll lim)
{
	for(int i=2; i<=lim; i++)
		isprime[i]=true;

	for(ll i=2; i<=lim; i++)
	{
		if(isprime[i])
		{
			primes.pb(i);
			for(ll j=i*i; j<=lim; j+=i)
				isprime[j]=false;
		}
	}
}

int divisors(ll x)
{
	int ret=1;
	for(int i=0; i<primes.size() && x>1; i++)
	{
		ll y=primes[i];
		int cnt=0;
		while(x%y==0)
		{
			x/=y;
			cnt++;
		}
		ret*=(cnt+1);
	}
	if(x>1)
		ret*=2;
	return ret;
}

bool square(int x)
{
	ll a=(ll)sqrt(x);
	return x==a*a;
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

	sieve(2000000);
	dp[2]=1;
	for(ll i=3; i<=2000000; i++)
	{
		dp[i]=dp[i-1];
		if(isprime[i])
			dp[i]++;
		else if(square(i) && isprime[divisors(i)])
			dp[i]++;
	}

	ll x;
	while(scanf("%lld", &x)==1)
		printf("%d\n", dp[x]);

	return 0;
}