#include <bits/stdc++.h>
using namespace std;
struct ListNode
{
    int val;
    ListNode *next;
};

vector<int> twoSum(vector<int> &nums, int target)
{
    int pos1 = 0, pos2 = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[i] + nums[j] == target)
            {
                return {i, j};
            }
        }
    }
    return {};
}
ListNode *makeNode(int x)
{
    ListNode *tmp = new ListNode();
    tmp->val = x;
    tmp->next = NULL;
    return tmp;
}
void addTail(ListNode *&head, ListNode *&tail, int x)
{
    ListNode *tmp = makeNode(x);
    if (head == NULL)
        head = tail = tmp;
    else
    {
        tail->next = tmp;
        tail = tmp;
    }
}
ListNode *addTwoNumbers(ListNode *l1, ListNode *l2)
{
    ListNode *head = NULL, *tail = NULL;
    int res = 0;
    while (l1 != NULL || l2 != NULL)
    {
        int sum = res;
        if (l1 != NULL)
        {
            sum += l1->val;
            l1 = l1->next;
        }
        if (l2 != NULL)
        {
            sum += l2->val;
            l2 = l2->next;
        }
        res = sum / 10;
        int k = sum % 10;
        addTail(head, tail, k);
    }
}

void longestSubstring(string s)
{
    set<char> m;
    int left = 0, ans = 0;
    for (int right = 0; right < s.length(); right++)
    {
        while (m.count(s[right]))
        {
            m.erase(s[left]);
            left++;
        }
        m.insert(s[right]);
        ans = max(ans, right - left + 1);
    }
    cout << ans;
}
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    nums1.insert(nums1.end(), nums2.begin(), nums2.end());
    sort(nums1.begin(), nums1.end());
    int Size = nums1.size();
    int mid = Size / 2;
    double median = 0;
    for (int i = 0; i < Size; i++)
    {
        if (Size % 2 == 0 && i == mid)
        {
            median = (nums1[mid] + nums1[mid - 1]) * 1.0 / 2;
            return median;
        }
        if (Size % 2 == 1 && mid == i)
        {
            median = nums1[mid];
            return median;
        }
    }
    return 1;
}
int isPalindrome(int x)
{
    if (x < 0)
        return 0;

    long long m = 0;
    long long tmp = x;

    while (tmp != 0)
    {
        m = m * 10 + tmp % 10;
        tmp /= 10;
    }

    return m == x;
}
int reverse(int x)
{
    int m = 0;

    while (x != 0)
    {
        int digit = x % 10;
        x /= 10;

        if (m > INT_MAX / 10 || m < INT_MIN / 10)
            return 0;

        m = m * 10 + digit;
    }

    return m;
}

long long myAtoi(string s)
{
    int i = 0, n = s.size();
    int sign = 1;
    while (i < n && s[i] == ' ')
        i++;
    if (s[i] == '-')
    {
        sign = -1;
        i++;
    }
    long long res = 0;
    while (i < n && isdigit(s[i]))
    {
        res = res * 10 + (s[i] - '0');
        i++;
    }

    return res * sign;
}

int main()
{
    string s, t;
    cin >> s >> t;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '#')
        {
            s[i - 1] = NULL;
            s[i] = NULL;
        }
    }
    cout << s;
}