#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  ll n;
  cin >> n;

  string s;
  cin >> s;

  vector<ll> nums(n);
  rep(i, n) {
    if (s[i] == 'R') nums[i] = 0;
    else if (s[i] == 'G') nums[i] = 1;
    else if (s[i] == 'B') nums[i] = 2;
  }

  vector<ll> cnt(3);
  rep(i, n) ++cnt[nums[i]];

  ll sum = 1;
  rep(i, 3) sum *= cnt[i];

  for (int i = 0; i < n; ++i) {
    for (int j = i + 1; j < n; ++j) {
      int k = 2 * j - i;

      if (k >= n) continue;
      if (nums[i] == nums[j]) continue;
      if (nums[i] == nums[k]) continue;
      if (nums[j] == nums[k]) continue;

      --sum;
    }
  }

  cout << sum << "\n";
  return 0;
}