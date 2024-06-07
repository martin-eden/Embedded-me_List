// Singly linked list structure plus stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-06-07
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
  printf("( Data 0x%04X Next 0x%04X )", Data, (TUint_2) Next);
}

/*
  Allocate memory for list node
*/
TBool me_List::SpawnNode(TListNode * * NodePtr)
{
  *NodePtr = (TListNode *) malloc(sizeof(TListNode));

  TBool IsSpawned = (*NodePtr != 0);

  if (!IsSpawned)
    return false;

  (*NodePtr)->Data = 0;
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

  Node->Data = 0;
  Node->Next = 0;

  free(Node);

  return true;
}

/*
  Iterate over list

  Iteration starts from <FirstNode> element.
  For each element we call <Handler> with list node.
  If <Handler> fails, iteration is stopped.

  If iteration wasn't stopped we return true.
*/
TBool me_List::Traverse(TListNode * FirstNode, TNodeHandler Handler)
{
  if (Handler == 0)
    return false;

  TListNode * Cursor = FirstNode;
  while (Cursor != 0)
  {
    if (!Handler(Cursor))
      return false;

    Cursor = Cursor->Next;
  }

  return true;
}

/*
  Release memory of all list nodes
*/
TBool me_List::KillList(TListNode * FirstNode)
{
  TListNode * Cursor = FirstNode;
  while (Cursor != 0)
  {
    TListNode * NextNode = Cursor->Next;
    KillNode(Cursor);
    Cursor = NextNode;
  }
  return true;
}

// --

/*
  Add node to stack structure
*/
void me_List::TStack::Add(TListNode * Node)
{
  Node->Next = Head;
  Head = Node;
}

// --

/*
  Add node to queue structure
*/
void me_List::TQueue::Add(TListNode * Node)
{
  if (Head == 0)
    Head = Node;

  if (Tail != 0)
    Tail->Next = Node;

  Tail = Node;
}

// --

/*
  2024-05-14
  2024-06-02
*/
