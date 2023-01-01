#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  set<string> st;
  char prev = '.';
  rep(i, n) {
    string w;
    cin >> w;

    if (i > 0) {
      if (st.count(w) or prev != w[0]) {
        cout << "No" << '\n';
        return 0;
      }
    }

    prev = w.back();
    st.emplace(w);
  }

  cout << "Yes" << '\n';
  return 0;
}