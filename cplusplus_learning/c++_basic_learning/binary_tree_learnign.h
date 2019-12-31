#pragma once
#include<iostream>
#include<queue>
#include<stdio.h>
using namespace std;
struct node {
	char n;
	struct node* lchild;
	struct node* rchild;
};

/*
	二叉树的反转
	输入：4 2 7 # 3 6 9
	输出：4 7 2 9 6 3 #
	遍历方式：层序遍历
*/

void func_main()
{
	struct node *tree = NULL;
	std::queue<struct node*> q;
	char temp;
	char sp = '\n';
	//4 2 7 # 3 6 9
	while (1)
	{
		//cin >> temp;
		scanf("%c", &temp);
		if (temp == sp)
			break;
		else if (temp == ' ')
			continue;
		else
		{
			//v.push_back(temp);
			if (tree == NULL)
			{
				tree = new struct node();
				tree->n = temp;
				q.push(tree);
			}
			else if (q.front()->lchild == NULL)
			{
				struct node *no = new struct node();
				q.front()->lchild = no;
				no->n = temp;
				q.push(no);
			}
			else if (q.front()->rchild == NULL)
			{
				struct node *no = new struct node();
				q.front()->rchild = no;
				no->n = temp;
				q.push(no);
				q.pop();
			}

		}
	}
	std::queue<struct node*> p;
	if (tree != NULL)
	{
		p.push(tree);
		struct node* index = p.front();
		cout << index->n;
		while (p.front()->lchild!=NULL)
		{
			struct node* no = index->lchild;
			index->lchild = index->rchild;
			index->rchild = no;
			cout << " " << index->lchild->n;
			cout << " " << index->rchild->n;
			p.pop();
			p.push(index->lchild);
			p.push(index->rchild);
			index = p.front();
		}
	}
	int g = 10;
}