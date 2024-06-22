// Singly linked list structure plus stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-06-22
*/

#include "me_List.h"

#include <stdio.h> // printf()

#include <me_MemorySegment.h> // Reserve()/Release()
#include <me_BaseTypes.h>

using
  me_List::TListNode,
  me_List::TStack,
  me_List::TQueue,
  me_MemorySegment::TMemorySegment,
  me_BaseTypes::TBool,
  me_BaseTypes::TUint_2;

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
TBool SpawnNode(TListNode * * Node, TUint_2 Payload)
{
  TMemorySegment NodeSeg;

  if (!NodeSeg.Reserve(sizeof(TListNode)))
    return false;

  *Node = (TListNode *) NodeSeg.Start.Addr;

  (*Node)->Payload = Payload;

  return true;
}

/*
  Release memory of list node
*/
void KillNode(TListNode * Node)
{
  TMemorySegment NodeSeg;

  NodeSeg.Start.Addr = (TUint_2) Node;
  NodeSeg.Size = sizeof(TListNode);

  NodeSeg.Release();
}

// --

/*
  Indicator that list is empty
*/
TBool me_List::TStack::IsEmpty()
{
  return (Head == 0);
}

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
void me_List::TStack::Remove()
{
  if (IsEmpty())
    return;
  TListNode * NextHead = Head->Next;
  KillNode(Head);
  Head = NextHead;
}

/*
  Release memory of all list nodes
*/
void me_List::TStack::Release()
{
  while (!IsEmpty())
    Remove();
}

/*
  Iterate over list data

  For each element we call <Handler> with list node data and externally
  provided data.

  "Externally provided data" means you can use Traverse() to find item
  with specific value.
*/
void me_List::TStack::Traverse(
  TNodeHandler Handler,
  TUint_2 HandlerBaggage
)
{
  if (Handler == 0)
    return;

  TListNode * Cursor = Head;

  while (Cursor != 0)
  {
    Handler(Cursor->Payload, HandlerBaggage);
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
  2024-06-20 IsEmpty()
*/
