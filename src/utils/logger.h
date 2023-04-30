#pragma once

#include "spdlog/async.h"
#include "spdlog/sinks/basic_file_sink.h"
#include "spdlog/sinks/daily_file_sink.h"
#include "spdlog/sinks/stdout_color_sinks.h"
#include "spdlog/spdlog.h"

namespace tmp
{
class Logger
{
   public:
    static Logger &GetInstance()
    {
        static Logger kLogger;
        return kLogger;
    }

    virtual ~Logger()
    {
        spdlog::drop(LOGGER_CONSOLE_);
        logger_ = nullptr;
    }

    template <typename... Args>
    void LogInfo(Args &&...args)
    {
        logger_->log(spdlog::source_loc{__FILE__, __LINE__, __func__},
                     spdlog::level::level_enum::info, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void LogWarn(Args &&...args)
    {
        logger_->log(spdlog::source_loc{__FILE__, __LINE__, __func__},
                     spdlog::level::level_enum::warn, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void LogDebug(Args &&...args)
    {
        logger_->log(spdlog::source_loc{__FILE__, __LINE__, __func__},
                     spdlog::level::level_enum::debug, std::forward<Args>(args)...);
    }

    template <typename... Args>
    void LogError(Args &&...args)
    {
        logger_->log(spdlog::source_loc{__FILE__, __LINE__, __func__},
                     spdlog::level::level_enum::err, std::forward<Args>(args)...);
    }

   private:
    std::shared_ptr<spdlog::logger> logger_;
    std::string LOGGER_CONSOLE_ = "lib_console";

    Logger()
    {
        spdlog::set_pattern("[%C:%m:%d-%H:%M:%S.%e][%s:%#:%!][tid:%t][%^%l%$] %v");
        logger_ = spdlog::stdout_color_mt("lib_console");
    }
};

#define LOGI(...)                                   \
    do                                              \
    {                                               \
        Logger::GetInstance().LogInfo(__VA_ARGS__); \
    }                                               \
    while (false)

#define LOGD(...)                                    \
    do                                               \
    {                                                \
        Logger::GetInstance().LogDebug(__VA_ARGS__); \
    }                                                \
    while (false)

#define LOGW(...)                                   \
    do                                              \
    {                                               \
        Logger::GetInstance().LogWarn(__VA_ARGS__); \
    }                                               \
    while (false)

#define LOGE(...)                                    \
    do                                               \
    {                                                \
        Logger::GetInstance().LogError(__VA_ARGS__); \
    }                                                \
    while (false)
}  // namespace tmp
