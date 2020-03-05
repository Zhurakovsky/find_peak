# find_peak

There are two approaches to solve the task:
1. Trivial linear comparison of the data. In my code realized in the "find_peak_trivial()" func. Complexity O(N).
2. Optimisation can by provided as an immediate break the search loop, when peak is found. This approach realized in the "find_peak_buffer()" function. In the average case complexity is O(N/2). Best case - almost O(1). The worst case O(N)