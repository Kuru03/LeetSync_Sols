class Solution {
public:
    string compressedString(string s) {
        string compressionProduct="";
        s+='1';
        int n=s.size();
        int cnt=1;
        char prevChar=s[0];
        for(int i=1;i<n;i++){
            if(s[i]!=prevChar){
                while(cnt>0){
                    int maxLimit=min(9,cnt);
                    cnt-=maxLimit;
                    char compressionNumber=maxLimit+'0';
                    compressionProduct+=compressionNumber;
                    compressionProduct+=prevChar;
                }
                prevChar=s[i];
                cnt=1; 
            }
            else{
                cnt++;
            }
        }
        return compressionProduct;
        
    }
};