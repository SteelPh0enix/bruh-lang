#include "tokenizer.hpp"
#include "logger.hpp"

namespace BruhLang {

std::ostream& operator<<(std::ostream& os, Token const& token) {
  return os;
}
namespace Tokenizer {
std::vector<Token> tokenize(std::string const& code) {
  std::vector<Token> tokens{};

  Log::code_error(69, "nasralem");

  return tokens;
}
}  // namespace Tokenizer
}  // namespace BruhLang