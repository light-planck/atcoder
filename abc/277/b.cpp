#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll n;
  cin >> n;

  set<string> st;
  set<char> chars1 = {'H', 'D', 'C', 'S'};
  set<char> chars2 = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

  rep(i, n) {
    string s;
    cin >> s;

    bool ok = true;
    if (st.count(s)) ok = false;
    if (not chars1.count(s[0])) ok = false;
    if (not chars2.count(s[1])) ok = false;

    if (not ok) {
      cout << "No" << '\n';
      return 0;
    }

    st.emplace(s);
  }

  cout << "Yes" << '\n';
  return 0;
}