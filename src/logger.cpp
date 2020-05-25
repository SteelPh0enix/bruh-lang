#include "logger.hpp"

namespace BruhLang {
namespace Log {
std::string get_message_type(MessageType type) {
  switch (type) {
    case MessageType::DEBUG:
      return "DEBUG";
    case MessageType::ERROR:
      return "ERROR";
    case MessageType::INFO:
      return "INFO";
    case MessageType::WARNING:
      return "WARNING";
  }
}

void code_error(int line, std::string const& message) {
  log(MessageType::ERROR, "<line " + std::to_string(line) + "> " + message);
}

void log(MessageType type, std::string const& message) {
  std::cout << "[" << get_message_type(type) << "] " << message << '\n';
}
}  // namespace Log
}  // namespace BruhLang