// // ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef NODE_HPP
#define NODE_HPP
#include <iostream>
#include <vector>
#include <memory>
#include <sstream> 

template <typename T>
class Node {
public:
    T value;
    std::vector<std::shared_ptr<Node<T>>> children;

    Node(const T& val) : value(val) {}

    T get_value() const { return value; }

    void add_child(std::shared_ptr<Node<T>> child) {
        children.push_back(child);
    }

    std::string toString() const {
        return value.toString();
    }

    bool operator==(const Node<T>& other) const {
        return value == other.value;
    }

    bool operator!=(const Node<T>& other) const {
        return !(*this == other);
    }

    // Destructor
    ~Node() {
        children.clear(); // This line is optional since shared_ptr will delete the children
    }
};

// Function template for converting any type to string
template <typename T>
std::string toString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

#endif // NODE_HPP