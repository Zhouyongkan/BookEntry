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
	cout << "������ӵ��鼮����:" << endl;
	int n = 0;
	cin >> n;
	Node* tmp = l;
	while (n>0)
	{
		Node* cre;
		Init(cre);
		cout << "�������Booknumber��" << endl;
		cin >> cre->data.Booknumber;
		cout << "����������֣�" << endl;
		cin >> cre->data.BookName;
		cout << "������ļ۸�" << endl;
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
	cout << "����             ���                  �۸�                ����" << endl;
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
	cout << "------��ӭ���������Ƽ���ѧͼ�����ϵͳ---------" << endl;
	cout << "----1.����鼮-------------2.����鼮-------------" << endl;
	cout << "----3.��ѯ�鼮-------------4.�黹�鼮-------------" << endl;
	cout << "----5.�����鼮-------------6.�˳�ϵͳ-------------" << endl;
}
void Find(Node*& l)
{
	cout << "��������ҵ��鼮��" << endl;
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
	cout << "û�д��飡����" << endl;
}
void Borrow(Node*& l)
{
	cout << "������Booknumber������" << endl;
	int n = 0;
	cin >> n;
	Node* cre = l->next;
	while (cre)
	{
		if (cre->data.Booknumber == n)
		{
			if (cre->data.numbers == 0)
			{
				cout << "���ѽ��꣡����" << endl;
			}
			else
			{
				cre->data.numbers--;
				cout << "�ѳɹ����ģ�����" << endl;
				cout << endl;
			}
		}
		cre = cre->next;
	}
}
void BackBooks(Node*& l)
{
	cout << "������Booknumber" << endl;
	int n = 0;
	cin >> n;
	Node* cre = l->next;
	for (; cre; cre = cre->next)
	{
		if (cre->data.Booknumber == n)
		{
			cre->data.numbers++;
			cout << "����ɹ�������" << endl;
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
		cout << "������ѡ��" << endl;
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