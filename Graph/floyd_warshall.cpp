vector<vector<int> > Solution::solve(vector<vector<int> > &A) {
    
    for(int i =0; i< A.size(); i++)
    {
        for(int j =0; j< A.size(); j++)
        {
            if(A[i][j] == -1)
                A[i][j] = 1e9;
        }
    }
    
    for(int k =0; k< A.size(); k++)
    {
        for(int i =0; i< A.size() ; i++)
        {
            for(int j =0; j< A.size(); j++)
            {
                A[i][j] = min(A[i][j],A[i][k]+A[k][j]);
            }
        }
    }
    
    for(int i =0; i< A.size(); i++)
    {
        for(int j =0; j< A.size(); j++)
        {
            if(A[i][j] == 1e9)
                A[i][j] = -1;
        }
    }
    
    return A;
}

