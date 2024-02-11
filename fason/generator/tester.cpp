#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stack>
#include <queue>
#include <sstream>

using namespace std;

class Node
{
public:
    Node *parent;
    string word;
    vector<Node *> children;
    Node(string word)
    {
        this->word = word;
        this->parent = NULL;
    }

    void deleteNode()
    {
        for (int i = 0; i < children.size(); i++)
        {
            children[i]->deleteNode();
        }
        delete this;
    }
};

class Tree
{
public:
    Node *root;

    void addNode(Node *node)
    {
        root->children.push_back(node);
    }

    void deleteTree()
    {
        root->deleteNode();
    }
};

Node *treeFromString(string &fasonString)
{
    Node *root = new Node("");
    Node *currentNode = root;
    stack<Node *> nodeStack;
    nodeStack.push(root);

    int currentChar = 0;
    int charLimit = fasonString.size();
    // Initialize root
    if (fasonString[currentChar] == '\\')
    {
        currentChar++;
        string word = "";
        while (currentChar < charLimit && fasonString[currentChar] != '/' && fasonString[currentChar] != '\\')
        {
            word += fasonString[currentChar];
            currentChar++;
        }
        root->word = word;
    }

    // After initializing root
    while (currentChar < charLimit)
    {
        if (fasonString[currentChar] == '\\')
        {
            currentChar++;
            string word = "";
            while (currentChar < charLimit && fasonString[currentChar] != '/' && fasonString[currentChar] != '\\')
            {
                word += fasonString[currentChar];
                currentChar++;
            }
            Node *newNode = new Node(word);
            newNode->parent = currentNode;
            currentNode->children.push_back(newNode);
            currentNode = newNode;
            nodeStack.push(newNode);
        }
        else if (fasonString[currentChar] == '/')
        {
            currentChar++;
            nodeStack.pop();
            if (nodeStack.empty())
                break;
            currentNode = nodeStack.top();
        }
    }
    return root;
}

void queryEvaluation(Tree &tree, string &query)
{
    Node *currentNode = tree.root;
    stringstream queryStream(query);
    string word;

    // Confirm root first
    getline(queryStream, word, '.');
    if (word != currentNode->word)
    {
        cout << "-1" << endl;
        return;
    }

    while (getline(queryStream, word, '.'))
    {
        bool found = false;
        for (int i = 0; i < currentNode->children.size(); i++)
        {
            if (currentNode->children[i]->word == word)
            {
                currentNode = currentNode->children[i];
                found = true;
                break;
            }
        }
        if (!found)
        {
            cout << "-1" << endl;
            return;
        }
    }

    if (currentNode->children.size() != 1)
        cout << "-1" << endl;
    else
        cout << currentNode->children[0]->word << endl;
}

int main()
{
    const char *inputFileName = "../tests/input/input10.txt";

    ifstream inputFile(inputFileName, ios::in);

    int num_chars = 0;
    int num_queries = 0;

    inputFile >> num_chars >> num_queries;

    string fasonString = "";

    inputFile >> fasonString;

    vector<string> queries(num_queries);
    for (int i = 0; i < num_queries; i++)
    {
        inputFile >> queries[i];
    }

    inputFile.close();

    Tree newTree;

    newTree.root = treeFromString(fasonString);

    for (auto query : queries)
    {
        queryEvaluation(newTree, query);
    }

    return 0;
}