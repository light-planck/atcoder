#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  string s;
  cin >> s;
  sort(all(s));
  int len = s.size();
  ll ans = 0;
  
  // n!
  do {

    // 数字の間のどれかに仕切りを入れるn-1通り
    // s[0], s[1] | s[2], ...(i = 2)
    for (int i = 1; i <= len - 1; i++) {
      string left, right;
      for (int j = 0; j < i; j++) left += s[j];
      for (int j = i; j < len; j++) right += s[j];
      if (left[0] == '0' || right[0] == '0') continue;
      ans = max(ans, (ll)stoi(left) * stoi(right));
    }
  } while (next_permutation(all(s)));

  cout << ans << endl;
  return 0;
}