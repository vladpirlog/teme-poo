#include <exception>

class EmptyMatrix : public std::exception
{
public:
    EmptyMatrix() noexcept {}
    EmptyMatrix(const EmptyMatrix &) noexcept = default;
    EmptyMatrix &operator=(const EmptyMatrix &) noexcept = default;
    virtual ~EmptyMatrix() noexcept = default;
    virtual const char *what() const noexcept
    {
        return "Empty Matrix";
    }
};
