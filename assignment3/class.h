#include <string>

class Student
{
private:
    std::string name_;
    int stuId_;

    int getStuId() const;

public:
    Student();
    Student(const std::string& name, int stuId);

    std::string getName() const;

    void setName(const std::string& name);
    
    void printStuInfo() const;
};
