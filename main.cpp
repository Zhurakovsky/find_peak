#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

void print(const std::vector<uint32_t>& v)
{
    for (const auto& i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

void find_peak_trivial(const std::vector<uint32_t>& v)
{
    if (v.size() < 3)
    {
        cout << "Array is too small" << endl;
        return;
    }

    auto found = std::max_element(std::begin(v), std::end(v));
    if (found != v.end())
    {
        if (found == v.begin())
        {
            cout << "Wrong array. Max value is on the first place" << endl;
            return;
        }

        if (found == (v.end() - 1))
        {
            cout << "Wrong array. Max value is on the last place" << endl;
            return;
        }

        if (*found > ((*(found - 1) / 2) + (*(found + 1) / 2)))
        {
            cout << "Peak found: " << *found << endl;
            return;
        }
    }
    cout << "Peak not found" << endl;
}

void find_peak_buffer(const std::vector<uint32_t>& v)
{
    if (v.size() < 3)
    {
        cout << "Array is too small" << endl;
        return;
    }
    std::array<uint32_t, 2> buffer{v[0], v[1]};
    
    if (buffer[0] > buffer[1])
    {
        cout << "Wrong array. Array starts with decreasing range." << endl;
        return;
    }

    int res = -1;
    
    for (auto it = v.begin()+2; it != v.end(); ++it)
    {
        if (*it >= buffer[1])
        {
            buffer[0] = buffer[1];
            buffer[1] = *it;
        }
        else
        {
            if (buffer[0] == buffer[1])
            {
                cout << "Wrong array. Flat shelf instead of pick." << endl;
            }
            else
            {
                res = static_cast<int>(buffer[1]);
            }
            break;
        }
    }

    if (res != -1)
    {
        cout << "Peak found: " << res << endl;
    }
    else
    {
        cout << "Peak not found" << endl;
    }
}

void find_peak_bsearch(const std::vector<uint32_t>& v)
{
    if (v.size() < 3)
    {
        cout << "Array is too small" << endl;
        return;
    }

    if (v.size() == 3)
    {
        if(v[0] < v[1] && v[1] > v[2])
        {
            cout << "Peak found: " << v[1] << endl;    
        }
        else
        {
            cout << "Peak not found" << endl;
        }
        
        return;
    }

    int left_border = 0;
    int right_border = v.size() - 1;
    
    int test_index = right_border - (right_border - left_border) / 2;
    if(v[test_index] > v[test_index - 1] && v[test_index] > v[test_index + 1])
    {
        cout << "Peak found: " << v[test_index] << endl;
    }
    else
    {
        if(v[test_index] <= v[test_index + 1])
        {
            std::vector<uint32_t>sub_vector(v.begin() + test_index, v.end());
            find_peak_bsearch(sub_vector);
        }
        else if(v[test_index - 1] > v[test_index])
        {
            std::vector<uint32_t>sub_vector(v.begin(), v.begin() + test_index + 1);
            find_peak_bsearch(sub_vector);
        }
        cout << "Peak not found" << endl;
    }
}


int main()
{
     vector<uint32_t> v{1, 1, 2, 3, 5, 8, 13, 21, 20, 19, 18, 17, 16, 15};
    // vector<uint32_t> v{1, 2, 3, 4, 5, 6, 7, 8, 9, 8, 7, 4, 1};
    // vector<uint32_t> v{0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    // vector<uint32_t> v{9, 8, 7, 6, 5, 4, 3, 2, 1, 0};
    // vector<uint32_t> v{0, 0, 0};
    // vector<uint32_t> v{0, 1, 0};
    // vector<uint32_t> v{0, 1, 1};
    // vector<uint32_t> v{1, 1, 0};
    print(v);
    
    //find_peak_trivial(v); // Solution 1.

    //find_peak_buffer(v);  // Solution 2.

    find_peak_bsearch(v);   // Solution 3.
    return 0;
}