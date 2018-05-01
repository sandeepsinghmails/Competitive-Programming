// Reference: https://www.geeksforgeeks.org/rotate-a-linked-list/

#if 0
This function rotates a Linked List counter-clockwise and
returns the new head.

Assumption: k < Size of the Linked List.
You will not modify the list if k >= Size of the Linked List

Sample Input:
    - k=4
    - List = 10->20->30->40->50->60

Counter-Clockwise Rotation:
Remove k nodes from the front of the list & move them to the end

Sample Output:
    - List = 50 60 10 20 30 40
#endif
ListNode* rotate(ListNode *head, int k)
{
	if (k == 0)
        return head;                // return UnModified List

        // Temporary ListNode* -- for Traversing the List
	ListNode* current = head;

	/* current will either point to kth or NULL after this loop.
	 * current will point to node 40 in Sample List
	 * Note: count cannot be 0, since you're already pointing to First Node, k-1 more to traverse
	 */
	int count = 1;
	while (count < k && current != NULL)
	{
		current = current->next;
		count++;
	}

	// If current is NULL, k >= Size of the Linked List
	// Don't change the list in this case
	if (current == NULL)
		return head;                // return UnModified List

    #if 0
    current points to kth node. Store it in a variable.
    For Sample List:
    10->20->30->40
                |
                kthNode
    #endif
    ListNode* kthNode = current;

    #if 0
    Reach the Last List Node:
    Once this Loop Completes:
    10->20->30->40->50->60
	                |
	                current
    #endif
    while (current->next != NULL)
    	current = current->next;

    #if 0
    Change next of last node to Previous head:
    10->20->30->40->50->60 ----> head
    |                   |
    head                current
    #endif
    current->next = head;

    #if 0
    Change head to (k+1)th node
    head is now changed to node 50

                kthNode
                |
    10->20->30->40->50->60
	                |
	                head
    #endif
    head = kthNode->next;

    #if 0
    Change next of kth node to NULL
    next of 40 is now NULL
    10->20->30->40---->NULL     50->60
                |               |
                kthNode         head
    #endif
    kthNode->next = NULL;

    return head;
}
