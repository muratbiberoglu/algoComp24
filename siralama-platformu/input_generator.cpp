#include <bits/stdc++.h>

using namespace std;

const int NUMBER_OF_TEST_FILES = 35;
const int differentTestFormats = 9;
const int testFormatDistribution[] = {4, 1, 5, 5, 5, 5, 3, 2, 5};

// bounds for each test format
const long long nLowerBoundArr[] = { 1, 1, 100, 1000, 10000, 100000, 500000, 1000000, 500000};
const long long nUpperBoundArr[] = { 100, 2, 1000, 10000, 100000, 500000, 1000000, 1000001, 1000000};

int k = 0;
void generate_array(ofstream& input, int n){
    vector<int> arr;
    for (int i = 1; i <= n; i++)
    {
       arr.push_back(i);
    }
    random_shuffle(arr.begin(), arr.end());
    
    input << n << endl;
    for (int column: arr)
    {
        input << column << " " ;
    }
}

void generate_edge_case(ofstream& input, int n){
    vector<int> arr;
    if(k == 0){
        for (int i = 1; i <= n; i++)
        {
            arr.push_back(i);
        }
    }
    else if(k == 1){
        for (int i = n; i > 0; i--)
        {
            arr.push_back(i);
        }
    }
    else if (k == 2){
        int m = n;
        if(n%2) m--; 
        for (int i = m; i > 0; i-=2)
        {
            arr.push_back(i);
        }
        for (int i = 1; i <= n; i+=2)
        {
            arr.push_back(i);
        }
    }
    else{
        int m = 1;
        if(n%2) m++; 
        for (int i = m; i < n; i+=2)
        {
            arr.push_back(i);
        }
        for (int i = n; i > 0; i-=2)
        {
            arr.push_back(i);
        }
    }
    
    input << n << endl;
    for (int column: arr)
    {
        input << column << " " ;
    }
    k++;
}

int whichTestFormat(int t)
{
    int counter = 0;
    for (int i = 0; i < differentTestFormats; i++)
    {
        counter += testFormatDistribution[i];
        if (t < counter)
            return i;        
    }
    return 0;
}

void generator(ofstream &input, int t)
{
    int type = whichTestFormat(t); 
    int n = rand() % (nUpperBoundArr[type] - nLowerBoundArr[type]) + nLowerBoundArr[type];
    if(type >= 8){
        generate_edge_case(input, n);
    }
    else{
        generate_array(input, n);
    }
    cout << t << ".: input is completed" << endl;
}

int main()
{
    srand(time(0));
    for (int t = 0; t < NUMBER_OF_TEST_FILES; t++)
    {
        ofstream input;
        stringstream ss;
        ss << "tests/input/input" << setw(2) << setfill('0') << t << ".txt";
        string filename = ss.str();
        input.open(filename);
        generator(input, t);
        input.close();
    }

    return 0;
}
