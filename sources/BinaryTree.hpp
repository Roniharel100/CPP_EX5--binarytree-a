#pragma once
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

namespace ariel
{
    template <typename T>

    class BinaryTree
    {
    private:
        struct Node
        {
            T data;
            Node *left, *right, *father;
            Node(const T &data, Node *left, Node *right, Node *father)
                : data(data), left(left), right(right), father(father) {}
        };
        Node *root;

    public:
        // inorder class
        class inorder
        {
        private:
            Node *in_node;

        public:
            inorder(Node *ptr) : in_node(ptr) {}

            T *operator->() const
            {
                return &(in_node->data);
            }

            T &operator*() const
            {
                return in_node->data;
            }

            inorder &operator++()
            {
                return *this;
            }

            const inorder operator++(int)
            {
                return *this;
            }

            bool operator==(const inorder &rhs) const
            {
                return false;
            }

            bool operator!=(const inorder &rhs) const
            {
                return false;
            }
        };

        // preorder class
        class preorder
        {
        private:
            Node *pre_node;

        public:
            preorder(Node *ptr) : pre_node(ptr) {}

            T *operator->() const
            {
                return &(pre_node->data);
            }

            T &operator*() const
            {
                return pre_node->data;
            }

            preorder &operator++()
            {
                return *this;
            }

            const preorder operator++(int)
            {
                return *this;
            }

            bool operator==(const preorder &rhs) const
            {
                return false;
            }
            bool operator!=(const preorder &rhs) const
            {
                return false;
            }
        };

        // postorder class
        class postorder
        {
        private:
            Node *post_node;

        public:
            postorder(Node *ptr) : post_node(ptr) {}

            T *operator->() const
            {
                return &(post_node->data);
            }

            T &operator*() const
            {
                return post_node->data;
            }

            postorder &operator++()
            {
                return *this;
            }

            const postorder operator++(int)
            {
                return *this;
            }
            bool operator==(const postorder &rhs) const
            {
                return false;
            }

            bool operator!=(const postorder &rhs) const
            {
                return false;
            }
        };

        // Binary tree functions
        BinaryTree &add_root(const T &root)
        {
            return *this;
        }

        BinaryTree &add_left(const T &father, const T &left)
        {
            return *this;
        }
        BinaryTree &add_right(const T &father, const T &right)
        {
            return *this;
        }
        inorder begin_inorder()
        {
            return inorder{root};
        }

        inorder end_inorder()
        {
            return inorder{nullptr};
        }
        preorder begin_preorder()
        {
            return preorder{root};
        }

        preorder end_preorder()
        {
            return preorder{nullptr};
        }

        postorder begin_postorder()
        {
            return postorder{root};
        }
        postorder end_postorder()
        {
            return postorder{nullptr};
        }

        inorder begin()
        {
            return begin_inorder();
        };
        inorder end()
        {
            return end_inorder();
        };
        friend std::ostream &operator<<(std::ostream &os, const BinaryTree<T> &binaryTree)
        {
            return os;
        }
    };
};
