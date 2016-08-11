#pragma once

namespace  Structures {
    /**
     * Class implements node for tree
     */
    template <class T>
    class TreeNode {
    private:
        T value;
        unsigned int child_number;
        TreeNode **childs = nullptr;

        void destroy() {
            if (childs != nullptr) {
                for (auto i = 0; i < child_number; i++) {
                    delete childs[i];
                }
                delete[] childs;
                child_number = 0;
            }
        }

    public:
        /**
         * Constructor
         * @param children_num - Number of childrens
         * @return new object
         */
        TreeNode(const int children_num) noexcept {
            child_number = children_num;
            if (child_number > 0) {
                childs = new TreeNode *[child_number];
                for (auto i = 0; i < child_number; i++) {
                    childs[i] = nullptr;
                }
            }
        }

        /**
         * Constructor
         * @param val - value for node
         * @param children_num - Number of childrens
         * @return new object
         */
        TreeNode(const T val, const int children_num) noexcept {
            child_number = children_num;
            if (child_number > 0) {
                childs = new TreeNode *[child_number];
                for (auto i = 0; i < child_number; i++) {
                    childs[i] = nullptr;
                }
            }
            value = val;
        }

        /**
         * Copy constructor
         * @param node cope formthis node
         * @return new object
         */
        TreeNode(const TreeNode& node) noexcept {
            child_number = node.getChildsCount();
            childs = node.getAllChilds();
            value = node.getValue();
        }

        /**
         * Move constructor
         * @param node move this object
         * @return new object
         */
        TreeNode(const TreeNode&& node) noexcept {
            child_number = node.getChildsCount();
            childs = new TreeNode*[child_number];
            for (auto i = 0; i < child_number; i++) {
                childs[i] = node.getChild(i);
            }
            value = node.getValue();
            node.destroy();
        }

        /**
         * Destructor
         */
        ~TreeNode() noexcept {
            destroy();
        }

        /**
         * Get all cildren nodes
         * @return array with childrens
         */
        TreeNode **getAllChilds() const noexcept {
            return childs;
        }

        /**
         * Get child at index
         * @param index - child index
         * @return nullptr if object is not exists or return child
         */
        TreeNode *getChild(const unsigned int index) const noexcept {
            if (index < 0 || index >= child_number) {
                return nullptr;
            }
            return childs[index];
        }

        /**
         * Get children count
         * @return children number
         */
        unsigned int getChildsCount() const noexcept {
            return child_number;
        }

        /**
         * Get value
         * @return node value
         */
        T getValue() const noexcept {
            return value;
        }

        /**
         * Add child to node
         * @param index child index
         * @param node node for adding
         */
        void addChild(const unsigned int index, TreeNode* node) noexcept {
            if (index < 0 || index > child_number) return;

            TreeNode *oldNode = getChild(index);
            if (oldNode != nullptr) {
                delete oldNode;
            }

            childs[index] = node;
        }

        /**
         * Add child to node
         * @param index child index
         * @param value value for child node
         */
        void addChild(const unsigned int index, const T value) noexcept {
            if (index < 0 || index > child_number) return;

            TreeNode *node = new TreeNode(value, child_number);
            addChild(index, node);
        }

        /**
         * Add child to node
         * @param index child index
         * @param value value for child node
         * @param children_count number of childs in child mode
         */
        void addChild(const unsigned int index, const T value, const unsigned int children_count) noexcept {
            if (index < 0 || index > child_number) return;

            TreeNode *node = new TreeNode(value, children_count);
            addChild(index, node);
        }

    };

    class Tree {

        Tree * root;
        Tree ** childs;

    public:
        //Tree(): child_number(2) {
        //}

    };
}