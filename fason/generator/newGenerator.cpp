#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <stack>

using namespace std;
vector<string> wordList;

void wordListRead()
{
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
            children[i] = NULL;
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
        stack<Node *> previousNodes;
        query += currentNode->word;

        while (currentNode->children.size() != 1 || currentNode->children[0]->children.size() != 0)
        {
            int randomIndex = rand() % currentNode->children.size();
            previousNodes.push(currentNode);
            currentNode = currentNode->children[randomIndex];
            query += "." + currentNode->word;
        }
        answer = currentNode->children[0]->word;

        return make_pair(query, answer);
    }

    pair<string, string> invalidTestCaseWrongLeaf()
    {
        string query = "";
        string answer = "";

        return make_pair(query, answer);
    }
};

int main()
{
    srand(time(NULL));
    wordListRead();

    Tree tree;
    tree.recursiveAdd(tree.root, 3, 3);
    tree.treeFiller();

    cout << tree.printTree() << endl;

    map<string, string> testCases;
    while (testCases.size() < 10)
    {
        pair<string, string> testCase = tree.geniuineTestCase();
        if (testCases[testCase.first] == "")
            testCases[testCase.first] = testCase.second;
    }

    for (auto it = testCases.begin(); it != testCases.end(); it++)
        cout << it->first << " " << it->second << endl;

    return 0;
}