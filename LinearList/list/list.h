#ifndef VECTOR_H_
#define VECTOR_H_
#include <iostream>


/* 通用的链表中的节点的定义 */
template <class T>
struct node
{
	T data;
	node<T>* next;
};


template <class T>
class List
{
private:
	node<T>* head;				// 头指针
	node<T>* rear;				// 尾指针
	int length;					// 链表的长度
public:
	List();
//	List():length(0);
	~List();

	int Length() {return length;}
	
	void InsertAfterHead (T e);
	void InsertBeforeRear (T e);
	void InsertAfterCurrent (T e, node<T>* cur);

	void DeleteHeadNode();
	void DeleteRearNode();
	void DeleteNextOfCurrent(node<T>* cur);
	
	T GetValue(int i);
	void SetValue(T e, int i);
	T GetCurrentValue(node<T>* cur);
	void SetCurrentValue(T e, node<T>* cur);

	int Position(T e);
	node<T>* FindPosition(T e);
	
	void PrettyPrint ();
	
};






using namespace std;

/* 构造函数 */
template <class T>
List<T>::List()
{
	length = 0;					/* 链表的初始长度为 0 */
	head = new node<T>;			/* 建立一个哨兵节点 */
	head->next = NULL;			/* 将哨兵节点的 next 初始化为 NULL */
	rear = head;
}

/* 析构函数 */
template <class T>
List<T>::~List()
{
	rear = NULL;
	delete head;				/* 释放内存 */
}


/* 在头节点之后插入一个元素 */
template <class T>
void List<T>::InsertAfterHead (T e)
{
	length++;					/* 插入一个节点之后链表长度加 1 */

	node<T>* p = new node<T>;	/* 为元素 e 申请一个节点 */
	p->data = e;				/* 将新申请的节点的 data 数据域赋值为给定元素 e */
	p->next = NULL;				/* 将新申请的节点的 next 指针初始化为 NULL 以避免不可预测的情况 */

	if(head == rear)			/* 当链表为空的时候尾节点需要指向新插入的节点 */
	{
		p->next = head->next;
		head->next = p;
		rear = p;
	}
	else
	{
		p->next = head->next;	/* 当链表不为空的时候只需将要插入的节点插入哨兵节点之后 */
		head->next = p;
	}
}


/* 在尾节点之前插入一个元素 */
template <class T>
void List<T>::InsertBeforeRear (T e)
{
	length++;					/* 插入一个节点之后链表的长度增加 1 */

	node<T>* p = new node<T>;	/* 为元素 e 申请一个节点 */
	p->data = e;
	p->next = NULL;				/* 将新申请的节点的 next 指针初始化为 NULL 以避免不可预测的情况 */
	
	rear->next = p;
	rear = p;
}


/* 在传入的指针所指向的节点之后插入一个元素 */
template <class T>
void List<T>::InsertAfterCurrent (T e, node<T>* cur)
{
	length++;					/* 插入一个节点之后链表的长度增加 1 */

	node<T>* p = new node<T>;	/* 为元素 e 申请一个节点 */
	p->data = e;
	p->next = NULL;				/* 将新申请的节点的 next 指针初始化为 NULL 以避免不可预测的情况 */
	
	p->next = cur->next;
	cur->next = p;
}


/* 将头节点之后的一个节点删除 (删除哨兵节点之后的一个元素) */
template <class T>
void List<T>::DeleteHeadNode()
{
	if(head == rear)
		return;
	else if(length == 1)
	{
		rear = head;
		delete head->next;
		length--;
	}
	else
	{
		node<T>* p = head->next;
		head->next = p->next;
		p->next = NULL;
		delete p;
		length--;				/* 删除一个节点之后列表长度减 1 */
	}
}


/* 将尾节点删除 */
template <class T>
void List<T>::DeleteRearNode()
{
	if(head == rear)
		return;
	else if(length == 1)
	{
		rear = head;
		delete head->next;
		length--;
	}
	else
	{
		node<T>* p = head;;
		while(p->next != rear) p = p->next;
		rear = p;
		delete p->next;
		rear->next = NULL;
		length--;				/* 删除一个节点之后列表长度减 1 */
	}
}



/* 删除给定指针所指向的节点之后的一个节点删除 */
template <class T>
void List<T>::DeleteNextOfCurrent(node<T>* cur)
{
	node<T>* p = cur->next;
	cur->next = p->next;
	p->next = NULL;
	delete p;
	length--;					/* 删除一个节点之后列表长度减 1 */
}



/* 返回链表中给定下标的元素值 */
template <class T>
T List<T>::GetValue(int i)
{
	if(i <= 0) return -1111;
	node<T>* p = head;
	while(i > 0) {p = p->next; i--;}
	return p->data;
}


/* 将链表中给定下标中的数据域更改为给定元素 */
template <class T>
void List<T>::SetValue(T e, int i)
{
	if(i <= 0) return;
	node<T>* p = head;
	while(i > 0) {p = p->next; i--;}
	p->data = e;
}


/* 返回链表中给定指针所指向的节点中的元素值 */
template <class T>
T List<T>::GetCurrentValue(node<T>* cur)
{
	return cur->data;
}


/* 将链表中给定指针所指向的节点中的数据域更改为给定元素 */
template <class T>
void List<T>::SetCurrentValue(T e, node<T>* cur)
{
	cur->data = e;
}
	

/* 查找给定元素在链表中的下标 */
template <class T>
int List<T>::Position(T e)
{
	int i = 0;
	node<T>* p = head->next;
	while(p)
	{
		i++;
		if(p->data == e) break;
		p = p->next;
	}
	return i;
}


/* 返回指向所查找元素所在节点的指针 */
template <class T>
node<T>* List<T>::FindPosition(T e)
{
	node<T>* p = head->next;
	while(p)
	{
		if(p->data == e) break;
		p = p->next;
	}
	return p;
}


/* 美观打印, 以规定的直观形式打印链表 */
template <class T>
void List<T>::PrettyPrint ()
{
	if(head == rear)
		cout << "Empty" << endl;
	else
	{
		node<T>* p = head->next;
		while (p) {cout << "[" << p->data << "]->"; p = p->next;}
		cout << "NULL" << endl;
	}
}








#endif
