#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  int n;
  cin >> n;
  vector<int> s(n);
  rep(i, n) cin >> s[i];

  int cnt = 0;
  set<int> st;
  for (int a = 1; a <= 1000; a++) {
    for (int b = 1; b <= 1000; b++) {
      rep(i, n) {
        if (4 * a * b + 3 * a + 3 * b == s[i]) {
          st.insert(i);
        }
      }
    }
  }

  cout << n - st.size() << endl;
  return 0;
}