#include "Core/Logger/Logger.h"
#include <chrono>
#include <iomanip>
#include <iostream>
#include <sstream>

namespace TRUFFLE
{
  std::string Logger::GetTimeStamp()
  {
    using namespace std::chrono;
    auto now = system_clock::now();
    auto itt = system_clock::to_time_t(now);
    std::tm tm;
#if defined(_WIN32) || defined(_WIN64)
    localtime_s(&tm, &itt);
#else
    localtime_r(&itt, &tm);
#endif
    std::ostringstream ss;
    ss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return ss.str();
  }

  std::string Logger::LevelToString(LogLevel level)
  {
    switch (level)
    {
    case LogLevel::TRACE:
      return "TRACE";
    case LogLevel::DEBUG:
      return "DEBUG";
    case LogLevel::INFO:
      return "INFO";
    case LogLevel::WARNING:
      return "WARNING";
    case LogLevel::ERROR:
      return "ERROR";
    default:
      return "UNKNOWN";
    }
  }

  void Logger::RegisterCallback(LogCallback callback)
  {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_callbacks.push_back(callback);
  }

  void Logger::ClearCallbacks()
  {
    std::lock_guard<std::mutex> lock(m_mutex);
    m_callbacks.clear();
  }

  void Logger::Log(LogLevel level, const std::string &message)
  {
    if (level < m_currentLevel)
      return;

    std::string formatted = "[" + GetTimeStamp() + "] [" + LevelToString(level) + "] " + message;

    std::lock_guard<std::mutex> lock(m_mutex);
    for (const auto &callback : m_callbacks)
    {
      callback(formatted);
    }
  }
}
