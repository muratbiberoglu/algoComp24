#include <bits/stdc++.h>
using namespace std;

template <typename T>
class OrderStatisticsNode
{
private:
    T data;
    int order_statistic;
    OrderStatisticsNode<T> *left;
    OrderStatisticsNode<T> *right;
    OrderStatisticsNode<T> *parent;

public:
    OrderStatisticsNode(T data);

    T &get_data();
    int get_order_statistic() const;
    OrderStatisticsNode<T> *get_left() const;
    OrderStatisticsNode<T> *get_right() const;
    OrderStatisticsNode<T> *get_parent() const;

    void set_data(T);
    void set_order_statistic(int);
    void set_left(OrderStatisticsNode<T> *);
    void set_right(OrderStatisticsNode<T> *);
    void set_parent(OrderStatisticsNode<T> *);
};

template <typename T>
class OrderStatisticsBST
{
private:
    OrderStatisticsNode<T> *root;

    void update_order_statistic(OrderStatisticsNode<T> *);
    OrderStatisticsNode<T> *get_minimum_helper(OrderStatisticsNode<T> *);

    void remove_helper(OrderStatisticsNode<T> *);

public:
    OrderStatisticsBST<T>();
    ~OrderStatisticsBST<T>();

    void insert(const T &);
    OrderStatisticsNode<T> *get_by_rank(int);
    OrderStatisticsNode<T> *get_by_value(const T &);

    OrderStatisticsNode<T> *get_root();
    void remove_by_rank(int);
    void remove_by_value(const T &);
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // FILE *file = freopen("testcase.txt", "r", stdin);

    int n = 0;
    int p = 0;
    int q = 0;
    cin >> n >> p >> q;
    vector<vector<int>> db(n, vector<int>(p));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            cin >> db[i][j];
        }
    }

    vector<OrderStatisticsBST<pair<int, int>>> indexes(p);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < p; j++)
        {
            indexes[j].insert({db[i][j], i});
        }
    }

    for (int qt = 0; qt < q; qt++)
    {
        int t;
        cin >> t;
        switch (t)
        {
        case 1:
        {
            int a = 0;
            int b = 0;
            int c = 0;
            int d = 0;
            cin >> a >> b >> c >> d;
            a--;
            c--;
            OrderStatisticsNode<pair<int, int>> *node = indexes[a].get_by_rank(b);
            int table_index = node->get_data().second;
            pair<int, int> to_be_removed = {db[table_index][c], table_index};
            indexes[c].remove_by_value(to_be_removed);

            db[table_index][c] += d;
            indexes[c].insert({db[table_index][c], table_index});

            /*
            fstream verbose;
            verbose.open("verbose.txt", ios::out | ios::app);
            OrderStatisticsNode<pair<int, int>> *node2 = indexes[c].get_root();
            queue<OrderStatisticsNode<pair<int, int>> *> nodes;
            nodes.push(node2);
            while (!nodes.empty())
            {
                OrderStatisticsNode<pair<int, int>> *current = nodes.front();
                nodes.pop();
                verbose << "{" << current->get_data().first << ", " << current->get_data().second << "} " << current->get_order_statistic();
                if (current->get_left() != nullptr)
                {
                    nodes.push(current->get_left());
                    verbose << " left: {" << current->get_left()->get_data().first << ", " << current->get_left()->get_data().second << "} ";
                }

                if (current->get_right() != nullptr)
                {
                    nodes.push(current->get_right());
                    verbose << " right: {" << current->get_right()->get_data().first << ", " << current->get_right()->get_data().second << "} ";
                }
                verbose << "\n";
            }
            verbose << "-------------------\n";
            verbose.close();
            */
            break;
        }
        case 2:
        {
            int a = 0;
            int b = 0;
            int c = 0;
            cin >> a >> b >> c;
            a--;
            c--;
            OrderStatisticsNode<pair<int, int>> *node = indexes[a].get_by_rank(b);
            auto table_index = node->get_data().second;
            cout << db[table_index][c] << endl;
            break;
        }
        }
    }

    // fclose(file);
    return 0;
}

template <typename T>
OrderStatisticsNode<T>::OrderStatisticsNode(T data) : data(data), order_statistic(1), left(nullptr), right(nullptr), parent(nullptr) {}

template <typename T>
T &OrderStatisticsNode<T>::get_data() { return data; }

template <typename T>
int OrderStatisticsNode<T>::get_order_statistic() const { return order_statistic; }

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsNode<T>::get_left() const { return left; }

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsNode<T>::get_right() const { return right; }

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsNode<T>::get_parent() const { return parent; }

template <typename T>
void OrderStatisticsNode<T>::set_data(T data) { this->data = data; }

template <typename T>
void OrderStatisticsNode<T>::set_order_statistic(int order_statistic) { this->order_statistic = order_statistic; }

template <typename T>
void OrderStatisticsNode<T>::set_left(OrderStatisticsNode<T> *left) { this->left = left; }

template <typename T>
void OrderStatisticsNode<T>::set_right(OrderStatisticsNode<T> *right) { this->right = right; }

template <typename T>
void OrderStatisticsNode<T>::set_parent(OrderStatisticsNode<T> *parent) { this->parent = parent; }

template <typename T>
OrderStatisticsBST<T>::OrderStatisticsBST()
{
    root = nullptr;
}

template <typename T>
OrderStatisticsBST<T>::~OrderStatisticsBST()
{
    std::queue<OrderStatisticsNode<T> *> nodes;
    nodes.push(root);

    while (!nodes.empty())
    {
        OrderStatisticsNode<T> *current = nodes.front();
        nodes.pop();

        if (current->get_left() != nullptr)
            nodes.push(current->get_left());
        if (current->get_right() != nullptr)
            nodes.push(current->get_right());

        delete current;
    }
}

