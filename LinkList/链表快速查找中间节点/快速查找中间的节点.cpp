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
//���ٲ���������м�Ľڵ�
	//���ٵ��������һ������
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


	//�������
   node * temp= head;
	while (head!=NULL)
	{
		n++;
		cout<<"node->data:"<<head->data<<endl;
		head = head->next;
	}
	head = temp;
	cout<<"head->data:"<<head->data<<endl;
	cout<<"����ĳ����ǣ�"<<n<<endl;

	//���ٵĲ����м��ĳ���ڵ�
	//��ͨ�ķ����ǣ��ȱ��������������ĳ���L,Ȼ�������±�����L/2��ʱ�򣬾Ϳ��Ի��������м�ڵ�
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
	
cout<<"�м�Ľڵ��ǣ�"<<slow->data<<endl;


	getchar();
	getchar();
	return 0;
}