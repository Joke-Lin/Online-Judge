#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *tar = head, *cur = head, *temp = head;
        int len = 0;
        while(temp != NULL) len++,temp = temp->next;
        if(len == 0) return head;
        k = k % len;
        if(k == 0) return head;
        int num = 0;
        while(true && k != 0) {
            if(cur->next == NULL) break;
            if(++num > k) {
                tar = tar->next;
            }
            cur = cur->next;
        }
        ListNode *st1 = head, *end1 = tar, *st2 = tar->next, *end2 = cur;
        end2->next = st1;
        end1->next = NULL;
        return st2;
    }
};