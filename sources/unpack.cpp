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

	Node document = LoadFile("Person.yml");

	pr.first_name = document["first_name"].as<string>();
      	pr.last_name = document["last_name"].as<string>();
      	pr.email.nickname = document["nickname"].as<string>();
	pr.email.server = document["server"].as<string>();
      	pr.age = document["age"].as<size_t>();
	pr.phone= document["phone"].as<string>();

	string email = pr.email.nickname + "@" + pr.email.server;
	cout << "[Person]" << endl;
  cout << "First name: " << pr.first_name << endl;
  cout << "Last name: " << pr.last_name << endl;
  cout << "Email: " << email << endl;
  cout << "Age: " << pr.age << endl;
	cout << "Phone: " << pr.phone << endl;

	return 0;
}
