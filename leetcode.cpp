#include "Operation.h"

class ValidPalindrome {
public:
    bool isPalindrome(string s) {
        string pure_char_str;
        for (size_t i = 0; i < s.size(); ++i) {
            if (std::isdigit(s[i])){
                pure_char_str.push_back(s[i]);
            }
            if (std::islower(s[i])) {
                pure_char_str.push_back(s[i]);
            }else if(isupper(s[i])){
                pure_char_str.push_back(tolower(s[i]));
            }
        }
        string reverse(pure_char_str);
        std::reverse(reverse.begin(), reverse.end());
        if (reverse == pure_char_str){
            return true;
        }else{
            return false;
        }
    }
};

class PathSum{
public:
    bool hasPathSum(TreeNode *root, int sum) {
        if (root == NULL){
            return false;
        }
        int cur_sum = sum-(root->val);
        if (cur_sum == 0 && root->right == NULL && root->left == NULL){
            return true;
        }
        
        if(hasPathSum(root->left, cur_sum)){
            return true;
        }
        if (hasPathSum(root->right, cur_sum)){
            return true;
        }
        return false;
    }
};

class MinimumDepthofBinaryTree {
public:
    int minDepth(TreeNode *root) {
        if (root == NULL){
            return 0;
        }
        if (root->left == NULL && root->right== NULL) {
            return 1;
        }
        int min_left_depth = 1 + minDepth(root->left);
        int min_right_depth = 1 + minDepth(root->right);
        if (root->left == NULL){
            return min_right_depth;
        }
        if (root->right == NULL){
            return min_left_depth;
        }
        return min(min_left_depth, min_right_depth);
    }
};

class MaximumDepthofBinaryTree {
public:
    int maxDepth(TreeNode *root) {
        if(root == NULL){
            return 0;
        }
        if (root->left == NULL && root->right== NULL) {
            return 1;
        }
        int max_left_depth = 1 + maxDepth(root->left);
        int max_right_depth = 1 + maxDepth(root->right);
        if (root->left == NULL){
            return max_right_depth;
        }
        if (root->right == NULL){
            return max_left_depth;
        }
        return max(max_left_depth, max_right_depth);
    }
};

class SymmetricTree {
public:
    bool isSymmetric(TreeNode *root) {
        if (root == NULL) {
            return true;
        }
        return isMirrorTree(root->left, root->right);
    }
    
    bool isMirrorTree(TreeNode *p, TreeNode *q) {
        if (p == NULL && q == NULL) {
            return true;
        }
        if ((p == NULL && q != NULL )||(p!= NULL && q == NULL)) {
            return false;
        }
        if (p->val != q->val){
            return false;
        }
        return (isMirrorTree(p->right, q->left)&& isMirrorTree(p->left, q->right));
    }
};

class PlusOne {
public:
    vector<int> plusOne(vector<int> &digits) {
        digits.insert(digits.begin(), 0);
        size_t end = digits.size() - 1;
        int extra = 0;
        digits[end] += 1;

        for (long long i = end; i > -1; --i) {
            digits[i] += extra;
            if (digits[i] > 9) {
                extra = digits[i]/10;
                digits[i] = digits[i]%10;
            }else{
                extra = 0;
            }
        }
        if (digits[0] == 0) {
            digits.erase(digits.begin());
        }
        return digits;
    }
};

class RemoveElement {
public:
    int removeElement(int A[], int n, int elem) {
        int c = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (A[i] == elem) {
                c++;
                continue;
            }else{
                A[j] = A[i];
                j++;
            }
        }
        return n - c;
    }
};


class ValidParentheses{
public:
    bool isValid(string s) {
        stack<char> sys;
        for (int i = 0; i < s.size(); ++i) {
            switch (s[i]) {
                case '(':
                    sys.push(')');
                    break;
                case '[':
                    sys.push(']');
                    break;
                case '{':
                    sys.push('}');
                    break;
                default:
                    if (sys.empty()) {
                        return false;
                    }
                    if (sys.top() != s[i]) {
                        return false;
                    }
                    sys.pop();
                    break;
            }
        }
        if (!sys.empty()){
            return false;
        }
        return true;
    }
};

class RemoveDuplicatesfromSortedArray {
public:
    int removeDuplicates(int A[], int n) {
        int c = 0;
        for (int i = 0, j = 0; i < n; ++i) {
            if (A[i] == A[j - 1]) {
                c++;
                continue;
            }else{
                A[j] = A[i];
                j++;
            }
        }
        return n - c;
    }
};

class RemoveNthNodeFromEndofList {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *p;
        ListNode *tail = head;
        for (int i = 0; i < n; ++i) {
            tail = tail->next;
        }
        p = head;
        while (tail->next->next != NULL) {
            p = p->next;
            tail = tail->next;
        }
        p->next = p->next->next;
        return head;
    }
};

class PascalsTriangle {
public:
    vector<vector<int> > generate(int numRows) {
        vector<vector<int> > ret;
        for (int i =0; i < numRows; ++i) {
            vector<int> line(i+1);
            line[0] = 1;
            line[i] = 1;
            for (int j = 1; j < i; ++j) {
                line[j] = ret[i-1][j-1]+ret[i-1][j];
            }
            ret.push_back(line);
        }
        return ret;
    }
};

