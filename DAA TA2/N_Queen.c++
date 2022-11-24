// Utkarsh Sathawane
// CSE A-68
// N-Queen Code

#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Cboard;
int N,X;


// Function to check whether Cboard[r][c] is safe place to place queen or not
// We will only check for left side since no queen is place on right side of Cboard[r][c]
bool isSafe(int r, int c)
{

    for (int i = 0; i < c; i++) /* Checking  row on  left side */
        if (Cboard[r][i] == 1)
            return false;

    int i = r;

    for (int j = c; j >= 0; j--) /* Checking upper diagonal  */
    {
        if (i < 0)
        {
            break;
        }
        if (Cboard[i][j] == 1)
        {
            return false;
        }
        i--;
    }

    i = r;
    for (int j = c; j >= 0; j--) /* Checking lower diagonal   */
    {
        if (i >= N)
        {
            break;
        }
        if (Cboard[i][j] == 1)
        {
            return false;
        }
        i++;
    }

    return true;
}

// Function to solve N-Queen problem
// It will use recursion and backtracking to solve our problem
bool NQueen(int c)
{

    // If all the queens are place then return true
    if (c >= N || X==0)
        return true;

    for (int i = 0; i < N; i++)
    {

        if (isSafe(i, c))
        {
            // place queen at Cboard[i][c]
            Cboard[i][c] = 1;
            X--;

            if (NQueen(c + 1))
                return true;

            // Remove queen at Cboard[i][c] since we cannot find solution after
            // placing queen on this position
            // This is where Backtracking takes place
            Cboard[i][c] = 0;
            X++;
        }
    }

    return false;
}
void Print() // This function will print our solution
{
    
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            cout << " " << Cboard[i][j] << " ";
        printf("\n");
    }
}
void solve()
{

    cout << "Enter Length of side of your chess board : ";
    cin >> N;
      cout << "Enter Number of Queen : ";
    cin >> X;
    Cboard.resize(N, vector<int>(N, 0));
    if (NQueen(0) == false)
    {
        cout << "No Solution For Given Input";
    }

    Print();
}


int main()
{
    solve();
    return 0;
}
