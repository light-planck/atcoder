#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, q;
  cin >> n >> q;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  map<int, vector<int>> mp;
  for (int i = 0; i < n; ++i) {
    mp[a[i]].push_back(i + 1);
  }

  rep(i, q) {
    int x, k;
    cin >> x >> k;

    if (mp[x].size() < k) {
      cout << -1 << "\n";
    }
    else{
      cout << mp[x][k - 1] << "\n";
    }
  }
  return 0;
}