//
// Created by Christopher McMorran on 2016-12-15.
//

#ifndef JAVASTYLE_ARRAYLIST_H
#define JAVASTYLE_ARRAYLIST_H

#include <vector>
#include <cstdlib>

template <typename T>
class ArrayList<T>
{
private:
	std::vector<T> _vector;
	std::vector<T*> deallocate_buffer;
public:
	ArrayList();

	template <typename T>
	ArrayList<T>& addLast(T* object);
	template <typename T>
	ArrayList<T>& addFirst(T* object);
	template <typename T>
	T removeLast();
	void pop();
	template <typename T>
	T removeFirst();
	template <typename T>
	T* toArray();

	virtual ~ArrayList();

};

template<typename T>
ArrayList<T> &ArrayList<T>::addLast(T *object)
{
	this->_vector.push_back(object);
	return *this;
}

template<typename T>
ArrayList<T> &ArrayList<T>::addFirst(T *object)
{
	this->_vector.insert(0, object);
	return *this;
}

template<typename T>
T ArrayList<T>::removeLast()
{
	T copy = this->_vector.at(this->_vector.size() -1);
	this->_vector.pop_back();
	return copy;
}
template <typename T>
void ArrayList<T>::pop()
{
	this->_vector.pop_back();
}

template <typename T>
T ArrayList<T>::removeFirst()
{
	T copy = this->_vector.at(0);
	this->_vector.erase(this->_vector.at(0));
	return copy;
}

template <typename T>
T * ArrayList<T>::toArray()
{
	T* space = malloc(sizeof(sizeof(T) * this->_vector.size()));
	for (int i = 0; i < this->_vector.size(); ++i)
	{
		space[i] = this->_vector.at(i);
		this->deallocate_buffer.push_back(space[i]);
	}
	return space;
}

template <typename T>
ArrayList<T>::ArrayList()
{
}

template <typename T>
ArrayList<T>::~ArrayList()
{
	for (int i = 0; i < this->deallocate_buffer.size(); ++i)
	{
		free(this->deallocate_buffer.at(i));
	}
}


#endif //JAVASTYLE_ARRAYLIST_H
