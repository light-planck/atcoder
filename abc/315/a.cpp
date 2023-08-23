#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  set<char> aeiou = {'a', 'e', 'i', 'o', 'u'};

  for (auto c : S) {
    if (!aeiou.count(c)) cout << c;
  }
  cout << '\n';
}
