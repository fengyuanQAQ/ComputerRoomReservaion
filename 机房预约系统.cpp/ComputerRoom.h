#pragma once
#include <iostream>

class ComputerRoom
{
public:
	int m_capacity;
	int m_size;//��ǰ������ʣ��
	int m_id;
	ComputerRoom(int capacity,int size,int id)
	{
		this->m_capacity = capacity;
		this->m_id = id;
		this->m_size = size;
	}
};