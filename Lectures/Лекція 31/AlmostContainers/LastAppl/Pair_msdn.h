template <typename T1, typename T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;
	
	T1 first;
	T2 second;

	// constant expression - новий засіб С++11, що спонукає компілятор
	// виконувати конструктори під час компіляції, якщо це можливо
	constexpr pair();
	constexpr pair(const T1& Val1, const T2& Val2);

	template <class Other1, class Other2>
		constexpr pair(const pair<Other1, Other2>& Right);
	template <class Other1, class Other2>
		constexpr pair(const pair <Other1 Val1, Other2 Val2>&& Right);
	template <class Other1, class Other2>
		constexpr pair(Other1&& Val1, Other2&& Val2);
};