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
int main()
{
	key_value::BSTree<string, string> dict;
	dict.Insert("left", "×ó±ß");
	dict.Insert("right", "ÓÒ±ß");
	dict.Insert("insert", "²åÈë");
	dict.Insert("string", "×Ö·û´®");

	string str;
	while (cin >> str)
	{
		auto ret = dict.Find(str);
		if (ret)
		{
			cout << "->" << ret->_value << endl;
		}
		else {
			cout << "ÎÞ´Ëµ¥´Ê£¬ÇëÖØÐÂÊäÈë£¡" << endl;
		}
	}

	return 0;
}
