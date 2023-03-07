#include <iostream>
#include <string>
using namespace std;
class Student {
public:
    Student(string name = "", int age = 0, float score = 0.0f);  //��ͨ���캯��
    Student(const Student& stu);  //�������캯����������
public:
    void display();
private:
    string m_name;
    int m_age;
    float m_score;
};
Student::Student(string name, int age, float score) : m_name(name), m_age(age), m_score(score) { }
//�������캯�������壩
Student::Student(const Student& stu) {
    this->m_name = stu.m_name;
    this->m_age = stu.m_age;
    this->m_score = stu.m_score;

    cout << "Copy constructor was called." << endl;
}
void Student::display() {
    cout << m_name << "��������" << m_age << "���ɼ���" << m_score << endl;
}
int main() {
    Student stu1("С��", 16, 90.5);
    Student stu2 = stu1;  //���ÿ������캯��
    Student stu3(stu1);  //���ÿ������캯��
    stu1.display();
    stu2.display();
    stu3.display();

    return 0;
}