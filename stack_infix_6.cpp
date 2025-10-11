#include <bits/stdc++.h>
using namespace std;
char st[100];
int top = -1;
void push(char c) {
    st[++top] = c;
}
char pop() {
    return st[top--];
}
int prec(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return -1;
}

bool right(char c) {
    return (c == '^');
}
string Postfix(string exp) {
    string result = "";
    top = -1; 
    for (int i = 0; i < (int)exp.length(); i++) {
        char c = exp[i];
        if (isalnum(c)) {
            result += c;
        }
        else if (c == '(') {
            push(c);
        }
        else if (c == ')') {
            while (top != -1 && st[top] != '(') {
                result += pop();
            }
            if (top != -1) pop();
        }
        else {
            while (top != -1 && 
                  ((prec(st[top]) > prec(c)) || 
                  (prec(st[top]) == prec(c) && !right(c))) &&
                   st[top] != '(') {
                result += pop();
            }
            push(c);
        }
    }
    while (top != -1) {
        result += pop();
    }
    return result;
}
string Prefix(string exp) {
    int n = exp.length();
    for (int i = 0; i < n / 2; i++) {
        char temp = exp[i];
        exp[i] = exp[n - i - 1];
        exp[n - i - 1] = temp;
    }
    for (int i = 0; i < n; i++) {
        if (exp[i] == '(') exp[i] = ')';
        else if (exp[i] == ')') exp[i] = '(';
    }
    string postfix = Postfix(exp);
    int m = postfix.length();
    for (int i = 0; i < m / 2; i++) {
        char temp = postfix[i];
        postfix[i] = postfix[m - i - 1];
        postfix[m - i - 1] = temp;
    }
    return postfix;
}
int main() {
    string exp;
    cout << "Enter Infix Expression: ";
    cin >> exp;
    string post = Postfix(exp);
    string pre = Prefix(exp);
    cout << "Postfix: " << post << endl;
    cout << "Prefix: " << pre << endl;
    return 0;
}
