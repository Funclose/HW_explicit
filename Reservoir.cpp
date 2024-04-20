#include <iostream>
#include "Reservoir.h"

//���� ��� user
Reservoir createReservoirFromUserInput() {
	char buffer[100];
	const int MaxSize = 100;

	
	std::cout << "������� �������� �������: ";
	std::cin.getline(buffer, MaxSize);
	char* name = new char[strlen(buffer) + 1];
	strcpy_s(name, strlen(buffer) + 1, buffer);

	
	std::cout << "������� ��� �������: ";
	std::cin.getline(buffer, MaxSize);
	char* type = new char[strlen(buffer) + 1];
	strcpy_s(type, strlen(buffer) + 1, buffer);

	
	int width;
	std::cout << "������� ������ �������: ";
	std::cin >> width;

	
	int length;
	std::cout << "������� ����� �������: ";
	std::cin >> length;

	
	int depth;
	std::cout << "������� ������������ �������: ";
	std::cin >> depth;

	
	Reservoir lake(name, type, width, length, depth);

	
	delete[] name;
	delete[] type;

	
	return lake;
}

Reservoir::Reservoir()
{
	name = nullptr;
	type = nullptr;
	width = 0;
	length = 0;
	depth = 0;
}

Reservoir::Reservoir(const char* name, const char* type, int width, int length, int depth)
{
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);

	this->type = type;

	this->width = width;
	this->length = length;
	this->depth = depth;
}

Reservoir::Reservoir(const Reservoir& value)
{
	name = new char[strlen(value.name) + 1];
	strcpy_s(name, strlen(value.name) + 1, value.name);

	type = value.type;

	width = value.width;
	length = value.length;
	depth = value.depth;
}

Reservoir::~Reservoir()
{
	delete[] name;
}

char* Reservoir::getName()
{
	return name;
}

const char* Reservoir::getType()
{
	return type;
}

int Reservoir::getWidth()
{
	return width;
}

int Reservoir::getLength()
{
	return length;
}

int Reservoir::getDepth()
{
	return depth;
}

double Reservoir::approximateVolume() //1.��������������� �����
{
	return width * length * depth;
}

double Reservoir::surfaceArea() //2.����� ����������� 
{
	return width * length;
}

bool Reservoir::sameType(const Reservoir& other) //3.������� �� ���
{
	return strcmp(type, other.type) == 0;
}



Reservoir Reservoir::copy() //5 ��� ����������� ��������
{
	return Reservoir(*this);
}

void Reservoir::setName(const char* name)
{
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Reservoir::setType(const char* type)
{
	this->type = type;
}

void Reservoir::setWidth(int width)
{
	this->width = width;
}

void Reservoir::setLength(int length)
{
	this->length = length;
}

void Reservoir::setDepth(int depth)
{
	this->depth = depth;
}

int main()
{
	setlocale(LC_ALL, "ru");



	Reservoir lake = createReservoirFromUserInput();
	

	
	std::cout << "�������� �������: " << lake.getName() << std::endl;
	std::cout << "��� �������: " << lake.getType() << std::endl;
	std::cout << "������ �������: " << lake.getWidth() << std::endl;
	std::cout << "����� �������: " << lake.getLength() << std::endl;
	std::cout << "������������ ������� �������: " << lake.getDepth() << std::endl;
	std::cout << "��������������� �����: " << lake.approximateVolume() << std::endl;

	std::cout << "����� ����� �������: " << lake.surfaceArea() << std::endl;

	Reservoir lakeCopy = lake.copy();

//�������� �� ��� �������
	if (lake.sameType(lakeCopy)) {
		std::cout << "������� �������� �� ������ ����." << std::endl;
	}
	else {
		std::cout << "������� �������� �� ����� ����." << std::endl;
	}
	return 0;
}


