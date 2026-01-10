/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    ListNode* getCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return NULL;
        }
        ListNode* slow = head;
        ListNode* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                return slow;  // Cycle detected
            }
        }
        return NULL;  // No cycle
    }

    ListNode* findStartingPoint(ListNode* head) {
        ListNode* intersection = getCycle(head);
        if (intersection == NULL) {
            return NULL;  // No cycle
        }

        ListNode* slow = head;
        while (slow != intersection) {
            slow = slow->next;
            intersection = intersection->next;
        }
        return slow;  // Start of the cycle
    }

public:
    ListNode *detectCycle(ListNode *head) {
        return findStartingPoint(head);
    }
};
