#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n, k;
  cin >> n >> k;

  priority_queue<ll> heap;
  rep(i, n) {
    ll a;
    cin >> a;
    heap.push(a);
  }

  ll ans = 0;
  while (k--) {
    if (heap.size() == 0) break;

    ll x = heap.top();
    heap.pop();
    ans += x;
    --x;
    if (x > 0) heap.push(x);
  }

  cout << ans << "\n";
  return 0;
}