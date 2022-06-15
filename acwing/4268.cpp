// Source :https://www.acwing.com/problem/content/4271/
// Author : Eland Woo
// Date   : 2022.6.10

/********************************************************************************** 
4268. 性感素数
“性感素数 ”是指形如 (p,p+6) 这样的一对素数。之所以叫这个名字，是因为拉丁语管“六”叫“sex”（即英语的“性感”）。
现给定一个整数，请你判断其是否为一个性感素数。

输入格式：
输入在一行中给出一个正整数 N。

输出格式：
若 N 是一个性感素数，则在一行中输出 Yes，并在第二行输出与 N 配对的另一个性感素数（若这样的数不唯一，
输出较小的那个）。若 N 不是性感素数，则在一行中输出 No，然后在第二行输出大于 N 的最小性感素数。

数据范围：
1≤N≤108

输入样例1：
47
输出样例1：
Yes
41

输入样例2：
21
输出样例2：
No
23
**********************************************************************************/

#include<iostream>
#include<math.h>

using namespace std;
/*
Knowledge to know:21
    Primes: cannot be divided exactly except 1 or itself.
    Sexy Primes: when p is a Prime, p - 6 and p + 6 are also primes.
*/


/* 
    function: to tell the number n is prime or not.
    If n is not a prime, then its divisors must be one greater than sqrt(n) and one less than sqrt(n).
*/
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= (int)sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

/* function to tell n is SexPrime or not */
bool isSexyPrime(int n) {
    return isPrime(n) && (isPrime(n - 6) || isPrime(n + 6));
}

int main() {
    int n;
    scanf("%d", &n);
    
    // 1.if n is SexPrime, find the smaller partner;
    // 2.if not,find the SexPrime bigger than n.
    if (isSexyPrime(n)) {
        printf("Yes\n");
        if (isPrime(n  - 6)) printf("%d", n - 6);
        else printf("%d", n + 6);
    } else {
        printf("No\n");
        while (++n)
            if (isSexyPrime(n)) {
                printf("%d", n);
                break; // attention!
            }
    }
    return 0;
}
