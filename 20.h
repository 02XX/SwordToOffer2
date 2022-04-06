class Solution {
public:
    bool isNumber(string s) {
        int i = 0;
        int size = s.size();
        while(s[i] == ' ' && i < size) i++;
        if(i >= size) return false;
        if(s[i] == '+' || s[i] == '-') i++;
        if(i >= size) return false;

        int fN = 0;
        while(i < size && (isN(s[i]) || s[i] == '.'))
        {
            if(s[i] == '.')
            {
                fN++;
            }
            i++;
        }

        if(fN > 1) return false;
        

        if(!isN(s[i]) && s[i] != '.') return false;

        


        


    }
    bool isN(int x)
    {
        if(x >= 48 && x <= 57) return true;
        return false;
    }
};