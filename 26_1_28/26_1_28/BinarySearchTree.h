#pragma once
#include<iostream>
using namespace std;

namespace wh {
	template<class K>
	struct BSTNode
	{
		K _key;
		BSTNode<K>* _left;
		BSTNode<K>* _right;

		BSTNode(const K& key)
			:_key(key)
			, _left(nullptr)
			, _right(nullptr)
		{
		}
	};


	template<class K>
	struct BSTree
	{
		typedef BSTNode<K> Node;
		bool Insert(const K& key)
		{
			if (_root == nullptr)
			{
				_root = new Node(key);
			}
			Node* parent = nullptr;
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;//防止函数栈帧销毁之后走丢
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur = cur->_left;
				}
				else {//此时为key == cur->_key
					return false;
				}
			}
			cur = new Node(key);//此时cur为空
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else {
				parent->_left = cur;
			}

			return true;
		}
		void InOrder()
		{
			_InOrder(_root);
		}

	private:
		Node* _root = nullptr;
		void _InOrder(Node* root)
		{
			if (root == nullptr)
				return;
			_InOrder(root->_left);
			cout << root->_key << " ";
			_InOrder(root->_right);
		}
	};
}
