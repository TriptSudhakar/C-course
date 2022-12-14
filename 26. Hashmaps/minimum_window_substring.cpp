#include<iostream>
#include<cstring>
#include<climits>
using namespace std;
string find_window(string s,string p)
{
    int sl = s.length();
    int pl = p.length();

    // 1. Corner case
    if(pl>sl) return "None";

    //2. Freq maps
    int fs[256] = {0};
    int fp[256] = {0};

    for(int i=0;i<pl;i++)
    {
        int ch = p[i];
        fp[ch]++;
    }

    // 3. Sliding window (Expansion & Contraction & Updating the minimum length window)
    int cnt = 0;
    int start = 0;
    int min_len = INT_MAX;
    int start_idx = -1;
    for(int i=0;i<sl;i++)
    {
        int ch = s[i];
        fs[ch]++;

        // Maintain the count of characters matched
        if(fp[ch]!=0 && fs[ch]<=fp[ch])
        {
            cnt++;
        }

        // If all the characters match
        if(cnt==pl)
        {
            // start shrinking the window
            char temp = s[start];

            // Loop to remove unwanted characters
            while(fp[temp]==0 || fs[temp]>fp[temp])
            {
                fs[temp]--;
                start++;
                temp = s[start];
            }

            // window size
            int window_len = i-start+1;
            if(window_len<min_len)
            {
                min_len = window_len;
                start_idx = start;
            }
        }
    }

    if(start_idx==-1) return "None";
    return s.substr(start_idx,min_len);
}
int main()
{
    string s = "heelleeoeaeo world";
    string p = "eelo";
    cout<<find_window(s,p)<<'\n';
    return 0;
}