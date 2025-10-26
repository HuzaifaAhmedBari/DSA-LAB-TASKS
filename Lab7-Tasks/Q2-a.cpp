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
        void sort() {
            bool sorted = true;
            do
            {
                sorted = true;
                Node *cur = head;
                while(cur->next != nullptr)
                {
                    if(cur->val>cur->next->val)
                    {
                        swap(cur->val,cur->next->val);
                        sorted = false;
                    }
                    cur = cur->next;
                }

            }while(not sorted);
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
};
int main()
{
    int arr[] = {5,2,9,4,1};
    List list;
    for(int i=0;i<sizeof(arr)/sizeof(arr[0]);i++)
        list.append_right(arr[i]);
    list.print();
    list.sort();
    list.print();

    return 0;
}