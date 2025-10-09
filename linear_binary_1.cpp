#include <bits/stdc++.h>
using namespace std;
struct C {
    string n, p, e;
};
int Linearsearch(C a[], int n, string x) {
    int l = 0, h = n - 1, m;
    bool f = false;
    while (l <= h) {
        m = (l + h) / 2;
        if (a[m].p == x) {
            f = true;
            return m;
            break;
        }
        else if (a[m].p < x) {
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }
    if (!f) {
        return -1;
    }
}
int main() {
    C a[5];
    cout << "Enter details for 5 users" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Name:";
        cin >> a[i].n;
        cout << "Phone Number:";
        cin >> a[i].p;
        cout << "Email Address:";
        cin >> a[i].e;
        cout << "-------------" << endl;
    }
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (a[j].p > a[j + 1].p) {
                C tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }
    string num;
    cout << "Enter number to search: ";
    cin >> num;
    int k = Linearsearch(a, 5, num);
    if (k != -1) {
        cout << "Found!" << endl;
        cout << "-------------" << endl;
        cout << "Details:" << endl;
        cout << "Name:" << a[k].n << endl;
        cout << "Phone Number:" << a[k].p << endl;
        cout << "Email Address:" << a[k].e << endl;
    }
    else {
        cout << "Sorry!! Not found" << endl;
    }
}

//binary search
#include <bits/stdc++.h>
using namespace std;

struct C {
    string n, p, e;
};

int Binarysearch(C a[], int n, string x) {
    int l = 0, h = n - 1;
    while (l <= h) {
        int m = l + (h - l) / 2;
        if (a[m].p == x) {
            return m;
        }
        else if (a[m].p < x) {
            l = m + 1;
        }
        else {
            h = m - 1;
        }
    }
    return -1;
}

int main() {
    C a[5];
    cout << "Enter details for 5 users" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Name:";
        cin >> a[i].n;
        cout << "Phone Number:";
        cin >> a[i].p;
        cout << "Email Address:";
        cin >> a[i].e;
        cout << "-------------" << endl;
    }

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4 - i; j++) {
            if (a[j].p > a[j + 1].p) {
                C tmp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = tmp;
            }
        }
    }

    string num;
    cout << "Enter number to search: ";
    cin >> num;

    int k = Binarysearch(a, 5, num);
    if (k != -1) {
        cout << "Found!" << endl;
        cout << "-------------" << endl;
        cout << "Details:" << endl;
        cout << "Name:" << a[k].n << endl;
        cout << "Phone Number:" << a[k].p << endl;
        cout << "Email Address:" << a[k].e << endl;
    }
    else {
        cout << "Sorry!! Not found" << endl;
    }

    return 0;
}
