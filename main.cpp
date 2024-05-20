#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

/*
 * Complete the 'countingValleys' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts following parameters:
 *  1. INTEGER steps
 *  2. STRING path
 */

int countingValleys(int steps, string path) {
    int len=path.length();
    int uc=0;
    int dc=0;
    int val=0;
    int i=0;
    if(path[0]=='D'){ // if he enters valley first
            val++;
        }
        
while(i<len){   
    (path[i]=='D')? dc++ : uc++ ; // counting each steps
               
    if(dc-uc!=0){  // if he comes at sea level we again check if he enters a valley or not on next step
        i++;
        continue;  
    }else{
        if(path[i+1]=='D') //if yes we increase valley traversed by 1 
            val++;  
          }    
      i++;  
    }
    
    return val;

}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string steps_temp;
    getline(cin, steps_temp);

    int steps = stoi(ltrim(rtrim(steps_temp)));

    string path;
    getline(cin, path);

    int result = countingValleys(steps, path);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
