#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
const int inf = INT_MAX;
const int mod = 1000000007;

int main() {
  int n;
  cin >> n;
  vector<pair<string, string>> p(n);
  rep(i, n) cin >> p[i].first >> p[i].second;
  bool ans = false;
  for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
      if (p[i].first == p[j].first and p[i].second == p[j].second) {
        ans = true;
      }
    }
  }
  puts(ans ? "Yes" : "No");
  return 0;
}