#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        ListNode *t = new ListNode();
        ListNode *it = t;
        while (true) {
            int pos = -1;
            for (int i = 0; i < lists.size(); ++i) {
                if (lists[i] && (pos == -1 || lists[i]->val < lists[pos]->val)) {
                    pos = i;
                }
            }
            if (pos == -1) break;
            it->next = lists[pos];
            lists[pos] = lists[pos]->next;
            it = it->next;
        }
        return t->next;
    }
};