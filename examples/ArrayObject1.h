// --------------
// ArrayObject1.h
// --------------

#ifndef ArrayObject1_h
#define ArrayObject1_h

#include <algorithm> // copy, equal, fill, lexicographical_compare
#include <cassert>   // assert
#include <cstddef>   // ptrdiff_t, size_t
#include <iostream>  // cout, endl
#include <stdexcept> // out_of_range
#include <utility>   // !=, <=, >, >=

using namespace std::rel_ops;

template <typename T, std::size_t N>
class ArrayObject1 {
    friend bool operator == (const ArrayObject1& lhs, const ArrayObject1& rhs) {
        return std::equal(lhs.begin(), lhs.end(), rhs.begin());}

    friend bool operator < (const ArrayObject1& lhs, const ArrayObject1& rhs) {
        return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

    public:
        typedef T                 value_type;

        typedef std::size_t       size_type;
        typedef std::ptrdiff_t    difference_type;

        typedef value_type*       pointer;
        typedef const value_type* const_pointer;

        typedef value_type&       reference;
        typedef const value_type& const_reference;

        typedef pointer           iterator;
        typedef const_pointer     const_iterator;

    private:
        value_type _a[N];

    public:
        explicit ArrayObject1 (const_reference v = value_type()) {
            std::fill(begin(), end(), v);}

        template <typename II>
        ArrayObject1 (II b, II e) {
            std::copy(b, e, begin());}

        // Default copy, destructor, and copy assignment.
        // ArrayObject1 (const ArrayObject1&);
        // ~ArrayObject1 ();
        // ArrayObject1& operator = (const ArrayObject1&);

        reference operator [] (size_type i) {
            return _a[i];}

        const_reference operator [] (size_type i) const {
            return (*const_cast<ArrayObject1*>(this))[i];}

        reference at (size_type i) {
            if (i >= size())
                throw std::out_of_range("Array::at index out of range");
            return (*this)[i];}

        const_reference at (size_type i) const {
            return const_cast<ArrayObject1*>(this)->at(i);}

        iterator begin () {
            return _a;}

        const_iterator begin () const {
            return _a;}

        iterator end () {
            return _a + N;}

        const_iterator end () const {
            return _a + N;}

        size_type size () const {
            return N;}};

#endif // ArrayObject1_h
