/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        vector<int> arr;
        ListNode* temp = head;
        while (temp != NULL) {
            arr.push_back(temp->val);
            temp = temp->next;
        }

        bool last = true;
        while (last) {
            int s, e;
            bool found = false;
            for (int i = 0; i < arr.size() && !found; i++) {
                int curSum = 0;
                for (int j = i; j < arr.size(); j++) {
                    curSum += arr[j];
                    if (curSum == 0) {
                        s = i;
                        e = j;
                        found = true;
                        break;
                    }
                }
            }
            if (found) {
                int temp = s;
                for (int k = e + 1; k < arr.size(); k++) {
                    arr[temp] = arr[k];
                    temp++;
                }
                while (s <= e) {
                    arr.pop_back();
                    s++;
                }
                last = true;
            } else
                last = false;
        }

        if (arr.size() == 0)
            return NULL;

        ListNode* newHead = new ListNode(arr[0]);
        temp = newHead;
        for (int i = 1; i < arr.size(); i++) {
            temp->next = new ListNode(arr[i]);
            temp = temp->next;
        }
        return newHead;
    }
};
