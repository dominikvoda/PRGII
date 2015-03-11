// SmallBank.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

class Client{
private:
	int code;
	string name;

public :
	Client(int c, string n);

	int GetCode();
	string GetName();
};

class Account{
private:
	int number;
	float balance;
	float interestRate;

	Client * owner;
	Client * partner;

public:
	Account(int n, Client * o);
	Account(int n, Client * o, Client * p);
	Account(int n, Client * o, float ir);
	Account(int n, Client * o, Client * p, float ir);

	int GetNumber();
	float GetBalance();
	float GetInterestedRate();
	Client * GetOwner();
	Client * GetPartner();

	void Deposit(float c);
	float Withdraw(float c);
	void AddInterest();
};

class Bank{
private:
	static const int MAX_CLIENTS = 100;
	static const int MAX_ACCOUNTS = 500;

	Client * clients[MAX_CLIENTS];
	int clientsCount;

	Account * accounts[MAX_ACCOUNTS];
	int accountsCount;

public:

	Bank();
	~Bank();

	Client * GetClient(int c);
	Account * GetAccount(int n);

	void AddClient(int c, string n);
	void AddAccount(int n, Client * o);
	void AddAccount(int n, Client * o, Client * p);
	void AddAccount(int n, Client * o, float ir);
	void AddAccount(int n, Client * o, Client * p, float ir);

	void AddInterest();

};

Client::Client(int c, string n){
	this->code = c;
	this->name = n;
}

int Client::GetCode(){
	return this->code;
}

string Client::GetName(){
	return this->name;
}

Account::Account(int n, Client * o){
	this->number = n;
	this->owner = o;
}

Account::Account(int n, Client * o, Client * p){
	this->number = n;
	this->owner = o;
	this->partner = p;
}

Account::Account(int n, Client * o, float ir){
	this->number = n;
	this->owner = o;
	this->interestRate = ir;
}

Account::Account(int n, Client * o, Client * p, float ir){
	this->number = n;
	this->owner = o;
	this->partner = p;
	this->interestRate = ir;
}

int Account::GetNumber(){
	return this->number;
}

float Account::GetBalance(){
	return this->balance;
}

float Account::GetInterestedRate(){
	return this->interestRate;
}

Client * Account::GetOwner(){
	return this->owner;
}

Client * Account::GetPartner(){
	return this->partner;
}

void Account::Deposit(float c){
	this->balance += c;
}

float Account::Withdraw(float c){
	if (c < this->balance){
		this->balance -= c;
		return this->balance;
	}
	return 0;
}

void Account::AddInterest(){
	this->balance *= (1 + this->interestRate);
}

Bank::Bank(){
	this->accountsCount = 0;
	this->clientsCount = 0;
}

Bank::~Bank(){
	for (int i = 0; i < this->accountsCount; i++)
		delete accounts[i];
	for (int i = 0; i < this->clientsCount; i++)
		delete clients[i];
}

Client * Bank::GetClient(int c){
	for (int i = 0; i < this->clientsCount; i++){
		if (this->clients[i]->GetCode() == c)
			return this->clients[i];
	}
}

Account * Bank::GetAccount(int n){
	for (int i = 0; i < this->accountsCount; i++){
		if (this->accounts[i]->GetNumber() == n)
			return this->accounts[i];
	}
}

void Bank::AddClient(int c, string n){
	this->clients[clientsCount++] = new Client(c, n);
}

void Bank::AddAccount(int n, Client * o){
	this->accounts[accountsCount] = new Account(n, o);
}

void Bank::AddAccount(int n, Client * o, Client * p){
	this->accounts[accountsCount] = new Account(n, o, p);
}

void Bank::AddAccount(int n, Client * o, float ir){
	this->accounts[accountsCount] = new Account(n, o, ir);
}

void Bank::AddAccount(int n, Client * o, Client * p, float ir){
	this->accounts[accountsCount] = new Account(n, o, p, ir);
}

void Bank::AddInterest(){
	for (int i = 0; i < accountsCount; i++){
		this->accounts[i]->AddInterest();
	}
}





int _tmain(int argc, _TCHAR* argv[])
{
	Bank * bank = new Bank();
	for (int i = 0; i < 50; i++){
		bank->AddClient(i, "klient-" + to_string(i));
	}
	for (int i = 0; i < 50; i++){
		cout << bank->GetClient(i)->GetCode() << endl;
	}
	return 0;
}

