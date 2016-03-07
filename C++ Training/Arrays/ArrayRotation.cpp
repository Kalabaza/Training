#include <iostream>
#include <array>

using namespace std;

const int ArraySize = 10;

int FindRotationCount(array<int, ArraySize> &A)
{
    int low = 0, high = static_cast<int>(A.size()) - 1, mid, next, prev;
    while (low <= high)
    {
        // Case 1: A[low] <= A[high]
        //             return low
        // mid <- (low + high) / 2
        // next <- (mid + 1) % N
        // prev <- (mid + N - 1) % N
        // Case 2: A[mid] <= A[next] && A[mid] <= A[prev]
        //             return mid
        // Case 3: A[mid] <= A[high]
        //             high <- mid - 1
        // Case 4: A[mid] >= A[low]
        //         low <- mid + 1

        // Case 1:
        if (A[low] <= A[high])
            return low;
        mid = (low + high) / 2;
        next = (mid + 1) % A.size();
        prev = static_cast<int>((mid + A.size() - 1) % A.size());
        // Case 2:
        if (A[mid] <= A[next] && A[mid] <= A[prev])
            return mid;
        // Case 3:
        else if (A[mid] <= A[high])
            high = mid - 1;
        // Case 4:
        else if (A[mid] >= A[low])
            low = mid + 1;
    }
    return -1;
}

int main()
{
    array<int, ArraySize> A{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    array<int, ArraySize> B{ 15, 22, 23, 28, 31, 38, 5, 6, 8, 10 };
    cout << "The array is rotated " << FindRotationCount(A) << " times" << endl;
    cout << "The array is rotated " << FindRotationCount(B) << " times" << endl;
    return 0;
}
