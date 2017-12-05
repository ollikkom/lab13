# lab13
Лабораторная работа №13


## $ cmake -H. -B_builds

## $ cmake --build _builds

## $ cd _builds

## $ ./pack Person.yml

Enter data to fields of the Person structure.
First name:
Sara

Last name:
As

Email:
ol@ya.ru

Age(optional):
12

Phone (optional):
8965445557


## $ cat Person.yml
first_name: Sara

last_name: As

nickname: ol

server: ya.ru

age: 12

phone: 8965445557


## $ yamllint person1.yml
Person.yml

  1:1       warning  missing document start "---"  (document-start)

Если нет yaml, устанавливаем
## $ sudo pip install yamllint
