class Solution {
public:
    string replaceSpace(string s) {
        string r = "";
        int begin = 0;
        for (int i = 0; i < int(s.size()); i++)
        {
            if(s[i] == ' ')
            {
                r = r + s.substr(begin, i - begin) + "%20";
                begin = i + 1;
            }
        }
        return r + s.substr(begin, int(s.size()) - begin);
        
    }
};