#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


void print() { cout << '\n'; }
template<class T> void print(const T& value) { cout << value << '\n'; }
template<class T, class... A> void print(const T& first, const A&... tail) { cout << first << " "; print(tail...); }
template<class... A> void print(const A&... tail) { print(tail...); }
template<class T> void print(vector<T>& vec) { for (const auto& a : vec) { cout << a << " "; } print(); }
template<class T> void print(vector<vector<T>>& vec2d) { for (auto& vec : vec2d) { print(vec); } }
void print(vector<string>& grid) { for (const auto& row : grid) print(row); }
template<class T, class U> void print(const map<T, U>& mp) { for (const auto& [x, y] : mp) { print(x, y); } }
template<class T> void print(set<T>& st) { for (const auto& a : st) { cout << a << " "; } print(); }
void print(vector<pair<ll, ll>>& vp) { for (auto [x, y] : vp) print(x, y); }


int main() {
  bool debug = false;

  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };
  auto round = [](ll a, ll b) { return (a + b - 1) / b; };

  ll n;
  cin >> n;

  ll m = 3;
  vector<ll> a(m);
  rep(i, m) cin >> a[i];

  vector<ll> l(n);
  rep(i, n) cin >> l[i];
  sort(l.rbegin(), l.rend());

  ll ans = 1e9;
  for (ll bit = 0; bit < (1<<n); ++bit) {
    if (bit == (1<<n)-1) debug = true;

    vector<ll> use;
    rep(i, n) {
      if (bit>>i & 1) use.emplace_back(l[i]);
    }

    ll m = use.size();
    if (m <= 2) continue;

    if (debug) print(use);

    for (ll left = 1; left < m-1; ++left) {
      for (ll right = left+1; right < m; ++right) {
        if (debug) print("left: ", left, "right: ", right);

        ll sum = 0;
        ll cost = 0;

        rep(i, left) sum += use[i];
        cost += abs(sum-a[0]);
        if (left >= 2) cost += round(left, 2)*10;

        if (debug) print("cost: ", cost, "sum: ", sum);
        sum = 0;

        for (ll i = left; i < right; ++i) sum += use[i];
        cost += abs(sum-a[1]);
        if (right-left >= 2) cost += round(right-left, 2)*10;

        if (debug) print("cost: ", cost, "sum: ", sum);
        sum = 0;

        for (ll i = right; i < m; ++i) sum += use[i];
        cost += abs(sum-a[2]);
        if (m-right >= 2) cost += round(m-right, 2)*10;

        if (debug) print("cost: ", cost, "sum: ", sum);
        sum = 0;

        chmin(ans, cost);

        if (debug) print("______________");
      }
    }
  }

  cout << ans << '\n';
  return 0;
}