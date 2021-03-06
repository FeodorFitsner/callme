#pragma once

#ifndef LOG_H_SPSC31OG
#define LOG_H_SPSC31OG

#ifdef CALLME_LOGGING

#define ELPP_THREAD_SAFE

#ifndef _MSC_VER
#define ELPP_STACKTRACE_ON_CRASH
#endif

#ifdef __clang__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-local-typedef"
#pragma GCC diagnostic ignored "-Wpessimizing-move"
#endif
#include "easyloggingpp.h"
#ifdef __clang__
#pragma GCC diagnostic pop
#endif

#define LOG_INFO(...) el::Loggers::getLogger("callme")->info(__VA_ARGS__)
#define LOG_WARN(...) el::Loggers::getLogger("callme")->warn(__VA_ARGS__)
#define LOG_ERROR(...) el::Loggers::getLogger("callme")->error(__VA_ARGS__)
#define LOG_DEBUG(...) el::Loggers::getLogger("callme")->debug(__VA_ARGS__)
#define LOG_TRACE(...) el::Loggers::getLogger("callme")->trace(__VA_ARGS__)

#define LOG_EXPR(Level, Expr) LOG_##Level("`"#Expr"` = %v", Expr)

#else

#define LOG_INFO(...)
#define LOG_WARN(...)
#define LOG_ERROR(...)
#define LOG_DEBUG(...)
#define LOG_TRACE(...)
#define LOG_EXPR(...)

#endif

#endif /* end of include guard: LOG_H_SPSC31OG */
