#pragma once
#include <memory>
#include <vector>
#include <algorithm>
using namespace std;

namespace node
{
    template <typename T>
    class Basic_Node
    {
    protected:
        /// @brief The data stored in the node
        T m_data;

    public:
        // Constructors
        /**
         * @brief Default constructor that initializes the node with default value of T
         */
        Basic_Node() : m_data() {}
        /**
         * @brief Parameterized constructor that initializes the node with the provided value
         * @param value The value to initialize the node with
         */
        Basic_Node(const T &value) : m_data(value) {}

        // Methods

        /**
         * @brief Returns the data stored in the node
         * @return The data stored in the node
         */
        T data() const
        {
            return m_data;
        }

        /**
         * @brief Sets the data stored in the node to the provided value
         * @param value The value to set the data to
         */
        void set(const T &value)
        {
            m_data = value;
        }

        // Operators

        /**
         * @brief Assigns a value to the data stored in this node
         * @param value The value to assign to the data
         * @return A reference to this node after assignment
         */
        Basic_Node &operator=(const T &value)
        {
            set(value);
            return *this;
        }

        /**
         * @brief Compare the data stored in a node with the data stored in the other node
         * @param other The other node to compare with
         * @return True if the nodes' data are equal, false otherwise
         */
        bool operator==(const Basic_Node &other) const
        {
            return m_data == other.data();
        }

        /**
         * @brief Compare the data stored in a node with the data stored in the other node for inequality
         * @param other The other node to compare with
         * @return True if the nodes' data are not equal, false otherwise
         */
        bool operator!=(const Basic_Node &other) const
        {
            return m_data != other.data;
        }
    };

    template <typename T>
    class Linear_Node : public Basic_Node<T>
    {
    protected:
        /// @brief Pointer to the next node in the linked list
        std::unique_ptr<Linear_Node<T>> m_next;
        /// @brief Pointer to the previous node in the linked list
        std::unique_ptr<Linear_Node<T>> m_prev;

    public:
        // Constructors
        /**
         * @brief Default constructor that initializes the node with default value of T
         */
        Linear_Node() : Basic_Node<T>(), m_next(nullptr), m_prev(nullptr) {}
        /**
         * @brief Parameterized constructor that initializes the node with the provided value
         * @param value The value to initialize the node with
         */
        Linear_Node(const T &value) : Basic_Node<T>(value), m_next(nullptr), m_prev(nullptr) {}

        // Methods
        /**
         * @brief Returns a pointer to the next node in the linked list
         * @return A pointer to the next node in the linked list or null if there is no next node
         */
        std::unique_ptr<Basic_Node<T>> &next()
        {
            return m_next;
        }
        /**
         * @brief Returns a pointer to the previous node in the linked list
         * @return A pointer to the previous node in the linked list or null if there is no previous node
         */
        std::unique_ptr<Basic_Node<T>> &prev()
        {
            return m_prev;
        }
        /**
         * @brief Sets the next node pointer to the provided node
         * @param next A pointer to the next node in the linked list
         */
        void set_next(std::unique_ptr<Basic_Node<T>> &&next)
        {
            this->m_next = std::move(next);
        }
        /**
         * @brief Sets the previous node pointer to the provided node
         * @param prev A pointer to the previous node in the linked list
         */
        void set_prev(std::unique_ptr<Basic_Node<T>> &&prev)
        {
            this->m_prev = std::move(prev);
        }
    };

    template <typename T>
    class Priority_Node : public Basic_Node<T>
    {
    protected:
        /// @brief The priority of the node, used to determine the order in which nodes are dequeued
        int m_priority;

    public:
        // Constructors
        /**
         * @brief Default constructor that initializes the node with default value of T
         */
        Priority_Node() : Basic_Node<T>(), m_priority(0) {}
        /**
         * @brief Parameterized constructor that initializes the node with the provided value and priority
         * @param value The value to initialize the node with
         */
        Priority_Node(const T &value) : Basic_Node<T>(value), m_priority(0) {}
        /**
         * @brief Parameterized constructor that initializes the node with the provided value and priority
         * @param value The value to initialize the node with
         * @param priority The priority of the node
         */
        Priority_Node(const T &value, int priority) : Basic_Node<T>(value), m_priority(priority) {}

