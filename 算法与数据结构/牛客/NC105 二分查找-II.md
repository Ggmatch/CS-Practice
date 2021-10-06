# [点击查看题目](https://www.nowcoder.com/practice/4f470d1d3b734f8aaf2afb014185b395?tpId=188)

## C题解
```c
/**
 * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
 *
 * 如果目标值存在返回下标，否则返回 -1
 * @param nums int整型一维数组 
 * @param numsLen int nums数组长度
 * @param target int整型 
 * @return int整型
 */
int search(int* nums, int numsLen, int target ) {
    // write code here
    int left=0, right=numsLen-1, res=-1;
    while(left<=right){
        int mid=left+(right-left)/2;
        if(nums[mid]==target){
            res=mid;
            right=mid-1;
        } else if (nums[mid]>target){
            right=mid-1;
        } else {
            left=mid+1;
        }
    }
    
    return res;
}
```

## JAVA题解
```java
import java.util.*;


public class Solution {
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 如果目标值存在返回下标，否则返回 -1
     * @param nums int整型一维数组 
     * @param target int整型 
     * @return int整型
     */
    public int search (int[] nums, int target) {
        // write code here
        int left=0, right=nums.length-1, res=-1;
        while(left<=right){
            int mid = left + (right-left)/2;
            if(nums[mid]==target){
                res=mid;
                right = mid-1;
            } else if (nums[mid]>target){
                right = mid-1;
            } else {
                left = mid+1;
            }
        }
        return res;
    }
}
```