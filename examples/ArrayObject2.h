// --------------
// ArrayObject2.h
// --------------

#ifndef ArrayObject2_h
#define ArrayObject2_h

#include <algorithm> // copy, equal, fill, lexicographical_compare
#include <cassert>   // assert
#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <memory>    // allocator
#include <stdexcept> // out_of_range
#include <utility>   // !=, <=, >, >=

#include "Memory.h" // my_destroy, my_uninitialized_copy, my_uninitialized_fill

using namespace std::rel_ops;

template <typename T, std::size_t N, typename A = std::allocator<T> >
class ArrayObject2 {
    public:
        typedef A                                        allocator_type;
        typedef typename allocator_type::value_type      value_type;

        typedef typename allocator_type::size_type       size_type;
        typedef typename allocator_type::difference_type difference_type;

        typedef typename allocator_type::pointer         pointer;
        typedef typename allocator_type::const_pointer   const_pointer;

        typedef typename allocator_type::reference       reference;
        typedef typename allocator_type::const_reference const_reference;

        typedef typename allocator_type::pointer         iterator;
        typedef typename allocator_type::const_pointer   const_iterator;

    private:
        char           _x[N * sizeof(value_type)];
        allocator_type _z;

    public:
        explicit ArrayObject2 (const_reference v = value_type(), const allocator_type& z = allocator_type()) :
                _z (z) {
            my_uninitialized_fill(_z, begin(), end(), v);}

        template <typename II>
        ArrayObject2 (II b, II e, const allocator_type& z = allocator_type()) :
                _z (z) {
            my_uninitialized_copy(_z, b, e, begin());}

        // Default copy and copy assignment.
        // ArrayObject2 (const ArrayObject2&);
        // ArrayObject2& operator = (const ArrayObject2&);

        ~ArrayObject2 () {
            my_destroy(_z, begin(), end());}

        reference operator [] (size_type i) {
            pointer _a = reinterpret_cast<pointer>(_x);
            return _a[i];}

        const_reference operator [] (size_type i) const {
            return (*const_cast<ArrayObject2*>(this))[i];}

        reference at (size_type i) {
            if (i >= size())
                throw std::out_of_range("Array::at index out of range");
            return (*this)[i];}

        const_reference at (size_type i) const {
            return const_cast<ArrayObject2*>(this)->at(i);}

        iterator begin () {
            pointer _a = reinterpret_cast<pointer>(_x);
            return _a;}

        const_iterator begin () const {
            return const_cast<ArrayObject2*>(this)->begin();}

        iterator end () {
            pointer _a = reinterpret_cast<pointer>(_x);
            return _a + N;}

        const_iterator end () const {
            return const_cast<ArrayObject2*>(this)->end();}

        size_type size () const {
            return N;}};

template <typename T, std::size_t N>
bool operator == (const ArrayObject2<T, N>& lhs, const ArrayObject2<T, N>& rhs) {
    return std::equal(lhs.begin(), lhs.end(), rhs.begin());}

template <typename T, std::size_t N>
bool operator < (const ArrayObject2<T, N>& lhs, const ArrayObject2<T, N>& rhs) {
    return std::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());}

#endif // ArrayObject2_h
