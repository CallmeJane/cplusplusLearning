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
	����������300���Ӹ㶨�㷨����

	ΪʲôôҪ�����㷨��
	���ݽṹ���㷨�Ѿ���Ϊ���뻥��������ıع��ż���

	��������˾ΪʲôҪ�������ݽṹ���㷨��
	��1���������Ա���㷨����
	��2���������Ա������Ǳ��
	��3���жϳ���Ա�����������ʱ���Ƿ��ɽ�����������
	��4���������ݽṹ���㷨ʱ��ߴ������ܣ����д����Ż��Ļ���

	�ص㿼�죺
	��1����������˼·
	��2����˼·д�ɴ���
	��3��*****���ڲ������ĿӦ����ôһ��������******
*/

/*
	��һ�����������ݽṹ
	��һ�����ʵ��㷨ȡ������ѡ������ݽṹ��
*/
/*
	����/�ַ�������
	1.ʵ���ַ����ķ�ת,�ڲ�ʹ��̫�����ռ�������
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
	����/�ַ�������
	2.����s��t,�ж�s�Ƿ�ʱt����ĸ��λ��
	eg:
	����s="anna",t="naan"
	�����ture(��Ϊ���߶���2��a��2��n)

	ע�����������ַ�����ֻ����Сд��ĸ

	������
	��1��ֻ��Сд��ĸ��һ���ַ��������26���ַ�
	��2����������СΪ26�����飬�ֱ�ͳ�������ַ�������ĸ�ĸ�����Ȼ��Ƚ������Ƿ����
	�Ż���ֻ��һ����СΪ26�����飬�������ַ�����ͳ�ƣ�һ��+1,һ��-1��Ȼ�󿴽���Ƿ�Ϊ0

	�ܽ᣺
	��1��������ҵ�������eg:26,�����㷨�������Ź�ģ�����������������
*/
bool is_first_same_second(string first, string second)
{
	int count[26] = {0};		//int[]����Ĭ�ϳ�ʼ��
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
	�������������˫������
	���⼼�ɣ�
	��1�����ÿ���ָ�룬��ʱ����Ҫ�õ�3��ָ�룬eg:������K��Ԫ�أ��м��Ԫ��
	��2������һ����ٵ�����ͷ
	eg:��1����������������������ϣ���������
	��2����������桢ż�����з��룬ǰ�벿��Ϊ��������벿��Ϊż��
	3.K��һ�飬��ת����
	��һ������ÿK���ڵ���з�ת�����ط�ת�������
	��1��Kʱһ����������С�ڵ�������ĳ���
	��2������ڵ�������K������������ô�뽫���Ľڵ㱣�ֽڵ�ԭ��
	��3���㷨ֻ��ʹ�ó����Ķ���ռ䣬
	��4�����ܵ���ֻ�ı�ڵ��ڵ�ֵ��Ҫ���ڵ���н���
	eg:���룺1->2->3->4->5
	�����K=2ʱ��2->1->4->3->5
		  K=3ʱ��3->2->1->4->5
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
	ջ������ȳ�(���ܻ�����ѵ���)
	ʵ�ַ�ʽ������������ɾ�����Ӷȶ���O(1)
	�������������ָ�����ʽ�������鳤�Ȳ���ʱ����ܸ��ӣ�

	4.�ж�һ��ֻ����'(',')','{','}','[',']'���ַ������Ƿ�Ϸ���
	��1��������Գ���
	��2���������ű���ʱ�������
	��3�����ַ���ʱ�Ϸ���
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
	ջ 5.����ÿ�����±��������Ҫ�ȶ�������ܵ��������ߡ�
	��1����֮�������ߣ����0
	��2�����µĳ��ȷ�Χ[1,30000]
	��3��ʾ����
	���룺[23,25,21,19,22,26,23]
	�����[1,4,2,1,1,0,0]

	�ܽ᣺һ��ջ���ڸ������ظ����ʲ��Һ���ȳ����ص�
*/
void wait_days_temperature(vector<int>& input, vector<int>& output)
{
	//s��ͷ�洢��ģ�β����С�ģ�������ջβ��ľͳ�ջ
	stack<int> s;		//���ڴ洢��ջ����ջ���±�
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
	ջ:
	�������ʽ����
	leetcode 224,227,770,772
	���ֱ��ͼ������������
	leetcode 84
*/

/*
	���У��Ƚ��ȳ���һ�����ڹ������������Breadth-first-search����
	һ��Ķ����ڶ�ͷ����ɾ�����ڶ�β���в��룬����һ����˳�����
	Ӧ�ó����������������

	˫�˶��У������ڶ�ͷ���в����ɾ����Ҳ�����ڶ�β���в����ɾ��
	ʵ��һ�����˫����
	Ӧ�ó������ƶ��Ĵ��ڻ�����������
	6.����һ��nums[]��k,k��С�Ļ������ڴ������ƶ���ÿ���ƶ�һ����
	���ÿ�����������е����ֵ
	��1��0<k<=len
	��2��ʾ����nums[1,3,-1,-3,5,3,6,7],k=3
	�����3��3��5��5��6��7

	˼·1��������ͨ����
	��1��deque�д���±꣬��ͷ������,
	��2��С�ڶ�ͷ�ģ�û������ȴ����
	��3���ȴ��������ڵ�
	��4���ٴ���С�ڵ�ǰԪ�ص�
	��5������һ����Ҫ�ĵ�ʱʲôʱ����output��������

	˼·2������˫�˶���
	��1������ÿһ��Ԫ�أ�С�ڶ�β����ӣ����ڶ�β������β�Ӻ���ǰ�޳�������С��
	��ǰԪ�صĺ�Խ��ģ�
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
					q.pop();				//���޳�Խ������ֵ
				while (*iter > nums[q.front()])
				{
					q.pop();				//���޳��������ֵ�Ķ�ͷ
					if (q.size() == 0)
						break;
				}
				q.push(index);
				if (index + 1 >= k)			//��һ��ܹؼ�������ʲôʱ���������
					output.push_back(nums[q.front()]);
			}
		}
		return true;
	}
}
/*
	��������ݹ鹦�ף�eg:ÿһ��ƽ����������ӽڵ�Ҳ��ƽ���������
	������״����ͨ��������ƽ�����������ȫ���������������������Ĳ���(QUADTREE)�������(N-AR TREE)
	��������������(RED-BLACK TREE)����ƽ�������������AVL TREE��һ�㲻���ʵ�
	������ʽ�����ı��������л�
*/
/*
	���ı����������ݸ��������Ⱥ�λ�ã�
	ǰ��������ȸ���������
	��������������������
	��������������ң����
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
	1.�ݹ鴴��һ�ã���һ���ܺõķ�ʽ������Ҫ��������֮�������Ĺ�ϵ
	2.�������Ҳ���Դ���һ����ȫ������
*/
template<class T>
BinaryTreeNode<T>* create_tree(T* a,int n,int index)		//ע�⣺���������贫������
{
	BinaryTreeNode<T>* root=nullptr;
	if (index < n)
	{
		root = new struct BinaryTreeNode<T>(a[index]);		//����ģ������ʱ��ҲҪ��Ӧ����
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
	//ע�⣺�ܹؼ�����1��ʼ
	int index = 1;
	BinaryTreeNode<int> *root = create_tree(ia, sizeof(ia) / sizeof(int), index);
	return root;
}

/*
	ǰ�������
	Ӧ�ó��������������������Ľ���
	����㣺
	��1���ݹ�ͷǵݹ��㷨��
	��2�����л��������Ľ�����л����ַ�������ʵ���Ǳ������������л������ַ����ָ���һ������
	1.�ݹ�ǰ�����һ����
*/
void prev_order(BinaryTreeNode<int>* root)
{
	if (root == nullptr)
	{
		return;
	}
	else
	{
		//���ʸ�����
		std::cout << root->_data<<" ";
		prev_order(root->_lchild);
		prev_order(root->_rchild);
	}
}
std::string prev_order_serialization(BinaryTreeNode<int>* root)
{
	std::string str="";
	if (root == nullptr)
		return "#,";		//�����ӽڵ�Ϊ��
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
	//���ն��ŷָ�
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
	//���ø���ջ���������ݵĴ���
	int index = 0;
	root = child_prev_order_desrialization(strs, index, strs.size());
	return root;
}
/*
	2.�ݹ��������һ����
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
	3.�ݹ�������һ����
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
	4.�������
	һ����Ҫ��������
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