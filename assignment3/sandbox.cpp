/*
 * CS106L Assignment 3: Make a Class
 * Created by Fabio Ibanez with modifications by Jacob Roberts-Baca.
 */
#include "class.h"

void sandbox() {
  Student stu1;
  Student stu2("ultrabababa", 20);

  stu1.setName("test");
  stu1.printStuInfo();

  stu2.printStuInfo();
}