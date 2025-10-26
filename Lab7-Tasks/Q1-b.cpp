#include <iostream>
using namespace std;
struct Node {
    int val;
    Node *next, *prev;
    Node() : val(0), next(nullptr), prev(nullptr) {}
    Node(int val) : val(val), next(nullptr), prev(nullptr) {}
    Node(int val, Node *next, Node *prev) : val(val), next(next), prev(nullptr) {}
};
class List {
    private:
        Node *head, *tail;
    public:
        List() : head(nullptr), tail(nullptr) {}
        void append_right(int x) {
            if(not head)
            {
                head = new Node(x);
                tail = head;
                return;
            }
            Node *cur = head;
            while(cur->next!=nullptr)
            {
                cur = cur->next;
            }
            cur->next = new Node(x);
            tail = cur->next;
            tail->prev = cur;
        }
        void append_left(int x) {
            Node *cur = new Node(x);
            cur->next = head;
            head->prev = cur;
            head = cur;
        }
        void print() {
            Node *cur = head;
            cout << "\nLinked List\n";
            while(cur!=nullptr)
            {
                cout << cur->val << ((cur->next!=nullptr)? " <-> " : "");
                cur = cur->next;
            }
        }
        void reverse(Node *cur, Node *before) {
            if(cur==nullptr)
                return;
            reverse(cur->next, cur);
            cur->prev = cur->next;
            cur->next = before;
        }
        void reverse() {
            reverse(head, nullptr);
            Node *cur = head;
            head = tail;
            tail = head;
        }
};
int main()
{
    List list;
    int arr[] = {1,2,3,4,5};
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        list.append_right(arr[i]);
    list.print();
    list.reverse();
    list.print();

    return 0;
}