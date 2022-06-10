#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> b(n);
  rep(i, n) cin >> b[i];

  vector<set<int>> a_idx(5000 + 1);
  rep(i, n) {
    a_idx[a[i]].insert(i);
  }
  
  rep(i, n - 3) {
    if (a_idx[b[i]].count(i)) {
      a_idx[b[i]].erase(i);
    }
  }

  vector<int> c(n);
  rep(i, 5000 + 1) {
    if (a_idx[i].count(i))
  }
  set<int> seen_a;
  rep(i, n - 1) {
    
  }
  return 0;
}