#include <exception>

class InvalidPercentage : public std::exception
{
public:
    InvalidPercentage() noexcept {}
    InvalidPercentage(const InvalidPercentage &) noexcept = default;
    InvalidPercentage &operator=(const InvalidPercentage &) noexcept = default;
    virtual ~InvalidPercentage() noexcept = default;
    virtual const char *what() const noexcept
    {
        return "Procentul nu se afla intre 0 si 100.";
    }
};
