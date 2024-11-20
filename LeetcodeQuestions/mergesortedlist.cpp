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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2){
        if (!list1)
            return list2;

        if (!list2)
            return list1;

        ListNode *head = nullptr, *tail = nullptr;
        if (list1->val <= list2->val){
            head = tail = list1;
            list1 = list1->next;
        }
        else{
            head = tail = list2;
            list2 = list2->next;
        }
        while (list1 && list2){
            if (list1->val <= list2->val){
                tail->next = list1;
                tail = list1;
                list1 = list1->next;
            }
            else{
                tail->next = list2;
                tail = list2;
                list2 = list2->next;
            }
        }
        tail->next = list1 ? list1 : list2;
        return head;
    }
};
int main(){
    Solution a;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(4);

    ListNode *head2 = new ListNode(1);
    head2->next = new ListNode(3);
    head2->next->next = new ListNode(4);
    ListNode *res = a.mergeTwoLists(head1, head2);
    printList(res);
}