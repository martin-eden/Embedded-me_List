// Singly linked list structure, stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-06-11
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

    // Debug print
    void PrintWrappings();
  };

  // List node handler function format
  typedef TBool (*TNodeHandler)(TUint_2);

  // Allocate memory for list node
  TBool SpawnNode(TListNode * * Node);
  // Free memory of list node
  TBool KillNode(TListNode * Node);
  // Iterate over list calling handler for every node
  TBool Traverse(TListNode * StartPtr, TNodeHandler Handler);
  // Shortcut for Traverse(.., KillNode)
  TBool KillList(TListNode * StartPtr);

  // Stack structure
  struct TStack
  {
    TListNode * Head;

    TStack() : Head(0) {};

    // Add node
    void Add(TListNode * Node);
  };

  // Queue structure
  struct TQueue
  {
    TListNode * Head;
    TListNode * Tail;

    TQueue() : Head(0), Tail(0) {};

    // Add node
    void Add(TListNode * Node);
  };
}

/*
  2024-05-14
  2024-05-29
  2024-06-02
  2024-06-11
*/
