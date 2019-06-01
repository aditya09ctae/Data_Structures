// implementation of z algorithm

/* references : www.geeksforgeeks.org/z-algorithm-linear-time-pattern-searching-algorithm/
www.youtube.com/watch?v=CpZh4eF8QBw
 */

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

void calculatezarr(string str,vi &zarr)
{
    int n = str.length();

    //initialize 0 to complete vector
    for(int i =0; i< n; i++)
    {
        zarr.push_back(0);
    }
    
    int L = 0,R = 0;
    for(int i =1; i< n; i++)
    {
        if(i > R)
        {
            L = i;
            R = i;
            
            while(R < n && str[R] == str[R-L])
            {
                R++;
            }
            
            zarr[i] = R-L;
            R--;
        }
        else
        {
            int k = i - L;
            
            if(zarr[k] + i < R+1)
            {
                zarr[i] = zarr[k];
            }
            else
            {
                L = i;
                while(R < n && str[R] == str[R-L])
                {
                    R++;
                }
                
                zarr[i] = R-L;
                R--;
            }
        }
    }
}

void printzarr(vi zarr)
{
    cout << "z array is : " ;
    for(int i =0; i< zarr.size(); i++)
        cout << zarr[i] << " ";
    
    cout << "\n";
}

void printresult(vi zarr,int s)
{
    for(int i =0; i< zarr.size(); i++)
    {
        if(zarr[i] == s)
        {
            cout << "found at :" << i - s -1  << "\n";
        }
    }
}

int main() {
    
    string s = "adityakumkumarislearningtocode";
    string t = "kumar";
    
    string temp_str = t + "#" + s;
    vi zarr;
    
    calculatezarr(temp_str,zarr);
    
    printzarr(zarr);
    
    printresult(zarr,t.size());
    return 0;
}
