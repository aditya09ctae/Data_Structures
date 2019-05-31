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

void printresult(vi lps,int s)
{
    for(int i =0; i< lps.size(); i++)
    {
        if(lps[i] == s)
        {
            cout << "found at :" << i - 2*s  << "\n";
        }
    }
}

int main() {
    
    string s = "adityakumkumarisgood";
    string t = "kumar";
    
    string temp_str = t + "#" + s;
    
    cout << temp_str << "\n";
    vi lps_vec;
    calculatelps(temp_str,lps_vec);
    
    printlps(lps_vec);
    
    printresult(lps_vec,t.size());
    return 0;
}
