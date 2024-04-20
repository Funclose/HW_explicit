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
	Reservoir(); // Конструктор за замовчуванням
	Reservoir(const char* name, const char* type, int width, int length, int depth); // Конструктор з параметрами
	Reservoir(const Reservoir& value); // Конструктор копіювання
	~Reservoir(); 

	//Геттеры
	char* getName(); // Повертає назву водойми
	const char* getType(); // Повертає тип водойми
	int getWidth(); // Повертає ширину водойми
	int getLength(); // Повертає довжину водойми
	int getDepth(); // Повертає глибину водойми


	//основные методы для дз
	double approximateVolume(); // Визначення приблизного обсягу
	double surfaceArea(); // Визначення площі водної поверхні
	bool sameType(const Reservoir& other); // Перевірка належності до одного типу
	
	Reservoir copy(); // метод копирования


	//сеттеры
	void setName(const char* name); // Встановлює назву водойми
	void setType(const char* type); // Встановлює тип водойми
	void setWidth(int width); // Встановлює ширину водойми
	void setLength(int length); // Встановлює довжину водойми
	void setDepth(int depth); // Встановлює глибину водойми
};

