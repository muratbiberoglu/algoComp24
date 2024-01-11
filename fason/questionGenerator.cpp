#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <stdlib.h>
#include <time.h>

std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

class FasonNode
{
public:
    std::string getName() { return this->name; }
    void setName(std::string new_name) { this->name = new_name; }

    void addNode(FasonNode *new_node) { children_nodes.push_back(new_node); }

    std::string generateFasonString()
    {
        std::string result = "\\";
        result += this->name;
        for (auto child : children_nodes)
        {
            if (child != NULL)
                result += child->generateFasonString();
        }
        result += "/";
        return result;
    }

    FasonNode() : name{""}, children_nodes{} {}
    FasonNode(std::string node_name) : name{node_name}, children_nodes{} {}
    FasonNode(std::string node_name, std::vector<FasonNode *> children) : name{node_name}, children_nodes{children} {}

    ~FasonNode()
    {
        for (auto child : children_nodes)
            delete child;
    }

    std::string name;
    std::vector<FasonNode *> children_nodes;
};

class FasonTools
{
public:
    FasonTools(int max_length, int weight, int depth) : string_max_length{max_length}, node_generation_weight{weight}, max_depth{depth} {}

    void treeGenerator(FasonNode *tree, int current_depth)
    {
        tree->setName(generateRandomString());

        if (current_depth >= max_depth)
            return;

        while (desicionMakerNode())
            tree->addNode(new FasonNode);

        for (auto child : tree->children_nodes)
            if (child != NULL)
                treeGenerator(child, current_depth + 1);

        return;
    }
    void treeFiller(FasonNode *tree)
    {
        if (tree->children_nodes.size() == 0)
            tree->children_nodes.push_back(new FasonNode(generateRandomString()));
        else
            for (auto child : tree->children_nodes)
                if (child != NULL)
                    treeFiller(child);
    }

private:
    inline static const std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    int string_max_length;
    int node_generation_weight;
    int max_depth;

    std::string generateRandomString()
    {
        int current_length = 0;
        std::string current_string = "";

        while (desicionMakerString(current_length))
        {
            int new_letter_index = rand() % alphabet.size();
            current_length += 1;
            current_string += alphabet[new_letter_index];
        }

        return current_string;
    }

    bool desicionMakerString(int current_length)
    {
        if (current_length == 0)
            return true;

        if (current_length >= string_max_length)
            return false;

        double add_desicion_dice = (double)rand() / (double)RAND_MAX;
        double completion_ratio = (double)current_length / (double)string_max_length;
        // Can change treshold, currently quadratic, can be sigmoid or else
        double add_treshold = completion_ratio * completion_ratio;

        if (add_desicion_dice > add_treshold)
            return true;

        return false;
    }

    bool desicionMakerNode()
    {
        int current_dice = rand() % (node_generation_weight + 1);

        return !(current_dice == node_generation_weight);
    }
};

int main()
{
    srand(time(NULL));

    FasonNode *tree = new FasonNode;

    FasonTools toolkit{10, 3, 5};

    toolkit.treeGenerator(tree, 0);
    toolkit.treeFiller(tree);


    return 0;
}