template <typename T>
void OrderStatisticsBST<T>::insert(const T &data)
{
    OrderStatisticsNode<T> *new_node = new OrderStatisticsNode<T>(data);

    if (root == nullptr)
    {
        root = new_node;
        return;
    }

    OrderStatisticsNode<T> *traversal_parent = root;
    while (traversal_parent != nullptr)
    {
        if (data < traversal_parent->get_data())
        {
            if (traversal_parent->get_left() == nullptr)
            {
                traversal_parent->set_left(new_node);
                new_node->set_parent(traversal_parent);
                update_order_statistic(traversal_parent);
                break;
            }
            else
            {
                traversal_parent = traversal_parent->get_left();
            }
        }
        else
        {
            if (traversal_parent->get_right() == nullptr)
            {
                traversal_parent->set_right(new_node);
                new_node->set_parent(traversal_parent);
                update_order_statistic(traversal_parent);
                break;
            }
            else
            {
                traversal_parent = traversal_parent->get_right();
            }
        }
    }
}

template <typename T>
void OrderStatisticsBST<T>::update_order_statistic(OrderStatisticsNode<T> *node)
{
    while (node != nullptr)
    {
        int left_order_statistic = 0;
        if (node->get_left() != nullptr)
        {
            left_order_statistic = node->get_left()->get_order_statistic();
        }

        int right_order_statistic = 0;
        if (node->get_right() != nullptr)
        {
            right_order_statistic = node->get_right()->get_order_statistic();
        }

        node->set_order_statistic(left_order_statistic + right_order_statistic + 1);
        node = node->get_parent();
    }
}

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsBST<T>::get_by_rank(int rank)
{
    // Throw exception?
    if (rank < 1)
        return nullptr;

    OrderStatisticsNode<T> *traversal_node = root;
    while (traversal_node != nullptr)
    {
        int current_rank = 1;
        if (traversal_node->get_left() != nullptr)
        {
            current_rank += traversal_node->get_left()->get_order_statistic();
        }

        if (current_rank == rank)
        {
            return traversal_node;
        }
        else if (current_rank < rank)
        {
            traversal_node = traversal_node->get_right();
            rank -= current_rank;
        }
        else
        {
            traversal_node = traversal_node->get_left();
        }
    }

    return nullptr;
}

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsBST<T>::get_root() { return root; }

template <typename T>
void OrderStatisticsBST<T>::remove_by_rank(int rank)
{
    OrderStatisticsNode<T> *currentNode = get_by_rank(rank);
    remove_helper(currentNode);
}

template <typename T>
void OrderStatisticsBST<T>::remove_by_value(const T &value)
{
    OrderStatisticsNode<T> *currentNode = get_by_value(value);
    remove_helper(currentNode);
}

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsBST<T>::get_by_value(const T &value)
{
    OrderStatisticsNode<T> *traversal_node = root;
    while (traversal_node != nullptr)
    {
        if (traversal_node->get_data() == value)
        {
            return traversal_node;
        }
        else if (value < traversal_node->get_data())
        {
            traversal_node = traversal_node->get_left();
        }
        else
        {
            traversal_node = traversal_node->get_right();
        }
    }

    return nullptr;
}

template <typename T>
void OrderStatisticsBST<T>::remove_helper(OrderStatisticsNode<T> *currentNode)
{
    if (currentNode == nullptr)
        return;

    OrderStatisticsNode<T> *parent = currentNode->get_parent();
    OrderStatisticsNode<T> *left = currentNode->get_left();
    OrderStatisticsNode<T> *right = currentNode->get_right();

    // If current node is a leaf node
    if (left == nullptr && right == nullptr)
    {
        // Check if the current node is root
        if (parent == nullptr)
            // In this case set root null
            root = nullptr;

        // Otherwise set the parent's child null accordingly
        else if (parent->get_right() == currentNode)
            parent->set_right(nullptr);
        else
            parent->set_left(nullptr);

        delete currentNode;
        // Update the order statistic of the parent
        update_order_statistic(parent);
        return;
    }

    // If the right is null, then set left as the current node
    if (right == nullptr)
    {
        // Check if the current node is leaf node
        if (parent == nullptr)
            // Set root accordingly if the parent is the root
            root = currentNode->get_left();

        else if (parent->get_right() == currentNode)
            parent->set_right(left);
        else
            parent->set_left(left);

        // Update the parent of left node
        // If parent is null it will still be null
        left->set_parent(parent);
        update_order_statistic(parent);

        delete currentNode;
        return;
    }

    // Otherwise, set the right node as current node
    if (parent == NULL)
        root = right;
    else if (parent->get_right() == currentNode)
        parent->set_right(right);
    else
        parent->set_left(right);

    // Update the parent of right node
    right->set_parent(parent);

    update_order_statistic(parent);

    // Then add left subtree to leftmost of right subtree
    OrderStatisticsNode<T> *leftmost = get_minimum_helper(right);
    leftmost->set_left(left);

    // Update the parent of leftnode
    if (left != NULL)
        left->set_parent(leftmost);

    // Update the order statistic of the parent
    update_order_statistic(leftmost);

    delete currentNode;
}

template <typename T>
OrderStatisticsNode<T> *OrderStatisticsBST<T>::get_minimum_helper(OrderStatisticsNode<T> *node)
{
    if (node == nullptr)
        return nullptr;

    while (node->get_left() != nullptr)
    {
        node = node->get_left();
    }
    return node;
}
