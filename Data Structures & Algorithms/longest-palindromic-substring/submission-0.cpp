class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.size();
        int left =s[0];
        int right =n;
        int currlen =0;
        int index =0;

        for(int i =0; i<=n;i++){

            left =i;
            right =i;
            while(left>=0 && right<n && s[left]== s[right]){
                if((right-left+1)>currlen){
                    currlen = right-left+1;
                    index = left;
                }
                
                left--;
                right++;

            }

            left =i;
            right =i+1;

            while(left>=0 && right<n && s[left]== s[right]){
                if((right-left+1)>currlen){
                    currlen = right-left+1;
                    index = left;
                }
                
                left--;
                right++;

            }
            
        }
        return s.substr(index, currlen);

            



        
        
    }
};
