// Question Writer: Fatih Baskın
// Question Tester(s): Murat Biberoğlu

#include <bits/stdc++.h>
using namespace std;

// FASON Tree Node
class Node
{
public:
    string word;
    vector<Node *> children;

    // Constructor for a node.
    Node(const string &str) : word(str) {}

    // Destructor for a node.
    ~Node()
    {
        for (auto child : children)
            if (child != NULL)
                delete child;
    }
};

// FASON Tree
class Tree
{
public:
    Node *root{NULL};

    // Constructor of the tree.
    Tree() : root(NULL) {}

    // Destructor of the tree.
    ~Tree()
    {
        if (root != NULL)
            delete root;
    }

    void treeFromString(const string &fasonString)
    {
        // Counter and limit working on the FASON String.
        int currentChar = 0;
        int charLimit = fasonString.size();

        // Initialize root.
        if (fasonString[currentChar] == '\\')
        {
            // Read the new word if the string starts with '\' ('\\' is used to escape backslash.)
            currentChar++;
            string word = "";
            while (currentChar < charLimit && fasonString[currentChar] != '/' && fasonString[currentChar] != '\\')
            {
                word += fasonString[currentChar];
                currentChar++;
            }
            root = new Node(word);
        }

        // We will continue constructing the tree using the currentNode and stack, starting from the root.
        // Stack is used to construct the tree easily.
        stack<Node *> nodeStack;
        Node *currentNode = root;
        nodeStack.push(root);

        // After initializing root
        while (currentChar < charLimit)
        {
            if (fasonString[currentChar] == '\\')
            {
                // Read the new word if the string starts with '\' ('\\' is used to escape backslash.)
                currentChar++;
                string word = "";
                // Read until arriving end of the string or '/'
                while (currentChar < charLimit && fasonString[currentChar] != '/' && fasonString[currentChar] != '\\')
                {
                    word += fasonString[currentChar];
                    currentChar++;
                }
                // After arriving the end of a node word, generate a node from that word.
                Node *newNode = new Node(word);
                // The word's parent would be the currentNode and newNode would be added to currentNode's children.
                currentNode->children.push_back(newNode);
                // After that, we will continue to build the subtree from the new node.
                currentNode = newNode;
                nodeStack.push(newNode);
            }
            else if (fasonString[currentChar] == '/')
            {
                // If we hit a node-closing character, we must go one step backwards.
                currentChar++;
                nodeStack.pop();
                if (nodeStack.empty())
                    break;
                currentNode = nodeStack.top();
            }
        }
    }

    void queryEvaluation(string &query)
    {
        // We will start from the root.
        Node *currentNode = root;

        // This stringstream will be used for parsing the query.
        stringstream queryStream(query);
        string word = "";

        // Confirm root first.
        getline(queryStream, word, '.');
        if (word != currentNode->word)
        {
            cout << "-1" << '\n';
            return;
        }

        // After confirming the root, get down in the tree
        while (getline(queryStream, word, '.'))
        {
            // Flag used to mark whether found or not.
            bool found = false;

            // Iterate trough the children of current node to find a match for the current word.
            for (int i = 0; i < currentNode->children.size(); i++)
            {
                if (currentNode->children[i]->word == word)
                {
                    currentNode = currentNode->children[i];
                    found = true;
                    break;
                }
            }

            // If the value in order is not found, invalid query, return immediately.
            if (!found)
            {
                cout << "-1" << '\n';
                return;
            }
        }

        // Values are the single child (single leaf) of a variable.
        if (currentNode->children.size() != 1)
            // If currentNode has more than one child.
            cout << "-1" << '\n';
        else if (currentNode->children.size() == 1 && currentNode->children[0]->children.size() != 0)
            // If the current node has one child but it is not a leaf.
            cout << "-1";
        else
            // Otherwise valid.
            cout << currentNode->children[0]->word << '\n';
    }
};

int main()
{
    // Used for fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int num_chars = 0;
    int num_queries = 0;
    cin >> num_chars >> num_queries;

    string fasonString = "";
    cin >> fasonString;

    Tree fasonTree;
    fasonTree.treeFromString(fasonString);

    for (int i = 0; i < num_queries; i++)
    {
        string query = "";
        cin >> query;
        fasonTree.queryEvaluation(query);
    }

    return 0;
}