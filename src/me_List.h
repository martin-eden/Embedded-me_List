// Singly linked list structure, stack and queue containers

/*
  Author: Martin Eden
  Last mod.: 2025-08-27
*/

#pragma once

#include <me_BaseTypes.h>
#include <me_BaseInterfaces.h>

namespace me_List
{
  /*
    List node

    Data field is TUint_2 and called "Payload". We make no assumptions
    about it. In practice it holds pointer to your memory structure.
  */
  struct TListNode
  {
    TUint_2 Payload;
    struct TListNode * Next;
  };

  /*
    Stack structure

    Using one cell of memory we can track start of list. So it is stack.
  */
  class TStack
  {
    protected:
      TListNode * Head;

    public:
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
      void Traverse(TMethod Handler, TUint_2 HandlerState = 0);
  };

  /*
    Queue structure

    Using two cells of memory we can track start and end of list.

    So Add() now has freedom to which end to add. But meh, if
    you want add to start, just use TStack. Here Add() adds to tail,
    it's queue.
  */
  class TQueue : public TStack
  {
    protected:
      TListNode * Tail;

    public:
      TQueue() : Tail(0) {};

      // Add node
      TBool Add(TUint_2 Payload);
  };

  namespace Freetown
  {
    // Allocate memory for list node with given data
    TBool SpawnNode(
      TListNode * * Node,
      TUint_2 Payload
    );

    // Release memory of list node
    void KillNode(
      TListNode * Node
    );
  }
}

/*
  2024 # # # # # # # # # #
*/
