#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        int pos = 0;
        if(head == NULL || head->next == NULL) return head;
        ListNode *res = head;
        while(true)
        {
            int a = head->val;
            int b = head->next->val;
            head->val = b;
            head->next->val = a;
            head = head->next->next;
            if(head == NULL || head->next == NULL) break;
        }
        return res;
    }
};