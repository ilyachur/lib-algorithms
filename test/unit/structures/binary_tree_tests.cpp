#include <gtest/gtest.h>
#include <structures/structures.h>
#include <gmock/gmock.h>

class binary_tree_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
};

TEST_F(binary_tree_tests, create_binary_tree) {
    Structures::Tree::BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(20);
    tree.insert(10);
    tree.insert(-10);
    tree.insert(-5);
    tree.insert(0);
    tree.insert(0);
    tree.insert(30);
    Structures::Tree::Node<int> *root = tree.getRoot();
    EXPECT_EQ(root, tree.getRoot());
    EXPECT_EQ(root, tree.search(1));
    EXPECT_EQ(-10, tree.min()->getValue());
    EXPECT_EQ(30, tree.max()->getValue());
    EXPECT_EQ(root->getChild(0), tree.search(-10));
    EXPECT_EQ(root->getChild(0)->getChild(0), nullptr);
    EXPECT_EQ(root->getChild(0)->getChild(1), tree.search(-5));
    EXPECT_EQ(root->getChild(0)->getChild(1)->getChild(0), nullptr);
    EXPECT_EQ(root->getChild(0)->getChild(1)->getChild(1), tree.search(0));
    EXPECT_EQ(root->getChild(1), tree.search(20));
    EXPECT_EQ(root->getChild(1)->getChild(0), tree.search(10));
    EXPECT_EQ(root->getChild(1)->getChild(0), tree.search(10));
}

TEST_F(binary_tree_tests, check_left_right_nodes) {
    Structures::Tree::BinaryTree<int> tree;
    tree.insert(1);
    tree.insert(20);
    tree.insert(10);
    tree.insert(-10);
    tree.insert(-5);
    tree.insert(0);
    tree.insert(0);
    tree.insert(30);
    Structures::Tree::Node<int> *root = tree.getRoot();
    EXPECT_EQ(root, tree.getRoot());
    EXPECT_EQ(root, tree.search(1));
    //EXPECT_EQ(root->getChild(0), root->getChild(Structures::Tree::BinaryTree::Child::left));
    //EXPECT_EQ(root->getChild(1), root->getChild(Structures::Tree::BinaryTree::Child::right));
}
