#include <iostream>
#include <vector>
#include <string>
#include <set>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


struct Solver {
  ll d;
  vector<vector<string>> front;
  vector<vector<string>> right;

  ll silhouettes;
  ll n;
  vector<vector<ll>> b;
  set<ll> remain_block;

  Solver(ll d, vector<vector<string>> front, vector<vector<string>> right) 
    : d(d), front(front), right(right), silhouettes(2), n(0), b(silhouettes, vector<ll>(d*d*d)) {}

  void solve() {
    rep(i, silhouettes) {
      rep(x, d) {
        rep(y, d) {
          rep(z, d) {
            if (not can_place(i, x, y, z)) continue;

            // // 同じxにブロックが存在するか
            // bool exist_xblock = false;
            // rep(ny, d) {
            //   if (b[i][x*d*d + ny*d + z] > 0) exist_xblock = true;
            // }
            // // 存在するならxを変えて置けそうな場所に置く
            // rep(nx, d) {
            //   if (is_silhouettes(i, nx, y, z)) continue;
            //   if (b[i][x*d*d + y*d + z]) continue;
            //   ++n;
            //   b[i][nx*d*d + y*d + z] = n;
            //   remain_block.emplace(n);
            //   break;
            // }

            if (i == 1) {
              if (not remain_block.empty()) {
                b[i][x*d*d + y*d + z] = *remain_block.begin();
                remain_block.erase(*remain_block.begin());
              }
              else {
                place_block(i, x, y, z);
              }
            }
            else {
              place_block(i, x, y, z);
              remain_block.emplace(n);
            }
          }
        }
      }
    }

    print_answer();
  }

  bool can_place(ll i, ll x, ll y, ll z) {
    return is_silhouettes(i, x, y, z) and b[i][x*d*d + y*d + z] == 0;
  }

  bool is_silhouettes(ll i, ll x, ll y, ll z) {
    return front[i][z][x] == '1' and right[i][z][y] == '1';
  }

  void place_block(ll i, ll x, ll y, ll z) {
    ++n;
    b[i][x*d*d + y*d + z] = n;
  }

  void print_answer() {
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