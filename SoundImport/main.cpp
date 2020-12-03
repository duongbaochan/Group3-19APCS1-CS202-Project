#include <iostream>
#include <Windows.h>

using namespace std;

int main() {
	PlaySound(TEXT("Sounds/woosh.wav"), NULL, SND_SYNC);
	cout << "Sound played!" << endl;
	system("pause");
	PlaySound(TEXT("Sounds/woosh_1.wav"), NULL, SND_SYNC);
	cout << "Sound played!" << endl;
	return 0;
}