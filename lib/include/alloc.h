#pragma once

#include <cstdlib>
#include <new>

namespace alloc {

template<typename T, int N = 10>
class CustomAllocator
{
  public:
    using value_type = T;

    CustomAllocator() = default;
    ~CustomAllocator();

    template<typename U>
    CustomAllocator(const CustomAllocator<U> &){};

    T *allocate(std::size_t n);
    void deallocate(T *p, std::size_t n);

    template<class U>
    struct rebind
    {
        using other = CustomAllocator<U, N>;
    };

  private:
    T *start;
    T *p;
    int size = 0;
    int cap = N;
};

template<typename T, int N>
T *CustomAllocator<T, N>::allocate(std::size_t n)
{
    if (n > cap) {
        throw std::bad_array_new_length();
    }
    if (size >= cap) {
        throw std::bad_alloc();
    }

    ++size;
    if (!p) {
        p = static_cast<T *>(std::malloc(cap * sizeof(T)));
        start = p;
        return p;
    } else {
        ++p;
        return p;
    }

    throw std::bad_alloc();
}

template<typename T, int N>
void CustomAllocator<T, N>::deallocate(T *p, std::size_t n)
{
}

template<typename T, int N>
CustomAllocator<T, N>::~CustomAllocator()
{
    std::free(start);
}

}  // namespace alloc