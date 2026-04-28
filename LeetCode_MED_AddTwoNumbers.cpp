// Leet Code Problem 2. Add Two Numbers | This program prompts the user to input 2 numbers and it creates a linked list in reverse order for each number. Then, both numbers are added and the result is printed.
//

#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        while (l1 || l2 || carry) {
            int sum = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            carry = sum / 10;
            curr->next = new ListNode(sum % 10);
            curr = curr->next;
            if (l1) l1 = l1->next;
            if (l2) l2 = l2->next;
        }

        ListNode* result = dummy->next;
        delete dummy;
        return result;
    }
};

ListNode* createList(const string& num) {
    ListNode* head = nullptr;
    ListNode* tail = nullptr;

    for (int i = num.length() - 1; i >= 0; i--) {
        ListNode* node = new ListNode(num[i] - '0');
        if (!head) {
            head = tail = node;
        }
        else {
            tail->next = node;
            tail = node;
        }
    }
    return head ? head : new ListNode(0);
}

void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " | ";
        head = head->next;
    }
    cout << endl;
}

void deleteList(ListNode* head) {
    while (head) {
        ListNode* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Solution sol;
    string a, b;
    char cont;

    cout << "Add Two Numbers Medium Problem (Reverse Order)\n";

    do {
        cout << "\nInput Number 1: ";
        cin >> a;
        cout << "Input Number 2: ";
        cin >> b;

        ListNode* l1 = createList(a);
        ListNode* l2 = createList(b);

        cout << "Linked List 1: ";
        printList(l1);
        cout << "Linked List 2: ";
        printList(l2);

        ListNode* sum = sol.addTwoNumbers(l1, l2);

        cout << "Sum of Both Lists:    ";
        printList(sum);

        deleteList(l1);
        deleteList(l2);
        deleteList(sum);

        cout << "\nWould you like to do another sum? (y/n): ";
        cin >> cont;

    } while (cont == 'y' || cont == 'Y');

    return 0;
}

