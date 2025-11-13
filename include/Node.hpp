template <typename T>
class Basic_Node
{
protected:
    /// @brief The data stored in the node
    T data;

public:
    // Constructors
    /**
     * @brief Default constructor that initializes the node with default value of T
     */
    Basic_Node() : data() {}
    /**
     * @brief Parameterized constructor that initializes the node with the provided value
     * @param value The value to initialize the node with
     */
    Basic_Node(const T& value) : data(value) {}

    // Methods

    /**
     * @brief Returns the data stored in the node
     * @return The data stored in the node
     */
    T data() const
    {
        return data;
    }

    /**
     * @brief Sets the data stored in the node to the provided value
     * @param value The value to set the data to
     */
    void set(const T& value)
    {
        data = value;
    }

    //Operators

    /**
     * @brief Assigns a value to the data stored in this node
     * @param value The value to assign to the data
     * @return A reference to this node after assignment
     */
    Basic_Node& operator=(const T& value)
    {
        set(value);
        return *this;
    }

    /**
     * @brief Compare the data stored in a node with the data stored in the other node
     * @param other The other node to compare with
     * @return True if the nodes' data are equal, false otherwise
     */
    bool operator==(const Basic_Node& other) const
    {
        return data == other.data;
    }

    /**
     * @brief Compare the data stored in a node with the data stored in the other node for inequality
     * @param other The other node to compare with
     * @return True if the nodes' data are not equal, false otherwise
     */
    bool operator!=(const Basic_Node& other) const
    {
        return data != other.data;
    }
};

template <typename T>
class Linear_Node : public Basic_Node<T>
{
protected:
    /// @brief Pointer to the next node in the linked list
    std::unique_ptr<Linear_Node<T>> next;
    /// @brief Pointer to the previous node in the linked list
    std::unique_ptr<Linear_Node<T>> prev;

public:
    // Constructors
    /**
     * @brief Default constructor that initializes the node with default value of T
     */
    Linear_Node() : Basic_Node<T>(), next(nullptr), prev(nullptr) {}
    /**
     * @brief Parameterized constructor that initializes the node with the provided value
     * @param value The value to initialize the node with
     */
    Linear_Node(const T& value) : Basic_Node<T>(value), next(nullptr), prev(nullptr) {}

    // Methods
    /**
     * @brief Returns a pointer to the next node in the linked list
     * @return A pointer to the next node in the linked list or null if there is no next node
     */
    std::unique_ptr<Basic_Node<T>>& next()
    {
        return next;
    }
    /**
     * @brief Returns a pointer to the previous node in the linked list
     * @return A pointer to the previous node in the linked list or null if there is no previous node
     */
    std::unique_ptr<Basic_Node<T>>& prev()
    {
        return prev;
    }
    /**
     * @brief Sets the next node pointer to the provided node
     * @param next A pointer to the next node in the linked list
     */
    void set_next(std::unique_ptr<Basic_Node<T>>&& next)
    {
        this->next = std::move(next);
    }
    /**
     * @brief Sets the previous node pointer to the provided node
     * @param prev A pointer to the previous node in the linked list
     */
    void set_prev(std::unique_ptr<Basic_Node<T>>&& prev)
    {
        this->prev = std::move(prev);
    }
};

template <typename T>
class Priority_Node : public Basic_Node<T>
{
protected:
    /// @brief The priority of the node, used to determine the order in which nodes are dequeued
    int priority;

public:
    // Constructors
    /**
     * @brief Default constructor that initializes the node with default value of T
     */
    Priority_Node() : Basic_Node<T>(), priority(0) {}
    /**
     * @brief Parameterized constructor that initializes the node with the provided value and priority
     * @param value The value to initialize the node with
     */
    Priority_Node(const T& value) : Basic_Node<T>(value), priority(0) {}
    /**
     * @brief Parameterized constructor that initializes the node with the provided value and priority
     * @param value The value to initialize the node with
     * @param priority The priority of the node
     */
    Priority_Node(const T& value, int priority) : Basic_Node<T>(value), priority(priority) {}

    // Methods
    /**
     * @brief Returns the priority of the node
     * @return The priority of the node
     */
    int priority() const
    {
        return priority;
    }

    /**
     * @brief Sets the priority of the node to the provided value
     * @param priority The value to set the priority to
     */
    void set_priority(int priority)
    {
        this->priority = priority;
    }

