#pragma once

#include <string>
#include <vector>
#include <functional>
#include <mutex>
#include <format>
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

    template <typename... Args>
    void Log(LogLevel level, std::format_string<Args...> fmt, Args &&...args)
    {
      if (level < m_currentLevel)
        return;

      std::string formattedMessage = std::format(fmt, std::forward<Args>(args)...);
      Log(level, formattedMessage);
    }

    void RegisterCallback(LogCallback callback);
    void ClearCallbacks();
  };

#define LOGGER() Logger::GetInstance()
#define LOG(level, ...) Logger::GetInstance().Log(level, __VA_ARGS__)
#define LOG_INFO(...) LOG(LogLevel::INFO, __VA_ARGS__)
#define LOG_DEBUG(...) LOG(LogLevel::DEBUG, __VA_ARGS__)
#define LOG_WARNING(...) LOG(LogLevel::WARNING, __VA_ARGS__)
#define LOG_ERROR(...) LOG(LogLevel::ERROR, __VA_ARGS__)
#define LOG_TRACE(...) LOG(LogLevel::TRACE, __VA_ARGS__)

} // namespace TRUFFLE
