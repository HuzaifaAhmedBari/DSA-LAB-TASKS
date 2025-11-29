#include <iostream>
#include <string>
using namespace std;

struct Node {
    string data;
    Node* next;
    Node(string d) {
        data = d;
        next = NULL;
    }
};

class HashTable {
private:
    int buckets;
    Node** table;

public:
    HashTable(int b) {
        buckets = b;
        table = new Node*[buckets];
        for (int i = 0; i < buckets; i++)
            table[i] = NULL;
    }

    int hashFunction(string s) {
        int sum = 0;
        for (int i = 0; i < s.length(); i++) {
            sum += int(s[i]);
        }
        return sum % buckets;
    }

    void insert(string s) {
        int index = hashFunction(s);
        Node* newNode = new Node(s);

        newNode->next = table[index];
        table[index] = newNode;

        cout << "Inserted \"" << s << "\" at bucket " << index << endl;
    }

    bool search(string s) {
        int index = hashFunction(s);
        Node* curr = table[index];

        while (curr != NULL) {
            if (curr->data == s) return true;
            curr = curr->next;
        }

        return false;
    }

    void display() {
        cout << "\n--- HASH TABLE ---\n";
        for (int i = 0; i < buckets; i++) {
            cout << "Bucket " << i << ": ";
            Node* curr = table[i];
            while (curr != NULL) {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    int buckets;
    cout << "Enter number of buckets: ";
    cin >> buckets;

    HashTable ht(buckets);

    int n;
    cout << "How many strings do you want to insert? ";
    cin >> n;

    cout << "\nEnter strings:\n";
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        ht.insert(s);
    }

    ht.display();

    cout << "\nSearch a string: ";
    string key;
    cin >> key;

    if (ht.search(key))
        cout << "\"" << key << "\" found in hash table.\n";
    else
        cout << "\"" << key << "\" NOT found.\n";

    return 0;
}