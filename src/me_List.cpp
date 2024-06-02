// Singly linked list structure plus stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-06-02
*/

#include "me_List.h"

#include <Arduino.h> // malloc(), free(), printf()
#include <me_BaseTypes.h>

using
  me_List::TListNode,
  me_BaseTypes::TBool;

void TListNode::PrintWrappings()
{
  printf("[TListNode 0x%04X]", (TUint_2) this);
  printf(" ");
  printf("( Data 0x%04X Next 0x%04X )", Data, (TUint_2) Next);
}

TBool me_List::SpawnNode(TListNode * * NodePtr)
{
  *NodePtr = (TListNode *) malloc(sizeof(TListNode));

  TBool IsSpawned = (*NodePtr != 0);

  if (!IsSpawned)
    return false;

  (*NodePtr)->Data = 0;
  (*NodePtr)->Next = 0;

  // printf("SpawnNode(0x%04X)\n", (TUint_2) *Node);

  return true;
}

TBool me_List::KillNode(TListNode * Node)
{
  // printf("KillNode(0x%04X)\n", (TUint_2) Node);

  if (Node == 0)
    return false;

  free(Node);

  return true;
}

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

TBool me_List::KillList(TListNode * FirstNode)
{
  return Traverse(FirstNode, KillNode);
}

// --

void me_List::TStack::Add(TListNode * Node)
{
  Node->Next = Head;
  Head = Node;
}

// --

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
