#include <iostream>
#include <thread>
#include "../sylar/log.h"
#include "../sylar/util.h"

int main() {
    sylar::Logger::ptr logger(new sylar::Logger);
    logger->addAppender(sylar::LogAppender::ptr(new sylar::StdoutLogAppender));

    //测试写入到文件里面
    sylar::FileLogAppender::ptr file_appender(new sylar::FileLogAppender("./log.txt"));
    logger->addAppender(file_appender);

    //写入文件的日志换一种format格式
    sylar::LogFormatter::ptr fmt(new sylar::LogFormatter("%d%t%m"));
    file_appender->setFormatter(fmt);

    //文件日志需要>=ERROR LEVEL
    file_appender->setLevel(sylar::LogLevel::ERROR);
//    sylar::LogEvent::ptr event(new sylar::LogEvent(logger, sylar::LogLevel::DEBUG, __FILE__, __LINE__, 0, sylar::GetThreadId(), sylar::GetFiberId(), time(0)));
//    logger->log(sylar::LogLevel::DEBUG, event);

    SYLAR_LOG_INFO(logger) << "test macro";
    SYLAR_LOG_ERROR(logger) << "test macro error";

    SYLAR_LOG_FMT_DEBUG(logger, "test macro fmt debug %s", "aa");

    auto l = sylar::LoggerMgr::GetInstance()->getLogger("xx");
    SYLAR_LOG_INFO(l) << "xxx";
    return 0;
}
