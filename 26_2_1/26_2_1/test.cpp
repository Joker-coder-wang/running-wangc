#include<set>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
 
class Solution {
public:
    ListNode* detectCycle(ListNode* head) {
        set<ListNode*> s;
        ListNode* cur = head;
        while (cur)
        {
            auto ret = s.insert(cur);
            if (ret.second == false)
                return cur;
            cur = cur->next;
        }
        return nullptr;
    }
};

int main()
{
    return 0;
}