#pragma once

namespace wc
{
    template<typename T>
    constexpr void swap(T& a, T& b)
    {
        T t = a;
        a = b;
        b = t;
    }

    template<typename T>
    constexpr void swap(T* a, T* b)
    {
        T* t = a;
        a = b;
        b = t;
    }

    template<class iter, class Compare>
    void insert_sort(iter first, size_t len, Compare comp)
    {
        int i, pos, remember;
        for (i = 1; i < len; i++)
        {
            remember = first[(pos = i)];
            while (--pos >= 0 && comp(remember, first[pos])) first[pos + 1] = first[pos];
            first[pos + 1] = remember;
        }
    }

    template<class iter, class Compare>
    constexpr void quickSort(iter first, size_t len, Compare comp)
    {
        if (len <= 1) return;
        if (len <= 50) { wc::insert_sort(first, len, comp); return; }
        size_t i = 0;
        size_t j = len;
        while (true)
        {
            while (comp(*(first + ++i), *(first))) if (i >= len-1) break;
            while (comp((*first), *(first + --j)));
            if (i >= j) break;
            wc::swap(*(first + i), *(first + j));
        }

        wc::swap(*(first), *(first + j));
        wc::quickSort(first, j, comp);
        wc::quickSort((first + j + 1), len - j - 1, comp);
    }

    template<class iter, class Compare>
    constexpr void quickSort(iter first, iter last, Compare comp)
    {
        wc::quickSort(first, last - first, comp);
    }


    template<class iter, class Compare>
    constexpr void sort(iter first, iter last, Compare comp)
    {
        wc::quickSort(first, last, comp);
    }

    template<class iter>
    constexpr void sort(iter first, iter last)
    {
        auto DefaultComparator = [](auto lhs, auto rhs)
        {
            return lhs < rhs;
        };
        wc::sort(first, last, DefaultComparator);
    }
}