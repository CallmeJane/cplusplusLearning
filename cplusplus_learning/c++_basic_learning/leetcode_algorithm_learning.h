#pragma once
#include<iostream>
#include<string>		//std::to_string
#include<stack>
#include<queue>
#include<vector>
#include<regex>			//std::regex,std::regex_token_iterator

using std::cout;
using std::cin;
using std::string;
using std::stack;
using std::queue;
using std::vector;
/*
	来自拉勾：300分钟搞定算法面试

	为什么么要面试算法？
	数据结构与算法已经成为进入互联网名企的必过门槛。

	互联网公司为什么要面试数据结构和算法？
	（1）考察程序员的算法功底
	（2）考察程序员的提升潜力
	（3）判断程序员在面对新问题时，是否由解决问题的能力
	（4）掌握数据结构和算法时提高代码性能，进行代码优化的基础

	重点考察：
	（1）解决问题的思路
	（2）将思路写成代码
	（3）*****对于不会的题目应该怎么一步步分析******
*/

/*
	第一讲：常用数据结构
	（一般优质的算法取决于你选择的数据结构）
*/
/*
	数组/字符串数组
	1.实现字符串的反转,在不使用太多多余空间的情况下
*/
void string_reverse(string& str)
{
	int len = str.length();
	char temp;
	for (int i = 0, j = len - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}
/*
	数组/字符串数组
	2.给定s和t,判断s是否时t的字母异位词
	eg:
	输入s="anna",t="naan"
	输出：ture(因为两者都有2个a，2个n)

	注：假设两个字符串中只包含小写字母

	分析：
	（1）只有小写字母，一个字符串最多由26个字符
	（2）用两个大小为26的数组，分别统计两个字符串中字母的个数，然后比较两个是否相等
	优化：只用一个大小为26的数组，对两个字符串的统计，一个+1,一个-1，然后看结果是否为0

	总结：
	（1）最好能找到常量，eg:26,这样算法不会随着规模的增大而成线性增加
*/
bool is_first_same_second(string first, string second)
{
	int count[26] = {0};		//int[]不会默认初始化
	if (first.length() == second.length())
	{
		int len = first.length();
		for (int i = 0; i < len; i++)
		{
			count[first[i] - 'a']++;
			count[second[i] - 'a']--;
		}
		for (int i = 0; i < 26; i++)
		{
			if (count[i] != 0)
				return false;
		}
		return true;
	}
	return false;
}

/*
	链表：单向链表和双向链表
	解题技巧：
	（1）利用快慢指针，有时候需要用到3个指针，eg:倒数第K个元素，中间的元素
	（2）构建一个虚假的链表头
	eg:（1）将两个有序链表进行整合，进行排序
	（2）将链表的奇、偶数进行分离，前半部分为奇数，后半部分为偶数
	3.K个一组，翻转链表
	给一个链表，每K个节点进行翻转，返回翻转后的链表
	（1）K时一个正整数，小于等于链表的长度
	（2）如果节点数不是K的整数倍，那么请将最后的节点保持节点原序
	（3）算法只能使用常数的额外空间，
	（4）不能单纯只改变节点内的值，要将节点进行交换
	eg:输入：1->2->3->4->5
	输出：K=2时，2->1->4->3->5
		  K=3时，3->2->1->4->5
*/
typedef struct list_k_node {
	int value;
	struct list_k_node* next;
}list_k_node;

void list_k_reserve(list_k_node* head,int k,int len)
{
	list_k_node* prev, *curr, *next;
	if (k >= len)
		return;
	else
	{
		prev = NULL;
		curr = head;
		int n = k;
		int time = 1;
		while (time*k < len)
		{
			while (n-->0)
			{
				//NULL(prev)->1(curr)->2(next)->3->4->5
				next = curr->next;
				//NULL(prev)<-1(curr)->2(next)->3->4->5
				curr->next = prev;
				//NULL<-1(prev)->2->3->4->5
				prev = curr;
				//NULL<-1(prev)->2(curr)->3->4->5
				curr = next;
			}
			n = k;
			time++;
		}
	}
}

/*
	栈：后进先出(可能会出很难的题)
	实现方式：单链表，插入删除复杂度都是O(1)
	（若是用数组和指针的形式，当数组长度不足时，会很复杂）

	4.判断一个只含有'(',')','{','}','[',']'的字符串，是否合法。
	（1）左右配对出现
	（2）左右括号必须时先左后右
	（3）空字符串时合法的
*/
bool check_str_valid(string str)
{
	stack<char> s_char;
	char temp;
	for(auto iter = str.begin(); iter != str.end(); iter++)
	{
		if (*iter == '(' || *iter=='{' || *iter=='[')
			s_char.push(*iter);
		else if (*iter == ')')
		{
			 temp=s_char.top();
			 s_char.pop();
			 if (temp != '(')
				 return false;
		}
		else if (*iter == '}')
		{
			temp = s_char.top();
			s_char.pop();
			if (temp != '{')
				return false;
		}
		else
		{
			temp = s_char.top();
			s_char.pop();
			if (temp != '[')
				return false;
		}
	}
	if (s_char.size() == 0)
		return true;
	else
		return false;
}

/*
	栈 5.根据每日气温表，输出还需要等多少天才能到气温升高。
	（1）若之后不再升高，输出0
	（2）气温的长度范围[1,30000]
	（3）示例：
	输入：[23,25,21,19,22,26,23]
	输出：[1,4,2,1,1,0,0]

	总结：一般栈用于辅助有重复访问并且后进先出的特点
*/
void wait_days_temperature(vector<int>& input, vector<int>& output)
{
	//s的头存储大的，尾存最小的，遇到比栈尾大的就出栈
	stack<int> s;		//用于存储出栈、入栈的下标
	int index;
	int i = 0;
	for (vector<int>::iterator iter = input.begin(); iter != input.end(); iter++,i++)
	{
		if (s.size() == 0)
			s.push(i);
		else
		{
			while (input[index=s.top()] < *iter)
			{
				output[index] = i - index;
				s.pop();
				if (s.size() == 0)
					break;
			}
			s.push(i);
		}
	}
}

/*
	栈:
	算数表达式问题
	leetcode 224,227,770,772
	求解直方图中最大矩形区域
	leetcode 84
*/

/*
	队列：先进先出（一般用于广度优先搜索（Breadth-first-search））
	一般的队列在队头进行删除，在队尾进行插入，进行一定的顺序操作
	应用场景：广度优先搜索

	双端队列：可以在队头进行插入和删除，也可以在队尾进行插入和删除
	实现一般采用双链表
	应用场景：移动的窗口或者连续区间
	6.给定一个nums[]和k,k大小的滑动窗口从左到右移动，每次移动一个，
	输出每个滑动窗口中的最大值
	（1）0<k<=len
	（2）示例：nums[1,3,-1,-3,5,3,6,7],k=3
	输出：3，3，5，5，6，7

	思路1：利用普通队列
	（1）deque中存的下标，队头存最大的,
	（2）小于队头的，没处理的先存进来
	（3）先处理超过窗口的
	（4）再处理小于当前元素的
	（5）还有一个重要的点时什么时候向output输入数据

	思路2：利用双端队列
	（1）对于每一个元素，小于队尾，入队，大于队尾，将队尾从后往前剔除（包括小于
	当前元素的和越界的）
*/
bool move_k_window_find_max(vector<int> nums,int k,vector<int>& output)
{
	if (k <= 0 || k > nums.size())
	{
		return false;
	}
	else
	{
		int index = 0;
		queue<int> q;
		for (auto iter = nums.begin(); iter != nums.end(); iter++,index++)
		{
			if (q.size() == 0)
			{
				q.push(index);
				if (index + 1 >= k)
					output.push_back(nums[q.front()]);
			}
			else
			{
				if (index - q.front() >= k)
					q.pop();				//先剔除越界的最大值
				while (*iter > nums[q.front()])
				{
					q.pop();				//后剔除不是最大值的队头
					if (q.size() == 0)
						break;
				}
				q.push(index);
				if (index + 1 >= k)			//这一句很关键，控制什么时候输出窗口
					output.push_back(nums[q.front()]);
			}
		}
		return true;
	}
}
/*
	树：考察递归功底（eg:每一个平衡二叉树的子节点也是平衡二叉树）
	树的形状：普通二叉树、平衡二叉树、完全二叉树、二叉搜索树、四叉树(QUADTREE)、多叉树(N-AR TREE)
	特殊的树：红黑树(RED-BLACK TREE)、自平衡二叉搜索树（AVL TREE）一般不会问道
	考察形式：树的遍历及序列化
*/
/*
	树的遍历：（根据根遍历的先后位置）
	前序遍历：先根，后左右
	中序遍历：先左后根最后右
	后序遍历：先左右，后根
*/
template<class T>
struct BinaryTreeNode {
	T _data;
	struct BinaryTreeNode<T> *_lchild;
	struct BinaryTreeNode<T> *_rchild;
	struct BinaryTreeNode(const T& data):_data(data),_lchild(nullptr),_rchild(nullptr)
	{}
	~BinaryTreeNode() {
	
	}
};

/*
	1.递归创建一棵：是一个很好的方式，但是要利用数据之间索引的关系
	2.层序遍历也可以创建一棵完全二叉树
*/
template<class T>
BinaryTreeNode<T>* create_tree(T* a,int n,int index)		//注意：第三参数需传递引用
{
	BinaryTreeNode<T>* root=nullptr;
	if (index < n)
	{
		root = new struct BinaryTreeNode<T>(a[index]);		//创建模板对象的时候也要对应类型
		root->_lchild = create_tree(a, n, 2*index);
		root->_rchild = create_tree(a, n, 2*index+1);
	}
	return root;
}

BinaryTreeNode<int>* init_trees()
{
	int ia[11];
	for (int i = 0; i < 11; i++)
	{
		ia[i] = i;
	}
	//注意：很关键，从1开始
	int index = 1;
	BinaryTreeNode<int> *root = create_tree(ia, sizeof(ia) / sizeof(int), index);
	return root;
}

/*
	前序遍历：
	应用场景：树的搜索或者树的建立
	考察点：
	（1）递归和非递归算法，
	（2）序列化（将树的结点序列化成字符串，其实就是遍历）及反序列化（将字符串恢复成一棵树）
	1.递归前序遍历一棵树
*/
void prev_order(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		//访问根左右
		std::cout << root->_data<<" ";
		prev_order(root->_lchild);
		prev_order(root->_rchild);
	}
}
std::string prev_order_serialization(BinaryTreeNode<int>* root)
{
	std::string str="";
	if (root == nullptr)
		return "#,";		//代表孩子节点为空
	else
	{
		//std::to_string
		str = str + std::to_string(root->_data)+",";
		str += prev_order_serialization(root->_lchild);
		str += prev_order_serialization(root->_rchild);
	}
	return str;
}

