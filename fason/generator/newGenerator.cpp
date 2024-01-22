#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;
vector<string> wordList;

void wordListRead()
{
    wordList.resize(0);

    ifstream file("word_list.txt", ios::in);
    string word;
    while (file >> word)
    {
        wordList.push_back(word);
    }
    file.close();
}

string getRandomWord()
{
    /* ofstream loggingFile("logging.txt", ios::app);
    loggingFile << "  Word list size: " << wordList.size() << endl;
    loggingFile.close(); */

    int randomIndex = rand() % wordList.size();
    string randomWord = wordList[randomIndex];
    wordList.erase(wordList.begin() + randomIndex);
    return randomWord;
}

/* bool isWordListUnique()
{
    map<string, bool> wordMap;
    for (int i = 0; i < wordList.size(); i++)
    {
        if (wordMap[wordList[i]])
            return false;
        wordMap[wordList[i]] = true;
    }
    return true;
} */

class Node
{
public:
    string word;
    vector<Node *> children;
    Node(string word)
    {
        this->word = word;
    }

    void deleteNode()
    {
        if (this == NULL)
            return;

        if (children.size() == 0)
        {
            delete this;
            return;
        }

        for (int i = 0; i < children.size(); i++)
        {
            if (children[i] == NULL)
                continue;
            children[i]->deleteNode();
        }
        delete this;
    }
};

class Tree
{
public:
    Node *root;
    Tree()
    {
        root = new Node(getRandomWord());
    }

    void addNodes(Node *parent, int width)
    {
        if (width == 0)
            return;
        for (int i = 0; i < width; i++)
        {
            Node *child = new Node(getRandomWord());
            parent->children.push_back(child);
        }
    }

    void recursiveAdd(Node *parent, int width, int depth)
    {
        if (depth == 0)
            return;
        addNodes(parent, width);
        for (int i = 0; i < parent->children.size(); i++)
            recursiveAdd(parent->children[i], width, depth - 1);
    }

    string printTree() { return printTreeHelper(root); }

    string printTreeHelper(Node *parent)
    {
        string tree = "\\";
        tree += parent->word;
        for (int i = 0; i < parent->children.size(); i++)
            tree += printTreeHelper(parent->children[i]);
        tree += "/";
        return tree;
    }

    void treeFillerHelper(Node *parent)
    {
        if (parent->children.size() == 0)
            parent->children.push_back(new Node(getRandomWord()));
        else
            for (int i = 0; i < parent->children.size(); i++)
                treeFillerHelper(parent->children[i]);
    }

    void treeFiller() { treeFillerHelper(root); }

    pair<string, string> geniuineTestCase()
    {
        string query = "";
        string answer = "";

        Node *currentNode = root;
        query += currentNode->word;

        while (currentNode->children.size() != 1 || currentNode->children[0]->children.size() != 0)
        {
            int randomIndex = rand() % currentNode->children.size();
            currentNode = currentNode->children[randomIndex];
            query += "." + currentNode->word;
        }
        answer = currentNode->children[0]->word;

        return make_pair(query, answer);
    }

    pair<string, string> invalidTestCaseWrongLeaf()
    {
        string answer = "-1";
        string query = "";
        queue<Node *> q;

        Node *currentNode = root;
        q.push(currentNode);
        while (currentNode->children.size() != 1 || currentNode->children[0]->children.size() != 0)
        {
            int randomIndex = rand() % currentNode->children.size();
            currentNode = currentNode->children[randomIndex];
            q.push(currentNode);
        }

        while (!q.empty() && q.size() > 1)
        {
            query += q.front()->word + ".";
            q.pop();
        }
        query += getRandomWord();

        return make_pair(query, answer);
    }

