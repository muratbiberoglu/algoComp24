#include <bits/stdc++.h>

using namespace std;

const int NUMBER_OF_TEST_FILES = 35;

void solver(ifstream& input, ofstream& output) {
    int n;
    input >> n;
    vector<int> arr;
    for(int i = 0; i < n; i++){
        int column;
        input >> column;
        arr.push_back(column);
    }

    // input array is ready
    long long count = 0;
    for(int i = 0; i < n; i++){
        int l = i, r = i;
        count++;
        bool left = true;
        while(true){
            if(left && l > 0 && arr[l-1] < arr[r]){
                l--;
                left = false;
            }
            else if(!left && r < n-1 && arr[r+1] < arr[l]){
                r++;
                left = true;
            }
            else{
                break;
            }
            count++;
        }
    }

    output << count;
}


int main() {
    for (int t = 0; t < NUMBER_OF_TEST_FILES; t++) {
        ifstream input;
        ofstream output;
        stringstream ss_input;
        stringstream ss_output;
        ss_input << "tests/input/input" << setw(2) << setfill('0') << t << ".txt";
        ss_output << "tests/output/output" << setw(2) << setfill('0') << t << ".txt";
        string filename_input = ss_input.str();
        string filename_output = ss_output.str();
        input.open(filename_input);
        output.open(filename_output);

        solver(input, output);
        cout << t << ". output is comleted" << endl;
        input.close();
        output.close();

    }
    return 0;
}
