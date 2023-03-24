#include <iostream>
#include <vector>


int main() {
  long long n, k;
  std::cin >> n >> k;

  std::vector<long long> a(n);
  for (auto& ai : a) std::cin >> ai;

  long long ok = 0;
  long long ng = 1e12 + 1;
  while (abs(ok-ng) > 1) {
    long long mid = (ok+ng) / 2;
    long long eat = 0;
    for (auto ai : a) {
      eat += std::min(ai, mid);
    }
    if (eat <= k) ok = mid;
    else ng = mid;
  }

  for (auto& ai : a) {
    k -= std::min(ai, ok);
    ai = std::max(0ll, ai-ok);
  }
  for (auto& ai : a) {
    if (k <= 0) break;
    if (ai == 0) continue;
    --ai;
    --k;
  }

  for (auto ai : a) std::cout << ai << ' ';
  std::cout << '\n';
  return 0;
}