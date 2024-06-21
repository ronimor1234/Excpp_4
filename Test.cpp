// ID: 208018028, Mail: ronimordechai70@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
#include <iostream>

using namespace std;

TEST_CASE("Node creation and value access") {
    SUBCASE("Creating a node with an integer value") {
        Node<int> node(5);
        CHECK(node.get_value() == 5);
    }

    SUBCASE("Creating a node with a string value") {
        Node<string> node("test");
        CHECK(node.get_value() == "test");
    }

    SUBCASE("Creating a node with a double value") {
        Node<double> node(3.14);
        CHECK(node.get_value() == 3.14);
    }

    SUBCASE("Creating a node with a boolean value") {
        Node<bool> node(true);
        CHECK(node.get_value() == true);
    }

    SUBCASE("Creating a node with a character value") {
        Node<char> node('a');
        CHECK(node.get_value() == 'a');
    }

    SUBCASE("Creating a node with an empty string value") {
        Node<string> node("");
        CHECK(node.get_value() == "");
    }

    SUBCASE("Creating a node with a large integer value") {
        Node<long> node(1234567890L);
        CHECK(node.get_value() == 1234567890L);
    }

    SUBCASE("Creating a node with a negative integer value") {
        Node<int> node(-42);
        CHECK(node.get_value() == -42);
    }

    SUBCASE("Creating a node with a negative double value") {
        Node<double> node(-3.14);
        CHECK(node.get_value() == -3.14);
    }
}

// TEST_CASE("Tree creation and structure") {
//     SUBCASE("Creating an empty tree") {
//         Tree<int> tree;
//         CHECK(tree.get_root() == nullptr);
//     }

//     SUBCASE("Creating a tree with a single node") {
//         Tree<int> tree;
//         auto root_node = std::make_shared<Node<int>>(5);
//         tree.set_root(root_node);
//         CHECK(tree.get_root() != nullptr);
//         CHECK(tree.get_root()->get_value() == 5);
//     }

//     SUBCASE("Creating a tree with multiple nodes") {
//         Tree<int> tree;
//         auto root_node = std::make_shared<Node<int>>(1);
//         auto child1 = std::make_shared<Node<int>>(2);
//         auto child2 = std::make_shared<Node<int>>(3);
//         tree.add_sub_node(root_node, child1);
//         tree.add_sub_node(root_node, child2);
//         tree.set_root(root_node);

//         CHECK(tree.get_root() != nullptr);
//         CHECK(tree.get_root()->get_value() == 1);
//         CHECK(tree.get_root()->get_children().size() == 2);
//         CHECK(tree.get_root()->get_children()[0]->get_value() == 2);
//         CHECK(tree.get_root()->get_children()[1]->get_value() == 3);
//     }

//     SUBCASE("Creating a tree with a single child") {
//         Tree<int> tree;
//         auto root_node = std::make_shared<Node<int>>(1);
//         auto child = std::make_shared<Node<int>>(2);
//         tree.add_sub_node(root_node, child);
//         tree.set_root(root_node);

//         CHECK(tree.get_root() != nullptr);
//         CHECK(tree.get_root()->get_value() == 1);
//         CHECK(tree.get_root()->get_children().size() == 1);
//         CHECK(tree.get_root()->get_children()[0]->get_value() == 2);
//     }

//     SUBCASE("Creating a tree with multiple levels") {
//         Tree<int> tree;
//         auto root_node = std::make_shared<Node<int>>(1);
//         auto child1 = std::make_shared<Node<int>>(2);
//         auto child2 = std::make_shared<Node<int>>(3);
//         auto grandchild1 = std::make_shared<Node<int>>(4);
//         auto grandchild2 = std::make_shared<Node<int>>(5);

//         tree.add_sub_node(root_node, child1);
//         tree.add_sub_node(root_node, child2);
//         tree.add_sub_node(child1, grandchild1);
//         tree.add_sub_node(child2, grandchild2);
//         tree.set_root(root_node);

//         CHECK(tree.get_root() != nullptr);
//         CHECK(tree.get_root()->get_value() == 1);
//         CHECK(tree.get_root()->get_children().size() == 2);
//         CHECK(tree.get_root()->get_children()[0]->get_value() == 2);
//         CHECK(tree.get_root()->get_children()[1]->get_value() == 3);
//         CHECK(tree.get_root()->get_children()[0]->get_children().size() == 1);
//         CHECK(tree.get_root()->get_children()[0]->get_children()[0]->get_value() == 4);
//         CHECK(tree.get_root()->get_children()[1]->get_children().size() == 1);
//         CHECK(tree.get_root()->get_children()[1]->get_children()[0]->get_value() == 5);
//     }

//     SUBCASE("Creating a tree with different data types") {
//         Tree<std::string> tree;
//         auto root_node = std::make_shared<Node<std::string>>("root");
//         auto child = std::make_shared<Node<std::string>>("child");
//         tree.add_sub_node(root_node, child);
//         tree.set_root(root_node);

//         CHECK(tree.get_root() != nullptr);
//         CHECK(tree.get_root()->get_value() == "root");
//         CHECK(tree.get_root()->get_children().size() == 1);
//         CHECK(tree.get_root()->get_children()[0]->get_value() == "child");
//     }

//     SUBCASE("Creating a tree with a custom object") {
//         Tree<Complex> tree;
//         Complex rootValue(1.0, 2.0);
//         Complex childValue(3.0, 4.0);
//         auto root_node = std::make_shared<Node<Complex>>(rootValue);
//         auto child_node = std::make_shared<Node<Complex>>(childValue);
//         tree.add_sub_node(root_node, child_node);
//         tree.set_root(root_node);

//         CHECK(tree.get_root() != nullptr);
//         CHECK(tree.get_root()->get_value() == rootValue);
//         CHECK(tree.get_root()->get_children().size() == 1);
//         CHECK(tree.get_root()->get_children()[0]->get_value() == childValue);
//     }
// }