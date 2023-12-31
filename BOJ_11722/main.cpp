#include <algorithm>
#include <bit>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <ranges>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

ll n;
vl A;
vl dp;

int main() {
  ios::sync_with_stdio(false);
  std::cin.tie(nullptr);

  cin >> n;

  A = vl(n);
  for (auto&& a : A) {
    cin >> a;
  }

  dp = vl(n, 1);
  auto ans = ll{1};
  for (auto i = 1; i < n; ++i) {
    for (auto j = 0; j < i; ++j) {
      if (A[i] < A[j]) {
        dp[i] = max(dp[i], dp[j] + 1);
        ans = max(ans, dp[i]);
      }
    }
  }

  cout << ans;

  return 0;
}