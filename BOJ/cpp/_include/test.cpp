#include <problem.h>
#include <test.h>

#ifdef _test_

#include <cstdio>
#include <algorithm>
using namespace std;

int d, n, m, a[50005];

int main() {
	scanf_s("%d %d %d", &d, &n, &m);
	for (int i = 1; i <= n; i++) scanf_s("%d", &a[i]);
	a[n + 1] = d;

	sort(a + 1, a + n + 1);

	int lft = 0, rgt = d, ans;
	while (lft <= rgt) {
		int mid = (lft + rgt) / 2;
		int pos = 0, cnt = 0;
		for (int i = 1; i <= n + 1; i++) {
			if (a[i] - a[pos] < mid) cnt++;
			else pos = i;
		}
		if (cnt > m) rgt = mid - 1;
		else lft = mid + 1, ans = mid;
	}

	printf("%d", ans);

	return 0;
}
#endif
