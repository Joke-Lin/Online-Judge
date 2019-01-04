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
        if(l1 == NULL && l2 == NULL) return NULL;
        ListNode *temp = new ListNode(0);
        ListNode *head = temp;
        bool flag = true;
        while(true)
        {
            if(l1 == NULL && l2 == NULL) break;
            if((l1 == NULL && l2 != NULL) || (l1!= NULL && l2 != NULL && l1->val > l2->val))
            {
                if(!flag) {
                    ListNode *mid = new ListNode(l2->val);
                    temp->next = mid;
                    temp = mid;
                } else temp->val = l2->val;
                l2 = l2->next;
            }
            else if((l1 != NULL && l2 == NULL) || (l1!= NULL && l2 != NULL && l1->val <= l2->val))
            {
                if(!flag) {
                    ListNode *mid = new ListNode(l1->val);
                    temp->next = mid;
                    temp = mid;
                } else temp->val = l1->val;
                l1 = l1->next;
            }
            flag = false;
        }
        return head;
    }
};