#include <iostream>
#include <string>
#include <fstream>
#include "yaml-cpp/yaml.h"
using namespace std;
using namespace YAML;

struct Email {
  std::string nickname;
  std::string server;
};

struct Person {
  std::string  first_name;
  std::string  last_name;
  Email        email;
  size_t       age;
  std::string  phone;
};


int main()
{
	Person pr;
	fstream MyFile ("Person.yml", fstream::out);

  cout << "Enter data to fields of the Person structure." << endl << "First name:" << endl;
  cin >> pr.first_name;
  cout << endl << "Last name:" << endl;
  cin >> pr.last_name;
  cout << endl << "Email" << endl;
  cin >> pr.email.nickname;
  string s_null, s_age;
	cout << endl << "Age(optional):" << endl;
	getline(cin, s_null);
	getline(cin, s_age);
	if(s_age.size() != 0) {
        	pr.age = std::stoi(s_age);
	}
	cout << endl << "Phone(optional):" << endl;
	getline(std::cin, pr.phone);

	int pos = pr.email.nickname.find("@");
	if (pos == -1)
	{
		cout << endl << "ERROR! Incorrect email!" << endl;
		return -1;
	}
	pr.email.server = pr.email.nickname.substr(pos + 1, pr.email.nickname.size());
	pr.email.nickname = pr.email.nickname.substr(0, pos);

	Emitter out;
	out << BeginMap;
	out << Key << "first_name";
	out << Value << pr.first_name;
	out << Key << "last_name";
	out << Value << pr.last_name;
	out << Key << "nickname";
	out << Value << pr.email.nickname;
	out << Key << "server";
	out << Value << pr.email.server;
	out << Key << "age";
	out << Value << pr.age;
	out << Key << "phone";
	out << Value << pr.phone;
	out << EndMap;
	out << Newline;


	MyFile << out.c_str();
	MyFile.close();

	return 0;
}
