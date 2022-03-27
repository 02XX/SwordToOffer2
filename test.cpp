#include<iostream>
#include<string>
#include<iomanip>
#include<vector>
using namespace std;
bool isEque(vector<int> lA,  vector<int> lB)
    {
        for(int i = 0; i < int(lA.size());i++)
        {
            if(lA[i] == lB[0])
            {
                int j = 0;
                for(; j < int(lB.size()); j++)
                {
                    if(lA[j + i] == lB[j]) continue;
                    else
                    {
                        j = 0;
                        break;
                    }
                }
                if(j == int(lB.size()) && lA[j + i - 1] == lB[j - 1]) 
                    return true;
            }
        }
        return false;
    }
int main(int argc, char const *argv[])
{
    vector<int> a {1,2,3};
    vector<int> b {2,3};
    
    cout << isEque(a,b);
    return 0;
}