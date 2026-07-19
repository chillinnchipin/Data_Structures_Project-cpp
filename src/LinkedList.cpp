#include "LinkedList.hpp"

namespace structures
{
    template <typename T>
    class Linked_List {
        append(const T& value) {
            // Makes a new node
            std::unique_ptr<node::Linear_Node<T>> new_node = std::make_unique<node::Linear_Node<T>>(value);

            // append the new node
            append(std::move(new_node));
        }

        append(std::unique_ptr<node::Linear_Node<T>>&& node) {
            // If the list is empty, set head and tail to the new node
            if (!head_) {
                head_ = std::move(node);
                tail_ = std::move(node);
            } else {
                // Otherwise, link the new node to the end and update tail
                tail_->set_next(std::move(node));
                node->set_prev(std::move(tail_));
                tail_ = std::move(node);
            }

            // Increment size
            size++;
        }

        append(std::vector<T> values) {
            // Append each value in the vector
            for (const T& value : values) {
                append(value);
            }
        }

        append(std::vector<std::unique_ptr<node::Linear_Node<T>>>& nodes) {
            // Append each node in the vector
            for (auto& node : nodes) {
                append(std::move(node));
            }
        }

        append(Linked_List<T>& other) {
            // Link tail and other head
            tail_->set_next(std::move(other.head_));
            tail_ = std::move(other.tail());
            other.head()->set_prev(std::move(tail_));

            // Add sizes together
            size_ += other.size();
        }

        prepend(const T& value) {
            // Create a new node
            std::unique_ptr<node::Linear_Node<T>> new_node = std::make_unique<node::Linear_Node<T>>(value);

            // Prepend the new node
            prepend(std::move(new_node));
        }

        prepend(std::unique_ptr<node::Linear_Node<T>>&& node) {
            // If the list is empty, set head and tail to the new node
            if (!head_) {
                head_ = std::move(node);
                tail_ = std::move(node);
            } else {
                // Otherwise, link the new node to the front and update head
                node->set_next(std::move(head_));
                head_->set_prev(std::move(node));
                head_ = std::move(node);
            }

            // Increment size
            size++;
        }

        add(const T& value, size_t index) {
            // Create a new node
            std::unique_ptr<node::Linear_Node<T>> new_node = std::make_unique<node::Linear_Node<T>>(value);

            // Add the new node at the specified index
            add(std::move(new_node), index);
        }

        add(std::unique_ptr<node::Linear_Node<T>>&& node, size_t index) {
            // Check for index out of bounds
            if (index > size_) {
                throw std::out_of_range("Index out of bounds");
            }

            // If adding at the front
            if (index == 0) {
                prepend(std::move(node));
                return;
            }

            // If adding at the end
            if (index == size_) {
                append(std::move(node));
                return;
            }

            // Traverse to the node at the index
            auto current = head_.get();
            for (size_t i = 0; i < index; ++i) {
                current = current->next().get();
            }

            // Link the new node in
            node->set_next(std::move(current));
            node->set_prev(std::move(current->prev()));
            current->prev->set_next(node);
            current->set_prev(std::move(node));

            // Increment size
            size_++;
        }

        void remove(size_t index) {
            // Check for size out of bounds
            if (index >= size_) {
                throw std::out_of_range("Index out of bounds");
            }

            // If removing from the front
            if (index == 0) {
                head_ = std::move(head_->next());
                if (head_) {
                    head_->set_prev(nullptr);
                } else {
                    tail_ = nullptr; // List is now empty
                }
            }

            // if removing from end
            if (index == size_ - 1) {
                tail_ = std::move(tail_->prev());
                if (tail_) {
                    tail_->set_next(nullptr);
                } else {
                    head_ = nullptr; // List is now empty
                }
            }

            // Iterate to the node to be removed
            auto current = head_.get();
            for (size_t i = 0; i < index; ++i) {   
                current = current->next().get();
            }

            // Unlink the node
            current->prev()->set_next(std::move(current->next()));
            current->next()->set_prev(std::move(current->prev()));

            // Decrement size
            size_--;
        }

        void remove(const T& value) {
            auto current = head_.get();

            // Traverse the list to find the value
            for (size_t i = 0; i < size_; ++i) {
                // Check if value matches
                if (current->data() == value) {
                    // Unlink the node
                    current->prev()->set_next(std::move(current->next()));
                    current->next()->set_prev(std::move(current->prev()));
                    
                    // Decrement size and return
                    size_--;
                    return;
                }
                current = current->next().get();
            }

            throw std::invalid_argument("Value not found in the list");
        }

