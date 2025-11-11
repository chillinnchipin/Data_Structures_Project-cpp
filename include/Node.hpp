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
