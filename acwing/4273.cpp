// Source :https://www.acwing.com/problem/content/description/4276/
// Author : Eland Woo
// Date   : 2022.6

/********************************************************************************** 
4273. 链表合并

给定两个单链表 L1=a1→a2→…→an−1→an 和 L2=b1→b2→…→bm−1→bm，满足：n≥2m。你的任务是将较短的那个链表逆序，
然后将之并入较长的链表，得到形如 a1→a2→bm→a3→a4→bm−1… 的结果。例如给定两个链表分别为 6→7 和 1→2→3→4→5，
你应该输出 1→2→7→3→4→6→5。本题中可能包含不在两个单链表中的节点，这些节点无需考虑。

输入格式
输入首先在第一行中给出两个链表 L1 和 L2 的头结点的地址，以及正整数 N，即给定的结点总数.一个结点的地址是一
个 5 位数的非负整数（可能包含前导 0），空地址 NULL 用 −1 表示。随后 N 行，每行按以下格式给出一个结点的信息：
Address Data Next其中 Address 是结点的地址，Data 是不超过 105 的正整数，Next 是下一个结点的地址。
题目保证没有空链表，并且较长的链表至少是较短链表的两倍长。

输出格式：
按顺序输出结果链表，每个结点占一行，格式与输入相同。

数据范围：
1≤N≤105

输入样例：
00100 01000 7
02233 2 34891
00100 6 00001
34891 3 10086
01000 1 02233
00033 5 -1
10086 4 00033
00001 7 -1

输出样例：
01000 1 02233
02233 2 00001
00001 7 34891
34891 3 10086
10086 4 00100
00100 6 00033
00033 5 -1
**********************************************************************************/
#include<bits/stdc++.h>

using namespace std;

struct Node {
    int addr;
    int dat; 
    int nxt;
};

int main() {
    int l1Node, l2Node, n;
    cin >> l1Node >> l2Node >> n;
    
    unordered_map<int, pair<int, int>> node;
    for (int i = 0; i < n; ++i) {
        int address, data, next;
        scanf("%d%d%d", &address, &data, &next);
        node[address] = {data, next};
    }
    
    // bad smell: could put in a same funtion.
    vector<Node> l1;
    for (int i = l1Node; ; i = node[i].second) {
        Node newNode;
        newNode.addr = i;
        newNode.dat = node[i].first;
        newNode.nxt = node[i].second;
        l1.push_back(newNode);
        if (node[i].second == -1) break;
    }
    vector<Node> l2;
    for (int i = l2Node; ; i = node[i].second) {
        Node newNode;
        newNode.addr = i;
        newNode.dat = node[i].first;
        newNode.nxt = node[i].second;
        l2.push_back(newNode);
        if (node[i].second == -1) break;
    }
    
    // let l1 be the longer linkedist.
    if (l1.size() < l2.size()) swap(l1, l2);
    
    // reverse and output
    int j = l2.size() - 1;
    for (int i = 0; i < l1.size(); ++i) {
        if (j >= 0 && i != 0 && i % 2 == 0) {
            printf("%05d %d %05d\n", l2[j].addr, l2[j].dat, l1[i].addr);
            j--;
        }
        if ((i + 1) % 2 == 0 && j >= 0) printf("%05d %d %05d\n", l1[i].addr, l1[i].dat, l2[j].addr);
        else {
            if (i == l1.size() - 1) printf("%05d %d %d\n", l1[i].addr, l1[i].dat, l1[i].nxt);
            else printf("%05d %d %05d\n", l1[i].addr, l1[i].dat, l1[i].nxt);
        }
    }
    if (j >= 0) printf("%05d %d %d\n", l2[j].addr, l2[j].dat, l2[j].nxt);
    return 0;
}