#include<bits/stdc++.h>
using namespace std;
int main()
{
    srand(time(0));
    int choice = (rand() % 100) + 1;
    int x;
    cin >> x;
    function<void()> guess = [&] () {
        if(x == choice) {
            cout << "Correct Guess";
            cout << endl;
            return;
        }
        if(x > choice) {
            cout << "Too High" << endl;
        } else {
            cout << "Too Low!!" << endl;
        }
        cin >> x;
        guess();
    };
    guess();
}
