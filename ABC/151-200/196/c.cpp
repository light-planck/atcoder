#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;
const int inf = 1e9;
const int mod = 1e9+7;

int main() {
  ll n;
  cin >> n;
  ll ans = 0;

  //1212のようなときは前半の数字だけ考えれば良い
  //12 | 12のようにして12を見る
  //ゆえ、O(sqrt(n))
  ll i = 1;
  while (true) {
    string s = to_string(i);
    if (stoll(s + s) > n) {
      ans = i - 1;
      break;
    }
    i++;
  }
  cout << ans << endl;
  return 0;
}