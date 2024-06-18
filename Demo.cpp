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
    
    Node<double> root_node(1.1);
    Tree<double> tree; // Binary tree that contains doubles.
    tree.add_root(root_node);

    Node<double> n1(1.2);
    Node<double> n2(1.3);
    Node<double> n3(1.4);
    Node<double> n4(1.5);
    Node<double> n5(1.6);

    tree.add_sub_node(root_node, n1);
    tree.add_sub_node(root_node, n2);
    tree.add_sub_node(n1, n3);
    tree.add_sub_node(n1, n4);
    tree.add_sub_node(n2, n5);

    // Draw the tree
    // std::cout << tree;

    // check of complex tree
    Tree<Complex> tree2;

    Node <Complex> root(Complex(1.0, 2.0));
    Node<Complex> child1(Complex(3.0, 4.0));
    Node<Complex> child2(Complex(5.0, 6.0));

    tree2.add_root(root);
    tree2.add_sub_node(root, child1);
    tree2.add_sub_node(root, child2);

    std::cout << tree2;

    // check for doubel tree
    // Tree<double> tree1;

    // // Create nodes
    // // auto root = std::make_shared<Node<double>>(1.2);
    // auto child1 = std::make_shared<Node<double>>(2.3);
    // auto child2 = std::make_shared<Node<double>>(3.4);

    // // Build tree structure
    // root->add_child(child1);
    // root->add_child(child2);
    // tree1.add_root(*root);

    // std::cout << tree1;
    return 0;
}
