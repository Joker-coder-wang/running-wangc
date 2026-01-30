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

		bool Find(const K& key)
		{
			if (_root == nullptr)
				return false;
			Node* cur =_root; 
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur->_right = cur;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur->_left = cur;
				}
				return true;
			}
			return false;
		}

		bool Erase(const K& key)
		{
			if (_root == nullptr)
				return false;
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (cur->_key < key)
				{
					parent = cur;
					cur->_right = cur;
				}
				else if (cur->_key > key)
				{
					parent = cur;
					cur->_left = cur;
				}
				else {
					//找到了key，现在进行删除操作
					if (cur->_left == nullptr)
					{
						//左为空，让父亲指向我的右
						if (cur == parent->_left)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
						delete cur;
					}
					else if (cur->_right == nullptr) {
						//右为空，让父亲指向我的左
						if (cur == parent->_left)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
						delete cur;
					}
					else {
						//左右都不为空，找到合适子树替代我
						//找一个节点，比左大，比右小来替代cur
						//由于二叉搜索树的性质，插入值比当前节点大的往右走，插入值比当前节点小的往左走
						Node* minRightParent = cur;
						Node* minRight = cur->_right;
						//Node* minRightParent = nullptr;//假设minRight没有左节点，那么minRight就不会更新
						//所以此处要设置minRightParent = cur；
						while(minRight->_left)
						{
							minRightParent = minRight;
							minRight = minRight->_left;
						}
						cur->_key = minRight->_key;//swap(minRight->_key,cur->_key);
						if(minRight == minRightParent->_left)
							minRightParent->_left = minRight->_right;
						else
							minRightParent->_right = minRight->_right;
						//因为此处minRightParent->_left为空,
						//且此时minRight->_left一定为空,但right不一定为空，一定要进行处理！！
						//处理方式就是把他给minRight的左子树

						delete minRight;
						return true;
					}
				}
			}
			return false;
		}

		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
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
