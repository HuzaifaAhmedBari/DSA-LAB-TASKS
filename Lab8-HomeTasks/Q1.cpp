#include<iostream>
using namespace std;
const int MAX = 100000;
class Stack {
    private:
        int top;
    public:
        char a[MAX];
        Stack() : top(-1) {}
        bool push(char c);
        char pop();
        bool isempty();
};
bool Stack::push(char c) {
    if(top>=(MAX-1))
        return false;
    a[++top] = c;
    return true;
}
char Stack::pop() {
    if(top<0)
        return '-';
    return a[top--];
}
bool Stack::isempty() {
    return top<0;
}
int main()
{
    string s = "BORROWROB";
    Stack st;
    for(int i=0;i<s.size();i++)
    {
        st.push(s[i]);
    }
    string temp;
    while(!st.isempty())
    {
        temp += st.pop();
    }
    if(s==temp)
    {
        cout << "The String is A Palindrome" << endl;
    }
    else
    {
        cout << "The String is Not A Palindrome" << endl;
    }

    return 0;
}
