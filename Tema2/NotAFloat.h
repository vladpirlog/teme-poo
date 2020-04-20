#include <exception>

class NotAFloat : public std::exception
{
public:
    NotAFloat() noexcept {}
    NotAFloat(const NotAFloat &) noexcept = default;
    NotAFloat &operator=(const NotAFloat &) noexcept = default;
    virtual ~NotAFloat() noexcept = default;
    virtual const char *what() const noexcept
    {
        return "Not a Float";
    }
};
