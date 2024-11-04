namespace Pollard_Rho {
  #define ll long long
  #define ull unsigned long long
  #define ld long double
  #define ne
  #define MAXN 10100
  using namespace std;
  const int maxn = 1e6 + 5;
  ll ksc(ull x, ull y, ll p) {return (x * y- (ull)((ld)x / p * y) * p + p) % p;}
  ll ksm(ll x, ll y, ll p) {
    ll res = 1;
    for(; y; y >>= 1, x = ksc(x,x,p)) if(y & 1) res = ksc(res, x, p);
    return res;
  }
  ll Abs(ll x) {return x < 0 ? -x : x;}
  ll gcd(ll x, ll y) {
    ll z;
    while (y){z = x; x = y; y = z % y;}
    return x;
  }
  bool mr(ll x, ll p) {
    if (ksm(x, p - 1, p) != 1) return 0;
    ll y = p - 1,z;
    while (!(y & 1)) {
      y >>= 1; z = ksm(x, y, p);
      if (z != 1 && z != p - 1) return 0;
      if (z == p - 1) return 1;
    }
    return 1;
  }
  ll te_pri[20] = {0, 2, 3, 5, 7, 43, 61, 24251};
  int te_num = 7;
  bool isprime(ll x) {
    if (x < 2)return 0;
    for (int i = 1; i <= te_num; ++i) if(x == te_pri[i]) return 1;
    for (int i = 1; i <= te_num; ++i) if(!(x % te_pri[i]) || !mr(te_pri[i], x))return 0;
    return 1;
  }
  ll rho(ll p) {
    ll x, y, z, c, g;
    int i, j;
    while(1) {
      y = x = rand() % p;
      z = 1, c = rand() % p;
      i = 0, j = 1;
      while(++i) {
        x = (ksc(x, x, p) + c) % p;
        z = ksc(z, Abs(y - x), p);
        if (x == y || !z) break;
        if(!(i % 127) || i == j) {
          g = gcd(z, p);
          if (g > 1)return g;
          if (i == j) y = x, j<<= 1;
        }
      }
    }
  }
  ll ys[maxn]; //最后的质数分解在ys中 
  int ind; //每次重新使用ind记得清零 
  void prho(ll p) {
    if (p == 1) return;
    if (isprime(p)) {ys[++ind] = p; return;}
    ll pi = rho(p);
    while (p % pi == 0) p /= pi;
    prho(pi), prho(p);
  }

  std::vector<int> divide(ll x) {
    ind = 0;
    prho(x);
    sort(ys + 1, ys + 1 + ind);
    int m = unique(ys + 1, ys + ind + 1) - ys - 1;
    std::vector<int> primes;
    for (int i = 1; i <= m; ++i) primes.emplace_back(ys[i]);
    return primes;
  }
}