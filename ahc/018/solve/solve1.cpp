// それぞれの家について、一つ目の水源まで最短距離でまっすぐに掘削を行う


#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


struct Pos {
  ll i, j;
  Pos(ll i=0, ll j=0) : i(i), j(j) {}
};


ll n, w, k, c;
vector<Pos> water;
vector<Pos> house;

vector<vector<bool>> broken;
ll power = 150;
ll cost = 0;


void init() {
  cin >> n >> w >> k >> c;
  broken = vector(n, vector<bool>(n, false));
  rep(i, w) {
    ll a, b;
    cin >> a >> b;
    water.emplace_back(a, b);
  }
  rep(i, k) {
    ll a, b;
    cin >> a >> b;
    house.emplace_back(a, b);
  }
}


void respond(ll i, ll j) {
  cost += power + c;
  cout << i << " " << j << " " << power << endl;
  ll r;
  cin >> r;
  if (r == -1) {
    cerr << "invalid: i=" << i << " j=" << j << endl;
    exit(1);
  }
  if (r == 2) {
    broken[i][j] = true;
    cerr << "total_cost=" << cost << endl;
    exit(0);
  }
  if (r == 1) {
    broken[i][j] = true;
  }
}


void destruct(ll i, ll j) {
  while (not broken[i][j]) {
    respond(i, j);
  }
}


void move(Pos start, Pos goal) {
  cout << "# move from (" << start.i << "," << start.j << ") to (" << goal.i << "," << goal.j << ")" << endl;

  // down/up
  if (start.i < goal.i) {
    for (int i = start.i; i < goal.i; i++) {
      destruct(i, start.j);
    }
  } else {
    for (int i = start.i; i > goal.i; i--) {
      destruct(i, start.j);
    }
  }

  // right/left
  if (start.j < goal.j) {
    for (int j = start.j; j <= goal.j; j++) {
      destruct(goal.i, j);
    }
  } else {
    for (int j = start.j; j >= goal.j; j--) {
      destruct(goal.i, j);
    }
  }
}


// それぞれの家について、一つ目の水源まで最短距離でまっすぐに掘削を行う
void solve() {
  for (auto h : house) {
    move(h, water[0]);
  }
}


int main() {
  init();
  solve();
  return 0;
}