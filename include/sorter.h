/**
 * @file sorter.h
 * Declaration of partial sorting functions in the segment-by-segment style
 *
 */

#ifndef ASPAS_SORTER_H_
#define ASPAS_SORTER_H_

#include <cstdint>
#include <type_traits>

namespace aspas
{

namespace internal 
{

/**
 * Integer version:
 * This method sorts the data segment by segment.
 * Segment size is SIMD width. 
 *
 * @param data targeting data
 * @param size data size
 * @return partially sorted data
 *
 */
template <typename T>
typename std::enable_if<std::is_same<T, int>::value>::type
sorter(T*& data, uint32_t size);

/**
 * Integer version (key, ptr):
 * This method sorts the keys segment by segment.
 * Segment size is SIMD width. 
 *
 * @param data targeting key data
 * @param ptr targeting pointer data
 * @param size data size
 * @return partially sorted key data with associative pointers
 *
 */
template <typename T>
typename std::enable_if<std::is_same<T, int>::value>::type
sorter_key(T*& data, int *&ptr, uint32_t size);

template <typename T>
typename std::enable_if<std::is_same<T, float>::value>::type
sorter_key(T*& data, int *&ptr, uint32_t size);

template <typename T>
typename std::enable_if<std::is_same<T, double>::value>::type
sorter_key(T*& data, int *&ptr, uint32_t size);

template <typename T>
typename std::enable_if<std::is_same<T, int>::value>::type
sorter_key(T*& data, long *&ptr, uint32_t size);

template <typename T>
typename std::enable_if<std::is_same<T, float>::value>::type
sorter_key(T*& data, long *&ptr, uint32_t size);

template <typename T>
typename std::enable_if<std::is_same<T, double>::value>::type
sorter_key(T*& data, long *&ptr, uint32_t size);



/**
 * Float version:
 * This method sorts the data segment by segment.
 * Segment size is SIMD width. 
 *
 * @param data targeting data
 * @param size data size
 * @return partially sorted data
 *
 */
template <typename T>
typename std::enable_if<std::is_same<T, float>::value>::type
sorter(T*& data, uint32_t size);

/**
 * Double version:
 * This method sorts the data segment by segment.
 * Segment size is SIMD width. 
 *
 * @param data targeting data
 * @param size data size
 * @return partially sorted data
 *
 */
template <typename T>
typename std::enable_if<std::is_same<T, double>::value>::type
sorter(T*& data, uint32_t size);


} // end namespace internal

} // end namespace aspas

#ifdef __AVX2__
#include "sorter_avx2.tcc"
#else
#ifdef __AVX__
#include "sorter_avx.tcc"
#endif
#endif

#ifdef __MIC__
#include "sorter_mic.tcc" 
#endif


#endif
