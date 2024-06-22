// ID: 208018028, Mail: ronimordechai70@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
#include <string>

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

TEST_CASE("Tree creation and structure") {
    SUBCASE("Creating an empty tree") {
        Tree<int> tree;
        CHECK(!tree.get_root());
    }

    SUBCASE("Creating a tree with a single node") {
        Tree<int> tree;
        Node<int> root(5);
        tree.add_root(root);
        CHECK(tree.get_root()->get_value() == 5);
    }


    SUBCASE("Creating a tree with multiple nodes") {
        Tree<int> tree;
        Node<int> root(1);
        Node<int> node1(2);
        Node<int> node2(3);
        tree.add_root(root);
        tree.add_sub_node(root, node1);
        tree.add_sub_node(root, node2);
        CHECK(tree.get_root()->get_value() == 1);
        CHECK(tree.get_root()->get_children().size() == 2);
        CHECK(tree.get_root()->get_children()[0]->get_value() == 2);
        CHECK(tree.get_root()->get_children()[1]->get_value() == 3);
    }

    SUBCASE("Creating a tree with multiple levels") {
        Tree<int> tree;
        Node<int> root_node(1);
        Node<int> child1(2);
        Node<int> child2(3);
        Node<int> grandchild1(4);
        Node<int> grandchild2(5);

        tree.add_root(root_node);
        tree.add_sub_node(root_node, child1);
        tree.add_sub_node(root_node, child2);
        tree.add_sub_node(child1, grandchild1);
        tree.add_sub_node(child2, grandchild2);

        CHECK(tree.get_root()->get_value() == 1);
        CHECK(tree.get_root()->get_children().size() == 2);
        CHECK(tree.get_root()->get_children()[0]->get_value() == 2);
        CHECK(tree.get_root()->get_children()[1]->get_value() == 3);
        CHECK(tree.get_root()->get_children()[0]->get_children().size() == 1);
        CHECK(tree.get_root()->get_children()[0]->get_children()[0]->get_value() == 4);
        CHECK(tree.get_root()->get_children()[1]->get_children().size() == 1);
        CHECK(tree.get_root()->get_children()[1]->get_children()[0]->get_value() == 5);
    }

    SUBCASE("Creating a tree with a Complex object") {
        Tree<Complex> tree;

        Node <Complex> root(Complex(1.0, 2.0));
        Node<Complex> child1(Complex(3.0, 4.0));
        Node<Complex> child2(Complex(5.0, 6.0));
        Node<Complex> child3(Complex(2.0, 6.0));
        Node<Complex> child4(Complex(4.0, 6.0));

        tree.add_root(root);
        tree.add_sub_node(root, child1);
        tree.add_sub_node(root, child2);
        tree.add_sub_node(child2, child3);
        tree.add_sub_node(child1, child4);
        CHECK(tree.get_root()->get_children().size() == 2);
        CHECK(tree.get_root()->get_children()[0]->get_value().get_real() == 3.0);
        CHECK(tree.get_root()->get_children()[0]->get_value().get_imag() == 4.0);
        CHECK(tree.get_root()->get_children()[1]->get_value().get_real() == 5.0);
        CHECK(tree.get_root()->get_children()[1]->get_value().get_imag() == 6.0);
        CHECK(tree.get_root()->get_children()[0]->get_children().size() == 1);
        CHECK(tree.get_root()->get_children()[0]->get_children()[0]->get_value().get_real() == 4.0);
        CHECK(tree.get_root()->get_children()[0]->get_children()[0]->get_value().get_imag() == 6.0);

        CHECK(tree.get_root()->get_children()[1]->get_children().size() == 1);
        CHECK(tree.get_root()->get_children()[1]->get_children()[0]->get_value().get_real() == 2.0);
        CHECK(tree.get_root()->get_children()[1]->get_children()[0]->get_value().get_imag() == 6.0);
    }

    SUBCASE("Creating a tree with k = 3 children") {
        Tree<string, 3> tree;

        Node<string> root_node("root");
        tree.add_root(root_node);

        Node<string> node1("child1");
        Node<string> node2("child2");
        Node<string> node3("child3");
        Node<string> node4("child4");

        tree.add_sub_node(root_node, node1);
        tree.add_sub_node(root_node, node2);
        tree.add_sub_node(root_node, node3);
        tree.add_sub_node(node1, node4);

        // Check root node
        CHECK(tree.get_root()->get_value() == "root");
        CHECK(tree.get_root()->get_children().size() == 3);

        // Check children of the root node
        CHECK(tree.get_root()->get_children()[0]->get_value() == "child1");
        CHECK(tree.get_root()->get_children()[1]->get_value() == "child2");
        CHECK(tree.get_root()->get_children()[2]->get_value() == "child3");

        // Check children of node1
        CHECK(tree.get_root()->get_children()[0]->get_children().size() == 1);
        CHECK(tree.get_root()->get_children()[0]->get_children()[0]->get_value() == "child4");
    }

    SUBCASE("Tree with double values and k = 10") {
        Tree<double, 10> tree;

        Node<double> root_node(1.5);
        tree.add_root(root_node);

        // Adding children nodes
        std::vector<Node<double>> children;
        for (int i = 0; i < 10; ++i) {
            children.emplace_back(2.5 + i);  // Values will be 2.5, 3.5, ..., 11.5
            tree.add_sub_node(root_node, children.back());
        }

        // Verify structure and values
        CHECK(tree.get_root()->get_value() == 1.5);
        CHECK(tree.get_root()->get_children().size() == 10);
        for (size_t i = 0; i < tree.get_root()->get_children().size(); ++i) {
            CHECK(tree.get_root()->get_children()[i]->get_value() == 2.5 + i);
            CHECK(tree.get_root()->get_children()[i]->get_children().empty());  // No grandchildren in this test
            }
        }
}

