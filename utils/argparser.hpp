#pragma once
#include <string>
#include <vector>

class Argparser {
 public:
  Argparser(int argc, char** argv);

  // Converts argument to specified type and returns it.
  // Arguments are stored as std::strings
  template <typename T>
  T get(unsigned index) const {
    return static_cast<T>(_arguments.at(index));
  }

  // Returns vector with all arguments
  std::vector<std::string> get_all() const;

  // Returns iterator to the beginning of arguments container
  std::vector<std::string>::const_iterator begin() const;

  // Returns iterator to the end of arguments container
  std::vector<std::string>::const_iterator end() const;

  // Returns full path sent throught argv
  std::string get_exec_path() const;

  // Returns executable name with extension
  std::string get_exec_name() const;

  // Returns executable name without extension
  std::string get_exec_basename() const;

  // Return argument count (excluding execpath)
  unsigned count() const;

 private:
  std::vector<std::string> _arguments;
  std::string _execpath;
};