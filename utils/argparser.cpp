#include "argparser.hpp"

constexpr char PATH_SEPARATOR =
#ifdef _WIN32
    '\\';
#else
    '/';
#endif

Argparser::Argparser(int argc, char** argv) : _arguments(argc - 1) {
  _execpath = std::string(argv[0]);
  for (int i = 1; i < argc; i++) {
    _arguments[i - 1] = std::string(argv[i]);
  }
}

template <>
std::string Argparser::get(unsigned index) const {
  return _arguments.at(index);
}

template <>
int Argparser::get(unsigned index) const {
  return std::stoi(_arguments.at(index));
}

std::vector<std::string> Argparser::get_all() const {
  return _arguments;
}

std::vector<std::string>::const_iterator Argparser::begin() const {
  return _arguments.cbegin();
}

std::vector<std::string>::const_iterator Argparser::end() const {
  return _arguments.cend();
}

std::string Argparser::get_exec_path() const {
  return _execpath;
}

std::string Argparser::get_exec_name() const {
  auto last_separator = _execpath.find_last_of(PATH_SEPARATOR);
  return _execpath.substr(last_separator + 1);
}

std::string Argparser::get_exec_basename() const {
  auto exec_name = get_exec_name();
  auto dot_position = exec_name.find_last_of('.');
  return exec_name.substr(0, dot_position);
}

unsigned Argparser::count() const {
  return _arguments.size();
}