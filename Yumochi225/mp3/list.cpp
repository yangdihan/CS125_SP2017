/**
 * @file list.cpp
 * Doubly Linked List (MP 3).
 *
 * @author Chase Geigle
 * @date (created) Fall 2011
 * @date (modified) Spring 2012, Fall 2012
 *
 * @author Jack Toole
 * @date (modified) Fall 2011
 */

/**
 * Destroys the current List. This function should ensure that
 * memory does not leak on destruction of a list.
 */
template <class T>
List<T>::~List()
{
    /// @todo Graded in MP3.1
    clear();
}

/**
 * Destroys all dynamically allocated memory associated with the current
 * List class.
 */
template <class T>
void List<T>::clear()
{
    /// @todo Graded in MP3.1
    // consider several cases
    // case 1, length = 0
    if (length == 0)
    {
        return;
    }
    // case 2, length = 1
    if (length == 1)
    {
        delete head;
        head = NULL;
        tail = NULL;
        return;
    }
    // case 3, multiple nodes
    // create a node pointer on the stack that will go away on its own
    ListNode* terminator = head;
    // the original idea is to use a while loop to remove the list
    while(terminator->next != NULL)
    {
        head=head->next;
        delete terminator;
        terminator = head;
    }

    delete terminator;
    head = NULL;
    tail = NULL;
    return;


}

/**
 * Inserts a new node at the front of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertFront(T const& ndata)
{
    /// @todo Graded in MP3.1
    if (length == 0)
    {
    // create a new node
    ListNode* newhead = new ListNode(ndata);
    //newhead's prev should already be null so no need to change that
    // change its next to the previous head of the list, this should be fine even if the head is pointing to null;
    newhead->next = NULL;
    // change head to newhead
    head = newhead;

    // if length is 0, then change tail to point to head as well
    tail = newhead;
    
    // increment length
    length++;
    return;
    }

    ListNode* newhead = new ListNode(ndata);
    newhead->next = head;
    head->prev = newhead;
    head = newhead;
    //here i dont have to worry about tail
    // tail already has a valid assignment
    // increment length
    length++;
    return;

}

/**
 * Inserts a new node at the back of the List.
 * This function **SHOULD** create a new ListNode.
 *
 * @param ndata The data to be inserted.
 */
template <class T>
void List<T>::insertBack(const T& ndata)
{
    /// @todo Graded in MP3.1
      if (length == 0)
    {
    // create a new node
    ListNode* newtail = new ListNode(ndata);
    //should not have to change the value of newtail's prev and next, since they are initilized to null in the constructor
    // head and tail should both point to newtail
    head = newtail;
    tail = newtail;
    length++;
    return;
    }

    // if length is not 0
    // still create a new node
    ListNode* newtail = new ListNode(ndata);
    // assign new tail's prev to the original tail
    newtail->prev = tail;
    // connecting the original last node to the new tail
    tail->next = newtail;
    //set the newtail as the tail
    tail = newtail;
    // increment length
    length++;
    return;
}

/**
 * Reverses the current List.
 */
template <class T>
void List<T>::reverse()
{
    reverse(head, tail);
}

/**
 * Helper function to reverse a sequence of linked memory inside a List,
 * starting at startPoint and ending at endPoint. You are responsible for
 * updating startPoint and endPoint to point to the new starting and ending
 * points of the rearranged sequence of linked memory in question.
 *
 * @param startPoint A pointer reference to the first node in the sequence
 *  to be reversed.
 * @param endPoint A pointer reference to the last node in the sequence to
 *  be reversed.
 */