    // Operators
    /**
     * @brief Compare the priority of this node with the priority of the other node for less than
     * @param other The other node to compare with
     * @return True if this node's priority is less than the other node's priority, false otherwise
     */
    bool operator<(const Priority_Node& other) const
    {
        return priority < other.priority;
    }
    /**
     * @brief Compare the priority of this node with the priority of the other node for greater than
     * @param other The other node to compare with
     * @return True if this node's priority is greater than the other node's priority, false otherwise
     */
    bool operator>(const Priority_Node& other) const
    {
        return priority > other.priority;
    }
    /**
     * @brief Compare the priority of this node with the priority of the other node for less than or equal to
     * @param other The other node to compare with
     * @return True if this node's priority is less than or equal to the other node's priority, false otherwise
     */
    bool operator<=(const Priority_Node& other) const
    {
        return priority <= other.priority;
    }
    /**
     * @brief Compare the priority of this node with the priority of the other node for greater than or equal to
     * @param other The other node to compare with
     * @return True if this node's priority is greater than or equal to the other node's priority, false otherwise
     */
    bool operator>=(const Priority_Node& other) const
    {
        return priority >= other.priority;
    }
    /**
     * @brief Compare the priority of this node with the priority of the other node for equality
     * @param other The other node to compare with
     * @return True if this node's priority is equal to the other node's priority, false otherwise
     */
    bool operator==(const Priority_Node& other) const
    {
        return priority == other.priority;
    }
    /**
     * @brief Compare the priority of this node with the priority of the other node for inequality
     * @param other The other node to compare with
     * @return True if this node's priority is not equal to the other node's priority, false otherwise
     */
    bool operator!=(const Priority_Node& other) const
    {
        return priority != other.priority;
    }
};

template <typename T>
class N_Tree_Node : public Basic_Node<T>
{
    protected:
    // Attributes

    /// @brief A list of pointers to child nodes in the tree
    std::vector<std::unique_ptr<Basic_Node<T>>> children;

    /// @brief the number of children nodes this node has
    size_t size;

    public:
    // Constructors
    /**
     * @brief Default constructor that initializes the node with default value of T
     */
    N_Tree_Node() : Basic_Node<T>(), children() {}
    /**
     * @brief Parameterized constructor that initializes the node with the provided value
     * @param value The value to initialize the node with
     */
    N_Tree_Node(const T& value) : Basic_Node<T>(value), children() {}
    /**
     * @brief Parameterized constructor that initializes the node with the provided value and children
     * @param value The value to initialize the node with
     * @param children A list of pointers to child nodes in the tree
     */
    N_Tree_Node(const T& value, const std::vector<std::unique_ptr<Basic_Node<T>>>& children)
        : Basic_Node<T>(value), children(children), size(children.size()) {}

    // Methods
    /**
     * @brief Adds a child node to the current node
     * @param child A pointer to the child node to be added
     */
    void add_child(std::unique_ptr<Basic_Node<T>> child)
    {
        children.push_back(std::move(child));
        size++;
    }

    /**
     * @brief Removes a child node from the current node at the specified index
     * @param index The index of the child node to be removed
     * @note If the index is out of bounds, throws an error
     */
    void remove_child(size_t index)
    {
        if (index < children.size())
        {
            children.erase(children.begin() + index);
            size--;
        } else {
            throw std::out_of_range("Index out of bounds");
        }
    }

    /**
     * @brief Removes a child node from the current node
     * @param child A pointer to the child node to be removed
     */
    void remove_child(std::unique_ptr<Basic_Node<T>>& child)
    {
        auto found = std::find_if(children.begin(), children.end(),
            [&child](const std::unique_ptr<Basic_Node<T>>& current) { return current.get() == child.get(); });
        if (found != children.end())
        {
            children.erase(found);
            size--;
        }
    }

    /**
     * @brief Returns a list of pointers to child nodes
     * @return A list of pointers to child nodes in the tree
     */
    std::vector<std::unique_ptr<Basic_Node<T>>>& get_children()
    {
        return children;
    }

    /**
     * @brief Returns the number of children nodes this node has
     * @return The number of children nodes
     */
    size_t size() const
    {
        return size;
    }
};

template <typename T>
class Binary_Tree_Node : public N_Tree_Node<T>
{
protected:
    /// @brief Pointer to the left child node in the binary tree
    std::unique_ptr<Basic_Node<T>> left;
    /// @brief Pointer to the right child node in the binary tree
    std::unique_ptr<Basic_Node<T>> right;
    /// @brief The maximum number of children for a binary tree node (2)
    static const size_t MAX_CHILDREN = 2;
public:
    // Constructors
    /**
     * @brief Default constructor that initializes the node with default value of T
     */
    Binary_Tree_Node() : N_Tree_Node<T>() {}
    /**
     * @brief Parameterized constructor that initializes the node with the provided value
     * @param value The value to initialize the node with
     */
    Binary_Tree_Node(const T& value) : N_Tree_Node<T>(value) {}

