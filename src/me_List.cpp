// Singly linked list structure plus stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
*/

#include <me_List.h>

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>
#include <me_MemorySegment.h> // Release(), Reserve() ..

using namespace me_List;

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
TBool TStack::Add(
  TUint_2 Payload
)
{
  TListNode * Node;

  if (!Freetown::SpawnNode(&Node, Payload))
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
  Freetown::KillNode(Head);
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
TBool TQueue::Add(
  TUint_2 Payload
)
{
  TListNode * Node;

  if (!Freetown::SpawnNode(&Node, Payload))
    return false;

  if (Head == 0)
    Head = Node;

  if (Tail != 0)
    Tail->Next = Node;

  Tail = Node;

  return true;
}

// ( Freetown

/*
  Allocate memory for list node with given data
*/
TBool Freetown::SpawnNode(
  TListNode * * Node,
  TUint_2 Payload
)
{
  using
    me_MemorySegment::Freetown::Reserve;

  TAddressSegment NodeSeg;

  if (!Reserve(&NodeSeg, sizeof(TListNode)))
    return false;

  *Node = (TListNode *) NodeSeg.Addr;

  (*Node)->Payload = Payload;

  return true;
}

/*
  Release memory of list node
*/
void Freetown::KillNode(
  TListNode * Node
)
{
  using
    me_MemorySegment::Freetown::FromAddrSize,
    me_MemorySegment::Freetown::Release;

  TAddressSegment NodeSeg =
    FromAddrSize((TUint_2) Node, sizeof(TListNode));

  Release(&NodeSeg);
}

// ) Freetown

// --

/*
  2024 # # # # # # #
*/
