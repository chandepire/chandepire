#ifndef MY_VECTOR_H_
#define MY_VECTOR_H_

#include<cstddef>
#include<memory>
#include <iostream>

template<typename T>
void destroy(T* ptr)
{
    ptr->~T();
}

template<typename ForwardIterator>
void destroy(ForwardIterator first, ForwardIterator last)
{
    for(;first != last;++first)
          destroy(&*first);
}

template<typename T>
class My_Vector{
public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T* iterator;
    typedef const T* const_iterator;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef ptrdiff_t difference_type;
protected:
    iterator start;
    iterator finish;
    iterator end_of_storage;
    std::allocator<T> alloc;
public:
    My_Vector();
    My_Vector(size_type n, const T& value);
    My_Vector(iterator first, iterator last);
    ~My_Vector();
    My_Vector(My_Vector& vec);
    My_Vector& operator=(My_Vector& vec);

public:
    iterator begin() {return start;}
    iterator end()   {return finish;}
    const_iterator begin() const {return start;}
    const_iterator end()   const {return finish;}

    size_type size() const {return finish-start;}
    size_type capacity() const {return end_of_storage-start;}
    bool empty() const {return start == finish;}

    reference operator[](size_type n) {return *(begin() + n);}
    const_reference operator[](size_type n) const {return *(begin() + n);}
    reference front() {return *begin();}
    const_reference front() const {return *begin();}
    reference back() {return *(end()-1);}
    const_reference back() const {return *(end()-1);}

    void push_back(const T& value);
    void pop_back();
    void insert(iterator pos, size_type n,const T& value);
    iterator erase(iterator pos);
    iterator erase(iterator first, iterator last);
    void resize(size_type new_size);
    void resize(size_type new_size,const T& value);
    void reserve(size_type new_size);
    void clear();

private:
    void free();
    void reallocate();
};

template<typename T>
My_Vector<T>::My_Vector():start(nullptr),finish(nullptr),end_of_storage(nullptr) {}

template<typename T>
My_Vector<T>::My_Vector(size_type n,const T& value)
{
      start = alloc.allocate(n);
      finish = end_of_storage = start + n;
      for(iterator it=start;it!=finish;++it)
            alloc.construct(it, value);
}

template<typename T>
My_Vector<T>::My_Vector(iterator first,iterator last)
{
      size_type n = last - first;
      start = alloc.allocate(n);
      finish = end_of_storage = start + n;
      std::uninitialized_copy(first, last, start);
}

template<typename T>
My_Vector<T>::~My_Vector()
{
  free();
}

template<typename T>
void My_Vector<T>::free()
{
  destroy(start, finish);
  alloc.deallocate(start, capacity());
}

template<typename T>
My_Vector<T>::My_Vector(My_Vector& vec)
{
  start = alloc.allocate(vec.size());
  finish= end_of_storage = start + vec.size();
  std::uninitialized_copy(vec.begin(), vec.end(),start);
}

template<typename T>
My_Vector<T>& My_Vector<T>::operator=(My_Vector& vec)
{
  if(*this != vec)
  {
    iterator new_start = alloc.alocate(vec.size());
    std::uninitialized_copy(vec.begin(), vec.end(),new_start);
    size_type old_size = size();
    size_type old_capacity = capacity();
    free();
    start = new_start;
    finish = start + old_size;
    capacity = start + old_capacity;
  }
  return *this;
}

template<typename T>
void My_Vector<T>::reallocate()
{
  size_type new_size = size()?2*size():1;
  iterator new_start = alloc.allocate(new_size);
  iterator new_finish= std::uninitialized_copy(begin(),end(),new_start);
  free();
  start = new_start;
  finish= new_finish;
  end_of_storage = start + new_size;
}

template<typename T>
void My_Vector<T>::push_back(const T& value)
{
    if(size() == capacity())
    {
      reallocate();
    }
    alloc.construct(finish++, value);
}

template<typename T>
void My_Vector<T>::pop_back()
{
  alloc.destroy(finish);
  --finish;
  std::cout <<"finish:" << *finish << std::endl;
}

template<typename T>
void My_Vector<T>::insert(iterator position, size_type n, const T& value){
	if (n <= (size_type)(capacity() - size())){
		if (n > (size_type)(finish - position)){
			std::uninitialized_fill(finish, finish + n - (size_type)(finish - position),value);
			std::uninitialized_copy(position, finish, position + n);
			std::uninitialized_fill(position, finish, value);
		}
		else{
			std::copy_backward(position, finish, finish + n);
			std::uninitialized_fill_n(position, n, value);
		}
		finish += n;
	}
	else{
		size_type new_size = size() + (size() > n ? size() : n);
		iterator new_start = alloc.allocate(new_size);
		iterator new_finish = std::uninitialized_copy(start, position, new_start);
		new_finish=std::uninitialized_fill_n(new_finish, n, value);
		new_finish = std::uninitialized_copy(position, finish, new_finish);
		free();
		start = new_start;
		finish = new_finish;
		end_of_storage = start + new_size;
	}
}

template<typename T>
typename My_Vector<T>::iterator My_Vector<T>::erase(iterator pos)
{
  if(pos + 1 != finish)
    std::uninitialized_copy(pos+1,finish,pos);
  alloc.destroy(--finish);
  return pos;
}

template<typename T>
typename My_Vector<T>::iterator My_Vector<T>::erase(iterator first,iterator last)
{
  size_type n = last - first;
  std::uninitialized_copy(last,finish,first);
  destroy(finish-n,finish);
  finish = finish - n;
  return first;
}

template<typename T>
void My_Vector<T>::resize(size_type new_size)
{
  resize(new_size, T());
}
template<typename T>
void My_Vector<T>::resize(size_type new_size, const T& value)
{
  if(new_size > size())
      insert(finish, new_size - size(),value);
  else
      erase(begin() + new_size, finish);
}
template<typename T>
void My_Vector<T>::reserve(size_type new_size)
{
  if(new_size > capacity())
  {
    iterator new_start = alloc.allocate(new_size);
    size_t old_size = size();
    std::uninitialized_copy(start, finish, new_start);
    free();
    start = new_start;
    finish = start + old_size;
    end_of_storage = start + new_size;
  }
}
template<typename T>
void My_Vector<T>::clear()
{
  erase(start, finish);
}
#endif
