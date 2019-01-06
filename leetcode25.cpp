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

// 作弊法 直接改变节点值
// class Solution {
// public:
//     ListNode* reverseKGroup(ListNode* head, int k) {
//         ListNode *res = head;
//         while(true)
//         {
//             ListNode *tempHead = head;
//             vector<int> nums;
//             while(head != NULL && nums.size() < k)
//             {
//                 nums.push_back(head->val);
//                 head = head->next;
//             }
//             if(nums.size() < k) break;
//             for(int i = k-1;i >= 0;i--)
//             {
//                 tempHead->val = nums[i];
//                 tempHead = tempHead->next;
//             }
//             head = tempHead;
//         }
//         return res;
//     }
// };

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int size = 0;
        ListNode *tempHead = head;
        while(tempHead != NULL) size++, tempHead = tempHead->next;
        if(size < k) return head; // 与题目描述不符。。。
        int times = size/k;
        ListNode *res = NULL, *Next = NULL, *NextDouble = NULL, *tail = NULL;
        for(int i = 0;i < times;i++)
        {
            if(Next != NULL) head = Next;
            tempHead = head;
            Next = head->next;
            for(int j = 0;j < k-1;j++)
            {
                NextDouble = Next->next;
                Next->next = head;
                head = Next;
                Next = NextDouble;
            } // 最后结果head还是这个片段的新head Next则是NULL 或者下一个片段的head
            if(res == NULL) res = head;
            if(tail != NULL) tail->next = head; // 这个片段的头是上一个片段的尾
            tail = tempHead; // 每一次原来的head变成新的tail
        }
        tail->next = Next;
        return res;
    }
};