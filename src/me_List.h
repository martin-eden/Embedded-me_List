// Singly linked list structure, stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-06-13
*/

#pragma once

#include <me_BaseTypes.h>

namespace me_List
{
  using
    me_BaseTypes::TUint_2,
    me_BaseTypes::TBool;

  /*
    List node

    Data field is TUint_2 and called "Payload". We make no assumptions
    about it. In practice it holds pointer to your memory structure.
  */
  struct TListNode
  {
    TUint_2 Payload;
    struct TListNode * Next;

    // Debug print
    void PrintWrappings();
  };

  /*
    List node handler function format

    I want <Handler> to have access not only to node data but to
    its own data too. So I can use Traverse() for more than just
    printing list of nodes but also for finding specific data.

    So for iterator it is three-address format: Handler, HandlerData,
    NodeData.
  */
  typedef TBool (*TNodeHandler)(TUint_2 NodePayload, TUint_2 HandlerData);

  // Allocate memory for list node with given data
  TBool SpawnNode(TListNode * * Node, TUint_2 Payload, TListNode * Next);
  // Free memory of list node
  TBool KillNode(TListNode * Node);

  /*
    Stack structure

    Using one cell of memory we can track start of list. So it is stack.
  */
  struct TStack
  {
    TListNode * Head;

    TStack() : Head(0) {};
    ~TStack() { Release(); };

    // Add node with data to start
    TBool Add(TUint_2 Payload);
    // Remove first node
    TBool Remove();
    // Iterate over list calling handler for every node
    TBool Traverse(TNodeHandler Handler, TUint_2 HandlerData);
    TBool Traverse(TNodeHandler Handler);
    // Release memory of all nodes
    void Release();

    void PrintWrappings();
    void Print();
  };

  /*
    Queue structure

    Using two cells of memory we can track start and end of list.

    So Add() now has freedom to which end to add. But meh, if
    you want add to start, just use TStack. Here Add() adds to tail,
    it's queue.

    Ability to add to arbitrary list end is possible but I found no
    practical usage for it. So Add() method is just overridden.
  */
  struct TQueue : TStack
  {
    TListNode * Tail;

    TQueue() : Tail(0) {};

    // Add node
    TBool Add(TUint_2 Payload);
  };
}

/*
  2024-05-14
  2024-05-29
  2024-06-02
  2024-06-11
  2024-06-13
*/