    // Methods
    /**
     * @brief Returns a pointer to the left child node
     * @return A pointer to the left child node or null if there is no left child
     */
    std::unique_ptr<Basic_Node<T>> left() const
    {
        return left;
    }

    /**
     * @brief Returns a pointer to the right child node
     * @return A pointer to the right child node or null if there is no right child
     */
    std::unique_ptr<Basic_Node<T>> right() const
    {
        return right;
    }

    /**
     * @brief Sets the left child node to the provided node
     * @param left A pointer to the left child node
     */
    void set_left(std::unique_ptr<Basic_Node<T>> left)
    {
        if (this->left == nullptr) size++;
        this->left = std::move(left);
        children.at(0) = std::move(this->left);
    }

    /**
     * @brief Sets the right child node to the provided node
     * @param right A pointer to the right child node
     */
    void set_right(std::unique_ptr<Basic_Node<T>> right)
    {
        if (this->right == nullptr) size++;
        this->right = std::move(right);
        children.at(1) = std::move(this->right);
    }

    /**
     * @brief Overrides the add_child method to ensure only two children can be added
     * @param child A pointer to the child node to be added
     * @note If more than two children are added, throws an error
     */
    void add_child(std::unique_ptr<Basic_Node<T>> child) override
    {
        if (size >= MAX_CHILDREN)
        {
            throw std::runtime_error("Cannot add more than two children to a binary tree node");
        }
        if (left == nullptr)
        {
            set_left(std::move(child));
        }
        else
        {
            set_right(std::move(child));
        }
        size++;
    }
};

template <typename T>
class Balanced_Tree_Node : public Binary_Tree_Node<T>
{
protected:
    /// @brief The height of the node in the balanced tree, the number of edges on the longest path from the node to a leaf, used for balancing purposes
    size_t height;
    /// @brief The balance factor of the node, used for balancing purposes. Negative values indicate a left-heavy tree, positive values indicate a right-heavy tree, and zero indicates a balanced tree
    int balance_factor;

public:
    // Constructors
    /**
     * @brief Default constructor that initializes the node with default value of T
     */
    Balanced_Tree_Node() : Binary_Tree_Node<T>(), height(0), balance_factor(0) {}
    /**
     * @brief Parameterized constructor that initializes the node with the provided value
     * @param value The value to initialize the node with
     */
    Balanced_Tree_Node(const T& value) : Binary_Tree_Node<T>(value), height(0), balance_factor(0) {}

    // Methods
    /**
     * @brief Returns the height of the node
     * @return The height of the node
     */
    size_t height() const
    {
        return height;
    }

    /**
     * @brief Sets the height of the node to the provided value
     * @param height The value to set the height to
     */
    void set_height(size_t height)
    {
        this->height = height;
    }

    /**
     * @brief Returns the balance factor of the node
     * @return The balance factor of the node
     */
    int balance_factor() const
    {
        return balance_factor;
    }

    /**
     * @brief Sets the balance factor of the node to the provided value
     * @param balance_factor The value to set the balance factor to
     */
    void set_balance_factor(int balance_factor)
    {
        this->balance_factor = balance_factor;
    }

protected:
    /**
     * @brief Checks the balance of the node and updates the height and balance factor accordingly
     * @note This method is typically called after modifying the tree structure to ensure that the node remains balanced
     */
    void check_balance();

    /**
     * @brief Rebalances the node if it is unbalanced, adjusting pointers to maintain the properties of the balanced tree
     * @note This method is called if check_balance() detects an imbalance
     */
    void rebalance();

    /**
     * @brief Performs a left rotation on the node to balance the tree.
     * @return A pointer to the new root of the subtree after the left rotation.
     */
    std::unique_ptr<Balanced_Tree_Node<T>> left_rotate();

    /**
     * @brief Performs a right rotation on the node to balance the tree
     * @return A pointer to the new root of the subtree after the right rotation
     */
    std::unique_ptr<Balanced_Tree_Node<T>> right_rotate();

    /**
     * @brief Checks the height of the node and updates it based on the heights of its children
     */
    void check_height();
};
