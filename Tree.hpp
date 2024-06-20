// ID: 208018028, Mail: ronimordechai70@gmail.com
#ifndef TREE_HPP
#define TREE_HPP

#include "Node.hpp"
#include <queue>
#include <stack>
#include <iterator>
#include <SFML/Graphics.hpp>
#include <iostream>

template <typename T, int K = 2>
class Tree {
private:
    std::shared_ptr<Node<T>> root;

    bool is_binary() const {
        return K == 2;
    }

public:
    Tree() : root(nullptr) {}

    void add_root(const Node<T>& node) {
        root = std::make_shared<Node<T>>(node);
    }

    void add_sub_node(const Node<T>& parent, Node<T>& child) {
        if (root) {
            add_sub_node_helper(root.get(), parent, child);
        }
    }

    std::shared_ptr<Node<T>> get_root() const {
        return root;
    }

    // BFS Iterator
    class BFSIterator {
    private:
        std::queue<std::shared_ptr<Node<T>>> queue;

    public:
        BFSIterator(std::shared_ptr<Node<T>> root) {
            if (root) queue.push(root);
        }

        bool operator!=(const BFSIterator& other) const {
            return !queue.empty() || !other.queue.empty();
        }

        BFSIterator& operator++() {
            auto node = queue.front();
            queue.pop();
            for (auto& child : node->children) {
                queue.push(child);
            }
            return *this;
        }

        Node<T>& operator*() const {
            return *queue.front();
        }

        Node<T>* operator->() const {
            return queue.front().get();
        }
    };

    BFSIterator begin_bfs() const {
        return BFSIterator(root);
    }

    BFSIterator end_bfs() const {
        return BFSIterator(nullptr);
    }

    // DFS Iterator
    class DFSIterator {
    private:
        std::stack<std::shared_ptr<Node<T>>> stack;

    public:
        DFSIterator(std::shared_ptr<Node<T>> root) {
            if (root) stack.push(root);
        }

        bool operator!=(const DFSIterator& other) const {
            return !stack.empty() || !other.stack.empty();
        }

        DFSIterator& operator++() {
            auto node = stack.top();
            stack.pop();
            for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                stack.push(*it);
            }
            return *this;
        }

        Node<T>& operator*() const {
            return *stack.top();
        }

