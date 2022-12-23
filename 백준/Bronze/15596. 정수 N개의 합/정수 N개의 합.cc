#include <vector>
long long sum(std::vector<int> &a) {
	long long ans = 0;
    for (int now : a) {
        ans+=now;
    }
	return ans;
}
