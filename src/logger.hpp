#pragma once
#include <iostream>
#include <string>

namespace BruhLang {
namespace Log {
enum class MessageType { INFO, DEBUG, WARNING, ERROR };
// Translate message type to string
std::string get_message_type(MessageType type);

// Log a code error
void code_error(int line, std::string const& message);

// Log a message
void log(MessageType type, std::string const& message);
}  // namespace Log
}  // namespace BruhLang