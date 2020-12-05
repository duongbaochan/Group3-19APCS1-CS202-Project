#pragma once

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Notifier
{
protected:
	string content;
public:
	Notifier();
	Notifier(string content);
	virtual void notify();
};

class Facebook : public Notifier
{
public:
	Facebook(string content);
	void notify();
};

class SMS : public Notifier
{
public:
	SMS(string content);
	void notify();
};

class Slack : public Notifier
{
public:
	Slack(string content);
	void notify();
};

class Notifying
{
private:
	Notifier* notifier;
public:
	Notifying();
	Notifying(Notifier* notifier);
	void notify();
};

void menu();

