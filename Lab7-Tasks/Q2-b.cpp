#include <iostream>
using namespace std;
struct Node {
    int val;
    Node *next;
    Node() : val(0), next(nullptr) {}
    Node(int val) : val(val), next(nullptr) {}
    Node(int val, Node *next) : val(val), next(next) {}
};
class List {
    private:
        Node *head;
    public:
        List() : head(nullptr) {}
        List(List &list) {
            Node *cur = list.head;
            while(cur!=nullptr)
                this->append_right(cur->val);
        }
        void append_right(int x) {
            if(not head)
            {
                head = new Node(x);
                return;
            }
            Node *cur = head;
            while(cur->next!=nullptr)
            {
                cur = cur->next;
            }
            cur->next = new Node(x);
        }
        void append_left(int x) {
            Node *cur = new Node(x);
            cur->next = head;
            head = cur;
        }
        void remove(int x) {
            Node *cur = head, *prev = nullptr;
            if(head!=nullptr and head->val==x) {
                prev = head;
                head = head->next;
                delete prev;
                return;
            }
            while(cur!=nullptr and cur->val!=x)
            {
                prev = cur;
                cur = cur->next;
            }
            if(cur!=nullptr)
            {
                prev->next = cur->next;
                delete cur;
            }
        }
        void insert_at_index(int pos, int val) {
            int idx = 0;
            Node *cur = head, *prev = nullptr;
            if(pos==0)
            {
                append_left(val);
                return;
            }
            while(cur!=nullptr and idx!=pos)
            {
                prev = cur;
                cur = cur->next;
                idx++;
            }
            if(idx==pos)
            {
                if(cur->next==nullptr)
                {
                    append_right(val);
                }
                else
                {
                    Node *temp = new Node(val);
                    prev->next = temp;
                    temp->next = cur;
                }
            }
        }
        void print() {
            Node *cur = head;
            cout << "\nLinked List\n";
            while(cur!=nullptr)
            {
                cout << cur->val << ((cur->next!=nullptr)? " -> " : "");
                cur = cur->next;
            }
        }
        friend void insertAlternate(List &list1, List &list2);
        ~List() {
            Node *cur = head, *prev = nullptr;
            while(cur!=nullptr)
            {
                prev = cur;
                cur = cur->next;
                delete prev;
            }
            head = nullptr;
        }
};

void insertAlternate(List &list1, List &list2) {
    Node* curr1 = list1.head, *curr2 = list2.head;
    while (curr1!=nullptr && curr2!=nullptr) {
        Node* temp1 = curr1->next;
        Node* temp2 = curr2->next;
        curr1->next = curr2;
        curr2->next = temp1;
        curr1 = temp1;
        curr2 = temp2;
    }
    list2.head = curr2;
}

int main() {
    List list1, list2;
    int arr1[] = {1,2,3};
    int arr2[] = {4,5,6,7,8};
    for(int i=0;i<sizeof(arr1)/sizeof(arr1[0]);i++)
        list1.append_right(arr1[i]);
    for(int i=0;i<sizeof(arr2)/sizeof(arr2[0]);i++)
        list2.append_right(arr2[i]);

    cout << "Before";
    list1.print();
    list2.print();

    insertAlternate(list1, list2);

    cout << "\n\nAfter";
    list1.print();
    list2.print();
}