        // Methods
        /**
         * @brief Returns the priority of the node
         * @return The priority of the node
         */
        int priority() const
        {
            return m_priority;
        }

        /**
         * @brief Sets the priority of the node to the provided value
         * @param priority The value to set the priority to
         */
        void set_priority(int priority)
        {
            this->m_priority = priority;
        }

        // Operators
        /**
         * @brief Compare the priority of this node with the priority of the other node for less than
         * @param other The other node to compare with
         * @return True if this node's priority is less than the other node's priority, false otherwise
         */
        bool operator<(const Priority_Node &other) const
        {
            return m_priority < other.priority();
        }
        /**
         * @brief Compare the priority of this node with the priority of the other node for greater than
         * @param other The other node to compare with
         * @return True if this node's priority is greater than the other node's priority, false otherwise
         */
        bool operator>(const Priority_Node &other) const
        {
            return m_priority > other.priority();
        }
        /**
         * @brief Compare the priority of this node with the priority of the other node for less than or equal to
         * @param other The other node to compare with
         * @return True if this node's priority is less than or equal to the other node's priority, false otherwise
         */
        bool operator<=(const Priority_Node &other) const
        {
            return m_priority <= other.priority();
        }
        /**
         * @brief Compare the priority of this node with the priority of the other node for greater than or equal to
         * @param other The other node to compare with
         * @return True if this node's priority is greater than or equal to the other node's priority, false otherwise
         */
        bool operator>=(const Priority_Node &other) const
        {
            return m_priority >= other.priority();
        }
        /**
         * @brief Compare the priority of this node with the priority of the other node for equality
         * @param other The other node to compare with
         * @return True if this node's priority is equal to the other node's priority, false otherwise
         */
        bool operator==(const Priority_Node &other) const
        {
            return m_priority == other.priority();
        }
        /**
         * @brief Compare the priority of this node with the priority of the other node for inequality
         * @param other The other node to compare with
         * @return True if this node's priority is not equal to the other node's priority, false otherwise
         */
        bool operator!=(const Priority_Node &other) const
        {
            return m_priority != other.priority();
        }
    };

    template <typename T>
    class N_Tree_Node : public Basic_Node<T>
    {
    protected:
        // Attributes

        /// @brief A list of pointers to child nodes in the tree
        std::vector<std::unique_ptr<Basic_Node<T>>> m_children;
        std::unique_ptr<Basic_Node<T>> m_parent;

        /// @brief the number of children nodes this node has
        size_t m_size;

    public:
        // Constructors
        /**
         * @brief Default constructor that initializes the node with default value of T
         */
        N_Tree_Node() : Basic_Node<T>(), m_children() {}
        /**
         * @brief Parameterized constructor that initializes the node with the provided value
         * @param value The value to initialize the node with
         */
        N_Tree_Node(const T &value) : Basic_Node<T>(value), m_children() {}
        /**
         * @brief Parameterized constructor that initializes the node with the provided value and children
         * @param value The value to initialize the node with
         * @param children A list of pointers to child nodes in the tree
         */
        N_Tree_Node(const T &value, const std::vector<std::unique_ptr<Basic_Node<T>>> &children)
            : Basic_Node<T>(value), m_children(children), m_size(children.size()) {}

        // Methods
        /**
         * @brief Adds a child node to the current node
         * @param child A pointer to the child node to be added
         */
        void add_child(std::unique_ptr<Basic_Node<T>> child)
        {
            m_children.push_back(std::move(child));
            m_size++;
        }

        /**
         * @brief Sets the parent node of the current node
         * @param parent A pointer to the parent node to be added
         */
        void set_parent(std::unique_ptr<Basic_Node<T>> parent)
        {
            this->m_parent = std::move(parent);
        }

        /**
         * @brief Removes a child node from the current node at the specified index
         * @param index The index of the child node to be removed
         * @note If the index is out of bounds, throws an error
         */
        void remove_child(size_t index)
        {
            if (index < m_children.size())
            {
                m_children.erase(m_children.begin() + index);
                m_size--;
            }
            else
            {
                throw std::out_of_range("Index out of bounds");
            }
        }

