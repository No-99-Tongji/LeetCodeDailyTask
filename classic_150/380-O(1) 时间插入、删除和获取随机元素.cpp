#include <cstdlib>
#include <ctime>
#include <unordered_map>
#include <vector>
using namespace std;

class RandomizedSet {
public:
    unordered_map<int, int> indices;
    vector<int> nums;
    RandomizedSet() {
        srand((unsigned)time(NULL));
    }
    
    bool insert(int val) {
        if (indices.find(val) == indices.end()) {
            nums.push_back(val);
            indices[val] = nums.size() - 1;
            return true;
        }
        return false;
    }
    
    bool remove(int val) {
        auto it = indices.find(val);
        if (it == indices.end()) {
            return false;
        }

        int idx = it->second;
        int last = nums.back();
        nums[idx] = last;
        indices[last] = idx;
        nums.pop_back();
        indices.erase(it);
        return true;
    }
    
    int getRandom() {
        return nums[(unsigned int)rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */