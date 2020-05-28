#pragma once

#include <iostream>
using namespace std;

#include <vector>
namespace XML
{
	template<class T>
	class stack
	{
	public:
		stack()
		{};
		bool empty() const
		{
			return _stack.size() == 0;
		}
		size_t size()
		{
			return _stack.size();
		}
		T& top()
		{
			return _stack.back();
		}
		const T& top()const
		{
			return _stack.back();
		}
		void push(const T& data)
		{
			_stack.push_back(data);
		}
		void pop()
		{
			if(empty())
				return;
			_stack.pop_back();
		}
	private:
		vector<T> _stack;
	};

}