        Node<T>* operator->() const {
            return stack.top().get();
        }
    };

    DFSIterator begin_dfs() const {
        return DFSIterator(root);
    }

    DFSIterator end_dfs() const {
        return DFSIterator(nullptr);
    }

    // InOrderIterator class
    /*
    * Visit the left subtree.
    * Visit the root node.
    * Visit the right subtree.
    */
    class InOrderIterator {
        private:
            std::stack<std::shared_ptr<Node<T>>> stack;

            void push_left_chain(std::shared_ptr<Node<T>> node) {
                while (node) {
                    stack.push(node);
                    node = node->children.size() > 0 ? node->children[0] : nullptr;
                }
            }

        public:
            InOrderIterator(std::shared_ptr<Node<T>> root) {
                push_left_chain(root);
            }

            bool operator!=(const InOrderIterator& other) const {
                return !stack.empty() || !other.stack.empty();
            }

            InOrderIterator& operator++() {
                if (!stack.empty()) {
                    auto node = stack.top();
                    stack.pop();
                    push_left_chain(node->children.size() > 1 ? node->children[1] : nullptr);
                }
                return *this;
            }

            Node<T>& operator*() const {
            return *stack.top();
            }

            Node<T>* operator->() const {
            return stack.top().get();
            }
        };

    InOrderIterator begin_in_order() const {
        return InOrderIterator(root);
    }

    InOrderIterator end_in_order() const {
        return InOrderIterator(nullptr);
    }

    // In-order traversal method
    void in_order_traversal() {
        in_order_traversal_impl(std::integral_constant<bool, (K == 2)>());
    }


    // Template specialization for k == 2 (binary tree)
    void in_order_traversal_impl(std::true_type) {
        std::cout << "The in-order of the tree is:" << std::endl;
        for (auto it = begin_in_order(); it != end_in_order(); ++it) {
            std::cout << it->get_value() << std::endl;
        }
        std::cout << std::endl;
    }

    // Template specialization for k != 2 (non-binary tree)
    void in_order_traversal_impl(std::false_type) {
        std::cout << "In-order traversal is not suitable for non-binary trees; performing DFS traversal from the root:" << std::endl;
        for (auto it = begin_dfs(); it != end_dfs(); ++it) {
            std::cout << it->get_value() << std::endl;
        }
        std::cout << std::endl;
    }

    // PreOrderIterator class
    /*
    * Visit the root subtree.
    * Visit the left node.
    * Visit the right subtree.
    */
    class PreOrderIterator {
        private:
            std::stack<std::shared_ptr<Node<T>>> stack;

        public:
            PreOrderIterator(std::shared_ptr<Node<T>> root) {
                if (root) stack.push(root);
            }

            bool operator!=(const PreOrderIterator& other) const {
                return !stack.empty() || !other.stack.empty();
            }

            PreOrderIterator& operator++() {
                auto node = stack.top();
                stack.pop();
                for (auto it = node->children.rbegin(); it != node->children.rend(); ++it) {
                    stack.push(*it);
                }
                return *this;
            }

            Node<T>& operator*() const {
                return *stack.top();
            }

            Node<T>* operator->() const {
                return stack.top().get();
            }
        };

    PreOrderIterator begin_pre_order() const {
        return PreOrderIterator(root);
    }

    PreOrderIterator end_pre_order() const {
        return PreOrderIterator(nullptr);
    }

    // Pre-order traversal method
    void pre_order_traversal() {
        pre_order_traversal_impl(std::integral_constant<bool, (K == 2)>());
    }

    void pre_order_traversal_impl(std::true_type) {
        std::cout << "The pre-order of the tree is:" << std::endl;
        for (auto it = begin_pre_order(); it != end_pre_order(); ++it) {
            std::cout << it->get_value() << std::endl;
        }
        std::cout << std::endl;
    }

    void pre_order_traversal_impl(std::false_type) {
        std::cout << "Pre-order traversal is not suitable for non-binary trees; performing DFS traversal from the root:" << std::endl;
        for (auto it = begin_dfs(); it != end_dfs(); ++it) {
            std::cout << it->get_value() << std::endl;
        }
        std::cout << std::endl;
    }
    // PostOrderIterator class
    /*
    * Visit the left subtree.
    * Visit the right node.
    * Visit the root subtree.
    */
    class PostOrderIterator {
        private:
            std::stack<std::shared_ptr<Node<T>>> stack;

        public:
            PostOrderIterator(std::shared_ptr<Node<T>> root) {
            if (root) {
                stack.push(root);
                // Initialize the stack with the entire left spine
                auto current = root;
                while (!current->children.empty()) {
                    stack.push(current->children.back());
                    current = current->children.back();
                }
            }
        }

        bool operator!=(const PostOrderIterator& other) const {
            return !stack.empty() || !other.stack.empty();
        }

        PostOrderIterator& operator++() {
            auto node = stack.top();
            stack.pop();
            if (!stack.empty()) {
            auto parent = stack.top();
            // Find the next child to push to the stack
            auto it = std::find_if(parent->children.rbegin(), parent->children.rend(),
                                   [&](const std::shared_ptr<Node<T>>& n) {
                                       return n == node;
                                   });
            // Push the next child onto the stack
            if (++it != parent->children.rend()) {
                auto current = *it;
                stack.push(current);
                // Push the entire left spine onto the stack
                while (!current->children.empty()) {
                    stack.push(current->children.back());
                    current = current->children.back();
                    }
                }
            }
            return *this;
        }

        Node<T>& operator*() const {
            return *stack.top();
        }

        Node<T>* operator->() const {
            return stack.top().get();
        }
    };

    PostOrderIterator begin_post_order() const {
        return PostOrderIterator(root);
    }

    PostOrderIterator end_post_order() const {
        return PostOrderIterator(nullptr);
    }

    // Post-order traversal method
    void post_order_traversal() {
        post_order_traversal_impl(std::integral_constant<bool, (K == 2)>());
    }

    // Template specialization for k == 2 (binary tree)
    void post_order_traversal_impl(std::true_type) {
        std::cout << "The post-order of the tree is:" << std::endl;
        for (auto it = begin_post_order(); it != end_post_order(); ++it) {
            std::cout << it->get_value() << std::endl;
        }
        std::cout << std::endl;
    }

    // Template specialization for k != 2 (non-binary tree)
    void post_order_traversal_impl(std::false_type) {
        std::cout << "Post-order traversal is not suitable for non-binary trees; performing DFS traversal from the root:" << std::endl;
        for (auto it = begin_dfs(); it != end_dfs(); ++it) {
            std::cout << it->get_value() << std::endl;
        }
    }
  

    // Implement PostOrderIterator, InOrderIterator, BFSIterator, DFSIterator...
    friend std::ostream& operator<<(std::ostream& os, const Tree<T, K>& tree) {
        sf::RenderWindow window(sf::VideoMode(1200, 800), "Tree Visualization");

        while (window.isOpen()) {
            sf::Event event;
            while (window.pollEvent(event)) {
                if (event.type == sf::Event::Closed) {
                    window.close();
                }
            }

            window.clear();

            // Draw the tree here using SFML
            if (tree.root) {
                draw_tree(window, tree.root.get(), 400, 50, 200);
            }

            window.display();
        }

        return os;
    }

