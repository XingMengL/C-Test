#pragma once

namespace XML
{
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
	
		// 构造一个带头节点的双向链表
		template<class T>
		class list
		{
			typedef ListNode<T> Node;
			typedef T* iterator;
		public:
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
			iterator begin();
			iterator end();
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
			//元素访问‘
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
			iterator insert(iterator pos, T& data)
			{
				return begin();
			}
			iterator erase(iterator pos)
			{
				return begin();
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
			Nodee* head;
		
		};
		
}