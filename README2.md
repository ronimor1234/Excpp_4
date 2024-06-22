# Excpp_4
//ID: 208018028, Mail: ronimordechai70@gmail.com
# Iterator and Template-Based Tree Program

Welcome to the Iterator and Template-Based Tree Program, a C++ project implementing a generic tree container with various traversal methods using iterators and templates, the program use the GUI representation using SFML.

## Table of Contents
- [Project Overview](#project-overview)
- [Installation](#installation)
- [Usage](#usage)
- [Core Components](#core-components)
- [Iterators](#iterators)
- [Heap Transformation](#heap-transformation)
- [Important Notes](#important-notes)
- [Summary](#summary)

## Project Overview
The Tree Program implements a generic tree data structure in C++ with support for various iterators and GUI visualization using SFML. The program allows you to create a tree with k children (default k=2, i.e., binary tree), traverse the tree using different iterators, and transform the tree into a min heap for binary trees.

### Core Files:
- **Tree.hpp**: Defines the tree structure using templates with k children and the iterators.
- **Node.hpp**: Defines the Node class used in the tree.
- **Complex.hpp** and **Complex.cpp**: Implement the Complex class used for node data.
- **Demo.cpp**: Demonstrates the functionality of the tree, including iterators and SFML GUI output.
- **Test.cpp**: Contains test cases for validating tree functionality.

### Additional Files:
- **Makefile**: Facilitates building and compiling the project.

## Installation
To set up the project, you need a g++ compiler and build tools. The `Makefile` can be used to compile the project.

# Run the Makefile
make tree

## Usage
After compiling the project with `make tree`, you can run the demo to see the implemented functions of the tree and the test to see some edge cases.

# Run the demo
./demo

# Run the test
./test

## Core Components
### Tree.hpp
- Manages the overall tree structure with k children, defaulting to a binary tree (k=2).
- Supports insertion, deletion, and traversal operations.

### Node.hpp
- Represents nodes in the tree, storing complex data.

### Complex.hpp and Complex.cpp
- Define and implement the Complex class used in nodes.

## Iterators
The program supports the following iterators:

### Binary Tree Iterators:
1. **In-order**: Traverses left subtree, root, then right subtree.
2. **Pre-order**: Traverses root, left subtree, then right subtree.
3. **Post-order**: Traverses left subtree, right subtree, then root.

### Non-Binary Tree Iterators:
- If the tree is not binary, the program uses DFS from the root.

### BFS and DFS Iterators:
- Both BFS and DFS iterators are available for all tree structures.

## Heap Transformation
For binary trees, the program supports transforming the tree into a min heap using the `myHeap` function.

- **Binary Tree**: Converts the tree into a min heap.
- **Non-Binary Tree**: Displays "This Tree is not binary: Heap transformation is only supported for binary trees."

## Important Notes
- The program uses the SFML library for GUI output, representing the tree visually using the `operator <<`.
- The nodes of the tree are from the same type: int\doubel\long\string or Complex.

## Summary
This project implements a flexible and efficient tree structure in C++, providing support for both binary and non-binary trees. It includes multiple traversal methods and iterators, ensuring robust functionality for various tree operations. The program utilizes the SFML library for GUI output, allowing visual representation of the tree. With comprehensive test cases and error handling, the project is designed to be reliable and extensible for future enhancements.

Explore the Iterator and Template-Based Tree Program and enjoy experimenting with different tree structures and traversal methods!