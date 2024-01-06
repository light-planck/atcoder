#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  string T;
  cin >> T;

  ll n = S.size();
  ll l = 0;
  char c = '.';
  rep(i, n) {
    if (S[i] != T[i]) {
      if (c == '.') {
        l = i;
        c = S[i];
        cout << S[i] << ' ';
      } else if (T[i] == c ) {
        cout << i - l << '\n';
        exit(0);
      }
    }
  }
}
