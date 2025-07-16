#include "class.h"
#include <string>
#include <iostream>

Student::Student() {
    name_ = "null";
    stuId_ = 0;
}

Student::Student(const std::string& name, int stuId)
    : name_(name), stuId_(stuId) {}

int Student::getStuId() const {
    return stuId_;
}

std::string Student::getName() const {
    return name_;
}

void Student::setName(const std::string& name) {
    name_ = name;
}

void Student::printStuInfo() const {
    std::cout << "name: " << getName() << std::endl;
    std::cout << "student ID: " << getStuId() << std::endl;
}
