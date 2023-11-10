#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;

  string S;
  cin >> S;

  rep(i, N - 1) {
    if ((S[i] == 'a' and S[i + 1] == 'b') or
        (S[i] == 'b' and S[i + 1] == 'a')) {
      cout << "Yes" << '\n';
      return 0;
    }
  }

  cout << "No" << '\n';
}
