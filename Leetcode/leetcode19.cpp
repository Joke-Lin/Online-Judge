#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int times = 0;
        ListNode* temp = head;
        while(temp != NULL && times < n-1)
        {
            temp = temp->next;
            times++;
        }
        if(times < n-1) return head;
        ListNode *front = head, *end = temp, *mid = head;
        bool flag = true;
        while(end->next != NULL)
        {
            if(!flag) front = front->next;
            mid = mid->next;
            end = end->next;
            flag = false;
        }
        if(flag) // 被删的是头节点
        {
            ListNode *newHead = front->next;
            delete head;
            return newHead;
        }
        else {
            front->next = mid->next;
            delete mid; // 删除delete速度更快 但是。。。
            return head;
        }
    }
};