// Adapted from donated nonius code.

#ifndef CATCH_MEASURE_HPP_INCLUDED
#define CATCH_MEASURE_HPP_INCLUDED

#include <catch2/benchmark/catch_clock.hpp>
#include <catch2/benchmark/detail/catch_complete_invoke.hpp>
#include <catch2/benchmark/detail/catch_timing.hpp>

#include <utility>

namespace Catch {
    namespace Benchmark {
        namespace Detail {
            template <typename Clock, typename Fun, typename... Args>
            TimingOf<Clock, Fun, Args...> measure(Fun&& fun, Args&&... args) {
                auto start = Clock::now();
                auto&& r = Detail::complete_invoke(fun, std::forward<Args>(args)...);
                auto end = Clock::now();
                auto delta = end - start;
                return { delta, std::forward<decltype(r)>(r), 1 };
            }
        } // namespace Detail
    } // namespace Benchmark
} // namespace Catch

#endif // CATCH_MEASURE_HPP_INCLUDED
