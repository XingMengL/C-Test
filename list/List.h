#pragma once

namespace XML
{
	/*节点类*/
	template<class T>

	// 构造一个节点
	struct ListNode
	{
		ListNode<T>* next;
		ListNode<T>* prev;
		T val;

		ListNode(const T& value)
			:next(nullptr)
			,prev(nullptr)
			,val(value)
		{}
	};
	
	/*迭代器类*/
	template<class T>
	struct ListIterator
	{
	public:
		typedef ListNode<T> Node;
		typedef ListIterator<T> self;
		//构造
		ListIterator(Node* node = nullptr)
			:_node(node)
		{}
		//具有类似指针的行为

		// *重载
		T& operator*()  
		{
			return _node->val;
		}
		// ->重载
		T* operator->()
		{
			 //return &(_node);
			 return &(operator*());
		}
		// 前置++ 重载
		self& operator++()
		{
			_node = _node->next;
			return *this;
		}
		//后置++ 
		self operator++(int)
		{
			self temp(*this);
			_node = _node->next;
			return temp;
		}
		// 前置-- 
		self& operator--()
		{
			_node = _node->prev;
		}
		// 后置--
		self operator--(int)
		{
			self temp(*this);
			_node = _node->prev;
			return temp;
		}
		// 比较
		bool operator!=(const self& s)
		{
			return _node != s._node;
		}
		bool operator==(const self& s)
		{
			return _node == s._node;
		}

	private:
		Node* _node;
		
	};
		/*容器类*/
		template<class T>
		class list
		{
		public:
			typedef ListNode<T> Node;
			typedef ListIterator<T> iterator;
		// list的迭代器必须对原生态的指针（节点类型的指针）进行封装
		// 构造一个带头节点的双向链表
			
			
			list()
			{
				CreateHead();
			}
			list(int n ,const T& value = T())
			{
				CreateHead();
				for(int i = 0 ; i < n ; i++)
				{
					push_back(value);
				}
			}

			template<class Iterator>
			list(Iterator first,Iterator last)
			{
				CreateHead();
				while( first != lasr)
				{
					push_back(*first);
					first++;
				}
				
			}

			list (const list<T>& L)
			{
				CreateHead();

				auto it = L.begin();

				while(it!=L.end())
				{
					push_back(*it);
					it++;
				}
				 
			}

			list<T>& operator=(const list<T>& L)
			{
				CreateHead();
			
			}

			~list()
			{
				clear();
				delete head;
				head = nullptr;
			}
			////////////////////////////////////////
			//迭代器操作
			iterator begin()
			{
				return iterator(head->next);
			}
			iterator end()
			{
				return iterator(head);
			}
			/////////////////////
			//容量操作
			size_t size()const
			{
				size_t count = 0;
				auto it = begin();
				while(it != end())
					++it,++count;

			}
			bool empty()
			{
				return head->next == head;
			}
	        void resize(size_t newsize, const T& data= T())	
			{
				size_t oldsize  = size();
				if(newsize < oldsize)
				{
					for(size_t i = newsize; i < oldsize; i++)
					{
						pop_back();
					}
				}
				else
				{
					for(size_t i = oldsize; i < newsize; i++)
					{
						push_back(data);
					}
				}
			}
			//////////////////
			//元素访问
			T& front()
			{
				return head->next->val;
			}
			T& back()
			{
				return head->prev->val;
			}
			//////////////
			//修改操作
			void push_back(	T& data)
			{
				insert(end(),data);
			}
			void pop_back()
			{
				auto it = end();
				erase(it--);
			}
			// 在pos的位置插入值为data的元素，返回该元素的位置
			iterator insert(iterator pos, T& data)
			{
				// 创建新的节点
				Node* newNode = new Node(data);
				newNode->prev = pos._node->prev;
				newNode->next = pos._node;
				newNode->prev->next = newNode;
				pos._node->prev = newNode;
				return iterator(newNode);
			}
			iterator erase(iterator pos)
			{
				Node* ret = pos._node->next;

				Node* cur = pos._node;
				cur->prev->next = cur->next;
				cur->next->prev = cur->prev;
				delete cur;

				return iterator(ret);
			}
			iterator erase(iterator first,iterator last)
			{
				return begin();
			}
			void clear()
			{
				erase(begin(),end());
			}
			void swap(list<	T> & L)
			{
				std::swap(head,L.head);
			}
		private:
			void CreateHead()
			{
				head = new Node;
				head->prev = head;
				head->next = head;
			}
		private:	
			Node* head;
		
		};
		
}

class Test
{
public:
	
};