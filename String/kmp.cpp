// implementation of KMP algorithm

// references : www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

// implementation of KMP algorithm

// references : www.geeksforgeeks.org/kmp-algorithm-for-pattern-searching/

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void calculatelps(string str,vi &lps)
{
    int n = str.length();
    cout << n << "\n";
    
    //initialize 0 to complete vector
    for(int i =0; i< n; i++)
    {
        lps.push_back(0);
    }
    
    for(int i =1; i< n; i++)
    {
        int j = lps[i-1];
        
        while(j > 0 && str[i] != str[j])
            j = lps[j-1];
        
        if(str[i] == str[j])
            j++;
        
        lps[i] = j;
    }
}

void printlps(vi lps)
{
    cout << "lps is : " ;
    for(int i =0; i< lps.size(); i++)
        cout << lps[i] << " ";
    
    cout << "\n";
}

void printresult(string s, vi &lps, string t)
{
    int m = s.size();
    int n = t.size();
    
    //cout << "\n" << m << " " << n << "\n";
    int j =0;
    for(int i =0; i< m; )
    {
        if(s[i] == t[j])
        {
            i++;
            j++;
        }
        
        if(j == n)
        {
            cout << "fount at " << i-j << "\n";
            j = lps[j-1];
        }
        else if(i < m && s[i] != t[j])
        {
            if(j != 0)
            {
                j = lps[j-1];
            }
            else
                i = i+1;
        }
    }
}

int main() {
    
    string s = "adityakumkumarisgood";
    string t = "kumar";
    
    vi lps_vec;
    calculatelps(t,lps_vec);
    
    printlps(lps_vec);
    
    printresult(s,lps_vec,t);
    return 0;
}
