#ifndef CATCH_REPORTER_TAP_HPP_INCLUDED
#define CATCH_REPORTER_TAP_HPP_INCLUDED

#include <catch2/reporters/catch_reporter_streaming_base.hpp>

namespace Catch {

    struct TAPReporter : StreamingReporterBase {

        TAPReporter( ReporterConfig const& config ):
            StreamingReporterBase( config ) {
            m_preferences.shouldReportAllAssertions = true;
        }
        ~TAPReporter() override;

        static std::string getDescription() {
            using namespace std::string_literals;
            return "Reports test results in TAP format, suitable for test harnesses"s;
        }

        void noMatchingTestCases(std::string const& spec) override;

        void assertionStarting( AssertionInfo const& ) override {}

        bool assertionEnded(AssertionStats const& _assertionStats) override;

        void testRunEnded(TestRunStats const& _testRunStats) override;

    private:
        std::size_t counter = 0;
    };

} // end namespace Catch

#endif // CATCH_REPORTER_TAP_HPP_INCLUDED