        void remove(std::unique_ptr<node::Linear_Node<T>>& node) {
            auto current = head_.get();

            // Traverse the list to find the node
            for (size_t i = 0; i < size_; ++i) {
                // Check if node matches
                if (current == node.get()) {
                    // Unlink the node
                    current->prev()->set_next(std::move(current->next()));
                    current->next()->set_prev(std::move(current->prev()));
                    
                    // Decrement size and return
                    size_--;
                    return;
                }
                current = current->next().get();
            }

            throw std::invalid_argument("Node not found in the list");
        }

        void clear() {
            head_ = nullptr;
            tail_ = nullptr;
            size_ = 0;
        }

        bool contains(const T& value) const {
            auto current = head_.get();

            // Traverse the list to find the value
            for (size_t i = 0; i < size_; ++i) {
                if (current->data() == value) {
                    return true;
                }
                current = current->next().get();
            }

            return false;
        }

        bool contains(std::unique_ptr<node::Linear_Node<T>>& node) const {
            auto current = head_.get();

            // Traverse the list to find the node
            for (size_t i = 0; i < size_; ++i) {
                if (current == node.get()) {
                    return true;
                }
                current = current->next().get();
            }

            return false;
        }

        std::unique_ptr<node::Linear_Node<T>> find(const T& value) const {
            auto current = head_.get();

            // Traverse the list to find the value
            for (size_t i = 0; i < size_; ++i) {
                if (current->data() == value) {
                    return std::make_unique<node::Linear_Node<T>>(*current);
                }
                current = current->next().get();
            }

            return nullptr;
        }

        std::unique_ptr<node::Linear_Node<T>> find(std::unique_ptr<node::Linear_Node<T>>& node) const {
            auto current = head_.get();

            // Traverse the list to find the node
            for (size_t i = 0; i < size_; ++i) {
                if (current == node.get()) {
                    return std::make_unique<node::Linear_Node<T>>(*current);
                }
                current = current->next().get();
            }

            return nullptr;
        }

        size_t index_of(const T& value) const {
            auto current = head_.get();

            // Traverse the list to find the value
            for (size_t i = 0; i < size_; ++i) {
                if (current->data() == value) {
                    return i;
                }
                current = current->next().get();
            }

            throw std::invalid_argument("Value not found in the list");
        }

        size_t index_of(std::unique_ptr<node::Linear_Node<T>>& node) const {
            auto current = head_;

            // Traverse the list to find the node
            for (size_t i = 0; i < size_; ++i) {
                if (current == node.get()) {
                    return i;
                }
                current = current->next();
            }

            throw std::invalid_argument("Node not found in the list");
        }

        std::array<T, size> to_array() const {
            std::array<T, size> arr;
            auto current = head_;

            // Traverse the list and fill the array
            for (size_t i = 0; i < size_; ++i) {
                arr[i] = current->data();
                current = current->next();
            }

            return arr;
        }

        std::vector<T> to_vector() const {
            std::vector<T> vec;
            vec.resize(size_);
            auto current = head_;

            // Traverse the list and fill the vector
            for (size_t i = 0; i < size_; ++i) {
                vec[i] = current->data();
                current = current->next();
            }

            return vec;
        }

        void validate() {
            // Traverse the list from head to tail
            auto current = head_;
            size_t count = 0;
            while (current.next()) {
                // Check forward links
                // Check backward links
                if (current.next()->prev().get() != current)
                    throw std::runtime_error("Linked List Validate Error");
                // Iterate current and count
                count++;
                current = std::move(current.next())
            }
            // Verify traverse ended at tail
            if (current != tail)
                throw std::runtime_error("Linked List Validate Error");
            // Ensure count equals size_
            if (size_ != count)
                throw std::runtime_error("Linked List Validate Error");
        }

        Linked_List& operator=(Linked_List<T> other) {
            // Swap the contents with other
            std::swap(head_, other.head_);
            head_ = std::move(other.head());
            tail_ = std::move(other.tail());
            size_ = std::move(other.size());
            return *this;
        }

        Linked_List& operator+(Linked_List<T> other) {
            // Create new list and add other to it
            Linked_List<T> new_list = *this;
            new_list.append(other);
            return new_list;
        }

        Linked_List& operator+=(Linked_List<T> other) {
            // Append the other list to this list
            append(other);
            return *this;
        }

        bool operator==(Linked_List<T> other) {
            // If sizes differ, lists are not equal
            if (size_ != other.size())
                return false;

            auto current1 = head_;
            auto current2 = other.head();

            // Traverse both lists and compare nodes
            for (size_t i = 0; i < size_; ++i) {
                if (*current1 != *current2)
                    return false;
                current1 = current1->next();
                current2 = current2->next();
            }

            return true;
        }
    };
}
