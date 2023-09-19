def longest_increasing_subsequence_length(nums):
    LIS = [nums[0]]
    def binary_search(target):
        left,right = 0,len(LIS)-1
        while left < right:
            mid = left + ((right-left) >> 1)
            if LIS[mid] >= target:
                right = mid
            else:
                left = mid + 1
        return left


    for i in range(1, len(nums)):
        if nums[i] < LIS[0]: LIS[0] = nums[i]
        elif nums[i] > LIS[-1]: LIS.append(nums[i])
        else:
            k = binary_search(nums[i])
            LIS[k] = nums[i]

    return len(LIS)