        /**
         * @brief Removes a child node from the current node
         * @param child A pointer to the child node to be removed
         */
        void remove_child(std::unique_ptr<Basic_Node<T>> &child)
        {
            auto found = std::find_if(m_children.begin(), m_children.end(),
                                      [&child](const std::unique_ptr<Basic_Node<T>> &current)
                                      { return current.get() == child.get(); });
            if (found != m_children.end())
            {
                m_children.erase(found);
                m_size--;
            }
        }

        /**
         * @brief Removes the parent node from the current node
         * @note This method sets the parent pointer to null, effectively removing the parent-child relationship
         */
        void remove_parent()
        {
            m_parent = nullptr;
            // m_parent.reset();
        }

        /**
         * @brief Returns a list of pointers to child nodes
         * @return A list of pointers to child nodes in the tree
         */
        std::vector<std::unique_ptr<Basic_Node<T>>> &children()
        {
            return m_children;
        }

        /**
         * @brief Returns a pointer to the parent node
         * @return A pointer to the parent node or null if there is no parent
         */
        std::unique_ptr<Basic_Node<T>> &parent()
        {
            return m_parent;
        }

        /**
         * @brief Returns the number of children nodes this node has
         * @return The number of children nodes
         */
        size_t size() const
        {
            return m_size;
        }
    };

    template <typename T>
    class Binary_Tree_Node : public Basic_Node<T>
    {
    protected:
        /// @brief Pointer to the left child node in the binary tree
        std::unique_ptr<Basic_Node<T>> m_left;
        /// @brief Pointer to the right child node in the binary tree
        std::unique_ptr<Basic_Node<T>> m_right;
        /// @brief Pointer to the parent node in the binary tree
        std::unique_ptr<Basic_Node<T>> m_parent;

    public:
        /// @brief The maximum number of children for a binary tree node (2)
        static const size_t MAX_CHILDREN = 2;

        // Constructors
        /**
         * @brief Default constructor that initializes the node with default value of T
         */
        Binary_Tree_Node() : Basic_Node<T>() {}
        /**
         * @brief Parameterized constructor that initializes the node with the provided value
         * @param value The value to initialize the node with
         */
        Binary_Tree_Node(const T &value) : Basic_Node<T>(value) {}

        // Methods
        /**
         * @brief Returns a pointer to the left child node
         * @return A pointer to the left child node or null if there is no left child
         */
        std::unique_ptr<Basic_Node<T>> left() const
        {
            return m_left;
        }

        /**
         * @brief Returns a pointer to the right child node
         * @return A pointer to the right child node or null if there is no right child
         */
        std::unique_ptr<Basic_Node<T>> right() const
        {
            return m_right;
        }

        /**
         * @brief Returns a pointer to the parent node
         * @return A pointer to the parent node or null if there is no parent
         */
        std::unique_ptr<Basic_Node<T>> parent() const
        {
            return m_parent;
        }

        /**
         * @brief Sets the left child node to the provided node
         * @param left A pointer to the left child node
         */
        void set_left(std::unique_ptr<Basic_Node<T>> left)
        {
            this->m_left = std::move(left);
        }

        /**
         * @brief Sets the right child node to the provided node
         * @param right A pointer to the right child node
         */
        void set_right(std::unique_ptr<Basic_Node<T>> right)
        {
            this->m_right = std::move(right);
        }

        /**
         * @brief Overrides the add_child method to ensure only two children can be added
         * @param child A pointer to the child node to be added
         * @note If more than two children are added, throws an error
         */
        void add_child(std::unique_ptr<Basic_Node<T>> child)
        {
            if (m_left == nullptr)
            {
                set_left(std::move(child));
            }
            else if (m_right == nullptr)
            {
                set_right(std::move(child));
            }
            else
            {
                throw std::runtime_error("Cannot add more than two children to a binary tree node");
            }
        }

        /**
         * @brief Removes the left node in the tree and sets the left node pointer to null
         */
        void remove_left()
        {

            if (m_left != nullptr)
            {
                m_left.reset();
            }
        }

        /**
         * @brief Removes the right node in the tree and sets the right node pointer to null
         */
        void remove_right()
        {
            if (m_right != nullptr)
            {
                m_right.reset();
            }
        }
    };

