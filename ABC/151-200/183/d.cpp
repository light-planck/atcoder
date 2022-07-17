#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

const int max_t = 2e5+1;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int n, w;
  cin >> n >> w;
  vector<int> s(n), t(n), p(n);
  vector<ll> sum(max_t + 10);

  rep(i, n) {
    int s, t, p;
    cin >> s >> t >> p;
    sum[s] += p;
    sum[t] -= p;
  }

  rep(i, max_t) {
    sum[i + 1] += sum[i];
    if (sum[i] > w) {
      cout << "No\n";
      return 0;
    }
  }

  cout << "Yes\n";
  return 0;
}