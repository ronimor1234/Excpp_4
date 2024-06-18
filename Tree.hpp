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

    // PreOrderIterator class
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

        std::shared_ptr<Node<T>> operator*() const {
            return stack.top();
        }
    };

    PreOrderIterator begin_pre_order() const {
        return PreOrderIterator(root);
    }

    PreOrderIterator end_pre_order() const {
        return PreOrderIterator(nullptr);
    }

    // Implement PostOrderIterator, InOrderIterator, BFSIterator, DFSIterator...
    friend std::ostream& operator<<(std::ostream& os, const Tree<T, K>& tree) {
        sf::RenderWindow window(sf::VideoMode(800, 600), "Tree Visualization");

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
                sf::Vertex line[] =
                {
                    sf::Vertex(sf::Vector2f(x + circle.getRadius(), y + circle.getRadius())),
                    sf::Vertex(sf::Vector2f(child_x + circle.getRadius(), child_y + circle.getRadius()))
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