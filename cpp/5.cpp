/*
5. Longest Palindromic Substring
Runtime: 12 ms, faster than 92.32% of C++ online submissions for Longest Palindromic Substring.
Memory Usage: 9.5 MB, less than 59.04% of C++ online submissions for Longest Palindromic Substring.
*/
class Solution {
public:
    string longestPalindrome(string s) {
        if( s.size() == 0 )
            return "";
        
        string ss = " ";
        for(int i = 0; i < s.size(); i++)
            ss += s.substr(i, 1) + " ";
        
        int n = ss.size();
        vector<int> len(n, 1);
        int maxLen = 1;
        int maxi = 1;
        int right = 0;
        int center = 0;
        int l;
        for(int i = 1; i < n; i++){
            if( i >= right ){
                l = 1;
            }
            else{
                int left = center - (i - center);
                l = min(len[left], right - i + 1);
            }
            
            while( i+l < n && i-l >= 0 ){
                if( ss[i+l] == ss[i-l] )
                    l++;
                else
                    break;
            }
            
            if( l > maxLen ){
                maxLen = l;
                maxi = i;
            }
            
            len[i] = l;
            
            if( i+l-1 > right ){
                right = i+l-1;    
                center = i;
            }
        }
        
        if( maxLen == 1 )
            return s.substr(0, 1);
        
        string tmp = ss.substr( maxi - maxLen + 1, 2 * maxLen - 1);
        string res = "";
        for(int i = 0; i < tmp.size(); i++)
            if( tmp[i] !=  ' ' )
                res += tmp[i];
        
        return res;
    }
};

// 1 2 3
// 3 5 7


// 5. Longest Palindromic Substring
class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 0) return "";
        
        string res;
        for(int i = 1; i < s.size(); i++){
            string tmp = check(i-1, s);
            if( res.size() < tmp.size() ) res = tmp;
            if(s[i-1] == s[i]){
                tmp = check_two(i-1, i, s);
                if( res.size() < tmp.size() ) res = tmp;
            }
        }
        
        string tmp = check(s.size()-1, s);
        if( res.size() < tmp.size() ) res = tmp;
        
        return res;
    }
    
    string check(int mid, string &s){
        string ss_back, ss_front;
        for(int i = 1; (mid+i < s.size()) && (mid-i >= 0); i++){
            if( s[mid+i] == s[mid-i] ){
                ss_back += s[mid+i];
                ss_front.insert(0, s, mid+i, 1);
            }
            else
                break;
        }
        
        return ss_front + s[mid] + ss_back;
    }
    
    string check_two(int l, int r, string &s){
        string ss_back, ss_front;
        for(int i = 1; (l-i >= 0) && (r+i < s.size()) ;i++ ){
            if( s[l-i] == s[r+i] ){
                ss_front.insert(0, s, l-i, 1);
                ss_back += s[r+i];
            }
            else
                break;
        }
        
        return ss_front + s[l] + s[r] + ss_back;
    }
};
