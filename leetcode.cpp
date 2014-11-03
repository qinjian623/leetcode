/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
#include <iostream>
using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x):val(x), next(NULL){}
};

class RemoveDuplicatesfromSortedList {
public:
    ListNode *deleteDuplicates(ListNode *head) {
	    if (head == NULL){
		    return NULL;
	    }
	    ListNode* cur = head;
	    ListNode* next = head->next;
	    while(cur != NULL){
		    while(next != NULL && cur->val == next->val){
			    next = next->next;
		    }
		    cur->next = next;
		    cur = next;
	    }
	    return head;
    }
};

class MergeSortedArray {
public:
    void merge(int A[], int m, int B[], int n) {
	    int cur = m+n-1;
	    int ac = m-1;
	    int bc = n-1;
	    while(ac >= 0 && bc >= 0){
		    if(A[ac]>B[bc]){
			    A[cur] = A[ac];
			    ac--;
		    }else{
			    A[cur] = B[bc];
			    bc--;
		    }
		    cur--;
	    }
	    if (ac == -1 && bc >= 0){
		    while(cur >= 0){
			    A[cur] = B[bc];
			    bc--;
			    cur--;
		    }
	    }
    }
};

class ClimbingStairs {
public:
    int climbStairs(int n) {
	    int A[n+1];
	    A[1] = 1;
	    A[2] = 2;
	    for (int i = 3; i < n+1; i++) {
		    A[i] = A[i - 1] + A[i - 2];
	    }
	    return A[n];
    }
};

// TODO -符号的处理
class ValidNumber {
public:
	int strlen(const char* s){
		int i = 0;
		while(s[i]!=0){
			i++;
		}
		return i;
	}

	void space_detect(const char *s, int & left, int & right){
		int len = strlen(s);
		cout << "len=" << len<< endl;

		for(int i = 0; i < len; ++i){
			cout << "i=" << i << endl;
			if(s[i] != ' '){
				left = i;
				break;
			}

		}
		for (int i = len-1; i >= 0; --i){
			if(s[i] != ' '){
				right = i+1;
				break;
			}
		}
	}

	bool isNumber(const char *s) {
		int state = 0;
		int left, right;
		space_detect(s, left, right);
		cout << left << ' ' << right << endl;
		for(int i = left; i < right ;++i){
			cout << "state = " << state << endl;

			if (s[i] == ' '){
				return false;
			}
			state = switch_state(state, s[i]);
			if(state < 0){
				return false;
			}
		}
		if(state == 1 || state ==  2 || state == 3 || state==5){
			return true;
		}else{
			return false;
		}
	}

	int switch_state(int now, char c){
		switch(now){
		case 0:
			if (c >= '0' && c <= '9'){
				return 1;
			}
			if (c == '.'){
				return 6;
			}
			return -1;
		case 1:
			if (c >= '0' && c <= '9'){
				return 1;
			}

			if (c == '.'){
				return 2;
			}
			if (c == 'e'){
				return 4;
			}
			return -1;
		case 2:
			if (c >= '0' && c <= '9'){
				return 3;
			}
			return -1;
		case 3:
			if (c >= '0' && c <= '9'){
				return 3;
			}
			if (c == 'e'){
				return 4;
			}
			return -1;
		case 4:
			if (c >= '0' && c <= '9'){
				return 5;
			}
			return -1;
		case 5:
			if (c >= '0' && c <= '9'){
				return 5;
			}
			return -1;
		case 6:
			if (c >= '0' && c <= '9'){
				return 3;
			}
			return -1;
		default:
			return -1;
		}
	}
};





int main(int argc, char *argv[])
{
	ValidNumber vn;
	std::cout << vn.isNumber(" e");
	return 0;
}





