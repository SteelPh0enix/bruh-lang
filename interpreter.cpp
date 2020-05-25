#include <algorithm>
#include <argparser.hpp>
#include <fstream>
#include <iostream>
#include <iterator>
#include <string>
#include <tokenizer.hpp>
#include <vector>

constexpr char const* const INTERPRETER_PROMPT = "bruh> ";

std::vector<char> load_file(std::string const& path) {
  auto file_contents = std::vector<char>{};
  auto file_stream = std::fstream(path, std::ios::in);

  auto file_start = std::istreambuf_iterator<char>(file_stream);
  auto file_end = std::istreambuf_iterator<char>{};
  auto vector_inserter = std::back_inserter(file_contents);

  std::copy(file_start, file_end, vector_inserter);

  return file_contents;
}

void run() {

}

void run_from_file(std::string const& path) {}

void interpret() {
  std::string command{};
  std::cout << INTERPRETER_PROMPT;
  while (std::getline(std::cin, command)) {
    std::cout << INTERPRETER_PROMPT;
  }
}

int main(int argc, char** argv) {
  auto arguments = Argparser(argc, argv);

  if (arguments.count() > 1) {
    std::cerr << "Usage:\n"
              << '\t' << arguments.get_exec_name() << " - runs in interpreter mode\n"
              << '\t' << arguments.get_exec_name() << " [filename] - runs code from file\n";
  } else if (arguments.count() == 1) {
    run_from_file(arguments.get<std::string>(0));
  } else {
    interpret();
  }
}