int str_to_int(std::string str)
{
	int ret = 0;
	for (auto iter = str.begin(); iter != str.end(); iter++)
	{
		ret = ret * 10 + *iter - '0';
	}
	return ret;
}
BinaryTreeNode<int>* child_prev_order_desrialization(std::vector<std::string> strs,int& index,int len)
{
	if (index >= len || strs[index]=="#")
		return nullptr;
	else
	{
		BinaryTreeNode<int>* root=new BinaryTreeNode<int>(str_to_int(strs[index]));
		root->_lchild=child_prev_order_desrialization(strs, index=index+1, len);
		root->_rchild=child_prev_order_desrialization(strs, index=index+1, len);
		return root;
	}	
}

BinaryTreeNode<int>* prev_order_desrialization(std::string str)
{
	BinaryTreeNode<int>* root = nullptr;
	//按照逗号分隔
	std::vector<std::string> strs;
	std::string temp="";
	for (auto iter = str.begin(); iter != str.end(); iter++)
	{
		if (*iter == ',')
		{
			strs.push_back(temp);
			temp = "";
		}
		else
			temp += *iter;
	}
	/*std::regex e("\,[^,]*,");
	std::regex_token_iterator<std::string::iterator> i(str.begin(), str.end(), e, -1);
	std::regex_token_iterator<std::string::iterator> end;
	while (i != end)
	{
		strs.push_back(*i++);
	}*/
	//利用辅助栈来进行数据的处理
	int index = 0;
	root = child_prev_order_desrialization(strs, index, strs.size());
	return root;
}
/*
	2.递归中序遍历一棵树
*/
void middle_order(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
		return;
	else
	{
		middle_order(root->_lchild);
		std::cout << root->_data << " ";
		middle_order(root->_rchild);
	}
}

