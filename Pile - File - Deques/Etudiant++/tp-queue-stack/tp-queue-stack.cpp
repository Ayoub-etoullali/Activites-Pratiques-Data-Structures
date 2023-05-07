#include <bits\stdc++.h>
using namespace std;

stack<int> stack_copy(stack<int> s)
{
    return s;
}

stack<int> stack_reverse_conserver(stack<int> s)
{
    queue<int> q;
    stack<int> s2;
    while (s.size())
    {
        q.push(s.top());
        s.pop();
    }
    while (q.size())
    {
        s.push(q.front());
        s2.push(q.front());
        q.pop();
    }
    return s2;
}
stack<int> stack_reverse(stack<int> *s)
{
    queue<int> q;
    stack<int> s2;
    while (s->size())
    {
        q.push(s->top());
        s->pop();
    }
    while (q.size())
    {
        s->push(q.front());
        s2.push(q.front());
        q.pop();
    }
    return s2;
}

stack<int> stack_copy_c_version(stack<int> s)
{
    stack<int> s2, temp;
    while (s.size())
    {
        temp.push(s.top());
        s.pop();
    }
    while (temp.size())
    {
        s.push(temp.top());
        s2.push(temp.top());
        temp.pop();
    }
    return s2;
}
void stack_circperm(stack<int> *s, int n)
{
    int k = 0;
    stack<int> temp_stack1, temp_stack2;
    while (k++ != n)
    {
        temp_stack2.push(s->top());
        s->pop();
    }
    while (s->size())
    {
        temp_stack1.push(s->top());
        s->pop();
    }
    k = 0;
    while (temp_stack2.size())
    {
        s->push(temp_stack2.top());
        temp_stack2.pop();
    }
    while (temp_stack1.size())
    {
        s->push(temp_stack1.top());
        temp_stack1.pop();
    }
}
void stack_circperm2(stack<int> *s, int k)
{

    stack<int> temp;
    int x = s->top();
    s->pop();
    int m = 1;
    while (m++ != k)
    {
        temp.push(s->top());
        s->pop();
    }
    s->push(x);
    while (temp.size())
    {
        s->push(temp.top());
        temp.pop();
    }
}

bool check_parenthese(string chaine)
{
    stack<char> s;
    for (int i = 0; i < chaine.size(); i++)
    {
        if (chaine[i] == ' ')
            continue;

        if (chaine[i] == '(' || chaine[i] == '[' || chaine[i] == '{')
        {
            s.push(chaine[i]);
            continue;
        }

        switch (chaine[i])
        {
        case ')':
            if (s.top() != '(')
                return false;
            s.pop();
            continue;
        case ']':
            if (s.top() != '[')
                return false;
            s.pop();
            continue;
        case '}':
            if (s.top() != '{')
                return false;
            s.pop();
            continue;
        default:
            continue;
        }
    }
    return true;
}

void test_permutation_circular()
{
    stack<int> st;
    st.push(103);
    st.push(2);
    st.push(98);
    st.push(11);
    st.push(7);
    stack_circperm(&st, 2);
    while (st.size())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

void test_permutation_circular2()
{
    stack<int> st;
    st.push(5);
    st.push(103);
    st.push(2);
    st.push(98);
    st.push(11);
    st.push(7);
    stack_circperm2(&st, 4);
    while (st.size())
    {
        cout << st.top() << endl;
        st.pop();
    }
}

void test_check_parenthese()
{
    string s = "[ [ [ ]]]";
    string s2 = "[{ }{{(2]]]";
    cout << check_parenthese(s) << endl;
    cout << check_parenthese(s2) << endl;
}
int main()
{
    test_check_parenthese();
    return 0;
}