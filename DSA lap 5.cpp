#include <bits/stdc++.h>
using namespace std;
// last stone weight
/*int main()
{
    int n, x;
    cin >> n;
    priority_queue<int> kg;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        kg.push(x);
    }
    while (kg.size() > 1)
    {
        int y = kg.top();
        kg.pop();
        int x = kg.top();
        kg.pop();
        if (x != y)
            kg.push(y - x);
    }
    if (kg.empty())
        cout << "0";
    else
        cout << kg.top();
}
*/
/*int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    map<int, int> freq;
    for (int i = 0; i < n; i++)
    {
        freq[a[i]]++;
    }
    priority_queue<pair<int, int>> pq;
    for (auto it : freq)
    {
        pq.push({it.second, it.first}); // lay tan suat truoc roi moi lay value
    }
    vector<int> res;
    // lay k phan tu
    for (int i = 0; i < k; i++)
    {
        res.push_back(pq.top().second);
        pq.pop();
    }
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }
}
*/
/*int main()
{
    int n;
    cin >> n;
    vector<int> score(n);
    for (int i = 0; i < n; i++)
    {
        cin >> score[i];
    }
    vector<pair<int, int>> a;
    for (int i = 0; i < n; i++)
    {
        a.push_back({score[i], i});
    }
    sort(a.begin(), a.end(), greater<pair<int, int>>());
    vector<string> res(n);
    for (int i = 0; i < n; i++)
    {
        int index = a[i].second;
        if (i == 0)
            res[index] = "Gold Medal";
        if (i == 1)
            res[index] = "Silver Medal";
        if (i == 2)
            res[index] = "Bronze Medal";
        if (i > 2)
            res[index] = to_string(i + 1);
    }
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
}
*/
/*int main()
{
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
    vector<pair<int, int>> d;
    for (int i = 0; i < n; i++)
    {
        long long distance = 1LL*a[i].first * a[i].first + 1LL*a[i].second * a[i].second;
        d.push_back({distance, i});
    }
    sort(d.begin(), d.end());
    for (int i = 0; i < k; i++)
    {
        int index = d[i].second;
        cout << a[index].first << " " << a[index].second << endl;
    }
    return 0;
}
*/
string process(string s)
{
    string res = "";
    for (char c : s)
    {
        if (c == '#')
        {
            if (!res.empty())
                res.pop_back();
        }
        else
            res.push_back(c);
    }
    return res;
}
/*int main()
{
    int n;
    cin >> n;
    vector<long long> st;
    for (int i = 0; i < n; i++)
    {
        string op;
        cin >> op;
        if (op == "+")
        {
            long long x = st[st.size() - 1] + st[st.size() - 2];
            st.push_back(x);
        }
        else if (op == "D")
        {
            st.push_back(2 * st.back());
        }
        else if (op == "C")
        {
            st.pop_back();
        }
        else
        {
            st.push_back(stoll(op));
        }
    }
    long long sum = 0;
    for (long long x : st)
    {
        sum += x;
    }
    cout << sum;
}
*/
/*int main()
{
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (!res.empty() && tolower(res.back()) == tolower(s[i]) && res.back() != s[i])
            res.pop_back();
        else
            res.push_back(s[i]);
    }
    cout << res;
}
*/
/*int main()
{
    string s;
    cin >> s;
    string res = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (!res.empty() && res.back() == s[i])
        {
            res.pop_back();
        }
        else
            res.push_back(s[i]);
    }
    cout << res;
}
*/
/*int main()
{
    int n;
    cin >> n;
    vector<int> a(n), st;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && a[st.back()] <= a[i])
        {
            st.pop_back();
        }
        if (st.empty())
            cout << i + 1<<" ";
        else
            cout << i - st.back()<<" ";
        st.push_back(i);
    }
}
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    getline(cin, s);

    stack<long long> st;
    string token = "";

    for (int i = 0; i <= s.size(); i++)
    {
        if (i < s.size() && s[i] != ' ')
        {
            token += s[i];
        }
        else
        {
            if (token == "")
                continue;

            // Nếu là số
            if (isdigit(token[0]) || (token[0] == '-' && token.size() > 1))
            {
                st.push(stoll(token));
            }
            else
            {
                if (st.size() < 2)
                {
                    cout << "KHONG HOP LE";
                    return 0;
                }

                long long b = st.top();
                st.pop();
                long long a = st.top();
                st.pop();

                if (token == "+")
                    st.push(a + b);
                else if (token == "-")
                    st.push(a - b);
                else if (token == "x")
                    st.push(a * b);
                else if (token == ":")
                {
                    if (b == 0)
                    {
                        cout << "KHONG HOP LE";
                        return 0;
                    }
                    st.push(a / b);
                }
                else
                {
                    cout << "KHONG HOP LE";
                    return 0;
                }
            }

            token = "";
        }
    }

    if (st.size() != 1)
        cout << "KHONG HOP LE";
    else
        cout << st.top();

    return 0;
}