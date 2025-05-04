#pragma once

#include <string>
#include <vector>
#include <functional>
#include <mutex>
#include "Utils/Singleton.h"

namespace TRUFFLE
{
  enum class LogLevel
  {
    TRACE,
    DEBUG,
    INFO,
    WARNING,
    ERROR
  };

  class Logger : public Singleton<Logger>
  {
  public:
    using LogCallback = std::function<void(const std::string &)>;

  private:
    LogLevel m_currentLevel = LogLevel::INFO;
    std::vector<LogCallback> m_callbacks;
    std::mutex m_mutex;

    std::string GetTimeStamp();
    std::string LevelToString(LogLevel level);

  public:
    friend class Singleton<Logger>;

    void SetLogLevel(LogLevel level) { m_currentLevel = level; }
    void Log(LogLevel level, const std::string &message);
    void RegisterCallback(LogCallback callback);
    void ClearCallbacks();
  };

#define LOGGER() Logger::GetInstance()
#define LOG(level, message) Logger::GetInstance().Log(level, message)
#define LOG_INFO(message) LOG(LogLevel::INFO, message)
#define LOG_DEBUG(message) LOG(LogLevel::DEBUG, message)
#define LOG_WARNING(message) LOG(LogLevel::WARNING, message)
#define LOG_ERROR(message) LOG(LogLevel::ERROR, message)
#define LOG_TRACE(message) LOG(LogLevel::TRACE, message)

} // namespace TRUFFLE
