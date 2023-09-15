#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;

  map<string, ll> rating = {{"tourist", 3858},   {"ksun48", 3679},
                            {"Benq", 3658},      {"Um_nik", 3648},
                            {"apiad", 3638},     {"Stonefeang", 3630},
                            {"ecnerwala", 3613}, {"mnbvmar", 3555},
                            {"newbiedmy", 3516}, {"semiexp", 3481}};

  cout << rating[S] << '\n';
}
