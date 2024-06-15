// Singly linked list structure plus stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-06-15
*/

#include "me_List.h"

#include <Arduino.h> // malloc(), free(), printf()
#include <me_BaseTypes.h>

using
  me_List::TListNode,
  me_BaseTypes::TBool;

/*
  Print contents of node structure to stdout in human-readable format.

  Useful for debug/testing.
*/
void TListNode::PrintWrappings()
{
  printf("[TListNode 0x%04X]", (TUint_2) this);
  printf(" ");
  printf("( Payload 0x%04X Next 0x%04X )", Payload, (TUint_2) Next);
  printf("\n");
}

/*
  Allocate memory for list node with given data
*/
TBool me_List::SpawnNode(TListNode * * NodePtr, TUint_2 Payload)
{
  *NodePtr = (TListNode *) malloc(sizeof(TListNode));

  TBool IsSpawned = (*NodePtr != 0);

  if (!IsSpawned)
    return false;

  (*NodePtr)->Payload = Payload;
  (*NodePtr)->Next = 0;

  return true;
}

/*
  Release memory of list node
*/
TBool me_List::KillNode(TListNode * Node)
{
  if (Node == 0)
    return false;

  Node->Payload = 0;
  Node->Next = 0;

  free(Node);

  return true;
}

// --

/*
  Add node with given data to stack structure

  Returns false when no memory.
*/
TBool me_List::TStack::Add(TUint_2 Payload)
{
  TListNode * Node;

  if (!SpawnNode(&Node, Payload))
    return false;

  Node->Next = Head;
  Head = Node;

  return true;
}

/*
  Remove (first) node from structure

  Returns false when structure is empty.
*/
TBool me_List::TStack::Remove()
{
  if (Head == 0)
    return false;

  TListNode * NextHead = Head->Next;

  KillNode(Head);

  Head = NextHead;

  return true;
}

/*
  Release memory of all list nodes
*/
void me_List::TStack::Release()
{
  while (Remove());
}

/*
  Iterate over list data

  For each element we call <Handler> with list node data and externally
  provided data.

  "Externally provided data" means you can use Traverse() to find item
  with specific value. Or you can put address of your structure there
  so with address of you method it becomes method call.
*/
void me_List::TStack::Traverse(
  TNodeHandler Handler,
  TUint_2 HandlerData
)
{
  if (Handler == 0)
    return;

  TListNode * Cursor = Head;

  while (Cursor != 0)
  {
    Handler(Cursor->Payload, HandlerData);

    Cursor = Cursor->Next;
  }
}

// --

/*
  Add node with given data to queue structure

  Returns false when there are no memory.
*/
TBool me_List::TQueue::Add(TUint_2 Payload)
{
  TListNode * Node;

  if (!SpawnNode(&Node, Payload))
    return false;

  if (Head == 0)
    Head = Node;

  if (Tail != 0)
    Tail->Next = Node;

  Tail = Node;

  return true;
}

// --

/*
  2024-05-14
  2024-06-02
  2024-06-13 Add() works with payload, Traverse() inside, TQueue is inherited
  2024-06-15 Traverse() is always iterates all list, no mid-stops
*/
