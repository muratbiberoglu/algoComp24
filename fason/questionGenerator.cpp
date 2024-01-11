#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <time.h>

std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};

std::string number_to_string(int number)
{
    std::stringstream ss;
    std::string str = "";

    if (number < 10)
        str = "0";

    ss << number;
    std::string str_num = "";
    ss >> str_num;
    str += str_num;
    return str;
}

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

    std::pair<std::string, std::string> query_generator(FasonNode *tree, std::string current_query)
    {
        int children_size = tree->children_nodes.size();

        current_query += tree->name;

        if (children_size == 0)
            return {current_query, invalid_message};

        int continue_desicion = rand() % (children_size + 1);

        if (continue_desicion < children_size)
        {
            current_query += ".";
            FasonNode *random_node = tree->children_nodes[continue_desicion];
            return query_generator(random_node, current_query);
        }

        std::string result = invalid_message;

        int dice = rand() % 2;
        if (dice)
        {
            current_query += ".";
            std::string rand_str = generateRandomString();

            for (auto node : tree->children_nodes)
                if (node->name == rand_str)
                    return query_generator(node, current_query);

            current_query += rand_str;
        }
        else
        {
            if (tree->children_nodes.size() == 1)
                result = tree->children_nodes[0]->name;
        }

        return {current_query, result};
    }

private:
    inline static const std::vector<char> alphabet = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    inline static const std::string invalid_message = "INVALID QUERY";

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

    std::string inputFileBaseName = "input/input";
    std::string outputFileBaseName = "output/output";

    std::vector<int> tree_depths = {2, 3, 4, 5, 6};
    std::vector<int> string_sizes = {5, 10};
    std::vector<int> tree_biases = {1, 2, 3, 4, 5, 6, 7};

    for (int iteration = 0; iteration < 35; iteration++)
    {
        std::string fasonString = "";
        int fasonSize = 0;

        int tree_bias = tree_biases[iteration % tree_biases.size()];
        int tree_depth = tree_depths[iteration % tree_depths.size()];
        int num_queries = tree_depth * tree_bias * 4;
        int max_str_len = string_sizes[iteration % string_sizes.size()];

        FasonTools toolkit{max_str_len, tree_bias, tree_depth};

        FasonNode *tree = new FasonNode;

        toolkit.treeGenerator(tree, 0);
        toolkit.treeFiller(tree);

        fasonString = tree->generateFasonString();
        fasonSize = fasonString.size();

        std::vector<std::pair<std::string, std::string>> queries;

        for (int query_iteration = 0; query_iteration < num_queries; query_iteration++)
            queries.push_back(toolkit.query_generator(tree, ""));

        std::string file_name = inputFileBaseName + number_to_string(iteration) + ".txt";

        FILE *file = freopen(file_name.c_str(), "w", stdout);

        std::cout << fasonSize << " " << num_queries << "\n";
        std::cout << fasonString << "\n";
        for (auto query : queries)
            std::cout << query.first << "\n";

        fclose(file);

        file_name = outputFileBaseName + number_to_string(iteration) + ".txt";

        file = freopen(file_name.c_str(), "w", stdout);

        for (auto query : queries)
            std::cout << query.second << "\n";

        fclose(file);

        delete tree;
    }

    return 0;
}