template <class T>
void List<T>::reverse(ListNode *&startPoint, ListNode *&endPoint)
{
 
    /// @todo Graded in MP3.1
    // check if reverse is unnecessary
    if ((startPoint == endPoint) || (length <= 1))
        return;
    // if start and end are null;
    if ((startPoint == NULL) || (endPoint == NULL))
    {
        return;
    }
    // create that node pointers that I need to navigate this list. Sort of dont know if I can decrease the amount of ptrs that I need
    ListNode* startPrev;
    ListNode* endNext;
    ListNode* switcher;
    ListNode* switcherPrev;
    // save the value of startPoint->pre and endPoint->next
    startPrev = (startPoint->prev); // this point startPrev should either contain the link to the node ahead of startPoint or NULL
    endNext = (endPoint->next); // this point endNext should either contain the link to the node after endPoint or NULL
    // see if the startPre and endNext are null or actual nodes

    
    //set up switcher and switcher pre
    switcher = startPoint;
    //change of switcherPre
    //switcherPrev = startPrev;
    switcherPrev = endNext;

    while (switcher != endPoint)
    {
    switcher->prev = switcher->next;
    switcher->next = switcherPrev;

    // increment switcherPre and switcher
    switcherPrev = switcher;
    switcher = switcher->prev;
    }

    //cout<<endPoint->prev<<endl;
    endPoint->next = endPoint->prev;
    endPoint->prev = startPrev;
    //cout<<endPoint->prev<<endl;
    //endPoint->next = switcherPrev;
    //cout<<endPoint->next<<endl;
    startPoint->next = endNext;

    if (startPrev != NULL)
    {
        startPrev->next = endPoint;  
    }

    if (endNext != NULL)
    {
        endNext->prev = startPoint;
    }
    

    if (endNext == NULL && startPrev == NULL)
    {
        ListNode* temp = endPoint;
        tail = startPoint;
        head = temp;


    }
    else if (endNext == NULL)
    {
    
        tail = startPoint;
    }
    else if (startPrev == NULL)
    {
   
        head = endPoint;
    }   

    
    return;



}

/**
 * Reverses blocks of size n in the current List. You should use your
 * reverse( ListNode * &, ListNode * & ) helper function in this method!
 *
 * @param n The size of the blocks in the List to be reversed.
 */
template <class T>
void List<T>::reverseNth(int n)
{
    /// @todo Graded in MP3.1
    if ((n <= 1) || (length <= 1))
    {
        return;
    }

    // create counter for number of nodes to send to helper function
    int count = 1;
    // create two node ptrs as reference
    ListNode* startPoint = head;
    ListNode* endPoint = head;
    //ListNode* placeSaver


    while (endPoint != NULL)
    {
        while ((count != n) && endPoint->next != NULL )
        {
            endPoint = endPoint->next;
            count++;
        }
        // call to reverse the list
        reverse(startPoint, endPoint);
        // reset count 
        count = 1;
        // reset start and end
        startPoint = startPoint->next;
        endPoint = startPoint;
    }  
    return;  

}

/**
 * Modifies the List using the waterfall algorithm.
 * Every other node (starting from the second one) is removed from the
 * List, but appended at the back, becoming the new tail. This continues
 * until the next thing to be removed is either the tail (**not necessarily
 * the original tail!**) or NULL.  You may **NOT** allocate new ListNodes.
 * Note that since the tail should be continuously updated, some nodes will
 * be moved more than once.
 */
template <class T>
void List<T>::waterfall()
{
    if (length <= 1)
    {
        return;
    }
    /// @todo Graded in MP3.1
    // create nodes ptrs to track 
    ListNode* switcher = head;
    ListNode* placeSaver = head->next;
    int count = 1;

    while(placeSaver != NULL)
    {
        // set up stepper to step through list
        // as well as increment placeSaver for the next node in the list
        // tracking the number of node visited
        switcher=placeSaver;
        placeSaver=switcher->next;
        count++;
        if (count%2 ==0 && placeSaver != NULL)
        {
            // if the count is even and the node is not the last node in the list
            // isolate the list to put to the end of the list
            (switcher->next)->prev = switcher->prev;
            (switcher->prev)->next = switcher->next;
            // connect tail to switcher
            // then connect switcher to tail
            tail->next = switcher;
            switcher->prev = tail;
            // make switcher the new tail
            tail = switcher;
            tail->next = NULL;
        }
    }

}

/**
 * Splits the given list into two parts by dividing it at the splitPoint.
 *
 * @param splitPoint Point at which the list should be split into two.
 * @return The second list created from the split.
 */
template <class T>
List<T> List<T>::split(int splitPoint)
{
    if (splitPoint > length)
        return List<T>();

    if (splitPoint < 0)
        splitPoint = 0;

    ListNode* secondHead = split(head, splitPoint);

    int oldLength = length;
    if (secondHead == head) {
        // current list is going to be empty
        head = NULL;
        tail = NULL;
        length = 0;
    } else {
        // set up current list
        tail = head;
        while (tail->next != NULL)
            tail = tail->next;
        length = splitPoint;
    }

    // set up the returned list
    List<T> ret;
    ret.head = secondHead;
    ret.tail = secondHead;
    if (ret.tail != NULL) {
        while (ret.tail->next != NULL)
            ret.tail = ret.tail->next;
    }
    ret.length = oldLength - splitPoint;
    return ret;
}

