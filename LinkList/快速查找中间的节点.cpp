#include<iostream>
#include<stdio.h>
using namespace std;
#include<time.h>
struct node
{
	int data;
	node * next;
};
int main()
{
	srand(time(nullptr));
//快速查找链表的中间的节点
	//快速的随机生成一个链表
	node * head=nullptr;
	node * p1 = (node *)malloc(sizeof(node));
	node * p2 = p1;
	int n=0;
	for (int i = 0; i < 13; i++)
	{
		if (head==nullptr)
		{
			head = p1;
			p1->next = nullptr;
		}
		else
		{
			p2->next = p1;
		}
		p2 = p1;
		p1->data = rand()%100;
		p1 = (node *)malloc(sizeof(node));

	}
	p2->next = nullptr;

	free(p1);
	p1 = nullptr;


	//输出链表
   node * temp= head;
	while (head!=NULL)
	{
		n++;
		cout<<"node->data:"<<head->data<<endl;
		head = head->next;
	}
	head = temp;
	cout<<"head->data:"<<head->data<<endl;
	cout<<"链表的长度是："<<n<<endl;

	//快速的查找中间的某个节点
	//普通的方法是：先遍历链表，获得链表的长度L,然后是重新遍历到L/2的时候，就可以获得链表的中间节点
	node *slow=head;
	node  *quick=head;
	
	while(quick)
	{
		quick = quick->next;
		if (quick)
		{
					quick = quick->next;
					slow = slow->next;
		}	
	}
	
cout<<"中间的节点是："<<slow->data<<endl;


	getchar();
	getchar();
	return 0;
}