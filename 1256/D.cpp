#include<cstdio>
#include<cmath>
#include<cstdlib>

int main() {
	int k = 0, n = 0, q = 0;
	scanf("%d", &q);
	for (int p = 0; p < q; ++p) {
		scanf("%d %d\n", &n, &k);
		char *arr = (char *)calloc(n + 1, sizeof(char));
		scanf("%s", arr);
		int i = -1, j = -1;
		while (k > 0) {
			for (++i; i < n; ++i)
				if (arr[i] == '0')
					break;
			if (i == n) break;
			if (i - j > k) {
				arr[i] = '1';
				arr[i - k] = '0';
				k = 0;
			}
			else {
				arr[i] = '1';
				arr[j + 1] = '0';
				k -= i - j - 1;
				++j;
			}
		}
		printf("%s\n", arr);
	}
	//system("pause");
}
