#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  vector<int> b = a;
  sort(all(b));
  b.erase(unique(all(b)), b.end());
  rep(i, a.size()) {
    int idx = lower_bound(all(b), a[i]) - b.begin();
    cout << idx << endl;
  }
  return 0;
}