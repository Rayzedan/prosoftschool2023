#include <string>
#include <string_view>
#include <iostream>

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

class NewA : public OtherComparisionOperators<NewA> {
public:
	NewA(int a, int b) : m_a(a), m_b(b) {}

	// Операторы сравнения с NewA
	bool operator<(const NewA& other) const
	{
		return (m_a < other.m_a) && (m_b < other.m_b);
	}

	bool operator>(const NewA& other) const
	{
		return (m_a > other.m_a) && (m_b > other.m_b);
	}

	// Операторы сравнения с int
	bool operator<(const int other) const
	{
        return (m_a < other) && (m_b < other);
	}

	bool operator>(const int other) const
	{
        return (m_a > other) && (m_b > other);
	}

	// Операторы сравнения с double
	bool operator<(const double other) const
	{
        return (m_a < static_cast<int>(other) && m_b < static_cast<int>(other));
	}

	bool operator>(const double other) const
	{
        return (m_a > static_cast<int>(other) && m_b > static_cast<int>(other));
	}

	// Операторы сравнения с char
	bool operator<(const char other) const
	{
        return (m_a < static_cast<int>(other) && m_b < static_cast<int>(other));
	}

	bool operator>(const char other) const
	{
        return (m_a > static_cast<int>(other) && m_b > static_cast<int>(other));
	}

	// Операторы сравнения с float
	bool operator<(const float other) const
	{
        return (m_a < static_cast<int>(other) && m_b < static_cast<int>(other)) ;
	}

	bool operator>(const float other) const
	{
        return (m_a > static_cast<int>(other) && m_b > static_cast<int>(other));
	}

private:
	int m_a = 0;
	int m_b = 0;
};

class NewB : public OtherComparisionOperators<NewB>
{
public:
	NewB(std::string_view val) : m_stringView(val) {}

	// Операторы сравнения с NewB
	bool operator<(const NewB& other) const
	{
		return m_stringView < other.m_stringView;
	}

	bool operator>(const NewB& other) const
	{
		return m_stringView > other.m_stringView;
	}

	// Операторы сравнения с std::string
	bool operator<(const std::string& other) const
	{
		return m_stringView < other;
	}

	bool operator>(const std::string& other) const
	{
		return m_stringView > other;
	}

private:
	std::string_view m_stringView;
};
