//	Node Declaration
template <class  TYPE> 
struct NODE 	  {
	   TYPE    data;
	   NODE   *link;
}; //  End of Node Declaration

//	List Class Declaration
template <class  TYPE, class KTYPE> 
class List  {
private:
	NODE<TYPE> *head;
	NODE<TYPE> *pos;
	NODE<TYPE> *rear;
	int         count;

// Function Declarations
    bool  _insert  (NODE<TYPE> *pPre,   TYPE dataIn);
	void  _delete  (NODE<TYPE> *pPre, NODE<TYPE> *pLoc, TYPE *dataOutPtr);
	bool  _search  (NODE<TYPE>  **pPre, NODE<TYPE>  **pLoc, KTYPE  key);
public:
	List();
	~List();
	int addNode(TYPE   dataIn);
	bool  removeNode(KTYPE  key, TYPE  *dataOutPtr);
	bool  retrieveNode (KTYPE  Argu, TYPE&  dataOut);
	bool  getNext(int fromWhere,  TYPE&  dataOut);
	int   listCount();
	bool  emptyList();
	bool  fullList(); 
}; // class List 

// 	End of List Class Declaration

/* 	=============== List Constructor  ==============	
	Initialize the list.
	  Pre    Class is being instantiated
	  Post   Class instantiated and initialized
*/
template <class TYPE, class KTYPE>
List<TYPE, KTYPE> :: List()  {
	head     = NULL;
	pos      = NULL;
	rear     = NULL;
	count    = 0;
} //  List Constructor 

/*	=============== Destructor ============== 
	Deletes all data in list and recycles memory
	   Pre    List is being deleted 
	   Post   Data and class structure have been deleted
*/
template<class TYPE, class KTYPE> 
List<TYPE, KTYPE > :: ~List (void) 
{
//	Local Definitions 
	NODE<TYPE>   *deletePtr;

//	Statements 
	if (head)
	   {
	    while (count > 0) 
	       {
	        deletePtr = head;
	        head      = head->link; 
	        count--;
	        delete  deletePtr; 
	       } // while
	   } //  if 
}	// Destructor 

/*	==================== addNode =================== 
	Inserts data into linked list.
	   Pre     dataIn contains data to be inserted
	   Post    Data inserted or error
	   Return -1 if overflow, 
	           0 if successful,
	           1 if duplicate key
*/
template <class TYPE, class KTYPE> 
int List<TYPE, KTYPE> :: addNode (TYPE dataIn) {
//	Local Definitions 
	bool  found;
	bool  success;

	NODE<TYPE>  *pPre;
	NODE<TYPE>  *pLoc;
	
//  Statements 
	found = _search (&pPre, &pLoc, dataIn.key);
	if (found)
	   // Duplicate keys not allowed 
	   return (+1);
	
	success = _insert (pPre,  dataIn);
	if (!success)
	   // Overflow 
	   return (-1);
	return (0);
}	//  addNode 

/*	===================== _insert ==================== 
	Inserts data into a new node in the linked list.
	   Pre     Insertion location identified by pPre
	           dataIn contains data to be inserted
	   Post    data inserted in linked list or overflow
	   Return  true  if successful, false if overflow
*/
template <class TYPE, class KTYPE>
bool List<TYPE, KTYPE> :: _insert (NODE<TYPE> *pPre,  
                                   TYPE        dataIn)
{
//	Local Definitions 
	NODE <TYPE>  *pNew;

//	Statements 
	if (! (pNew = new NODE<TYPE>))
	   return false;
	
	pNew->data = dataIn; 
	pNew->link = NULL; 
		 
	if (pPre == NULL)
	   {
	    //  Adding before first node or to empty list. 
	    pNew->link = head;
	    head = pNew;
	   } // if pPre 
	else
	    {
	     // Adding in middle or at end 
	     pNew->link  = pPre->link;
	     pPre->link  = pNew;
	    } // if else  
	 
	     // Now check for add at end of list 
	     if (pNew->link == NULL)
	        // Adding to empty list. Set rear  
	        rear = pNew;

	count++;

	return true;
}	// _insert 

/* 	================== removeNode ================== 
	Removes data from linked list. 
	   Pre    dltkey is identifier of node to be deleted
	          pDataOut is pointer to data variable to 
	          receive a copy of the deleted data
	   Post   data copied to output variable and node
	          deleted or not found
	   Return false if not found
	          true  if deleted
*/
template <class TYPE, class KTYPE>
bool List<TYPE, KTYPE> ::  
          removeNode (KTYPE dltkey, TYPE *pDataOut)
{
//	Local Definitions 
	bool         found;
	NODE<TYPE>  *pPre;
	NODE<TYPE>  *pLoc;
	
//	Statements 
	found = _search (&pPre, &pLoc, dltkey);
	if (found)
	    _delete (pPre, pLoc, pDataOut);
	return found;
} // removeNode

