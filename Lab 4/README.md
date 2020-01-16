# Pseudo-Codes

	Now different functions can be constructed for the operations in the doubly linked list. The Pseudo code of those operations are written as follows:
Create node:
Declare a new temporary node
temporary->data = value
temporary->next = NULL
temporary->previus = NULL    
head = temporary		
tail = temporary
temporary = NULL

Inserting the node in the start:
Create a new node
Enter the value you wish to enter 
node-> data = value 
Node ->next = head
Node->previous = null
Head = node 

Inserting node in the end:
Create a node 
Enter the value you wish to enter 
Node -> data= value 
Node ->next = null
Node->previous = tail 
Tail->next = node 
Tail = node  

Inserting the node in the middle:
Create a node 
Enter the value of node you wish to enter
Enter the position at which you enter 
Create a pointer p pointing towards head 
For i = 0, i <position, i++ 
P= p->next
New pointer q = p->previus
Temp ->data = value 
q->next = temporary
temporary->previus = q
temporary->next = p
p->previus = temporary

Deleting node from start:
Pointer temporary = head
If there are more than one elements in the list
head = head->next
head->previus = NULL
delete temporary
free temporary

Deleting node from end:
Pointer temporary =tail 
If there are more than one element in the list
tail = tail->previus
tail->next = NULL
delete temporary
free temporary

Deleting node from middle:
Create a pointer temporary pointing to head
Enter the position you want to delete 
For i = 1 ,  i < position , i++
temporary = temporary ->next 
declare two pointers p and q
p = temporary->previus
q = temporary->next
p->next = q
q->previus = p
delete temporary
temporary = NULL

Display list:
Create a pointer temporary
temporary = head 
While (temporary ->next !=null)
Print temporary ->data 
temporary = temporary ->next 
End 

Search element in the list:
temporary = head
c = head
counter i
while number not found in the list
temporary = c
c = c->next
i++
if number is found
number = c
c = c->next
print: place of number
else
print: number not found

Display list in reverse order:
Create a pointer pointing to tail
temporary = tail 
While (temporary ->previous !=null)
Print temporary p->data 
temporary = temporary ->previous 
End 

Destroy List:
For (I = 1; I <= no. of elements in the list; i++)
	Call the founction delete from end;
