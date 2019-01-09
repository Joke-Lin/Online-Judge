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

/* *
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
  public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2)
    {
        ListNode *res = NULL;
        ListNode *head = NULL;
        while(true)
        {
            int pos = 0; // 取l1 还是 l2
            int small = 0x3f3f3f3f;
            if(l1 != NULL && l1->val < small) small = l1->val, pos = 1;
            if(l2 != NULL && l2->val < small) small = l2->val, pos = 2;
            if(pos == 0) break;
            else  {
                if(res == NULL) res = new ListNode(small), head = res;
                else {
                    ListNode *temp = new ListNode(small);
                    res->next = temp;
                    res = res->next;
                }
                if(pos == 1) l1 = l1->next;
                else l2 = l2->next;
            }
        }
        return head;
    }
};