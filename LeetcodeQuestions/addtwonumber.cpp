#include <bits/stdc++.h>
using namespace std;

struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printList(ListNode *head){
    ListNode *current = head;
    while (current != nullptr){
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

class Solution{
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ListNode *res = new ListNode(), *temp = res;
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr){
            int s = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
            temp->val = s % 10;
            carry = s / 10;
            l1 = l1 ? l1->next : l1;
            l2 = l2 ? l2->next : l2;
            if (l1 || l2){
                temp->next = new ListNode();
                temp = temp->next;
            }
        }
        if (carry != 0){
            temp->next = new ListNode(carry);
        }
        return res;
    }
};
int main(){
    Solution a;
    ListNode *head1 = new ListNode(5);
    // head1->next = new ListNode(3);
    // head1->next->next = new ListNode(4);

    ListNode *head2 = new ListNode(5);
    // head2->next = new ListNode(5);
    // head2->next->next = new ListNode(6);
    // head2->next->next->next = new ListNode(9);
    // head2->next->next->next->next = new ListNode(8);
    ListNode *res = a.addTwoNumbers(head1, head2);
    printList(res);
}