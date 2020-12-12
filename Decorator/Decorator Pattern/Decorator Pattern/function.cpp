#include "function.h"

//void menu()
//{
//	while (true)
//	{
//
//	cout << "This is example of decorator pattern in real world: " << endl;
//	cout << "Notifying info of the library to librarian user." << endl;
//	cout << "1. Enter notification's content." << endl;
//	cout << "2. Use sample notification." << endl;
//	int c;
//	cin >> c;
//	string content = "";
//	while (true)
//	{
//		switch (c)
//		{
//		case 1:
//		{
//			cin >> content;
//			break;
//		}
//
//		case 2:
//		{
//			content = "Your requested newspaper is available at shelf #15.";
//			break;
//		}
//
//		default:
//		{
//			cout << "Wrong choice. Please input again." << endl;
//			break;
//		}
//		}
//		if (c == 1 || c == 2)
//			break;
//	}
//
//	cout << "Please choose the type(s) of notification." << endl;
//	cout << "1. Facebook," << endl;
//	cout << "2. SMS," << endl;
//	cout << "3. Slack." << endl;
//	cout << "Enter \"a b\" if you want to choose multiple types." << endl;
//	string tmp;
//	getline(cin, tmp);
//	string choice;
//	getline(cin, choice);
//
//	stringstream ss;
//	ss << choice;
//
//	int c1 = 0, c2 = 0, c3 = 0;
//	ss >> c1 >> c2 >> c3;
//
//	Facebook fb(content);
//	SMS sms(content);
//	Slack slack(content);
//
//	Notifying fb_notify(&fb);
//	Notifying sms_notify(&sms);
//	Notifying slack_notify(&slack);
//
//	if (c1 == 1 || c2 == 1 || c3 == 1)
//		fb_notify.notify();
//	if (c1 == 2 || c2 == 2 || c3 == 2)
//		sms_notify.notify();
//	if (c1 == 3 || c2 == 3 || c3 == 3)
//		slack_notify.notify();
//
//	char ch;
//	while (true)
//	{
//		cout << "Replay the example Y/N?" << endl;
//		cin >> ch;
//		if (ch == 'N' || ch == 'n')
//			break;
//		else if (ch == 'Y' || ch == 'y')
//			break;
//		else
//			cout << "Invalid choice. Please input again." << endl;
//	}
//
//	if (ch == 'N' || ch == 'n')
//		break;
//	}
//
//}

