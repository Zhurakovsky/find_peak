# find_peak

There are three approaches to solve the task:
1. Trivial linear comparison of the data. In my code realized in the "find_peak_trivial()" func. Complexity O(N).
2. Optimisation can by provided as an immediate break the search loop, when peak is found. This approach realized in the "find_peak_buffer()" function. In the average case complexity is O(N/2). Best case - almost O(1). The worst case O(N)
3. Recursive binary search with average complexity O(log(N)). For the simplicity I have used index-based access to the elements of array instead of prefferable in the such cases .at() function. Further optimisation may expect to omit recursion and using, i.e. one global vector and iterators to left and right borders.