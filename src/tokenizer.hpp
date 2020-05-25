#pragma once
#include <string>
#include <vector>
#include <iostream>

namespace BruhLang {
struct Token {};

std::ostream& operator<<(std::ostream& os, Token const& token);
namespace Tokenizer {
std::vector<Token> tokenize(std::string const& code);
}
}  // namespace BruhLang