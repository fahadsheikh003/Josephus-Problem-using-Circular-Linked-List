#include<iostream>

using namespace std;

struct node
{
	int data;
	node* next;

	node() : data(-1), next(NULL) {};

	node(int x, node* n) : data(x), next(n) {};
};

class List
{
	node* head;
	int n, m;

public:
	List() : head(NULL), n(0), m(0) {};

	void setN(int x)
	{
		n = x;
	}

	void setM(int x)
	{
		m = x;
	}

	void deletenode(node* temp)
	{
		cout << temp->data << " ";
		delete temp;
	}

	void game()
	{
		if (head == NULL)
			return;
		
		node* temp;
		node* curr = head;

		if (m == 0)//deleting every node until last node is encountered
		{
			while (curr->next != curr)
			{
				temp = curr;
				head = curr->next;
				while (curr->next)
					curr = curr->next;
				curr->next = head;
				deletenode(temp);
				curr = head;
			}
		}
		else//deleting every m+1 node until last node is encountered
		{			
			int count = 0;
			while (curr->next != curr)
			{
				count++;
				if (count == m)
				{
					temp = curr->next;
					curr->next = curr->next->next;
					if (temp == head)//if the node we're deleting is head
					{
						head = curr;
					}
					deletenode(temp);
					count = 0;
				}
				curr = curr->next;
			}
		}
	}

	void gamewin()
	{
		cout << endl << "Player " << head->data << " wins" << endl;
		delete head;
		head = NULL;
	}

	void populate()
	{
		int x = 1;
		for (int i = 0; i < n; i++)
		{
			if (head == NULL)
			{
				head = new node(x++, head);
				head->next = head;
			}
			else
			{
				node* curr = head;
				while (curr->next != head)
				{
					curr = curr->next;
				}
				curr->next = new node(x++, curr->next);
			}
		}
	}

	void Display()
	{
		if (head == NULL)
			return;

		node* curr = head;
		do
		{
			cout << curr->data << " ";
			curr = curr->next;
		} while (curr != head);
	}
};

int main()
{
	List L;

	L.setN(5);

	L.populate();

	L.setM(2);

	L.game();

	L.gamewin();
}