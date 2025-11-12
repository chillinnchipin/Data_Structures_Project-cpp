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

    // Methods
    /**
     * @brief Adds a child node to the current node
     * @param child A pointer to the child node to be added
     */
    void add_child(std::unique_ptr<Basic_Node<T>> child)
    {
        children.push_back(std::move(child));
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
};
