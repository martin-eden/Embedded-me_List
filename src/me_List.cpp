// Singly linked list structure plus stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-10-05
*/

#include "me_List.h"

#include <me_BaseTypes.h>

using namespace me_List;

using
  me_List::Freetown::SpawnNode,
  me_List::Freetown::KillNode;

/*
  Indicator that list is empty
*/
TBool TStack::IsEmpty()
{
  return (Head == 0);
}

/*
  Add node with given data to stack structure

  Returns false when no memory.
*/
TBool TStack::Add(TUint_2 Payload)
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
void TStack::Remove()
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
void TStack::Release()
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
void TStack::Traverse(
  TMethod Handler,
  TUint_2 HandlerState
)
{
  if (Handler == 0)
    return;

  TListNode * Cursor = Head;

  while (Cursor != 0)
  {
    Handler(Cursor->Payload, HandlerState);
    Cursor = Cursor->Next;
  }
}

// --

/*
  Add node with given data to queue structure

  Returns false when there are no memory.
*/
TBool TQueue::Add(TUint_2 Payload)
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
  2024-10-05 Freetown
*/
