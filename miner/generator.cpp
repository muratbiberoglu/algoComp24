// test case generator for the problem miner.


// Create a random full binary tree with n nodes.


#include <bits/stdc++.h>
using namespace std;

#define MAX_NODE_VALUE 100
#define MAX_EDGE_VALUE 6
#define MAX_NODE_COUNT 1000
#define MAX_K_VALUE 32
#define NUMBER_OF_TEST_CASES 20

 

string create_string_test_case_number(int test_case){
    string test_case_number = to_string(test_case);
    while(test_case_number.size() < 2){
        test_case_number = "0" + test_case_number;
    }
    return test_case_number;
}


int main(){
    srand(time(NULL));
    /* Compile the solver.cpp */
    string solver_compile_command = "g++ solver.cpp -o solver";
    system(solver_compile_command.c_str());
    cout<< "Program compiled successfully\n";

    
    // create input file as test/input/<test_name>.txt file
    // and corresponding output file as test/output/<test_name>.txt file by running solver with inputs

    
    // create test cases
    for(int test_case = 0; test_case < NUMBER_OF_TEST_CASES ; test_case++){
        // create input file
        string input_file_name = "tests/input/input" + create_string_test_case_number(test_case) + ".txt";
        ofstream input_file(input_file_name);
        

        // create output file
        string output_file_name = "tests/output/output" + create_string_test_case_number(test_case) + ".txt";
        
        // create random number n
        int n = rand() % MAX_NODE_COUNT + 1;
        input_file << n << " ";
        
        // create random number k
        int k = rand() % MAX_K_VALUE + 1;
        input_file << k << "\n";

        // create random number val[i] for each node i
        
        for(int i = 1; i <= n; i++){
            int val = rand() % MAX_NODE_VALUE + 1;
            input_file << val << " ";
        }

        input_file << "\n";

        // create random edges
        // each node has 2 children
        // each node has 1 parent except root
        // each node has 1 edge to parent
        // each node has 2 edges to children
        // each node has 3 edges in total

        // create a random permutation of nodes
        vector<int> nodes(n+1);
        for(int i = 1; i <= n; i++){
            nodes[i] = i;
        }

        // create edges for full binary tree
        for(int i=1 ; i <= ( (n-1)/2 ) ; i++){
            int a = nodes[i];
            int b = nodes[2*i];
            int c = rand() % MAX_EDGE_VALUE + 1;
            input_file << a << " " << b << " " << c << "\n";
            b = nodes[2*i + 1];
            input_file << a << " " << b << " " << c << "\n";
        }

        // add one more edge for the last node if n is even
        if(n%2 == 0){
            int a = nodes[n/2];
            int b = nodes[n];
            int c = rand() % MAX_EDGE_VALUE + 1;
            input_file << a << " " << b << " " << c << "\n";
        }

        // close input file
        input_file.close();

        // run solver with input file and output to output file
        string solver_command = "solver.exe " + input_file_name + " " + output_file_name;
        system(solver_command.c_str());

    }
}




