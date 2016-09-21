#pragma once

namespace  Structures {
    namespace Tree {
        /**
         * Class implements node for tree
         */
        template<class T>
        class Node {
        private:
            T value;
            unsigned int child_number;
            Node **childs = nullptr;
            Node *parent;

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
            Node(const int children_num, Node *parent = nullptr) noexcept {
                child_number = children_num;
                this->parent = parent;
                if (child_number > 0) {
                    childs = new Node *[child_number];
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
            Node(const T val, const int children_num, Node *parent = nullptr) noexcept {
                child_number = children_num;
                this->parent = parent;
                if (child_number > 0) {
                    childs = new Node *[child_number];
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
            Node(const Node &node) noexcept {
                child_number = node.getChildsCount();
                childs = node.getAllChilds();
                value = node.getValue();
            }

            /**
             * Move constructor
             * @param node move this object
             * @return new object
             */
            Node(const Node &&node) noexcept {
                child_number = node.getChildsCount();
                childs = new Node *[child_number];
                for (auto i = 0; i < child_number; i++) {
                    childs[i] = node.getChild(i);
                }
                value = node.getValue();
                node.destroy();
            }

            /**
             * Destructor
             */
            ~Node() noexcept {
                destroy();
            }

            /**
             * Get all cildren nodes
             * @return array with childrens
             */
            Node **getAllChilds() const noexcept {
                return childs;
            }

            Node *getParent() noexcept {
                return parent;
            }

            void setParent(Node * prt) noexcept {
                parent = prt;
            }

            /**
             * Get child at index
             * @param index - child index
             * @return nullptr if object is not exists or return child
             */
            Node *getChild(const unsigned int index) const noexcept {
                if (index < 0 || index >= child_number) {
                    return nullptr;
                }
                return childs[index];
            }

            void setChild(Node * newNode, const unsigned int index) const noexcept {
                if (index < 0 || index >= child_number) {
                    return;
                }
                if (childs[index] != nullptr) {
                    delete childs[index];
                }
                childs[index] = newNode;
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
             * Set value
             * @param value value for child node
             */
            void setValue(T value)  noexcept {
                this->value = value;
            }

            /**
             * Add child to node
             * @param index child index
             * @param node node for adding
             */
            void addChild(const unsigned int index, Node *node) noexcept {
                if (index < 0 || index > child_number) return;

                Node *oldNode = getChild(index);
                if (oldNode != nullptr) {
                    delete oldNode;
                }

                node->parent = this;

                childs[index] = node;
            }

            /**
             * Add child to node
             * @param index child index
             * @param value value for child node
             */
            void addChild(const unsigned int index, const T value) noexcept {
                if (index < 0 || index > child_number) return;

                Node *node = new Node(value, child_number);
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

                Node *node = new Node(value, children_count);
                addChild(index, node);
            }

        };

        template<class T>
        class Tree {
        protected:
            Node<T> *root;

        public:
            Tree() {
                root = nullptr;
            }

            ~Tree() {
                delete root;
            }

            /**
             * Copy constructor
             * @param tree cope formthis node
             * @return new object
             */
            Tree(const Tree &tree) noexcept {
            }

            /**
             * Move constructor
             * @param tree move this object
             * @return new object
             */
            Tree(const Tree &&tree) noexcept {
            }

            Node<T> *getRoot() noexcept {
                return root;
            }

            virtual Node<T>* min() noexcept = 0;
            virtual Node<T>* max() noexcept = 0;
            virtual Node<T>* min(Node<T> *element) noexcept = 0;
            virtual Node<T>* max(Node<T> *element) noexcept = 0;
            virtual Node<T>* successor(Node<T> *element) noexcept = 0;
            virtual void insert(Node<T> *element) noexcept = 0;
            virtual Node<T> *search(T value) noexcept  = 0;
            virtual Node<T> *search(Node<T> *element, T value) noexcept  = 0;
            virtual void insert(T value) noexcept = 0;
            virtual void remove(Node<T> *element, bool recursive = false) noexcept = 0;
        };

        template <class T>
        class BinaryTree: public Tree<T> {
        public:
            static enum Child {
                left = 0,
                right = 1
            } child;

            virtual Node<T>* min() noexcept {
                return min(this->root);
            }

            virtual Node<T>* max() noexcept {
                return max(this->root);
            }

            virtual Node<T>* min(Node<T> *element) noexcept {
                while (element->getChild(Child::left) != nullptr) {
                    element = element->getChild(Child::left);
                }
                return element;
            }

            virtual Node<T>* max(Node<T> *element) noexcept {
                while (element->getChild(Child::right) != nullptr) {
                    element = element->getChild(Child::right);
                }
                return element;
            }

            virtual Node<T>* successor(Node<T> *element) noexcept {
                if (element->getChild(Child::right) != nullptr) {
                    return min(element->getChild(Child::right));
                }
                Node<T>* parent = element->getParent();
                Node<T>* currentElement = element;
                while(parent != nullptr && currentElement == parent->getChild(Child::right)) {
                    currentElement = parent;
                    parent = parent->getParent();
                }
                return parent;
            }

            virtual void insert(Node<T>* element) noexcept {
                Node<T> *tmp = this->root;
                Node<T> *parent = nullptr;
                while (tmp != nullptr) {
                    parent = tmp;
                    if (element->getValue() < tmp->getValue()) {
                        tmp = tmp->getChild(Child::left);
                    } else {
                        tmp = tmp->getChild(Child::right);
                    }
                }
                element->setParent(parent);
                if (parent == nullptr) {
                    this->root = element;
                } else if (element->getValue() < parent->getValue()) {
                    parent->setChild(element, Child::left);
                } else {
                    parent->setChild(element, Child::right);
                }
            }

            virtual void insert(T value) noexcept {
                Node<T> * element = new Node<T>(value, 2);
                insert(element);
            }

            virtual void remove(Node<T> *element, bool recursive = false) noexcept {
                if (recursive) {
                    delete element;
                    return;
                }

                if (element->getChild(Child::left) == nullptr || element->getChild(Child::right) == nullptr) {
                    if (element->getChild(Child::left) == nullptr && element->getChild(Child::right) == nullptr) {
                        if (element->getParent() != nullptr) {
                            for (auto i = 0; i < element->getParent()->getChildsCount(); i++) {
                                if (element->getParent()->getChild(i) == element) {
                                    element->getParent()->setChild(nullptr, i);
                                    break;
                                }
                            }
                        }
                    } else {
                        int change_child = Child::left;
                        if (element->getChild(Child::right) != nullptr) {
                            change_child = Child::right;
                        }
                        element->getChild(change_child)->setParent(element->getParent());
                        if (element->getParent() != nullptr) {
                            for (auto i = 0; i < element->getParent()->getChildsCount(); i++) {
                                if (element->getParent()->getChild(i) == element) {
                                    element->getParent()->setChild(element->getChild(change_child), i);
                                    break;
                                }
                            }
                        }
                    }
                    delete element;
                    return;
                } else {
                    Node<T> * suc = successor(element);
                    element->setValue(suc->getValue());
                    if (suc->getParent()->getChild(Child::left) == suc) {
                        suc->getParent()->setChild(suc->getChild(Child::right), Child::left);
                        if (suc->getChild(Child::right) != nullptr) {
                            suc->getChild(Child::right)->setParent(suc->getParent());
                        }
                    } else {
                        suc->getParent()->setChild(suc->getChild(Child::right), Child::right);
                        if (suc->getChild(Child::right) != nullptr) {
                            suc->getChild(Child::right)->setParent(suc->getParent());
                        }
                    }
                    delete suc;
                }
            }

            virtual Node<T> *search(Node<T> *element, T value) noexcept {
                if (element == nullptr || value == element->getValue()) {
                    return element;
                }
                if (value < element->getValue()) {
                    return search(element->getChild(Child::left), value);
                } else {
                    return search(element->getChild(Child::right), value);
                }
            }

            virtual Node<T> *search(T value) noexcept {
                return search(this->root, value);
            }

        };
    }
}