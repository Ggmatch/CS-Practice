# [点击查看题目](https://www.nowcoder.com/practice/650474f313294468a4ded3ce0f7898b9?tpId=188)

## C题解
```c
/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 * };
 */

/**
 * 
 * @param head ListNode类 
 * @return bool布尔型
 */
bool hasCycle(struct ListNode* head ) {
    // write code here
    struct ListNode *slow, *fast;
    slow = fast = head;
    while((fast!=NULL) && (fast->next!=NULL)){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return true;
        }
    }
    return false;
}
```

## JAVA题解
```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow, fast;
        slow = fast = head;
        while((fast!=null) && (fast.next!=null)){
            slow = slow.next;
            fast = fast.next.next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
}
```