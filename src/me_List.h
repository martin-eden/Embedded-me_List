// Singly linked list structure, stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-06-02
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_List
{
  using
    me_BaseTypes::TUint_2,
    me_BaseTypes::TBool;

  // List node
  struct TListNode
  {
    TUint_2 Data;
    struct TListNode * Next;

    void PrintWrappings();
  };

  // List node handler function format
  typedef TBool (*TNodeHandler)(TListNode*);

  // Allocate memory for list node
  TBool SpawnNode(TListNode * * Node);
  // Free memory of list node
  TBool KillNode(TListNode * Node);
  // Iterate over list calling handler for every node
  TBool Traverse(TListNode * StartPtr, TNodeHandler Handler);
  // Shortcut for Traverse(.., KillNode)
  TBool KillList(TListNode * StartPtr);

  // Stack container
  struct TStack
  {
    TStack() : Head(0) {};

    TListNode * Head;
    void Add(TListNode * Node);
  };

  // Queue container
  struct TQueue
  {
    TQueue() : Head(0), Tail(0) {};

    TListNode * Head;
    TListNode * Tail;
    void Add(TListNode * Node);
  };
}

/*
  2024-05-14
  2024-05-29
  2024-06-02
*/
