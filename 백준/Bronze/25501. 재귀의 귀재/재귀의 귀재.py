import sys
from collections import deque
input=sys.stdin.readline


'''
def recursion(const char *s, int l, int r){
    if(l >= r) return 1;
    else if(s[l] != s[r]) return 0;
    else return recursion(s, l+1, r-1);
}

def isPalindrome(const char *s){
    return recursion(s, 0, strlen(s)-1);
}

def main(){
    printf("ABBA: %d\n", isPalindrome("ABBA")); // 1
    printf("ABC: %d\n", isPalindrome("ABC"));   // 0
}
'''

def recursion(s, l, r):
    global cnt
    cnt+=1
    if l>=r:
        return 1
    elif s[l]!=s[r]:
        return 0
    else:
        return recursion(s, l+1, r-1)

def isPalindrome(s):
    return recursion(s, 0, len(s)-1)

t=int(input())
for _ in range(t):
    cnt=0
    word=input().strip()
    print(isPalindrome(word),cnt)
    