    pair<string, string> invalidTestCaseStopBranch()
    {
        string answer = "-1";
        string query = "";
        queue<Node *> q;

        Node *currentNode = root;
        q.push(currentNode);
        while (currentNode->children.size() != 1 || currentNode->children[0]->children.size() != 0)
        {
            int randomIndex = rand() % currentNode->children.size();
            currentNode = currentNode->children[randomIndex];
            q.push(currentNode);
        }

        int qSize = q.size();
        if (qSize == 1)
            return invalidTestCaseWrongLeaf();

        int randomStop = rand() % q.size() - 1;

        for (int i = 0; i < randomStop - 1; i++)
        {
            query += q.front()->word + ".";
            q.pop();
        }
        query += q.front()->word;

        return make_pair(query, answer);
    }

    ~Tree()
    {
        root->deleteNode();
    }
};

class TestCases
{
public:
    vector<int> m = {2, 3, 4, 5, 6};
    vector<int> d = {2, 2, 3, 3, 4, 4};

    string inputFileBase = "../tests/input/input";
    string outputFileBase = "../tests/output/output";

    string number_to_string(int number)
    {
        stringstream ss;
        string str = "";

        if (number < 10)
            str = "0";

        ss << number;
        string str_num = "";
        ss >> str_num;
        str += str_num;
        return str;
    }

    string inputFileName(int i)
    {
        string fileName = inputFileBase + number_to_string(i) + ".txt";
        return fileName;
    }

    string outputFileName(int i)
    {
        string fileName = outputFileBase + number_to_string(i) + ".txt";
        return fileName;
    }

    int power(int base, int exp)
    {
        int result = 1;
        for (int i = 0; i < exp; i++)
            result *= base;
        return result;
    }

    void generateTestCases()
    {
        /* fstream loggingFile("logging.txt", ios::out);
        loggingFile.close(); */

        for (int i = 0; i < m.size(); i++)
        {
            for (int j = 0; j < d.size(); j++)
            {
                wordListRead();

                int testCaseCount = power(m[i], d[j]) / 4;
                int testCaseNumber = (i * d.size()) + j;

                /* ofstream loggingFile("logging.txt", ios::app);
                loggingFile << "Generating test cases for m = " << m[i] << " and d = " << d[j] << endl;
                loggingFile << "  Test case count: " << testCaseCount << endl;
                loggingFile << "  Test case number: " << testCaseNumber << endl;
                loggingFile.close(); */

                Tree tree;
                tree.recursiveAdd(tree.root, m[i], d[j]);
                tree.treeFiller();

                /* loggingFile.open("logging.txt", ios::app);
                loggingFile << "  Tree created." << endl;
                loggingFile.close(); */

                map<string, string> testCases;
                while (testCases.size() < testCaseCount)
                {
                    if (rand() % 3 == 0)
                    {
                        pair<string, string> testCase = tree.invalidTestCaseWrongLeaf();
                        if (testCases[testCase.first] == "")
                            testCases[testCase.first] = testCase.second;
                        continue;
                    }
                    if (rand() % 3 == 0)
                    {
                        pair<string, string> testCase = tree.invalidTestCaseStopBranch();
                        if (testCases[testCase.first] == "")
                            testCases[testCase.first] = testCase.second;
                        continue;
                    }
                    pair<string, string> testCase = tree.geniuineTestCase();
                    if (testCases[testCase.first] == "")
                        testCases[testCase.first] = testCase.second;
                }

                string treeString = tree.printTree();

                ofstream inputFile(inputFileName(testCaseNumber), ios::out);
                inputFile << treeString.size() << " " << testCaseCount << endl;
                inputFile << treeString << endl;
                for (auto it = testCases.begin(); it != testCases.end(); it++)
                    inputFile << it->first << endl;
                inputFile.close();

                ofstream outputFile(outputFileName(testCaseNumber), ios::out);
                for (auto it = testCases.begin(); it != testCases.end(); it++)
                    outputFile << it->second << endl;
                outputFile.close();
            }
        }
    }
};

int main()
{
    srand(time(NULL));
    wordListRead();

    TestCases testCases;
    testCases.generateTestCases();

    return 0;
}