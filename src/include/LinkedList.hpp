#pragma once
#include "Node.hpp"
namespace structures
{
    template <typename T>
    class Linked_List
    {
    protected:
        // Attributes

        /// @brief Pointer to the first node in the linked list
        std::unique_ptr<node::Linear_Node<T>> head_;

        /// @brief Pointer to the last node in the linked list
        std::unique_ptr<node::Linear_Node<T>> tail_;

        /// @brief The size of the linked list, the number of nodes it contains
        size_t size_;

    public:
        // Constructors

        /**
         * @brief Default constructor that initializes an empty linked list
         */
        Linked_List() : head_(nullptr), tail_(nullptr), size_(0) {}

        /**
         * @brief Parameterized constructor that initializes the linked list with a single node containing the provided value
         * @param value The value to initialize the first node with
         */
        Linked_List(const T &value) : head_(std::make_unique<node::Linear_Node<T>>(value)), tail_(head_.get()), size_(1) {}

        // Methods

        /**
         * @brief Returns a pointer to the first node in the linked list
         * @return A pointer to the first node in the linked list or null if the list is empty
         */
        std::unique_ptr<node::Linear_Node<T>> &head()
        {
            return head_;
        }

        /**
         * @brief Returns a pointer to the last node in the linked list
         * @return A pointer to the last node in the linked list or null if the list is empty
         */
        std::unique_ptr<node::Linear_Node<T>> &tail()
        {
            return tail_;
        }

        /**
         * @brief Returns the number of nodes in the linked list
         * @return The number of nodes in the linked list
         */
        size_t size() const
        {
            return size_;
        }

        /**
         * @brief Checks if the linked list is empty
         * @return True if the linked list is empty, false otherwise
         */
        bool is_empty() const
        {
            return size_ == 0;
        }

        /**
         * @brief Appends a new node with the provided value to the end of the linked list
         * @param value The value to be stored in the new node
         */
        void append(const T &value);

        /**
         * @brief Appends an existing node to the end of the linked list
         * @param node A pointer to the node to be appended
         */
        void append(std::unique_ptr<node::Linear_Node<T>> &&node);

        /**
         * @brief Appends an list of values as new nodes to the end of the linked list
         * @param values An list of values to be appended as new nodes
         */
        void append(std::vector<T> values);

        /**
         * @brief Appends an list of values as new nodes to the end of the linked list
         * @param nodes An list of nodes to be appended as new nodes
         */
        void append(std::vector<std::unique_ptr<node::Linear_Node<T>>> &nodes);

        /**
         * @brief Appends all nodes from another linked list to the end of this linked list
         * @param other A linked list whose nodes are to be appended
         */
        void append(Linked_List<T> &other);

        /**
         * @brief Prepends a new node with the provided value to the beginning of the linked list
         * @param value The value to be stored in the new node
         */
        void prepend(const T &value);

        /**
         * @brief Prepends an existing node to the beginning of the linked list
         * @param node A pointer to the node to be prepended.
         */
        void prepend(std::unique_ptr<node::Linear_Node<T>> &&node);

        /**
         * @brief Adds a new node with the provided value at the specified index in the linked list
         * @param value The value to be stored in the new node
         * @param index The index at which to add the new node
         * @note If the index is out of bounds, throws an error
         */
        void add(const T &value, size_t index);

        /**
         * @brief Adds an existing node at the specified index in the linked list
         * @param node A pointer to the node to be added
         * @param index The index at which to add the node
         * @note If the index is out of bounds, throws an error
         */
        void add(std::unique_ptr<node::Linear_Node<T>> &&node, size_t index);

        /**
         * @brief Removes the node at the specified index from the linked list
         * @param index The index of the node to be removed
         * @note If the index is out of bounds, throws an error
         */
        void remove(size_t index);

        /**
         * @brief Removes the first occurrence of a node with the specified value from the linked list
         * @param value The value of the node to be removed
         * @note If the value is not found, throws an error
         */
        void remove(const T &value);

        /**
         * @brief Removes the specified node from the linked list
         * @param node A pointer to the node to be removed
         * @note If the node is not found, throws an error
         */
        void remove(std::unique_ptr<node::Linear_Node<T>> &node);

        /**
         * @brief Clears the linked list, removing all nodes.
         */
        void clear();

