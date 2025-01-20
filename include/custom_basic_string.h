#include <uchar.h>  //char16_t, char32_t

#include <cstddef>  //std::size_t
#include <cstring>  //std::memset, std::memcpy

namespace kirillidk_containers {

template <typename CharT>
class basic_string {
   public:
    /* member types */
    typedef CharT value_type;
    typedef std::size_t size_type;

    /* Constructors and destructor */
    basic_string();
    basic_string(size_type __count, CharT __ch);

    // Copy constructor
    basic_string(const basic_string& __other);

    // Destructor
    ~basic_string();

    /* methods */
    size_type size() const;
    size_type capacity() const;

    /* overloaded operators */
    basic_string& operator=(const basic_string& __other);

    CharT& operator[](size_type __index);
    const CharT& operator[](size_type __index) const;

   private:
    /* helper functions */
    void _M_swap_data(basic_string& __other);

    CharT* _M_arr;
    size_type _M_size;
    size_type _M_capacity;
};

/* defined types */
typedef basic_string<char> string;
typedef basic_string<wchar_t> wstring;
typedef basic_string<char16_t> u16string;
typedef basic_string<char32_t> u32string;

/**
 * @brief Default constructor
 * @note Initializes a 15-element `basic_string` with null characters
 */
template <typename CharT>
basic_string<CharT>::basic_string()
    : _M_arr(new CharT[16]), _M_size(0), _M_capacity(15) {
    std::memset(_M_arr, '\0', _M_capacity);
}

/**
 * @brief Fill constructor
 * @param __count The size of a new `basic_string`
 * @param __ch The character used to fill the `basic_string`
 */
template <typename CharT>
basic_string<CharT>::basic_string(size_type __count, CharT __ch)
    : _M_arr(new CharT[__count + 1]), _M_size(__count), _M_capacity(__count) {
    std::memset(_M_arr, __ch, _M_size);
    _M_arr[_M_size] = '\0';
}

/**
 * @brief Copy constructor
 * @param __other A reference to another `basic_string` object to copy from
 */
template <typename CharT>
basic_string<CharT>::basic_string(const basic_string& __other)
    : _M_size(__other._M_size), _M_capacity(__other._M_capacity) {
    delete[] _M_arr;
    _M_arr = new CharT[_M_size + 1];
    std::memcpy(_M_arr, __other._M_arr, _M_size + 1);
}

/**
 * @brief Destructor
 */
template <typename CharT>
basic_string<CharT>::~basic_string() {
    delete[] _M_arr;
}

/**
 * @brief Assignment operator
 * @param __other A reference to another `basic_string` object to assign from
 * @return A reference to this `basic_string` object after assignment
 */
template <typename CharT>
basic_string<CharT>& basic_string<CharT>::operator=(
    const basic_string& __other) {
    if (this == &__other) {
        return *this;
    }
    basic_string<CharT> copy = __other;
    basic_string<CharT>::_M_swap_data(copy);
    return *this;
}

/**
 * @brief Accesses the character at the specified index (non-const version)
 * @param __index The zero-based index of the character to access
 * @return A reference to the character at the specified index, allowing
 * modification
 * @note No bounds checking is performed. Ensure the index is within valid
 * range
 */
template <typename CharT>
CharT& basic_string<CharT>::operator[](basic_string<CharT>::size_type __index) {
    return *(basic_string<CharT>::_M_arr + __index);
}

/**
 * @brief Accesses the character at the specified index (const version)
 * @param __index The zero-based index of the character to access
 * @return A const reference to the character at the specified index, preventing
 * modification
 * @note No bounds checking is performed. Ensure the index is within valid
 * range
 */
template <typename CharT>
const CharT& basic_string<CharT>::operator[](
    basic_string<CharT>::size_type __index) const {
    return *(basic_string<CharT>::_M_arr + __index);
}

/**
 * @brief Returns the number of characters currently
 * stored in the `basic_string`
 */
template <typename CharT>
typename basic_string<CharT>::size_type basic_string<CharT>::size() const {
    return _M_size;
}

/**
 * @brief Returns the total allocated capacity of the `basic_string`
 */
template <typename CharT>
typename basic_string<CharT>::size_type basic_string<CharT>::capacity() const {
    return _M_capacity;
}

/**
 * @brief Swaps the data of two `basic_string` objects
 * @param __other A reference to another `basic_string` object whose data will
 * be swapped with this one
 */
template <typename CharT>
void basic_string<CharT>::_M_swap_data(basic_string<CharT>& __other) {
    std::swap(this->_M_arr, __other._M_arr);
    std::swap(this->_M_size, __other._M_size);
    std::swap(this->_M_capacity, __other._M_capacity);
}

}  // namespace kirillidk_containers