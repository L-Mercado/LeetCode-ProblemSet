// Leet Code Problem 83. Remove Duplicates From Sorted List | This program determines whether there exists duplicates of a node in a linked list, if found, it will delete the duplicate. Then it prints the results of the deletion.
//

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        ListNode* current = head;

        while (current != nullptr && current->next != nullptr) {
            if (current->val == current->next->val) {
                ListNode* duplicate = current->next;
                current->next = current->next->next;
                delete duplicate;
            }
            else {
                current = current->next;
            }
        }

        return head;
    }
};


ListNode* createList(int arr[], int size) {
    if (size == 0) return nullptr;

    ListNode* head = new ListNode(arr[0]);
    ListNode* current = head;

    for (int i = 1; i < size; i++) {
        current->next = new ListNode(arr[i]);
        current = current->next;
    }

    return head;
}

void printList(ListNode* head) {
    while (head != nullptr) {
        cout << head->val;
        if (head->next != nullptr) cout << " -> ";
        head = head->next;
    }
}



int main() {
    Solution sol;

    
    cout << "Example 1:" << endl;
    int array1[] = { 1, 2, 2, 3, 4, 5, 6 };
    int size1 = sizeof(array1) / sizeof(array1[0]);

    ListNode* list1 = createList(array1, size1);

    cout << "Input: ";
    printList(list1);
    cout << endl;

    list1 = sol.deleteDuplicates(list1);

    cout << "Output: ";
    printList(list1);
    cout << endl << endl;

   
    cout << "Example 2:" << endl;
    int array2[] = { 1, 2, 3, 4, 4, 5 };
    int size2 = sizeof(array2) / sizeof(array2[0]);

    ListNode* list2 = createList(array2, size2);

    cout << "Input: ";
    printList(list2);
    cout << endl;

    list2 = sol.deleteDuplicates(list2);

    cout << "Output: ";
    printList(list2);
    cout << endl;

   
    return 0;
}
