#pragma once
namespace product1 {
	template<typename T>
	class iterator{
	public:
		using value_type = T;
		using size_type = size_t;
	private:
		size_type cursor_;
		value_type step_;
		value_type value_;
	public:
		iterator(size_type cursor_start, value_type begin_val, value_type step_val) :
			cursor_(cursor_start),
			value_(begin_val),
			step_(step_val)
		{
			value_ += value_*step_;			//�������ĳ�ʼλ���ڿ�ʼ+ָ��ƫ�Ƶ�λ��
		}
		value_type operator*()	const 
		{
			//����Ҫ�޸�ֵ
			return value_;
		}
		bool operator!(const iterator& rhs)const
		{
			//����ҪҲ�����޸�ֵ���ж��α����ָ���Ƿ����
			return (cursor_!=rhs.cursor_)
		}
		iterator& operator++()
		{
			//��Ҫ�޸�ֵ
			value_ += step_;
			++cursor_;
			return (*this);				//���ܷ���this����Ϊ��ָ��
		}
	};
	template<typename T>
	class page {
	pulic:
		using value_type = T;
		using ref = value_type &;
		using const_ref = const value_type &;
		using iter = product1::iterator<value_type>;
		using const_iter = const product1::iterator<value_type>;
		using size_type = product1::iterator::size_type;
	private:
		const value_type begin_;
		const value_type end_;
		const value_type step_;
		const size_type max_count_;
		//https://blog.csdn.net/j_anson/article/details/70599098
	};
}


