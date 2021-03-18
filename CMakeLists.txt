cmake_minimum_required(VERSION 3.17)
project(DAA_Assignment)

set(CMAKE_CXX_STANDARD 14)

add_executable(DAA_Assignment main.cpp include/Point.h src/Point.cpp include/Point.h src/Interval.cpp include/Interval.h src/Rectangle.cpp include/Rectangle.h src/Stripe.cpp include/Stripe.h src/MeasureHelper.cpp include/MeasureHelper.h src/Edge.cpp include/Edge.h src/IntervalHelper.cpp include/IntervalHelper.h src/StripeOutput.cpp include/StripeOutput.h src/Ctree.cpp include/Ctree.h)