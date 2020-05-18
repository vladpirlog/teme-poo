#include <exception>

class InvalidType : public std::exception
{
public:
    InvalidType() noexcept {}
    InvalidType(const InvalidType &) noexcept = default;
    InvalidType &operator=(const InvalidType &) noexcept = default;
    virtual ~InvalidType() noexcept = default;
    virtual const char *what() const noexcept
    {
        return "Valoarea citita nu are tipul corespunzator.";
    }
};