class PascalsTriangleII {
public:
    vector<int> getRow(int rowIndex) {
        rowIndex++;
        vector<vector<int>> rows;
        rows.push_back(vector<int>(rowIndex));
        rows.push_back(vector<int>(rowIndex));
        int current = 1;
        int previous = 0;
        for (int i =0; i < rowIndex; ++i) {
            vector<int> pre = rows[previous];
            rows[current][0] = 1;
            rows[current][i] = 1;
            for (int j = 1; j < i; ++j) {
                rows[current][j] = rows[previous][j-1]+rows[previous][j];
            }
            std::swap(current, previous);
        }
        return rows[previous];
    }
};

class BalancedBinaryTree {
public:
    bool isBalanced(TreeNode *root) {
        return balanced_power(root) > 0;
    }
    
    int balanced_power(TreeNode * root){
        if (root == NULL) {
            return 0;
        }
        int left_bp = balanced_power(root->left);
        int right_bp = balanced_power(root->right);
        if (left_bp < 0 || right_bp < 0 || abs(left_bp - right_bp) > 1) {
            return -1;
        }else{
            return max(left_bp, right_bp)+1;
        }
    }
};

class BinaryTreeLevelOrderTraversalII {
public:
    vector<vector<int> > levelOrderBottom(TreeNode *root) {
        vector<vector<int>> ret;
        depth_traking(root, ret, 1);
        reverse(ret.begin(), ret.end());
        return ret;
    }
    
    void depth_traking(TreeNode *root, vector<vector<int>> & recycle, int cur_depth){
        if (root == NULL) {
            return;
        }
        if (recycle.size() < cur_depth) {
            recycle.push_back(vector<int>());
        }
        recycle[cur_depth - 1].push_back(root->val);
        depth_traking(root->left, recycle, cur_depth+1);
        depth_traking(root->right, recycle, cur_depth+1);
    }
};

class LongestCommonPrefix {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string ret;
        if (strs.size() == 0) {
            return "";   // Or maybe return null?
        }
        
        for (int prefixLen = 0; prefixLen < strs[0].length(); prefixLen++) {
            char c = strs[0][prefixLen];
            for (int i = 1; i < strs.size(); i++) {
                if ( prefixLen >= strs[i].length() ||
                    strs[i][prefixLen] != c ) {
                    return ret;                }
            }
            ret.push_back(strs[0][prefixLen]);
        }
        return ret;
    }
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

class LengthofLastWord {
        public:
                int lengthOfLastWord(const char *s) {
                        bool in_space_region = true;
                        int i, len = 0;
                        int last_len = 0;
                        for (i = 0; s[i] != 0; ++i) {
                                if (s[i] == ' ' && !in_space_region) {
                                        last_len = len;
                                        len = 0;
                                        in_space_region = true;
                                }
                                if (s[i] != ' ' && in_space_region) {
                                        len = 0;
                                        in_space_region = false;
                                }
                                if (s[i] != ' ' && !in_space_region) {
                                        len++;
                                }
                        }
                        if(i == 0){
                                return 0;
                        }
                        if (s[i - 1] != ' ')
                                return len;
                        else
                                return last_len;
                }
};

class AddBinary {
public:
    string addBinary(string a, string b) {
            int max_len = max(a.length(), b.length());
            vector<int> va = str2int_vector(a, max_len);
            vector<int> vb = str2int_vector(b, max_len);
            plus(va, vb);
            return vector2str(va);
    }

    string vector2str(vector<int> v){
            string s;
            int start = 0;
            if(v[0] == 0){
                    start++;
            }
            for (int i = start; i< v.size(); ++i) {
                    s.push_back(v[i]+'0');
            }
            return s;
    }
    void plus(vector<int> &a, vector<int> &b){
            for(int i = a.size()-1; i > 0; --i){
                    a[i] += b[i];
            }
            for(int i = a.size()-1; i > 0; --i){
                    if (a[i] > 1){
                            a[i-1] += a[i]/2;
                            a[i] = a[i]%2;
                    }
            }
    }
    vector<int> str2int_vector(string& s, int max_len){
            vector<int> v(max_len+1, 0);
            for(int i = max_len,j = s.length()-1;j >= 0; --i, --j){
                    v[i] = s[j] - '0';
            }
            return v;
    }
};


int main(int argc, char *argv[])
{
	LengthofLastWord vn;
std::cout << vn.lengthOfLastWord("b a ")<< endl;
std::cout << vn.lengthOfLastWord("aasdfasdf wo")<< endl;
std::cout << vn.lengthOfLastWord("aasdfasdf wo ")<< endl;
std::cout << vn.lengthOfLastWord("hello world")<< endl;
std::cout << vn.lengthOfLastWord(" ")<< endl;

std::cout << vn.lengthOfLastWord("a ")<< endl;
std::cout << vn.lengthOfLastWord("a")<< endl;
std::cout << vn.lengthOfLastWord("")<< endl;

	return 0;
}





