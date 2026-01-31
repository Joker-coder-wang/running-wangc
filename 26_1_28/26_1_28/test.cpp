#define  _CRT_SECURE_NO_WARNINGS 1
#include"BinarySearchTree.h"

//int main()
//{
//	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
//	key::BSTree<int> t1;
//
//	for (auto e : a) {
//		t1.Insert(e);
//	}
//	t1.InOrder();
//
//	t1.Erase(8);
//	t1.InOrder();
//
//
//	return 0;
//}
//int main()
//{
//	key_value::BSTree<string, string> dict;
//	dict.Insert("left", "左边");
//	dict.Insert("right", "右边");
//	dict.Insert("insert", "插入");
//	dict.Insert("string", "字符串");
//
//	string str;
//	while (cin >> str)
//	{
//		auto ret = dict.Find(str);
//		if (ret)
//		{
//			cout << "->" << ret->_value << endl;
//		}
//		else {
//			cout << "无此单词，请重新输入！" << endl;
//		}
//	}
//
//	return 0;
//}

int main()
{
	string arr[] = { "苹果", "苹果", "西瓜", "苹果", "苹果", "西瓜", "苹果", "香蕉", "苹果", "香蕉" };
	key_value::BSTree<string, int> t2;
	for (const auto& e : arr)
	{
		auto ret = t2.Find(e);//先查找t2中有没有
		if(ret==nullptr)
		{
			t2.Insert(e, 1);
		}
		else {
			ret->_value++;
		}
	}
	t2.InOrder();
	return 0;
}
