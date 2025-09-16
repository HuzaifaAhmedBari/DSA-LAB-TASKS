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
        int length() {
            return measure(head, 0);
        }
        int measure(Node *cur, int count) {
            if(cur==nullptr)
                return count;
            count++;
            return measure(cur->next, count);
        }
};
int main()
{
    int arr[] = {1,2,3,4,5,6};
    int n = sizeof(arr)/sizeof(arr[0]);
    List list;
    for(int i=0;i<n;i++) {
        list.append_left(arr[i]);
    }
    list.print();
    cout << "\n\nLength of Linked List : " << list.length() << endl;
}
