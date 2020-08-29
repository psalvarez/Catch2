#ifndef CATCH_MATCHERS_EXCEPTION_HPP_INCLUDED
#define CATCH_MATCHERS_EXCEPTION_HPP_INCLUDED

#include <catch2/matchers/catch_matchers.hpp>

namespace Catch {
namespace Matchers {

class ExceptionMessageMatcher final : public MatcherBase<std::exception> {
    std::string m_message;
public:

    ExceptionMessageMatcher(std::string const& message):
        m_message(message)
    {}

    bool match(std::exception const& ex) const override;

    std::string describe() const override;
};

//! Creates a matcher that checks whether a std derived exception has the provided message
ExceptionMessageMatcher Message(std::string const& message);

} // namespace Matchers
} // namespace Catch

#endif // CATCH_MATCHERS_EXCEPTION_HPP_INCLUDED
