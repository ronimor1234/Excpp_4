// ID: 208018028, Mail: ronimordechai70@gmail.com
/**
 * Demo application for Ex4 - Tree program with iterators and templates.
 * This program demonstrates the functionality of the Tree class with various data types and traversal methods.
 * It also showcases the transformation of the tree into a min heap for binary trees.
 */

#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    // Integer tree
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

    // Draw the tree
    cout << tree1;
    
    cout << "Integer Tree (tree1):\n" << endl;
    // Perform traversals
    cout <<"\n" << endl;
    tree1.post_order_traversal();
    tree1.in_order_traversal();
    tree1.pre_order_traversal();

    // BFS and DFS traversals
    cout << "The BFS of tree1 is:" << endl;
    for (auto node_iter4 = tree1.begin_bfs_scan(); node_iter4 != tree1.end_bfs_scan(); ++node_iter4) {
        cout << node_iter4->get_value() << endl;
    }
    cout << "\n" << endl;

    cout << "The DFS of tree1 is:" << endl;
    for (auto node_iter5 = tree1.begin_dfs_scan(); node_iter5 != tree1.end_dfs_scan(); ++node_iter5) {
        cout << node_iter5->get_value() << endl;
    }
    cout << "\n" << endl;

    // Convert tree1 to min heap
    tree1.myHeap();
    cout << tree1;

    // Double tree
    Node<double> root_node2(2.1);
    Tree<double> tree2; 
    tree2.add_root(root_node2);

    Node<double> node1(6.2);
    Node<double> node2(1.3);
    Node<double> node3(4.4);
    Node<double> node4(1.5);
    Node<double> node5(1.6);

    tree2.add_sub_node(root_node2, node1);
    tree2.add_sub_node(root_node2, node2);
    tree2.add_sub_node(node1, node3);
    tree2.add_sub_node(node1, node4);
    tree2.add_sub_node(node2, node5);

    // Draw the tree
    cout << "\nDouble Tree (tree2):\n" << tree2;

    // Perform traversals
    tree2.post_order_traversal();
    tree2.in_order_traversal();
    tree2.pre_order_traversal();

    // Convert tree2 to min heap
    tree2.myHeap();
    cout << tree2;

    // Complex tree
    Tree<Complex> tree3;

    Node <Complex> root(Complex(1.0, 2.0));
    Node<Complex> child1(Complex(3.0, 4.0));
    Node<Complex> child2(Complex(5.0, 6.0));
    Node<Complex> child3(Complex(2.0, 6.0));
    Node<Complex> child4(Complex(4.0, 6.0));

    tree3.add_root(root);
    tree3.add_sub_node(root, child1);
    tree3.add_sub_node(root, child2);
    tree3.add_sub_node(child2, child3);
    tree3.add_sub_node(child1, child4);

    // Draw the tree
    cout << "\nComplex Tree (tree3):\n" << tree3;

    // Perform traversals
    tree3.post_order_traversal();
    tree3.in_order_traversal();
    tree3.pre_order_traversal();

    // Convert tree3 to min heap
    tree3.myHeap();
    cout << tree3;

    // Tree with k = 3 children
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

    // Perform DFS traversal
    cout << "The DFS of tree4 is:" << endl;
    for (auto node_iter1 = tree4.begin_dfs_scan(); node_iter1 != tree4.end_dfs_scan(); ++node_iter1) {
        cout << node_iter1->get_value() << endl;
    }
    cout << "\n";

    // Perform other traversals
    tree4.pre_order_traversal();
    tree4.post_order_traversal();
    cout << "\n";
    tree4.in_order_traversal();

    // Draw the tree
    cout << "\nTree with k = 3 children (tree4):\n" << tree4;

    // Tree with k = 5 children
    Node<int> root_node5(1);
    Tree<int, 5> tree5;
    tree5.add_root(root_node5);

    Node<int> node5_1(11);
    Node<int> node5_2(12);
    Node<int> node5_3(13);
    Node<int> node5_4(14);
    Node<int> node5_5(15);

    tree5.add_sub_node(root_node5, node5_1);
    tree5.add_sub_node(root_node5, node5_2);
    tree5.add_sub_node(root_node5, node5_3);
    tree5.add_sub_node(root_node5, node5_4);
    tree5.add_sub_node(root_node5, node5_5);

    Node<int> node5_6(21);
    tree5.add_sub_node(node5_1, node5_6);

    // Convert tree5 to min heap
    tree5.myHeap();
    cout << "\n";

    // Add more children to node5_1
    Node<int> node5_7(22);
    Node<int> node5_8(23);

    tree5.add_sub_node(node5_1, node5_7);
    tree5.add_sub_node(node5_1, node5_8);

    // Perform DFS traversal
    cout << "The DFS of tree5 is:" << endl;
    for (auto node_iter6 = tree5.begin_dfs_scan(); node_iter6 != tree5.end_dfs_scan(); ++node_iter6) {
        cout << node_iter6->get_value() << endl;
    }
    cout << "\n";

    // Perform other traversals
    tree5.post_order_traversal();
    cout << "\n";
    tree5.in_order_traversal();
    tree5.pre_order_traversal();

    // Binary string tree
    Node<string> root_node6("root");
    Tree<string, 2> tree6;
    tree6.add_root(root_node6);

    Node<string> nodeS1_1("left_child");
    Node<string> nodeS2_2("right_child");
    Node<string> nodeS3_3("left_child2");
    Node<string> nodeS4_4("right_child2");

    tree6.add_sub_node(root_node6, nodeS1_1);
    tree6.add_sub_node(root_node6, nodeS2_2);
    tree6.add_sub_node(nodeS1_1, nodeS3_3);
    tree6.add_sub_node(nodeS1_1, nodeS4_4);

    // Before transformation to heap
    cout << tree6;

    // Convert tree6 to min heap
    tree6.myHeap();

    // After transformation to heap
    cout << tree6;

    return 0;
}
