#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n, k;
  cin >> n >> k;
  k--;

  vector<int> s(n);
  rep(i, n) {
    rep(j, 3) {
      int p;
      cin >> p;
      s[i] += p;
    }
  }

  vector<int> t = s;
  sort(t.rbegin(), t.rend());

  rep(i, n) {
    if (s[i] + 300 >= t[k]) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}