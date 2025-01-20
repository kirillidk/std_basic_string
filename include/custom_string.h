#include <cstddef>  //std::size_t
#include <cstring>  //std::memset, std::memcpy

namespace kirillidk_containers {

class string {
   public:
    /* member types */
    typedef std::size_t size_type;

    /* Constructors and destructor */
    string();
    string(size_type __count, char __ch);

    // Copy constructor
    string(const string& __other);

    // Destructor
    ~string();

    /* methods */
    size_type size() const;
    size_type capacity() const;

    /* overloaded operators */
    string& operator=(const string& __other);

    char& operator[](size_type __index);
    const char& operator[](size_type __index) const;

   private:
    /* helper functions */
    void _M_swap_data(string& __other);

    char* _M_arr;
    size_type _M_size;
    size_type _M_capacity;
};

/**
 * @brief Default constructor
 * @note Creates a 15 bit string filled with null characters
 */
string::string() : _M_arr(new char[16]), _M_size(0), _M_capacity(15) {
    std::memset(_M_arr, '\0', _M_capacity);
}

/**
 * @brief Fill constructor
 * @param __count The size of new string
 * @param __ch The character used to fill the string
 */
string::string(size_type __count, char __ch)
    : _M_arr(new char[__count + 1]), _M_size(__count), _M_capacity(__count) {
    std::memset(_M_arr, __ch, _M_size);
    _M_arr[_M_size] = '\0';
}

/**
 * @brief Copy constructor
 * @param __other
 */
string::string(const string& __other)
    : _M_size(__other._M_size), _M_capacity(__other._M_capacity) {
    delete[] _M_arr;
    _M_arr = new char[_M_size + 1];
    std::memcpy(_M_arr, __other._M_arr, _M_size + 1);
}

/**
 * @brief Destructor
 */
string::~string() { delete[] _M_arr; }

string& string::operator=(const string& __other) {
    if (this == &__other) {
        return *this;
    }
    string copy = __other;
    string::_M_swap_data(copy);
    return *this;
}

char& string::operator[](string::size_type __index) {
    return *(string::_M_arr + __index);
}

const char& string::operator[](string::size_type __index) const {
    return *(string::_M_arr + __index);
}

/**
 * @brief Returns size of the string
 */
string::size_type string::size() const { return _M_size; }

/**
 * @brief Returns capacity of the string
 */
string::size_type string::capacity() const { return _M_capacity; }

void string::_M_swap_data(string& __other) {
    std::swap(this->_M_arr, __other._M_arr);
    std::swap(this->_M_size, __other._M_size);
    std::swap(this->_M_capacity, __other._M_capacity);
}

}  // namespace kirillidk_containers
