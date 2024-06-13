// Singly linked list structure plus stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-06-13
*/

#include "me_List.h"

#include <Arduino.h> // malloc(), free(), printf()
#include <me_BaseTypes.h>

using
  me_List::TListNode,
  me_BaseTypes::TBool;

/*
  Print contents of structure to stdout in human-readable format.

  Useful for debug/testing.
*/
void TListNode::PrintWrappings()
{
  printf("[TListNode 0x%04X]", (TUint_2) this);
  printf(" ");
  printf("( Data 0x%04X Next 0x%04X )", Payload, (TUint_2) Next);
  printf("\n");
}

/*
  Allocate memory for list node with given data
*/
TBool me_List::SpawnNode(
  TListNode * * NodePtr,
  TUint_2 Payload,
  TListNode * Next
)
{
  *NodePtr = (TListNode *) malloc(sizeof(TListNode));

  TBool IsSpawned = (*NodePtr != 0);

  if (!IsSpawned)
    return false;

  (*NodePtr)->Payload = Payload;
  (*NodePtr)->Next = Next;

  return true;
}

/*
  Release memory of list node
*/
TBool me_List::KillNode(TListNode * Node)
{
  if (Node == 0)
    return false;

  // Node->PrintWrappings();

  Node->Payload = 0;
  Node->Next = 0;

  free(Node);

  return true;
}

// --

/*
  Add node with given data to stack structure
*/
TBool me_List::TStack::Add(TUint_2 Payload)
{
  TListNode * Node;

  if (!SpawnNode(&Node, Payload, Head))
    return false;

  Head = Node;

  return true;
}

/*
  Iterate over list data

  For each element we call <Handler> with list node data and externally
  provided data. If <Handler> returns false, iteration is stopped.

  If iteration wasn't stopped we return true.

  "Externally provided data" means you can use Traverse() to find item
  with specific value. Or you can address of your structure there and
  address of you method, so it becomes method call.
*/
TBool me_List::TStack::Traverse(
  TNodeHandler Handler,
  TUint_2 HandlerData
)
{
  if (Handler == 0)
    return false;

  TListNode * Cursor = Head;

  while (Cursor != 0)
  {
    if (!Handler(Cursor->Payload, HandlerData))
      return false;

    Cursor = Cursor->Next;
  }

  return true;
}

// Shortcut for Traverse() without <HandlerData>
TBool me_List::TStack::Traverse(TNodeHandler Handler)
{
  return Traverse(Handler, 0);
}

/*
  Release memory of all list nodes
*/
void me_List::TStack::Release()
{
  TListNode * Cursor = Head;

  while (Cursor != 0)
  {
    TListNode * NextNode = Cursor->Next;

    KillNode(Cursor);

    Cursor = NextNode;
  }

  Head = 0;
}

// --

/*
  Add node with given data to queue structure
*/
TBool me_List::TQueue::Add(TUint_2 Payload)
{
  TListNode * Node;

  if (!SpawnNode(&Node, Payload, 0))
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
*/
