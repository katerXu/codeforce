#include<cstdio>
#include<cmath>
#include<cstdlib>

int main() {
	long long a = 0, b = 2, sqrta;
	bool flag = false;
	scanf("%lld", &a);
	sqrta = sqrt(a) + 1;
	for (b = 2; b < sqrta; ++b)
		if (a%b == 0){
			flag = true;
			break;
		}
	while (flag) {
		if (a == b) {
			flag = false;
			break;
		}
		else if (a%b == 0)
			a /= b;
		else break;
	}
	printf("%lld\n", flag ? 1 : a);
	//system("pause");
}