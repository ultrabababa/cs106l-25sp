/*
 * CS106L Assignment 2: Marriage Pact
 * Created by Haven Whitney with modifications by Fabio Ibanez & Jacob Roberts-Baca.
 *
 * Welcome to Assignment 2 of CS106L! Please complete each STUDENT TODO
 * in this file. You do not need to modify any other files.
 *
 */

#include <fstream>
#include <iostream>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <unordered_set>

std::string kYourName = "Myla Newton"; // Don't forget to change this!

/**
 * Takes in a file name and returns a set containing all of the applicant names as a set.
 *
 * @param filename  The name of the file to read.
 *                  Each line of the file will be a single applicant's name.
 * @returns         A set of all applicant names read from the file.
 *
 * @remark Feel free to change the return type of this function (and the function
 * below it) to use a `std::unordered_set` instead. If you do so, make sure
 * to also change the corresponding functions in `utils.h`.
 */
std::unordered_set<std::string> get_applicants(std::string filename) {
  std::ifstream infile(filename, std::ios::in);

  if (!infile.is_open()) {
    std::cerr << "can not open file:" << filename << std::endl;
    return std::unordered_set<std::string>();
  }

  std::unordered_set<std::string> applicants;
  std::string line;
  while (std::getline(infile, line)) {
    applicants.insert(line);
  }

  return applicants;
}

std::string get_initials(const std::string& name) {
  if (name.empty()) {
    return "";
  }

  std::string initials, word;
  std::istringstream iss(name);

  while (iss >> word) {
    initials += static_cast<char>(std::toupper(word[0]));
  }

  return initials;
}

bool same_initial(const std::string& name, const std::string& student) {
  return get_initials(name) == get_initials(student);
}

/**
 * Takes in a set of student names by reference and returns a queue of names
 * that match the given student name.
 *
 * @param name      The returned queue of names should have the same initials as this name.
 * @param students  The set of student names.
 * @return          A queue containing pointers to each matching name.
 */
std::queue<const std::string*> find_matches(std::string name, std::unordered_set<std::string>& students) {
  std::queue<const std::string*> names;
  for (const auto& element : students) {
    if (same_initial(name, element)) {
      names.push(&element);
    }
  }
  return names;
}

/**
 * Takes in a queue of pointers to possible matches and determines the one true match!
 *
 * You can implement this function however you'd like, but try to do something a bit
 * more complicated than a simple `pop()`.
 *
 * @param matches The queue of possible matches.
 * @return        Your magical one true love.
 *                Will return "NO MATCHES FOUND." if `matches` is empty.
 */
std::string get_match(std::queue<const std::string*>& matches) {
  if (matches.empty()) {
    return "NO MATCHES FOUND.";
  }
  
  return *matches.back();
}

/* #### Please don't remove this line! #### */
#include "autograder/utils.hpp"
