#include <vector>
#include <iostream>

int helper(std::vector<int> memo, int n) {
	if (memo[n] != -1) {
		return memo[n];
	}
	memo[n] = helper(memo, n - 1) + helper(memo, n - 2);
	return memo[n];
}

int fib(int n) {
	if (n < 1) { return 0; }
	std::vector<int> memo(n + 1, -1);
	memo[0] = 0;
	memo[1] = 1; 
	memo[2] = 1;
	return helper(memo, n);
}

int fib2(int n) {
	std::vector<int> memo(n + 1, -1);
	memo[0] = 0;
	memo[1] = 1;
	memo[2] = 1;
	if (n <= 2) {
		return memo[n];
	}
	for (int i = 2; i <= n; i++) {
		memo[i] = memo[i - 1] + memo[i - 2];
	}
	return memo[n];
}


void main() {
	std::cout << fib(20) << std::endl;
	std::cout << fib2(20) << std::endl;
}