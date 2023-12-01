#include <bits/stdc++.h>
using namespace std;

vector<string> infix_exp;
vector<string> postfix_exp;
vector<string> operands;
vector<string> operators;

bool all_interger(){
    for (auto x : operands){
        if(x.find('.') != string::npos){
            return false;
        }
    }
    return true;
}

bool no_division(){
    for(auto x : operators){
        //cout << x << " ";
        if(x == "/") return false;
    }
    return true;
}
void split(string a){
    int idx = 0;
    int pos = 0;
    string temp;
    while(a[idx] == '(' || a[idx] == ')' || a[idx] == '+' || a[idx] == '-' || a[idx] == '*' || a[idx] == '/'){
        infix_exp.push_back(a.substr(idx, 1));
        ++idx;
    }
    pos = idx;
    while(idx < a.length()) {
        if (a[idx] == '(' || a[idx] == ')' || a[idx] == '+' || a[idx] == '-' || a[idx] == '*' || a[idx] == '/') {
            if(idx - pos >= 1){
                infix_exp.push_back(a.substr(pos, idx - pos));
                pos = idx + 1;
            } else pos = idx + 1;
            temp = a.substr(idx, 1);
            infix_exp.push_back(temp);
        }
        ++idx;
    }
    //cout << a.length() << " " << pos << endl;
    if(pos < a.length()){
        temp = a.substr(pos, a.length()-pos);
        infix_exp.push_back(temp);
    }
    //for(auto x : infix_exp) cout << x << " ";
}
int prior(string a){
    if(a == "*" || a == "/") return 2;
    else if(a == "+" || a == "-") return 1;
    return 0;
}
void convert(string a){
    stack<string> s;

    for(auto x : infix_exp){
//        cout << x << endl;
        if(x == "("){
            s.push(x);
        } else if (x == ")"){
            while(!s.empty() && s.top() != "("){
                postfix_exp.push_back(s.top());
                s.pop();
            }
            s.pop();
        } else if (x == "+" || x == "-" || x == "*" || x == "/"){
            operators.push_back(x);
            while(!s.empty() && prior(s.top()) > prior(x)){
                postfix_exp.push_back(s.top());
                s.pop();
            }
            s.push(x);
        } else {
            operands.push_back(x);
            postfix_exp.push_back(x);
        }
    }
// (2*3+7/8)*(5-1)
    while(!s.empty()){
        postfix_exp.push_back(s.top()); s.pop();
    }
    //for(auto x : postfix_exp) cout << x << " ";
}
void calculator(){
    stack<double> st;
    bool dot = false;
    for(auto x : postfix_exp){
        if ( !st.empty() && (x == "+" || x == "-" || x == "*" || x == "/")){
            double b = st.top(); st.pop();
            double a = st.top(); st.pop();
            double tmp;

            if(x == "+") tmp = a + b;
            else if (x == "-") tmp = a - b;
            else if (x == "*") tmp = a * b;
            else tmp = a / b;
            st.push(tmp);

            if(tmp != (int)tmp) dot = true;
        } else {
            st.push(stod(x));
        }
    }
    double ans = st.top();

//    cout << "all_dot: " << all_interger() << endl;
//    cout << "dot: " << dot << endl;
//
//    cout << "no_division: " << no_division() << endl;

    if(!all_interger()) dot = true;
    if(dot) cout << fixed << setprecision(1) << ans << endl;
    else cout << (int)ans << endl;
}
int main(){
    string a;
    cin >> a;
    split(a);
    convert(a);
    calculator();
}

/*****************************************************************************************/
