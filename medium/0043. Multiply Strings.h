// 43. Multiply Strings

// Runtime: 48 ms, faster than 14.35% of C++ online submissions for Multiply Strings.
// Memory Usage: 12.2 MB, less than 12.82% of C++ online submissions for Multiply Strings.

class Solution {
public:
    string multiply(string num1, string num2) {
        int n1 = num1.length();
        int n2 = num2.length();
        if (n1 > n2) {
            swap(num1, num2);
            swap(n1, n2);
        }
        
        string ans("0");
        for (int i = n1 - 1; i >= 0; --i) {
            ans = add(ans, multiply(num1[i] - '0', n1 - 1 - i, num2));
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
    
    string multiply(int num, int zero_cnt, const string& num2) {
        if (num == 0) return "0";
        
        string ans;
        if (zero_cnt > 0) {
            ans.append(zero_cnt, '0');
        }
        
        int carry = 0;
        for (int i = num2.length() - 1; i >= 0; --i) {
            char c = num2[i];
            int v = num * (c - '0') + carry;
            if (v < 10) {
                carry = 0;
                ans.append(1, v + '0');
            } else {
                carry = v / 10;
                ans.append(1, (v % 10) + '0');
            }
        }
        if (carry) {
            ans.append(1, carry + '0');
        }
        
        return ans;
    }
    
    string add(string num1, string num2) {
        string ans;
        int carry = 0;
        int n1 = num1.length();
        int n2 = num2.length();
        if (n1 > n2) {
            swap(num1, num2);
            swap(n1, n2);
        }
        for (int i = 0; i < n1; ++i) {
            int v = (num1[i] - '0') + (num2[i] - '0') + carry;
            if (v < 10) {
                carry = 0;
                ans.append(1, v + '0');
            } else {
                carry = v / 10;
                ans.append(1, (v % 10) + '0');
            }
        }
        for (int i = n1; i < n2; ++i) {
            int v = (num2[i] - '0') + carry;
            if (v < 10) {
                carry = 0;
                ans.append(1, v + '0');
            } else {
                carry = v / 10;
                ans.append(1, (v % 10) + '0');
            }
        }
        if (carry) {
            ans.append(1, carry + '0');
        }
        
        return ans;
    }
};