    template <typename T>
    class Balanced_Tree_Node : public Binary_Tree_Node<T>
    {
    protected:
        /// @brief The height of the node in the balanced tree, the number of edges on the longest path from the node to a leaf, used for balancing purposes
        size_t m_height;
        /// @brief The balance factor of the node, used for balancing purposes. Negative values indicate a left-heavy tree, positive values indicate a right-heavy tree, and zero indicates a balanced tree
        int m_balance_factor;

    public:
        // Constructors
        /**
         * @brief Default constructor that initializes the node with default value of T
         */
        Balanced_Tree_Node() : Binary_Tree_Node<T>(), m_height(0), m_balance_factor(0) {}
        /**
         * @brief Parameterized constructor that initializes the node with the provided value
         * @param value The value to initialize the node with
         */
        Balanced_Tree_Node(const T &value) : Binary_Tree_Node<T>(value), m_height(0), m_balance_factor(0) {}

        // Methods
        /**
         * @brief Returns the height of the node
         * @return The height of the node
         */
        size_t height() const
        {
            return m_height;
        }

        /**
         * @brief Sets the height of the node to the provided value
         * @param height The value to set the height to
         */
        void set_height(size_t height)
        {
            this->m_height = m_height;
        }

        /**
         * @brief Returns the balance factor of the node
         * @return The balance factor of the node
         */
        int balance_factor() const
        {
            return m_balance_factor;
        }

        /**
         * @brief Sets the balance factor of the node to the provided value
         * @param balance_factor The value to set the balance factor to
         */
        void set_balance_factor(int balance_factor)
        {
            this->m_balance_factor = balance_factor;
        }

    protected:
        /**
         * @brief Checks the balance of the node and updates the height and balance factor accordingly
         * @note This method is typically called after modifying the tree structure to ensure that the node remains balanced
         */
        void check_balance()
        {
            // the height on the left and right of the node
            size_t left_height = 0;
            size_t right_height = 0;

            // gets the left height
            if (this->m_left)
                left_height = Binary_Tree_Node<T>::m_left->height();

            // gets the right height
            if (this->m_right)
                right_height = Binary_Tree_Node<T>::m_right->height();

            // sets the height and balance factor
            m_height = 1 + std::max(left_height, right_height);
            m_balance_factor = static_cast<int>(right_height) - static_cast<int>(left_height);

            // calls rebalance if node is unbalanced
            if (m_balance_factor < -1 || m_balance_factor > 1)
            {
                rebalance();
            }
        }

        /**
         * @brief Rebalances the node if it is unbalanced, adjusting pointers to maintain the properties of the balanced tree
         * @note This method is called if check_balance() detects an imbalance
         */
        void rebalance()
        {
            // Check for direction of inbalance
            if (m_balance_factor > 1)
            {
                // Right heavy, peform left rotate
                *this = left_rotate();
            }
            else if (m_balance_factor < -1)
            {
                // Left heavy, perform right rotate
                *this = right_rotate();
            }
        }

        /**
         * @brief Performs a left rotation on the node to balance the tree.
         * @return A pointer to the new root of the subtree after the left rotation.
         */
        std::unique_ptr<Balanced_Tree_Node<T>> left_rotate()
        {
            // TODO
        }

        /**
         * @brief Performs a right rotation on the node to balance the tree
         * @return A pointer to the new root of the subtree after the right rotation
         */
        std::unique_ptr<Balanced_Tree_Node<T>> right_rotate()
        {
            // TODO
        }

        /**
         * @brief Checks the height of the node and updates it based on the heights of its children
         */
        void check_height()
        {
            // TODO
        }
    };

    template <typename T>
    class Heap_Node : public Balanced_Tree_Node<T>
    {
    protected:
        /// @brief The priority of the node, used to determine the order in which nodes are dequeued
        int m_priority;

    public:
        // Constructors
        /**
         * @brief Default constructor that initializes the node with default value of T
         */
        Heap_Node() : Balanced_Tree_Node<T>(), m_priority(0) {}
        /**
         * @brief Parameterized constructor that initializes the node with the provided value and priority
         * @param value The value to initialize the node with
         * @param priority The priority of the node
         */
        Heap_Node(const T &value, int priority) : Balanced_Tree_Node<T>(value), m_priority(priority) {}

