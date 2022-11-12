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
// template<class T, class U> void print(const map<T, U>& mp) { for (const auto& [x, y] : mp) { print(x, y); } }
template<class T> void print(set<T>& st) { for (const auto& a : st) { cout << a << " "; } print(); }
// void print(vector<pair<ll, ll>>& vp) { for (auto [x, y] : vp) print(x, y); }


int main() {
  auto chmin = [](auto& a, auto b) { if (a > b) a = b; };

  ll n, m;
  cin >> n >> m;

  vector<ll> a(n);
  rep(i, n) cin >> a[i];
  sort(a.begin(), a.end());
  ll sum_a = accumulate(a.begin(), a.end(), 0);

  if (a[0] == 0 and a.back() == m-1) {
    auto b = a;
    rep(i, n) a.emplace_back(b[i]);
  }

  ll len_a = a.size();

  vector<ll> s(len_a+1);
  rep(i, len_a) s[i + 1] = s[i] + a[i];

  ll ans = 1e9;
  ll right = 1;

  // print(a);
  for (ll left = 0; left < len_a; ++left) {
    if (left == right) ++right;
    if (right >= n and right-n >= left) break;

    while ((right < len_a) and ((a[right]-a[right-1]+m) % m <= 1)) {
      ++right;
    }

    ll now = s[right]-s[left];
    // print(left, right, now);
    chmin(ans, sum_a-now);
  }

  cout << ans << '\n';
  return 0;
}