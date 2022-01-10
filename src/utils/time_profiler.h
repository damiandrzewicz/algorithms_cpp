#pragma once

#include <iostream>
#include <chrono>

class TimeProfiler
{
public:
    TimeProfiler(const char *funcName)
    	: funcName_(funcName)
    {
    	start();
    }
    ~TimeProfiler()
    {
    	stop();
    	print_profile();
    }

    void start()
    {
    	start_ = std::chrono::high_resolution_clock::now();
    }

    long stop()
    {
    	stop_ = std::chrono::high_resolution_clock::now();
    	return elapsed_time();
    }

    long elapsed_time()
    {
    	return (std::chrono::duration_cast<std::chrono::microseconds>(stop_ - start_)).count();
    }

    void print_profile()
    {
    	std::cout << funcName_ << ": t=" << elapsed_time() << "[us]" << std::endl;
    }

private:
    const char *funcName_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_, stop_;
};