        // Methods
        /**
         * @brief Returns the priority of the node
         * @return The priority of the node
         */
        int priority() const
        {
            return m_priority;
        }

        /**
         * @brief Sets the priority of the node to the provided value
         * @param priority The value to set the priority to
         */
        void set_priority(int priority)
        {
            this->m_priority = priority;
        }
    };

    template <typename T>
    class Graph_Node : public Basic_Node<T>
    {
    protected:
        /// @brief A list of pointer to connected nodes or edges in the graph
        std::vector<std::unique_ptr<Basic_Node<T>>> m_edges;

    public:
        // Constructors
        /**
         * @brief Default constructor that initializes the node with default value of T
         */
        Graph_Node() : Basic_Node<T>(), m_edges() {}

        /**
         * @brief Parameterized constructor that initializes the node with the provided value
         * @param value The value to initialize the node with
         */
        Graph_Node(const T &value) : Basic_Node<T>(value), m_edges() {}

        // Methods
        /**
         * @brief Adds an edge to the current node
         * @param edge A pointer to the node that is connected by the edge
         */
        void add_edge(std::unique_ptr<Basic_Node<T>> edge)
        {
            m_edges.push_back(std::move(edge));
        }

        /**
         * @brief Removes an edge from the current node at the specified index
         * @param index The index of the edge to be removed
         * @note If the index is out of bounds, throws an error
         */
        void remove_edge(size_t index)
        {
            if (index < m_edges.size())
            {
                m_edges.erase(m_edges.begin() + index);
            }
            else
            {
                throw std::out_of_range("Index out of bounds");
            }
        }

        /**
         * @brief Removes a specific edge from the current node
         * @param edge A pointer to the node that is connected by the edge to be removed
         */
        void remove_edge(std::unique_ptr<Basic_Node<T>> &edge)
        {
            auto found = std::find_if(m_edges.begin(), m_edges.end(),
                                      [&edge](const std::unique_ptr<Basic_Node<T>> &current)
                                      { return current.get() == edge.get(); });
            if (found != m_edges.end())
            {
                m_edges.erase(found);
            }
        }

        /**
         * @brief Returns a list of pointers to connected nodes or edges
         * @return A list of pointers to connected nodes or edges in the graph
         */
        std::vector<std::unique_ptr<Basic_Node<T>>> &edges()
        {
            return m_edges;
        }
    };

    template <typename T>
    class Weighted_Graph_Node : public Graph_Node<T>
    {
    protected:
        /// @brief A list of weights corresponding to the edges in the graph
        std::vector<double> m_weights;

    public:
        // Constructors
        /**
         * @brief Default constructor that initializes the node with default value of T
         */
        Weighted_Graph_Node() : Graph_Node<T>(), m_weights() {}

        /**
         * @brief Parameterized constructor that initializes the node with the provided value
         * @param value The value to initialize the node with
         */
        Weighted_Graph_Node(const T &value) : Graph_Node<T>(value), m_weights() {}

        // Methods
        /**
         * @brief Adds an edge with a corresponding weight to the current node
         * @param edge A pointer to the node that is connected by the edge
         * @param weight The weight of the edge
         */
        void add_edge(std::unique_ptr<Basic_Node<T>> edge, double weight)
        {
            Graph_Node<T>::add_edge(std::move(edge));
            m_weights.push_back(weight);
        }

        /**
         * @brief Removes an edge and its corresponding weight from the current node at the specified index
         * @param index The index of the edge to be removed
         * @note If the index is out of bounds, throws an error
         */
        void remove_edge(size_t index)
        {
            Graph_Node<T>::remove_edge(index);
            if (index < m_weights.size())
            {
                m_weights.erase(m_weights.begin() + index);
            }
            else
            {
                throw std::out_of_range("Index out of bounds");
            }
        }

        /**
         * @brief Returns a list of weights corresponding to the edges in the graph
         * @return A list of weights corresponding to the edges in the graph
         */
        std::vector<double> &weights()
        {
            return m_weights;
        }
    };
}