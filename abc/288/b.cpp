#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n, k;
  cin >> n >> k;

  vector<string> t;
  rep(i, n) {
    string s;
    cin >> s;

    if (i < k) t.emplace_back(s);
  }
  sort(t.begin(), t.end());

  for (auto x : t) cout << x << endl;
  return 0;
}