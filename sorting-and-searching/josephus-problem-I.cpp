#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* next;

};

struct List
{
	Node* head;
	Node* tail;
};

int n;
List L;

void Init(List &L)
{
	L.head = L.tail = NULL;
}

Node* MakeNode(int x)
{
	Node* temp = new Node;
	temp->data = x;
	temp->next = temp;
	return temp;
}

void InsertTail(List& L, int x)
{
	if (L.head == NULL)
		L.head = L.tail = MakeNode(x);
	else
	{
		Node* temp = MakeNode(x);
		L.tail->next = temp;
		temp->next = L.head;
		L.tail = temp;
	}
}

void Solve()
{
	Node *p = L.tail;
	for (int i = 1; i <= n; i++)
	{
		Node* pPrev = p->next;
		p = pPrev->next;
		cout << p->data << " ";
		pPrev->next = p->next;
		delete p;
		p = pPrev;
	}
}

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	Init(L);
	for (int i = 1; i <= n; i++)
	{
		InsertTail(L, i);
	}
	Solve();
	return 0;
}

