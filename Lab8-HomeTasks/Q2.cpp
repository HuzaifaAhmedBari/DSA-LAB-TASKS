#include<bits/stdc++.h>
using namespace std;
class Transaction {
    private:
        string desc;
        int id, flag;
        double amt;
        static int counter;
    public:
        Transaction() : desc("Unkown"), id(++counter), amt(0), flag(-1) {}
        Transaction(string desc, double amt) : desc(desc), id(++counter), amt(amt) {
            flag = ((amt>=0)? 1 : 0);
            if(amt>=1500)
            {
                amt -= ((double(amt))*(double(30)/double(100)));
            }
            else if(amt>=1000)
            {
                amt -= ((double(amt))*(double(15)/double(100)));
            }
            else if(amt>=500)
            {
                amt -= ((double(amt))*(double(5)/double(100)));
            }
        }
        void display() {
            cout << "ID = " << id << " , amt = " << amt << " , desc = " << desc << " , flag = " << flag << endl;
        }
        friend class Stack;
};
struct Node {
    Transaction t;
    Node *next;
    Node(Transaction &obj) {
        t = obj;
        next = nullptr;
    }
};
class Stack {
    private:
        Node *top;
    public:
        Stack() : top(nullptr) {}
        void push(Transaction &obj) {
            Node *newNode = new Node(obj);
            newNode->next = top;
            top = newNode;
        }
        void remove() {
            if(top == nullptr)
                return;
            top->t.desc += " [REVERSED]";
            top->t.flag = 2;
            cout << "Amount of Changed from " << top->t.amt << " to " << (-1*top->t.amt) << endl;
            top->t.display();
            cout<<endl;
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        void pop() {
            if(top == nullptr)
                return;
            top->t.display();
            Node* temp = top;
            top = top->next;
            delete temp;
        }
        bool isempty() {
            return top==nullptr;
        }
};
int Transaction::counter = 0;
int main()
{
    srand(time(0));
    Transaction t1("Blue Jacket", 1200.f), t2("Cotton Socks", 450.f), t3("Leather Jacket", 1700.f), t4("Defective Shirt", -300.f);
    Transaction arr[4] = {t1, t2, t3, t4};
    Stack st;
    st.push(t1);
    st.push(t2);
    st.push(t3);
    st.push(t4);
    st.remove();
    cout << "TOP" << endl;
    while(!st.isempty())
    {
        st.pop();
        cout<<endl;
    }
    cout << "BOTTOM" << endl;

}
