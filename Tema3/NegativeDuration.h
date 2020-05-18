#include <exception>

class NegativeDuration : public std::exception
{
public:
    NegativeDuration() noexcept {}
    NegativeDuration(const NegativeDuration &) noexcept = default;
    NegativeDuration &operator=(const NegativeDuration &) noexcept = default;
    virtual ~NegativeDuration() noexcept = default;
    virtual const char *what() const noexcept
    {
        return "Durata filmului este un numar negariv.";
    }
};
