#pragma once
#include <cstring>

class Reservoir
{
	char* name;
	const char* type;
	int width;
	int length;
	int depth;
public:
	Reservoir(); // ����������� �� �������������
	Reservoir(const char* name, const char* type, int width, int length, int depth); // ����������� � �����������
	Reservoir(const Reservoir& value); // ����������� ���������
	~Reservoir(); 

	//�������
	char* getName(); // ������� ����� �������
	const char* getType(); // ������� ��� �������
	int getWidth(); // ������� ������ �������
	int getLength(); // ������� ������� �������
	int getDepth(); // ������� ������� �������


	//�������� ������ ��� ��
	double approximateVolume(); // ���������� ����������� ������
	double surfaceArea(); // ���������� ����� ����� �������
	bool sameType(const Reservoir& other); // �������� ��������� �� ������ ����
	
	Reservoir copy(); // ����� �����������


	//�������
	void setName(const char* name); // ���������� ����� �������
	void setType(const char* type); // ���������� ��� �������
	void setWidth(int width); // ���������� ������ �������
	void setLength(int length); // ���������� ������� �������
	void setDepth(int depth); // ���������� ������� �������
};

