#include <iostream>
using namespace std;
struct Student {
    int roll;
    string name;
    Student() {}
    Student(int roll, string name) : roll(roll), name(name) {}
    void display() {
        cout << "Name : " << name << "  Roll No : " << roll;
    }
};
struct Node {
    Student std;
    Node *next;
    Node() : next(nullptr) {}
    Node(Student std) : std(std), next(nullptr) {}
    Node(int roll, string name) : std(Student(roll,name)),  next(nullptr) {}
    Node(Student std, Node *next) : std(std), next(next) {}
};
class List {
    private:
        Node *head;
    public:
        List() : head(nullptr) {}
        void append_right(Student x) {
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
        void append_left(Student x) {
            Node *cur = new Node(x);
            cur->next = head;
            head = cur;
        }
        void insert_at_index(int pos, Student val) {
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
        void remove(int pos) {
            Node *cur = head, *prev = nullptr;
            int val = 1;
            if(pos==1)
            {
                head = head->next;
                delete cur;
                return;
            }
            while(cur!=nullptr and val!=pos)
            {
                prev = cur;
                cur = cur->next;
                val++;
            }
            if(cur!=nullptr)
            {
                prev->next = cur->next;
                delete cur;
            }
        }
        void remove_from_start() {
            remove(1);
        }
        void remove_from_end() {
            int val = 1;
            Node *cur = head;
            while(cur->next!=nullptr)
            {
                cur = cur->next;
                val++;
            }
            remove(val);
        }
        void print() {
            Node *cur = head;
            cout << "\nLinked List\n";
            while(cur!=nullptr)
            {
                cur->std.display();
                cout << ((cur->next!=nullptr)? " -> " : "");
                cur = cur->next;
            }
            cout << endl;
        }
};
int main()
{
    List list;
    list.append_right(Student(847, "Huzaifa"));
    list.append_right(Student(1012, "Saad"));
    list.append_right(Student(419, "Bilal"));

    list.print();
    list.remove_from_start();
    list.print();

    return 0;
}