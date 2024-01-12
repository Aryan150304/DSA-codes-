// leetcode daily problem - https://leetcode.com/problems/determine-if-string-halves-are-alike/description/?envType=daily-question&envId=2024-01-12
class Solution {
public:
    bool halvesAreAlike(string s) {
        int i = 0;
        int counti = 0;
        int j = s.length()-1;
        int mid = (i+j)/2;
        int countj=0;

        for(int j=0;j<=mid;j++){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'){
                counti++;
            }
        }
         for(int j=mid+1;j<=s.length()-1;j++){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'){
                countj++;
            }
        }

        if(counti==countj){
            return true;
        }
        else{
            return false;
        }
    }
};


// approach 2 

lass Solution {
public:
    bool halvesAreAlike(string s) {
        int i = 0;
        int counti = 0;
        int j = s.length()-1;
        int countj=0;
        while(j>=i){
            if(s[j]=='a'||s[j]=='e'||s[j]=='i'||s[j]=='o'||s[j]=='u'||s[j]=='A'||s[j]=='E'||s[j]=='I'||s[j]=='O'||s[j]=='U'){
                countj++;
            }
            if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'||s[i]=='A'||s[i]=='E'||s[i]=='I'||s[i]=='O'||s[i]=='U'){
                counti++;
                cout<<counti<<endl;
            }
            j--;
            i++;
        }
        cout<<counti<<" "<<countj<<endl;
        if(counti==countj){
            return true;
        }
        else{
            return false;
        }
        
    }
};
