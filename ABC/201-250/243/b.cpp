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

  int n;
  cin >> n;
  vector<int> a(n), b(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> b[i];

  ll cnt1 = 0;
  ll cnt2 = 0;
  rep(i, n) {
    if (a[i] == b[i]) ++cnt1;
  }
  rep(i, n) rep(j, n) {
    if (a[i] == b[j]) ++cnt2;
  }

  cout << cnt1 << "\n";
  cout << cnt2 - cnt1 << "\n";
  return 0;
}