private:
    static void draw_tree(sf::RenderWindow& window, Node<T>* node, float x, float y, float offset) {
        if (!node) return;

        sf::CircleShape circle(32);
        circle.setFillColor(sf::Color::Yellow);
        circle.setPosition(x, y);

        sf::Font font;
        if (!font.loadFromFile("Arial Regular.ttf")) {
            std::cerr << "Error loading font\n";
            return; // or handle the error appropriately
        }

        sf::Text text;
        text.setFont(font);
        // text.setString(node->value.toString());

        setText(text, node->value);


        text.setCharacterSize(10);
        text.setFillColor(sf::Color::Black);
        
        // Calculate the text position to center it within the circle
        sf::FloatRect textRect = text.getLocalBounds();
        text.setOrigin(textRect.left + textRect.width / 2.0f,
                    textRect.top + textRect.height / 2.0f);
        text.setPosition(circle.getPosition().x + circle.getRadius(),
                    circle.getPosition().y + circle.getRadius());

        window.draw(circle);
        window.draw(text);

        float child_x = x - offset;
        float child_y = y + 100;
        for (auto& child : node->children) {
            if (child) {
                 // Calculate line positions
            float line_x1 = x + circle.getRadius(); // Starting from the bottom center
            float line_y1 = y + circle.getRadius() * 2;

            float line_x2 = child_x + circle.getRadius(); // Ending at the top center
            float line_y2 = child_y;

            sf::Vertex line[] =
            {
                sf::Vertex(sf::Vector2f(line_x1, line_y1)),
                sf::Vertex(sf::Vector2f(line_x2, line_y2))
            };
            window.draw(line, 2, sf::Lines);

            draw_tree(window, child.get(), child_x, child_y, offset / 2);
            child_x += offset;
            }
        }
    }

     void add_sub_node_helper(Node<T>* current, const Node<T>& parent, const Node<T>& child) {
        if (current->value == parent.value) {
            current->add_child(std::make_shared<Node<T>>(child));
        } else {
            for (auto& node : current->children) {
                add_sub_node_helper(node.get(), parent, child);
            }
        }
    }

    private:
    // Helper function to set text based on type
    static void setText(sf::Text& text, const T& value) {
        std::ostringstream oss;
        setTextHelper(oss, value);
        text.setString(oss.str());
    }

    // SFINAE helper function to handle different types
    template <typename U = T>
    static typename std::enable_if<std::is_same<U, double>::value || std::is_same<U, int>::value, void>::type
    setTextHelper(std::ostringstream& oss, const T& value) {
        oss << value;
    }

    template <typename U = T>
    static typename std::enable_if<std::is_same<U, std::string>::value, void>::type
    setTextHelper(std::ostringstream& oss, const T& value) {
        oss << value;
    }

    template <typename U = T>
    static typename std::enable_if<!std::is_same<U, double>::value && !std::is_same<U, int>::value && !std::is_same<U, std::string>::value, void>::type
    setTextHelper(std::ostringstream& oss, const T& value) {
        oss << value.toString();
    }
    
};

#endif // TREE_HPP