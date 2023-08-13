#pragma once
namespace zjh
{
	template<class Iterator,class T,class Ref,class Ptr>
	class reverse_iterator
	{
	public:
		Ref operator*()
		{
			Iterator tmp = _it;
			return *(--tmp);
		}
		Iterator& operator++()
		{
			_it--;
			return it;
		}
		Iterator operator++(int)
		{
			Iterator ret = _it;
			_it--;
			return ret;
		}
		Iterator& operator--()
		{
			_it++;
			return _it;
		}
		Iterator operator--(int)
		{
			Iterator ret = _it;
			_it++;
			return ret;
		}
		Ptr operator->()
		{
			return &(operator*());
		}
	private:
		Iterator _it;
	};
}