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

// class Solution {
// public:
//     ListNode* mergeKLists(vector<ListNode*>& lists) {
//         ListNode *res = NULL;
//         ListNode *head = res;
//         while(true)
//         {
//             int small_pos = -1; // 最小的那一路对应的位置
//             int small = 0x3f3f3f3f;
//             for(int i = 0; i < lists.size(); i++)
//             {
//                 if(lists[i] == NULL) continue;
//                 if(lists[i]->val < small)
//                 {
//                     small = lists[i]->val;
//                     small_pos = i;
//                 }
//             }
//             if(small_pos == -1) break;
//             else {
//                 if(res == NULL) res = new ListNode(small), head = res;
//                 else {
//                     ListNode *temp = new ListNode(small);
//                     res->next = temp;
//                     res = res->next;
//                 }
//                 lists[small_pos] = lists[small_pos]->next;
//             }
//         }
//         return head;
//     }
// };


class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int size = lists.size();
        if(size == 0) return NULL;
        while(size > 1) 
        {
            for(int i = 0; i < size/2; i++)
            {
                lists[i] = mergeTwoLists(lists[i],lists[size-i-1]);
            }
            size = size / 2 + size % 2;
        }
        return lists[0];
    }

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