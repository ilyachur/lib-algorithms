#include <gtest/gtest.h>
#include <structures/structures.h>
#include <gmock/gmock.h>

#include <string>

class tree_node_tests: public ::testing::Test {
protected:
    virtual void TearDown() {
    }

    virtual void SetUp() {
    }

public:
};

TEST_F(tree_node_tests, create_nodes) {
    Structures::TreeNode<std::string> *node = new Structures::TreeNode<std::string>("val", 2);
    Structures::TreeNode<std::string> *node1 = new Structures::TreeNode<std::string>("test1", 0);
    Structures::TreeNode<std::string> *node2 = new Structures::TreeNode<std::string>("test2", 1);
    EXPECT_NE(nullptr, node->getAllChilds());
    EXPECT_EQ(2, node->getChildsCount());
    EXPECT_EQ("val", node->getValue());
    EXPECT_EQ(nullptr, node->getChild(0));
    EXPECT_EQ(nullptr, node->getChild(1));
    EXPECT_EQ(nullptr, node->getChild(2));

    EXPECT_EQ(nullptr, node1->getAllChilds());
    EXPECT_EQ(0, node1->getChildsCount());
    EXPECT_EQ("test1", node1->getValue());
    EXPECT_EQ(nullptr, node1->getChild(0));

    EXPECT_NE(nullptr, node2->getAllChilds());
    EXPECT_EQ(1, node2->getChildsCount());
    EXPECT_EQ("test2", node2->getValue());
    EXPECT_EQ(nullptr, node2->getChild(0));
    EXPECT_EQ(nullptr, node2->getChild(1));

    node->addChild(0, node1);
    node->addChild(1, "testCreate", 3);
    EXPECT_NE(nullptr, node->getChild(1));
    node->getChild(1)->addChild(2, node2);

    EXPECT_EQ(node1, node->getChild(0));
    EXPECT_EQ(node2, node->getChild(1)->getChild(2));
    EXPECT_EQ("test1", node->getChild(0)->getValue());
    EXPECT_EQ("test2", node->getChild(1)->getChild(2)->getValue());
    EXPECT_EQ("testCreate", node->getChild(1)->getValue());

    node1->getValue();
    delete node;
}
