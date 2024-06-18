// ID: 208018028, Mail: ronimordechai70@gmail.com
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "Node.hpp"
#include "Tree.hpp"
#include "Complex.hpp"
#include <iostream>

using namespace std;

int main() {
    Node<int> root_node(1);
    Tree<int> tree;
    // tree.add_root(root_node);
    Node<int> n1(2);
    Node<int> n2(3);

    // tree.add_sub_node(root_node, n1);
    // tree.add_sub_node(root_node, n2);

    // for (auto node = tree.begin_pre_order(); node != tree.end_pre_order(); ++node) {
    //     cout << node->get_value() << endl;
    // }

    return 0;
}