std::string middle_order_serialization(BinaryTreeNode<int>* root)
{
	std::string str = "";
	if (root == nullptr)
		return str+"#,";
	else
	{
		str +=middle_order_serialization(root->_lchild);
		str += std::to_string(root->_data)+",";
		str += middle_order_serialization(root->_rchild);
	}
	return str;
}
/*
	3.递归后序遍历一棵树
*/
void sub_order(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
		return;
	else
	{
		sub_order(root->_lchild);
		sub_order(root->_rchild);
		std::cout << root->_data << " ";
	}
}
/*
	4.层序遍历
	一般需要借助队列
*/
void layer_order(BinaryTreeNode<int>* root)
{
	std::queue<BinaryTreeNode<int>*> aux_queue;
	if (root != nullptr)
	{
		std::cout << root->_data << " ";
		aux_queue.push(root);
	}
	while (aux_queue.empty() != true)
	{
		BinaryTreeNode<int>* visited = aux_queue.front();
		aux_queue.pop();
		if (visited->_lchild != nullptr)
		{
			std::cout << visited->_lchild->_data << " ";
			aux_queue.push(visited->_lchild);
		}
		if (visited->_rchild != nullptr)
		{
			std::cout << visited->_rchild->_data << " ";
			aux_queue.push(visited->_rchild);
		}
	}
}