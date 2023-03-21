#include <type_traits>
#include <string_view>
#include <string>
#include <utility>

template <typename T, typename ...OtherTypes>
struct any_of
{
    static constexpr bool value = (std::is_same_v<T, OtherTypes> || ...);
};

template <typename  T, typename ...OtherTypes>
constexpr bool any_of_v = any_of<T, OtherTypes...>::value;

template<typename T>
class OtherComparisionOperators {
public:
    template <typename A>
    constexpr bool operator==(const A& other) const {
        return !(Value() < other) && !(Value() > other);
    }
    template <typename A>
    constexpr bool operator!=(const A& other) const {
        return ((Value() < other) || (Value() > other));
    }
    template <typename A>
    constexpr bool operator<=(const A& other) const {
        return !(Value() > other);
    }
    template <typename A>
    constexpr bool operator>=(const A& other) const {
        return !(Value() < other);
    }
private:
    constexpr T const& Value() const
    {
        return static_cast<const T&>(*this);
    }
    OtherComparisionOperators() = default;
    ~OtherComparisionOperators() = default;
    OtherComparisionOperators<T>(const OtherComparisionOperators<T>& other) = default;
    OtherComparisionOperators<T>(OtherComparisionOperators<T>&& other) = default;
    OtherComparisionOperators<T>& operator=(const OtherComparisionOperators<T>& other) = default;
    OtherComparisionOperators<T>& operator=(OtherComparisionOperators<T>&& other) = default;

    friend T;
};

class B
{
public:
    B(int a, int b) : m_a(a), m_b(b){}
    int m_a = 0;
    int m_b = 0;
};


class A : public OtherComparisionOperators<A>
{
public:
    A(int a, int b) : m_a(a), m_b(b){}


    template <typename OtherT>
    std::enable_if_t<any_of_v<OtherT, A, B>, bool>
    operator<(const OtherT& other) const
    {
        return (m_a < other.m_a) && (m_b < other.m_b);
    }

    template <typename OtherT>
    std::enable_if_t<any_of_v<OtherT, A, B>, bool>
    operator>(const OtherT& other) const
    {
        return (m_a > other.m_a) && (m_b > other.m_b);
    }

    template <typename OtherT>
    std::enable_if_t<std::is_integral_v<OtherT>, bool>
    operator<(const OtherT& other) const
    {
        return m_a < other;
    }

    template <typename OtherT>
    std::enable_if_t<std::is_integral_v<OtherT>, bool>
    operator>(const OtherT& other) const
    {
        return m_a > other;
    }

private:
    int m_a = 0;
    int m_b = 0;
};
