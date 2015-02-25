// prII_class.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

class KeyValue{
private:
	int key;
	float value;
	KeyValue *next;

public:
	KeyValue(int k, float v);
	~KeyValue();
	float GetValue();
	void CreateNext(int k, int v);
	KeyValue* GetNext();
};

KeyValue::KeyValue(int k, float v){
	this->key = k;
	this->value = v;
	this->next = NULL;
}

KeyValue::~KeyValue(){
	if (this->next != NULL)
		delete this->next;
}

float KeyValue::GetValue(){
	return this->value;
}

void KeyValue::CreateNext(int k, int v){
	this->next = new KeyValue(k, v);
}

KeyValue* KeyValue::GetNext(){
	return this->next;
}

int _tmain(int argc, _TCHAR* argv[])
{
	KeyValue * c1 = new KeyValue(1, 1.5);
	cout << c1->GetValue() << endl;
	c1->CreateNext(2, 2.5);
	cout << c1->GetNext()->GetValue() << endl;
	delete c1;
	return 0;
}

