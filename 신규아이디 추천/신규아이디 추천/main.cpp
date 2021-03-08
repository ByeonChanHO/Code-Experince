#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
string FirstStep(string new_id);
string SecondStep(string new_id);
string ThirdStep(string new_id, int Count);
string FourStep(string new_id);
string FiveStep(string new_id);
string SixStep(string new_id);	
string SevenStep(string new_id);

int main() {

	string new_id = "abcdefghijklmn.p";



	new_id = FirstStep(new_id);
	new_id = SecondStep(new_id);
	new_id = ThirdStep(new_id, 0);
	new_id = FourStep(new_id);
	new_id = FiveStep(new_id);
	new_id = SixStep(new_id);
	new_id = SevenStep(new_id);
	
	
	cout << new_id << endl;

	system("pause");
	return 0;
}

string FirstStep(string new_id) {

	int temp;
	//+32
	
	for (string::iterator it = new_id.begin(); it != new_id.end(); ++it) {
		temp = static_cast<int>(*it);
		if (temp >= 65 && temp <= 90) { temp = temp + 32; *it = static_cast<char>(temp); }
	}



	return new_id;
}

string SecondStep(string new_id) {
	
	string a = "~!@#$%^&*()=+[{]}:?,<>/";
	int temp = 0;


	for (int i = 0; i < new_id.length(); i++) {
		temp = static_cast<int>(new_id[i]);

		if (temp >= 33 && temp <= 44) { new_id.erase(new_id.begin() + i); i = i - 1; }
		else if (temp >= 58 && temp <= 64) { new_id.erase(new_id.begin() + i); i = i - 1; }
		else if (temp >= 91 && temp <= 94) { new_id.erase(new_id.begin() + i); i = i - 1; }
		else if (temp >=123 && temp <=126) { new_id.erase(new_id.begin() + i); i = i - 1; }
		else if (temp == 47 || temp == 96) { new_id.erase(new_id.begin() + i); i = i - 1; }
	}

	return new_id;
}

string ThirdStep(string new_id, int Count) {


	if(new_id[Count] == '.' && new_id[Count + 1] == '.'){ new_id.erase(new_id.begin() + Count); }
	else{ Count++; }

	if (Count >= new_id.length()) { return new_id; }
	new_id = ThirdStep(new_id, Count);

	return new_id;
}

string FourStep(string new_id) {


	if (new_id.size() >= 1 && new_id.front() == '.') { new_id.erase(new_id.begin()); }

	if (new_id.size() >= 1 && new_id.back() == '.') { new_id.pop_back(); }

	return new_id;
}

string FiveStep(string new_id) {

	if (new_id.size() == 0) { new_id.push_back('a'); }
	
	return new_id;
}

string SixStep(string new_id) {

	if (new_id.length() > 15) { new_id.erase(new_id.begin() + 15, new_id.end()); }

	new_id = FourStep(new_id);

	return new_id;
}

string SevenStep(string new_id) {
	
	while (new_id.length() < 3) { 
		new_id = new_id + new_id.back(); 
	}

	return new_id;
}