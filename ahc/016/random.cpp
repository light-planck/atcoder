#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


random_device seed_gen;
mt19937 engine(seed_gen());

ll rand_int(ll l, ll r) {
  uniform_int_distribution<> dist(l, r);
  return dist(engine);
}


int main() {
  ll sum = 0;
  rep(i, 10) {
    sum += rand_int(0, 100);
  }
  cout << sum/10 << '\n';
  return 0;
}