// Source : https://www.acwing.com/problem/content/4272/
// Author : Eland Woo
// Date   : 2022.6.11

/********************************************************************************** 
4269. 校庆
2019 年浙江大学将要庆祝成立 122 周年。为了准备校庆，校友会收集了所有校友的身份证号。现在需要请你编写程序，
根据来参加校庆的所有人士的身份证号，统计来了多少校友。

输入格式：
输入在第一行给出正整数 N。随后 N 行，每行给出一位校友的身份证号（18 位由数字和大写字母 X 组成的字符串）。
随后给出前来参加校庆的所有人士的信息：首先是一个正整数 M。随后 M 行，每行给出一位人士的身份证号。
题目保证校友和来宾的身份证号不重复。

输出格式:
首先在第一行输出参加校庆的校友的人数。然后在第二行输出最年长的校友的身份证号。注意身份证第 7−14 位给出的是
yyyymmdd 格式的生日。如果没有校友来，则在第二行输出最年长的来宾的身份证号。题目保证这样的校友或来宾必是唯一的。

数据范围:
1≤N,M≤105

输入样例：
5
372928196906118710
610481197806202213
440684198612150417
13072819571002001X
150702193604190912
6
530125197901260019
150702193604190912
220221196701020034
610481197806202213
440684198612150417
370205198709275042

输出样例：
3
150702193604190912
**********************************************************************************/



#include<bits/stdc++.h>

using namespace std;

bool isElder(string a, string b) {
    return a.substr(6, 7) < b.substr(6, 7);
}

int main() {
    int m, n;
    unordered_set<string> h;
    string schoolmate[100010];
    string guest[100010];
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        cin >> schoolmate[i];
        h.insert(schoolmate[i]);
    }
    scanf("%d", &m);
    for (int i = 0; i < m; ++i) cin >> guest[i];
    
    int flag = 0; // def: 0 means no schoolmate.
    pair<int, int> ans = {0, -1}; // {num of schoolmates, oldest one}.
    for (int i = 0; i < m; ++i) {
        if (h.find(guest[i]) != h.end()) {
            // cout << guest[i] << " is a schoolmate"<< endl;
            if (!flag) {
                if (ans.first == 1000) cout<< guest[i];
                ans = {1, i};
                flag = 1;
            } else {
                if (ans.first == 1000) cout<< guest[i] << " " << guest[ans.second] << endl;
                if (isElder(guest[i], guest[ans.second]))
                    ans.second = i;
                    ans.first += 1;
                    
            }
            continue;
        }
        // if there is no schoolmate for now, find the oldest guest.
        if (!flag) {
            if (ans.second == -1) ans = {0, i};
            else {
                if (isElder(guest[i], guest[ans.second]))
                ans  = {0, i};
            }
        }
    }

    cout << ans.first << endl <<guest[ans.second];
    return 0;
}