std::string capture_output(std::function<void()> func) {
    std::stringstream buffer;
    std::streambuf *old = std::cout.rdbuf(buffer.rdbuf());
    func();
    std::cout.rdbuf(old);
    return buffer.str();
}

TEST_CASE("Tree Traversals- with in,pre,post order iterator to binary tree") {
    Node<int> root_node(10);
    Tree<int> tree;
    tree.add_root(root_node);

    Node<int> n1(2);
    Node<int> n2(8);
    Node<int> n3(4);
    Node<int> n4(7);
    Node<int> n5(6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    SUBCASE("Post-order Traversal") {
        std::string expected =
            "The post-order of the tree is:\n"
            "6\n"
            "8\n"
            "7\n"
            "4\n"
            "2\n"
            "10\n";

        std::string output = capture_output([&]() {
            tree.post_order_traversal();
        });

        // Remove trailing whitespace from expected and output
        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }

    SUBCASE("In-order Traversal") {
        std::string expected =
            "The in-order of the tree is:\n"
            "4\n"
            "2\n"
            "7\n"
            "10\n"
            "6\n"
            "8\n";

        std::string output = capture_output([&]() {
            tree.in_order_traversal();
        });

        // Remove trailing whitespace from expected and output
        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }

    SUBCASE("Pre-order Traversal (Binary Tree)") {
        std::string expected =
            "The pre-order of the tree is:\n"
            "10\n"
            "2\n"
            "4\n"
            "7\n"
            "8\n"
            "6\n";

        std::string output = capture_output([&]() {
            tree.pre_order_traversal();
        });

        // Remove trailing whitespace from expected and output
        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }
}

TEST_CASE("Tree Traversals - with in,pre,post order iterator to Non-Binary Tree(will use the DFS iter)") {
    Node<string> root_node4("root");
    Tree<string, 3> tree4;
    tree4.add_root(root_node4);

    Node<string> nodeS1("child1");
    Node<string> nodeS2("child2");
    Node<string> nodeS3("child3");
    Node<string> nodeS4("child4");

    tree4.add_sub_node(root_node4, nodeS1);
    tree4.add_sub_node(root_node4, nodeS2);
    tree4.add_sub_node(root_node4, nodeS3);
    tree4.add_sub_node(nodeS1, nodeS4);

    SUBCASE("Post-order Traversal") {
        std::string expected =
            "Post-order traversal is not suitable for non-binary trees; performing DFS traversal from the root:\n"
            "root\n"
            "child1\n"
            "child4\n"
            "child2\n"
            "child3\n";

        std::string output = capture_output([&]() {
            tree4.post_order_traversal();
        });

        // Remove trailing whitespace from expected and output
        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }

    SUBCASE("In-order Traversal") {
        std::string expected =
            "In-order traversal is not suitable for non-binary trees; performing DFS traversal from the root:\n"
            "root\n"
            "child1\n"
            "child4\n"
            "child2\n"
            "child3\n";

        std::string output = capture_output([&]() {
            tree4.in_order_traversal();
        });

        // Remove trailing whitespace from expected and output
        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }

    SUBCASE("Pre-order Traversal") {
        std::string expected =
            "Pre-order traversal is not suitable for non-binary trees; performing DFS traversal from the root:\n"
            "root\n"
            "child1\n"
            "child4\n"
            "child2\n"
            "child3\n";

        std::string output = capture_output([&]() {
            tree4.pre_order_traversal();
        });

        // Remove trailing whitespace from expected and output
        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }
}

TEST_CASE("Tree Traversals - BFS and DFS iterators") {
    // Binary Tree
    Node<int> root_node1(10);
    Tree<int> tree1;
    tree1.add_root(root_node1);

    Node<int> n1(2);
    Node<int> n2(8);
    Node<int> n3(4);
    Node<int> n4(7);
    Node<int> n5(6);

    tree1.add_sub_node(root_node1, n1);
    tree1.add_sub_node(root_node1, n2);
    tree1.add_sub_node(n1, n3);
    tree1.add_sub_node(n1, n4);
    tree1.add_sub_node(n2, n5);

    SUBCASE("BFS Traversal - Binary Tree") {
        std::string expected =
            "10\n"
            "2\n"
            "8\n"
            "4\n"
            "7\n"
            "6\n";

        std::string output = capture_output([&]() {
            for (auto node_iter = tree1.begin_bfs_scan(); node_iter != tree1.end_bfs_scan(); ++node_iter) {
                std::cout << node_iter->get_value() << std::endl;
            }
        });

        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }

    SUBCASE("DFS Traversal - Binary Tree") {
        std::string expected =
            "10\n"
            "2\n"
            "4\n"
            "7\n"
            "8\n"
            "6\n";

        std::string output = capture_output([&]() {
            for (auto node_iter = tree1.begin_dfs_scan(); node_iter != tree1.end_dfs_scan(); ++node_iter) {
                std::cout << node_iter->get_value() << std::endl;
            }
        });

        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }

    // Non-binary Tree
    Node<std::string> root_node2("root");
    Tree<std::string, 3> tree2;
    tree2.add_root(root_node2);

    Node<std::string> node1("child1");
    Node<std::string> node2("child2");
    Node<std::string> node3("child3");
    Node<std::string> node4("child4");

    tree2.add_sub_node(root_node2, node1);
    tree2.add_sub_node(root_node2, node2);
    tree2.add_sub_node(root_node2, node3);
    tree2.add_sub_node(node1, node4);

    SUBCASE("BFS Traversal - Non-binary Tree") {
        std::string expected =
            "root\n"
            "child1\n"
            "child2\n"
            "child3\n"
            "child4\n";

        std::string output = capture_output([&]() {
            for (auto node_iter = tree2.begin_bfs_scan(); node_iter != tree2.end_bfs_scan(); ++node_iter) {
                std::cout << node_iter->get_value() << std::endl;
            }
        });

        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }

    SUBCASE("DFS Traversal - Non-binary Tree") {
        std::string expected =
            "root\n"
            "child1\n"
            "child4\n"
            "child2\n"
            "child3\n";

        std::string output = capture_output([&]() {
            for (auto node_iter = tree2.begin_dfs_scan(); node_iter != tree2.end_dfs_scan(); ++node_iter) {
                std::cout << node_iter->get_value() << std::endl;
            }
        });

        expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
        output.erase(output.find_last_not_of(" \n\r\t") + 1);

        CHECK(output == expected);
    }
}

TEST_CASE("Convert binary tree to min heap") {
    // Create a binary tree
    Node<double> root_node(4.4);
    Tree<double> tree;
    tree.add_root(root_node);

    Node<double> n1(6.2);
    Node<double> n2(2.1);
    Node<double> n3(1.3);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // Capture the output of the myHeap function
    std::string output = capture_output([&]() {
        tree.myHeap();
    });

    std::string expected =
        "The Nodes of the Min heap by order:\n"
        "1.3\n"
        "1.5\n"
        "1.6\n"
        "6.2\n"
        "4.4\n"
        "2.1\n";

    // Remove trailing whitespace from expected and output
    expected.erase(expected.find_last_not_of(" \n\r\t") + 1);
    output.erase(output.find_last_not_of(" \n\r\t") + 1);

    // Compare the output with the expected result
    if(output != expected) {
        std::cerr << "Expected:\n" << expected << "\nActual:\n" << output << std::endl;
    }

    CHECK(output == expected);
}

TEST_CASE("Try to convert non-binary tree to min heap") {
    // Create a non-binary tree
    Node<int> root_node(1);
    Tree<int, 3> tree; // Not a binary tree

    // Adding nodes to create a non-binary tree
    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    tree.add_root(root_node);
    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(root_node, n3);

    // Capture the output of the myHeap function
    std::string output = capture_output([&]() {
        tree.myHeap();
    });

    std::string expected = "This Tree is not binary: Heap transformation is only supported for binary trees.\n";

    // Compare the output with the expected result
    CHECK(output == expected);
}
