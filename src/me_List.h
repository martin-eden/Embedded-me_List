// Singly linked list structure, stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-05-30
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_List
{
  using
    me_BaseTypes::TUint_2,
    me_BaseTypes::TBool;

  typedef TUint_2 TPtr;

  // List node
  struct TNode
  {
    TPtr DataPtr;
    struct TNode * NextNode;

    void PrintWrappings();
  };

  // Pointer to node
  typedef TNode * TNodePtr;

  // Signature of list node handler function
  typedef TBool (*THandler)(TNodePtr);

  // Allocate memory for list node
  TBool SpawnNode(TNodePtr * NodePtr);
  // Free memory of list node
  TBool KillNode(TNodePtr NodePtr);
  // Iterate over list calling handler for every node
  TBool Traverse(TNodePtr StartPtr, THandler Handler);
  // Shortcut for Traverse(.., KillNode)
  TBool KillList(TNodePtr StartPtr);

  // Stack container
  struct TStack
  {
    TStack() : HeadPtr(0) {};

    TNodePtr HeadPtr;
    void Add(TNodePtr NodePtr);
  };

  // Queue container
  struct TQueue
  {
    TQueue() : HeadPtr(0), TailPtr(0) {};

    TNodePtr HeadPtr;
    TNodePtr TailPtr;
    void Add(TNodePtr NodePtr);
  };
}

/*
  2024-05-14
  2024-05-29
*/