/*	=================== _delete ================== 
	Deletes data from a linked list and returns 
	data to calling module.
	   Pre  pPre is a pointer to predecessor node
	        pLoc is a pointer to target node
	        pDataOut is pointer to output data area
	   Post Data have been deleted and returned 
	        Data memory has been recycled
*/
template <class TYPE, class KTYPE>
void List<TYPE, KTYPE> :: _delete (NODE<TYPE>   *pPre,
                                   NODE<TYPE>   *pLoc, 
                                   TYPE         *pDataOut) 
{
//	Statements 
	*pDataOut = pLoc->data;
	if (pPre == NULL)
	    // Deleting first node 
	    head = pLoc->link;  
	else
	    // Deleting any other node
	    pPre->link = pLoc->link;
	 
	// Test for deleting last node 
	if (pLoc->link == NULL)
	   rear = pPre;

	count--;
	delete pLoc;
  
	return;
}	//  _delete 

/*	=================== retrieveNode ================== 
	Interface to search function. 
	   Pre    key is the search argument
	          dataOut is variable to receive data
	   Post   dataOut contains located data if found
	          if not found, contents are unchanged
	   Return true if successful, false if not found
*/

template <class TYPE, class KTYPE>
bool List<TYPE, KTYPE> 
         :: retrieveNode (KTYPE  key, TYPE&  dataOut)
{
//	Local Definitions 
	bool          found;
	NODE <TYPE>  *pPre;
	NODE <TYPE>  *pLoc;

//	Statements 
	found = _search (&pPre, &pLoc, key);
	if (found)
	   dataOut = pLoc->data;
	return found;
}	// retrieveNode 

/*	==================== _search =================== 
	Searches list and passes back address of node 
	containing target and its logical predecessor.
	   Pre    pPre is pointer variable for predecessor
	          pLoc is pointer variable for found node
	          key  is search argument
	   Post   pLoc points to first node equal/greater key 
	          -or- null if target > key of last node
	          pPre points to largest node smaller than key
	          -or- null if target < key of first node
	   Return true if successful, false if not found
*/
template <class TYPE, class KTYPE> 
bool List<TYPE, KTYPE> :: _search (NODE<TYPE> **pPre,  
                                   NODE<TYPE> **pLoc,
                                   KTYPE        key)
{
//	Statements 
	*pPre  = NULL;
	*pLoc  = head;
	if (count == 0)
	    return false;
	
	// Test for argument > last node in list 
	if (key > rear->data.key) 
	   {
	    *pPre = rear;
	    *pLoc = NULL;
	    return false;
	   } // if 

	while (key > (*pLoc)->data.key)
	   {
	    //  Have not found search argument location 
	    *pPre = *pLoc;
	    *pLoc = (*pLoc)->link;
	   } // while 
	
	if (key == (*pLoc)->data.key)
	    //   argument found--success 
	    return true;
	else
	    return false;
}	//  _search 

/*	=============== emptyList ============== 
	Returns Boolean indicating whether the
	list is empty.
	   Pre    Nothing 
	   Return true if empty, false if list has data 
*/
template<class TYPE, class KTYPE> 
bool List<TYPE, KTYPE> :: emptyList (void) 
{
//	Statements 
 	return (count == 0);
}	//  emptyList 

/*	=================== fullList ================== 
	Returns Boolean indicating whether the list is full
	or has room for more data. 
	   Pre    Nothing 
	   Return true if full, false if room for another node
*/
template <class TYPE, class KTYPE>
bool List<TYPE, KTYPE> :: fullList (void) 
{
//	Local Definitions  
	NODE<TYPE>  *temp;

//	Statements 
	if (temp = new NODE<TYPE>)
	   {
	    delete temp;
	    return false;
	   } // if

	// Dynamic memory full 
	return true;
}	// fullList 

/*	==================== listCount ==================== 
	Returns integer representing number of nodes in list.
	   Pre     Nothing
	   Return  count for number of nodes in list
*/
template <class TYPE, class KTYPE>
int List<TYPE, KTYPE> :: listCount(void) 
{
//	Statements 
	return count;	
}	// listCount

/*	====================== getNext ===================== 
	getNext traverses a linked list. Each call either starts 
	at the beginning of the list or returns the location of  
	the element in the list that was last returned.
	   Pre   fromWhere is 0 to start at the first element
	         dataOut is reference to data variable 
	   Post   if another element, address placed in output area
	   Return true if another element located, 
	          false if end of list
*/
template <class TYPE, class KTYPE> 
bool List<TYPE, KTYPE> :: getNext (int    fromWhere,
                                   TYPE&  dataOut)
{
//	Local Definitions 
	bool success;

//	Statements 
	if (fromWhere == 0)
	   {
	    // Start from first node 
	    if (count == 0)
	        success = false;
	    else
	       {
	        pos      = head;
	        dataOut  = pos->data;
	        success  = true;
	       } // if else 
	   } // if fromwhere is zero
	else
	   {
	    // Continue from current position 
	    if (pos->link == NULL)
	        success = false;
	    else
	       {
	        pos      = pos->link;
	        dataOut  = pos->data;
	        success  = true;
	       } // if else 
	   } // if fromWhere else 
	
	return success;
}	// getNext