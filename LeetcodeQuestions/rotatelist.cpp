#include <bits/stdc++.h>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution{
public:
    int length(ListNode *head){
        ListNode *temp = head;
        int c = 0;
        while (temp){
            temp = temp->next;
            c++;
        }
        return c;
    }
    ListNode *rotateRight(ListNode *head, int k){
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        ListNode *temp = head, *trannv;
        int l = length(head);
        if(l==0)return head;
        k = k % l;
        if(k==0) return head;
        int c = l - k;
        if (c == 0)
            return head->next;
        for (int i = 1; i < c; i++){
            temp = temp->next;
        }
        trannv = head;
        head = temp->next;
        temp->next = nullptr;
        temp = head;
        while (temp->next){
            temp = temp->next;
        }
        temp->next = trannv;
        return head;
    }
};
void printList(ListNode *head){
    ListNode *current = head;
    while (current != nullptr){
        std::cout << current->val << " ";
        current = current->next;
    }
    std::cout << std::endl;
}
int main(){
    Solution a;
    ListNode *head1 = new ListNode(1);
    head1->next = new ListNode(2);
    head1->next->next = new ListNode(3);
    head1->next->next->next = new ListNode(4);
    head1->next->next->next->next = new ListNode(5);
    printList(a.rotateRight(head1, 0));
}