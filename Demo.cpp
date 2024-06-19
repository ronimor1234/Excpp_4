// ID: 208018028, Mail: ronimordechai70@gmail.com
/**
 * Demo app for Ex4
 */
// #include <iostream>
// #include <string>
// #include "node.hpp"
// #include "tree.hpp"

// using namespace std;

// int main()
// {

//     Node<double> root_node = Node(1.1);
//     Tree<double> tree; // Binary tree that contains doubles.
//     tree.add_root(root_node);
//     Node<double> n1 = Node(1.2);
//     Node<double> n2 = Node(1.3);
//     Node<double> n3 = Node(1.4);
//     Node<double> n4 = Node(1.5);
//     Node<double> n5 = Node(1.6);

//     tree.add_sub_node(root_node, n1);
//     tree.add_sub_node(root_node, n2);
//     tree.add_sub_node(n1, n3);
//     tree.add_sub_node(n1, n4);
//     tree.add_sub_node(n2, n5);
   
//     // The tree should look like:
//     /**
//      *       root = 1.1
//      *     /       
//      *    1.2      1.3
//      *   /  \      /
//      *  1.4  1.5  1.6
//      */

//     for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node)
//     {
//         cout << node->get_value() << endl;
//     } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

//     for (auto node = tree.begin_post_order(); node != tree.end_post_order(); ++node)
//     {
//         cout << node->get_value() << endl;
//     } // prints: 1.4, 1.5, 1.2, 1.6, 1.3, 1.1

//     for (auto node = tree.begin_in_order(); node != tree.end_in_order(); ++node)
//     {
//         cout << node->get_value() << endl;
//     } // prints: 1.4, 1.2, 1.5, 1.1, 1.6, 1.3

//     for (auto node = tree.begin_bfs_scan(); node != tree.end_bfs_scan(); ++node)
//     {
//         cout << node->get_value() << endl;
//     } // prints: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

//     for (auto node : tree)
//     {
//         cout << node.get_value() << endl;
//     } // same as BFS: 1.1, 1.2, 1.3, 1.4, 1.5, 1.6

//     cout << tree; // Should print the graph using GUI.

//     Tree<double,3> three_ary_tree; // 3-ary tree.
//     three_ary_tree.add_root(root_node);
//     three_ary_tree.add_sub_node(root_node, n1);
//     three_ary_tree.add_sub_node(root_node, n2);
//     three_ary_tree.add_sub_node(root_node, n3);
//     three_ary_tree.add_sub_node(n1, n4);
//     three_ary_tree.add_sub_node(n2, n5);

//      // The tree should look like:
//     /**
//      *       root = 1.1
//      *     /      |     
//      *    1.2    1.3    1.4
//      *   /        |
//      *  1.5      1.6
//      */
    
// }


// #include <iostream>
// #include <string>
// #include "Node.hpp"
// #include "Tree.hpp"
// #include "Complex.hpp"

// using namespace std;

// int main() {
    // Node<double> root_node(1.1);
    // Tree<double> tree; // Binary tree that contains doubles.
    // tree.add_root(root_node);
    // Node<double> n1(1.2);
    // Node<double> n2(1.3);
    // Node<double> n3(1.4);
    // Node<double> n4(1.5);
    // Node<double> n5(1.6);

    // auto root = tree.get_root();
    // tree.add_sub_node(root, n1);
    // tree.add_sub_node(root, n2);
    // tree.add_sub_node(root->children[0], n3);
    // tree.add_sub_node(root->children[0], n4);
    // tree.add_sub_node(root->children[1], n5);

    // for (auto it = tree.begin_pre_order(); it != tree.end_pre_order(); ++it) {
    //     cout << (*it)->get_value() << endl;
    // } // prints: 1.1, 1.2, 1.4, 1.5, 1.3, 1.6

    // // Implement other traversals and print the values similarly...

    // cout << tree; // Should print the graph using GUI.

    // Tree<double, 3> three_ary_tree; // 3-ary tree.
    // three_ary_tree.add_root(root_node);
    // three_ary_tree.add_sub_node(root, n1);
    // three_ary_tree.add_sub_node(root, n2);
    // three_ary_tree.add_sub_node(root, n3);
    // three_ary_tree.add_sub_node(root->children[0], n4);
    // three_ary_tree.add_sub_node(root->children[1], n5);

    // return 0;
// }

#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

int main() {
    // check int tree
    Node<int> root_node1(1);
    Tree<int> tree1; // Binary tree that contains doubles.
    tree1.add_root(root_node1);

    Node<int> n1(2);
    Node<int> n2(3);
    Node<int> n3(4);
    Node<int> n4(5);
    Node<int> n5(6);

    tree1.add_sub_node(root_node1, n1);
    tree1.add_sub_node(root_node1, n2);
    tree1.add_sub_node(n1, n3);
    tree1.add_sub_node(n1, n4);
    tree1.add_sub_node(n2, n5);

    // Draw the tree
    std::cout << tree1;

    cout << "The in-order of tree1 is:" <<endl;
    for (auto node_iter1 = tree1.begin_in_order(); node_iter1 != tree1.end_in_order(); ++node_iter1)
    {
        cout << node_iter1->get_value() << endl;
    }

    cout << "The pre-order of tree1 is:" << endl;
    for (auto node_iter2 = tree1.begin_pre_order(); node_iter2 != tree1.end_pre_order(); ++node_iter2)
    {
        cout << node_iter2->get_value() << endl;
    }

    cout << "The post-order of tree1 is:" << endl;
    for (auto node_iter3 = tree1.begin_post_order(); node_iter3 != tree1.end_post_order(); ++node_iter3)
    {
        cout << node_iter3->get_value() << endl;
    }

    // check doubel tree
    Node<double> root_node2(1.1);
    Tree<double> tree2; // Binary tree that contains doubles.
    tree2.add_root(root_node2);

    Node<double> node1(1.2);
    Node<double> node2(1.3);
    Node<double> node3(1.4);
    Node<double> node4(1.5);
    Node<double> node5(1.6);

    tree2.add_sub_node(root_node2, node1);
    tree2.add_sub_node(root_node2, node2);
    tree2.add_sub_node(node1, node3);
    tree2.add_sub_node(node1, node4);
    tree2.add_sub_node(node2, node5);

    // Draw the tree
    std::cout << tree2;

    // check of complex tree
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
    std::cout << tree3;

    // check for string tree
    // Node<string> root_node4("hi");
    // Tree<string> tree4; // Binary tree that contains doubles.
    // tree4.add_root(root_node4);

    // Node<string> nodeS1("r");
    // Node<string> nodeS2("d");
    // Node<string> nodeS3("ff");
    // Node<string> nodeS4("sc");
    // Node<string> nodeS5("ff");

    // tree4.add_sub_node(root_node4, nodeS1);
    // tree4.add_sub_node(root_node4, nodeS2);
    // tree4.add_sub_node(nodeS1, nodeS3);
    // tree4.add_sub_node(nodeS1, nodeS4);
    // tree4.add_sub_node(nodeS2, nodeS5);

    // Create a tree with k = 3 children
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

    // Draw the tree
    std::cout << tree4;

    // Create a tree with k = 5 children
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

    // Add more children to node5_1
    Node<int> node5_7(22);
    Node<int> node5_8(23);

    tree5.add_sub_node(node5_1, node5_7);
    tree5.add_sub_node(node5_1, node5_8);

    // Draw the tree
    std::cout << tree5;

    return 0;
}