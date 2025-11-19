#include <vector>
#include <iostream>
using namespace std;

const long long K = 2e10;

class Solution {
public:
    int len;
    vector<long long> power;

    bool check(int r, long long k, long long min_power) {
        vector<long long> diff(len + 1, 0); // 差分数组，记录需要额外增加的电量
        long long current_power = 0; // 当前城市从左侧新增电站获得的电量
        for (int i = 0; i < len; ++i) {
            current_power += diff[i]; // 更新当前城市获得的额外电量
            if (power[i] + current_power < min_power) {
                long long needed = min_power - (power[i] + current_power);
                k -= needed;
                if (k < 0) {
                    return false;
                }
                current_power += needed;
                // 在 i+r 位置放电站，会影响到 i+2r 的城市
                if (i + 2 * r + 1 < len) {
                    diff[i + 2 * r + 1] -= needed;
                }
            }
        }
        return true;
    }
    void init(vector<int>& stations, int r) {
        len = stations.size();
        power.assign(len, 0);
        long long current_sum = 0;
        // 先计算第一个窗口的电量和
        for (int i = 0; i <= r && i < len; ++i) {
            current_sum += stations[i];
        }
        power[0] = current_sum;
        // 使用滑动窗口计算每个城市的初始电量
        for (int i = 1; i < len; ++i) {
            current_sum = power[i-1];
            if (i - r - 1 >= 0) {
                current_sum -= stations[i - r - 1];
            }
            if (i + r < len) {
                current_sum += stations[i + r];
            }
            power[i] = current_sum;
        }
    }
    long long maxPower(vector<int>& stations, int r, long long k) {
        init(stations, r);
        long long L = 0, R = K;
        while (L < R) {
            // cout << L << " " << R << endl;
            long long mid = (L + R + 1) >> 1;
            if (check(r, k, mid)) {
                L = mid;
            } else {
                R = mid - 1;
            }
        }
        return L;
    }
};

int main() {
    auto sol = Solution();
    vector<int> stations = {57,70,35,30,29,13,17,88,89,49};
    long long result = sol.maxPower(stations, 1, 90);
    cout << result << endl;
    return 0;
}