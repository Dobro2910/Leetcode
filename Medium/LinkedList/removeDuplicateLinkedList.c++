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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* currentNode = head;
        ListNode* previousNode = nullptr;   // nullptr in C++, not null
        std::map<int, int> numberMap;            // lowercase 'set' and std::

        while (currentNode != nullptr) {
            if (numberMap.find(currentNode->val) != numberMap.end()) { // check if key exists
                ++numberMap[currentNode->val];  // increment count
            } else {
                numberMap[currentNode->val] = 1; // insert new key with count 1
            }
            currentNode = currentNode->next; // move to next node
        }

        ListNode* newHead = nullptr;
        currentNode = head;

        while (currentNode != nullptr) {
            if (numberMap[currentNode->val] > 1) { // check if exists
                if (currentNode->next == nullptr && newHead == nullptr) {
                    return newHead;
                } else if (currentNode->next == nullptr) {
                    previousNode->next = nullptr;
                }
                currentNode = currentNode->next;
            } else {
                if (previousNode == nullptr) {
                    previousNode = currentNode;
                    newHead = previousNode;
                } else {
                    previousNode->next = currentNode;
                    previousNode = currentNode;
                }
                currentNode = currentNode->next;
            }
        }

        return newHead;
    }
};