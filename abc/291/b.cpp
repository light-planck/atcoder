#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  vector<ll> x(5 * n);
  rep(i, 5*n) cin >> x[i];
  sort(x.begin(), x.end());

  deque<ll> deq(x.begin(), x.end());
  rep(i, n) deq.pop_front();
  rep(i, n) deq.pop_back();

  double sum = 0;
  for (auto x : deq) sum += x;
  printf("%.10f\n", sum / (3*n));
  return 0;
}