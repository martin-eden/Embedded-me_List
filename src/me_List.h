// Singly linked list structure, stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2024-06-22
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
  typedef void (*TNodeHandler)(TUint_2 NodePayload, TUint_2 HandlerData);

  /*
    Stack structure

    Using one cell of memory we can track start of list. So it is stack.
  */
  struct TStack
  {
    TStack() : Head(0) {};
    ~TStack() { Release(); };

    // Emptiness indicator
    TBool IsEmpty();
    // Add node with data to start
    TBool Add(TUint_2 Payload);
    // Remove first node
    void Remove();
    // Release memory of all nodes
    void Release();
    // Iterate over list calling handler for every node
    void Traverse(TNodeHandler Handler, TUint_2 HandlerData = 0);

    protected:
      TListNode * Head;
  };

  /*
    Queue structure

    Using two cells of memory we can track start and end of list.

    So Add() now has freedom to which end to add. But meh, if
    you want add to start, just use TStack. Here Add() adds to tail,
    it's queue.

    Ability to add to arbitrary list end is possible but I found no
    practical usage for it.
  */
  struct TQueue : TStack
  {
    TQueue() : Tail(0) {};

    // Add node
    TBool Add(TUint_2 Payload);

    protected:
      TListNode * Tail;
  };
}

/*
  2024-05-14
  2024-05-29
  2024-06-02
  2024-06-11
  2024-06-13
  2024-06-15
  2024-06-21
  2024-06-22 Hid SpawnNode()/KillNode()
*/