/**
 * Helper function to split a sequence of linked memory at the node
 * splitPoint steps **after** start. In other words, it should disconnect
 * the sequence of linked memory after the given number of nodes, and
 * return a pointer to the starting node of the new sequence of linked
 * memory.
 *
 * This function **SHOULD NOT** create **ANY** new List objects!
 *
 * @param start The node to start from.
 * @param splitPoint The number of steps to walk before splitting.
 * @return The starting node of the sequence that was split off.
 */
template <class T>
typename List<T>::ListNode* List<T>::split(ListNode* start, int splitPoint)
{
    /// @todo Graded in MP3.2
     // change me!
    // any splitPoint being passed in can be assumed to be valid
    // ie splitPoint < length
    ListNode* secondHead = start;
    int count = 1;
    //use a loop to travel down the list
    while (count <= splitPoint)
    {
        secondHead = secondHead->next;
        count++;
    }

    secondHead->prev->next = NULL;
    secondHead->prev = NULL;
    return secondHead;

}

/**
 * Merges the given sorted list into the current sorted list.
 *
 * @param otherList List to be merged into the current list.
 */
template <class T>
void List<T>::mergeWith(List<T>& otherList)
{
    // set up the current list
    head = merge(head, otherList.head);
    tail = head;

    // make sure there is a node in the new list
    if (tail != NULL) {
        while (tail->next != NULL)
            tail = tail->next;
    }
    length = length + otherList.length;

    // empty out the parameter list
    otherList.head = NULL;
    otherList.tail = NULL;
    otherList.length = 0;
}

/**
 * Helper function to merge two **sorted** and **independent** sequences of
 * linked memory. The result should be a single sequence that is itself
 * sorted.
 *
 * This function **SHOULD NOT** create **ANY** new List objects.
 *
 * @param first The starting node of the first sequence.
 * @param second The starting node of the second sequence.
 * @return The starting node of the resulting, sorted sequence.
 */
template <class T>
typename List<T>::ListNode* List<T>::merge(ListNode* first, ListNode* second)
{
    /// @todo Graded in MP3.2
     // change me!
    // creates two listnodes
    ListNode* newhead;
    ListNode* attacher;
    // if one of the node passed in is NULL, then return the other
    if (second == NULL)
    {
        return first;
    }

    if (first == NULL)
    {
        return first;
    }

    //decide where first node to make the newhead of the list to return
    if (second->data < first->data)
        {
            newhead = second;
            second = second->next;
        }
    else
        {
            newhead = first;
            first = first->next;    
        }

    attacher = newhead;
    //establish condition to loop
    while(first != NULL && second != NULL)
    {
        if (second->data < first->data)
        {
            second->prev = attacher;
            attacher->next = second;
            attacher = attacher->next;
            second=second->next;
        }
        // if first is = or < than second
        else
        {
            first->prev = attacher;
            attacher->next = first;
            attacher = attacher->next;
            first = first->next;
        }
    }
    if (second == NULL && first == NULL)
    {
        return newhead;
    }

    if (second == NULL)
    {
        // so first need to be attached
        attacher->next = first;
        first->prev = attacher;
    }

    if (first == NULL)
    {
        attacher->next = second;
        second->prev = attacher;
    }
    return newhead;
}

/**
 * Sorts the current list by applying the Mergesort algorithm.
 */
template <class T>
void List<T>::sort()
{
    if (empty())
        return;
    head = mergesort(head, length);
    tail = head;
    while (tail->next != NULL)
        tail = tail->next;
}

/**
 * Sorts a chain of linked memory given a start node and a size.
 * This is the recursive helper for the Mergesort algorithm (i.e., this is
 * the divide-and-conquer step).
 *
 * @param start Starting point of the chain.
 * @param chainLength Size of the chain to be sorted.
 * @return A pointer to the beginning of the now sorted chain.
 */
template <class T>
typename List<T>::ListNode* List<T>::mergesort(ListNode* start, int chainLength)
{
    /// @todo Graded in MP3.2
    // change me!
    int splitPoint = chainLength/2;
    //int mergePoint = chainLength/4;
    
    // base case
    if (start->next == NULL && start->prev == NULL)
    {
        return start;
    }

    //ListNode* firstHalf = start;
    ListNode* newhead = split(start, splitPoint);
    int mergePoint = chainLength - splitPoint;
    ListNode* firstHalf = mergesort(start, splitPoint);
    ListNode* secondHalf = mergesort(newhead, mergePoint);
    
    ListNode* combined = merge(firstHalf, secondHalf);
    //recursivly call split to break list into base cases
    return combined;

    
}
