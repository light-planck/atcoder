#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int kInf = 1e9;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  int a;
  cin >> a;

  string s;
  cin >> s;

  int x = stoi(s);
  int len = s.size();
  if (len > 1 && x % 10 != 0) {
    swap(s[0], s[len - 1]);
  }
  int y = stoi(s);
  
  if (x % a != 0 && y % a != 0) {
    cout << -1 << "\n";
    return 0;
  }

  int cnt1 = 0;
  while (x > 1) {
    if (x % a != 0) {
      cnt1 = kInf;
      break;
    }

    ++cnt1;
    x /= a;
  }

  int cnt2 = 0;
  while (y > 1) {
    if (y % a != 0) {
      cnt2 = kInf;
      break;
    }
    
    ++cnt2;
    y /= a;
  }

  cout << cnt1 << " " << cnt2 << "\n";

  int ans = min(cnt1, cnt2);
  cout << ans + 1 << "\n";
  
  // if (min(cnt1, cnt2) == 0) {
  //   cout << max(cnt1, cnt2) << "\n";
  // }
  // else {
  //   cout << min(cnt1, cnt2) << "\n";
  // }
  return 0;
}