        /**
         * @brief Checks if the linked list contains a node with the specified value
         * @param value The value to check for in the linked list
         * @return True if a node with the specified value exists in the linked list, false otherwise
         */
        bool contains(const T &value) const;

        /**
         * @brief Checks if the linked list contains the specified node
         * @param node A pointer to the node to check for in the linked list
         * @return True if the specified node exists in the linked list, false otherwise
         */
        bool contains(std::unique_ptr<node::Linear_Node<T>> &node) const;

        /**
         * @brief Finds the first node with the specified value in the linked list
         * @param value The value to search for in the linked list
         * @return A pointer to the first node with the specified value, or null if not found
         */
        std::unique_ptr<node::Linear_Node<T>> find(const T &value) const;

        /**
         * @brief Finds the specified node in the linked list
         * @param node A pointer to the node to search for in the linked list
         * @return A pointer to the specified node if it exists in the linked list, or null if not found
         */
        std::unique_ptr<node::Linear_Node<T>> find(std::unique_ptr<node::Linear_Node<T>> &node) const;

        /**
         * @brief Returns the index of the first occurrence of a node with the specified value in the linked list
         * @param value The value to search for in the linked list
         * @return The index of the first occurrence of a node with the specified value, or -1 if not found
         */
        size_t index_of(const T &value) const;

        /**
         * @brief Returns the index of the specified node in the linked list
         * @param node A pointer to the node to search for in the linked list
         * @return The index of the specified node if it exists in the linked list, or -1 if not found
         */
        size_t index_of(std::unique_ptr<node::Linear_Node<T>> &node) const;

        /**
         * @brief Sorts the linked list in ascending order based on the values stored in the nodes
         * @warning throws an error if the type T does not support comparison operations
         */
        void sort();

        /**
         * @brief Reverses the order of the nodes in the linked list
         */
        void reverse();

        /**
         * @brief Sorts the linked list in descending order based on the values stored in the nodes
         * @warning throws an error if the type T does not support comparison operations
         */
        void reverse_sort();

        /**
         * @brief Returns a list of the values stored in the linked list
         * @return A list containing the values stored in the linked list
         */
        std::vector<T> to_vector() const;

        /**
         * @brief Returns a list of the values stored in the linked list
         * @return A list containing the values stored in the linked list
         */
        std::array<T, size> to_array() const;

    private:
        /**
         * @brief Validates the integrity of the linked list, ensuring that all nodes are correctly linked
         * @note This method checks for any inconsistencies in the linked list structure and raises an error if any issues are found
         */
        void validate();

    public:
        // Operators

        /**
         * @brief Assigns another linked list to this linked list
         * @param other The linked list to assign to this linked list
         * @return A reference to this linked list after assignment
         */
        Linked_List &operator=(Linked_List<T> other);

        /**
         * @brief Concatenates another linked list to this linked list
         * @param other The linked list to concatenate to this linked list
         * @return A new linked list containing the nodes of both linked lists
         */
        Linked_List &operator+(Linked_List<T> other);

        /**
         * @brief Concatenates another linked list to this linked list
         * @param other The linked list to concatenate to this linked list
         * @return A reference to this linked list after concatenation
         */
        Linked_List &operator+=(Linked_List<T> other);

        /**
         * @brief Compares this linked list with another linked list for equality
         * @param other The linked list to compare with
         * @return True if both linked lists have the same nodes in the same order, false otherwise
         */
        bool operator==(Linked_List<T> other);

        /**
         * @brief Compares this linked list with another linked list for inequality
         * @param other The linked list to compare with
         * @return True if the linked lists have different nodes or different order, false otherwise
         */
        bool operator!=(Linked_List<T> other);

        /**
         * @brief Returns a pointer to the node at the specified index in the linked list
         * @param index The index of the node to retrieve
         * @return A pointer to the node at the specified index
         * @note If the index is out of bounds, throws an error
         */
        std::unique_ptr<node::Linear_Node<T>> operator[](size_t index);

        /**
         * @brief Overloads the output stream operator to print the linked list
         * @param os The output stream to print to
         * @param list The linked list to be printed
         * @return The output stream after printing the linked list
         */
        friend std::ostream &operator<<(std::ostream os, Linked_List<T> &list);
    };
}
