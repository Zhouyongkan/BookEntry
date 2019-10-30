#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
typedef struct
{
	int Booknumber;
	char BookName[30];
	int Price;
	int numbers;
}TheBook;
typedef struct Node
{
	TheBook data;
	struct Node* next;
}Node;
void Init(Node*& l)
{
	l = new Node;
	l->data.numbers = 0;
	l->data.Booknumber = 0;
	l->data.Price = 0;
	l->next = nullptr;
}
bool CheckIsRepeat(Node* l, Node* cur)
{
	Node* cre = l->next;
	for (; cre; cre = cre->next)
	{
		if (cre->data.Booknumber == cur->data.Booknumber)
		{
			cre->data.numbers++;
			return true;
		}
	}
	return false;
}
void  CreateBooks(Node*& l)
{
	Init(l);
	cout << "你想添加的书籍数量:" << endl;
	int n = 0;
	cin >> n;
	Node* tmp = l;
	while (n>0)
	{
		Node* cre;
		Init(cre);
		cout << "输入书的Booknumber：" << endl;
		cin >> cre->data.Booknumber;
		cout << "输入书的名字：" << endl;
		cin >> cre->data.BookName;
		cout << "输入书的价格：" << endl;
		cin >> cre->data.Price;
		if ((l->next) != nullptr)
		{
			if (CheckIsRepeat(l, cre))
			{
			}
			else
			{
				cre->data.numbers++;
				tmp->next = cre;
				tmp = cre;
			}
		}
		else if ((l->next) == nullptr)
		{
			cre->data.numbers++;
			tmp->next = cre;
			tmp = cre;
		}
		n--;
	}
}

void show(Node*& l)
{
	cout << "书名             书号                  价格                数量" << endl;
	Node* cre = l->next;
	for (; cre;)
	{
		/*tmp = tmp->next;*/
		if (cre->data.numbers != 0)
		{
			cout << cre->data.Booknumber << "                   " << cre->data.BookName << "                  " << cre->data.Price << "                  " << cre->data.numbers << endl;
			cre = cre->next;
		}
		else if (cre->data.numbers == 0)
		{
			cre = cre->next;
		}
	}
}
void menu()
{
	cout << "------欢迎进入西安科技大学图书管理系统---------" << endl;
	cout << "----1.浏览书籍-------------2.添加书籍-------------" << endl;
	cout << "----3.查询书籍-------------4.归还书籍-------------" << endl;
	cout << "----5.借阅书籍-------------6.退出系统-------------" << endl;
}
void Find(Node*& l)
{
	cout << "请输入查找的书籍：" << endl;
	char arr[20] = "";
	cin >> arr;
	Node* cre = l->next;
	for (; cre; cre = cre->next)
	{
		if (strcmp(cre->data.BookName, arr) == 0)
		{
			cout << cre->data.Booknumber << "                   " << cre->data.BookName << "                  " << cre->data.Price << "                  " << cre->data.numbers << endl;
			return;
		}
	}
	cout << "没有此书！！！" << endl;
}
void Borrow(Node*& l)
{
	cout << "请输入Booknumber来借书" << endl;
	int n = 0;
	cin >> n;
	Node* cre = l->next;
	while (cre)
	{
		if (cre->data.Booknumber == n)
		{
			if (cre->data.numbers == 0)
			{
				cout << "书已借完！！！" << endl;
			}
			else
			{
				cre->data.numbers--;
				cout << "已成功借阅！！！" << endl;
				cout << endl;
			}
		}
		cre = cre->next;
	}
}
void BackBooks(Node*& l)
{
	cout << "请输入Booknumber" << endl;
	int n = 0;
	cin >> n;
	Node* cre = l->next;
	for (; cre; cre = cre->next)
	{
		if (cre->data.Booknumber == n)
		{
			cre->data.numbers++;
			cout << "还书成功！！！" << endl;
		}
	}
}
int main()
{
	Node*l;
	int put = 0;
	do
	{
		menu();
		cout << "请输入选择" << endl;
		cin >> put;

		switch (put)
		{
		case 1:
			show(l);
			break;
		case 2:
			CreateBooks(l);
			break;
		case 3:
			Find(l);
			break;
		case 4:
			BackBooks(l);
			break;
		case 5:
			Borrow(l);
			break;
		default:
			break;
		}
	} while (put != 6);
	system("pause");
	return 0;
}