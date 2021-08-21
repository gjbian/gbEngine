#include <chrono>
#include <iostream>

#define ENABLE_TIME_MEASURE

#ifdef ENABLE_TIME_MEASURE

static std::chrono::system_clock::time_point start;
static std::chrono::system_clock::time_point finish;

void TIME_MEASURE_START() {
	start = std::chrono::system_clock::now();
}

void TIME_MEASURE_END() {
	finish = std::chrono::system_clock::now();
	auto duration = std::chrono::duration_cast<std::chrono::microseconds>(finish - start);
	auto cost = double(duration.count()) * std::chrono::microseconds::period::num / std::chrono::microseconds::period::den;
	std::cout << "time cost:" << cost << std::endl;
}

#else

#define TIME_MEASURE_START()
#define TIME_MEASURE_END()

#endif