#include <iostream>
#include <vector>
#include <string>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


struct Solver {
  ll silhouettes;
  ll d;
  vector<vector<string>> front;
  vector<vector<string>> right;

  Solver(ll d, vector<vector<string>> front, vector<vector<string>> right) 
    : silhouettes(2), d(d), front(front), right(right) {}

  void solve() {
    ll n = 0;
    vector b(silhouettes, vector<ll>(d*d*d));

    rep(i, silhouettes) {
      rep(x, d) {
        rep(y, d) {
          rep(z, d) {
            if (front[i][z][x] == '1' and right[i][z][y] == '1') {
              ++n;
              b[i][x*d*d + y*d + z] = n;
            }
          }
        }
      }
    }

    cout << n << '\n';
    rep(i, silhouettes) {
      for (auto c : b[i]) cout << c << " ";
      cout << '\n';
    }
  }
};


int main() {
  ll d;
  cin >> d;

  ll silhouettes = 2;
  vector front(silhouettes, vector<string>(d));
  vector right(silhouettes, vector<string>(d));

  rep(i, silhouettes) {
    rep(j, d) {
      cin >> front[i][j];
    }
    rep(j, d) {
      cin >> right[i][j];
    }
  }

  Solver solver(d, front, right);
  solver.solve();
  return 0;
}