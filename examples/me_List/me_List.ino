// [me_List] test/debug

/*
  Author: Martin Eden
  Last mod.: 2024-06-13
*/

#include <me_List.h>

#include <me_UartSpeeds.h>
#include <me_InstallStandardStreams.h>
#include <me_BaseTypes.h>

// Forwards:
void Test();

void setup()
{
  Serial.begin(me_UartSpeeds::Arduino_Normal_Bps);
  InstallStandardStreams();

  printf("[me_List] Hello there.\n");
  Test();
  printf("Done.\n");
}

void loop()
{
}

// --

using
  me_BaseTypes::TBool,
  me_BaseTypes::TUint_2;

// Forwards:
TBool PrintNode(TUint_2 NodeData, TUint_2 HandlerData);

// Show stuff
void Test()
{
  /*
    We will create stack (or maybe queue) list, add some numbers to it,
    print it and release memory.

    Actually memory will be released when <List> variable leave scope
    i.e. at end of function. So List.Release() here is not strictly
    needed.

    * Memory leaks test

      You can test that memory is properly released by trying to
      allocate more nodes that can be fit into memory and calling this
      function several times: "Counter <= 4000, Test(); Test();"

      Number of nodes allocated and printed should stay the same.

    * No memory condition

      When we have no memory to allocate next node,
      Add() will return false.
  */

  // me_List::TStack List;
  me_List::TQueue List;

  for (TUint_2 Counter = 1; Counter <= 4; ++Counter)
    List.Add(Counter);

  List.Traverse(PrintNode);

  List.Release();
}

/*
  Node handler

  For egocentric functions you need just your data.

  For cases like "find node with minimum value" you want to store
  your findings somewhere. Or load additional data from somewhere,
  if you are doing "find node with this value". That's why second
  address, <HandlerData>. Put there address of your object and you
  can call it's methods.

  When handler returns false it means iteration over list should
  be stopped.
*/
TBool PrintNode(
  TUint_2 NodeData,
  TUint_2 HandlerData __attribute__((unused))
)
{
  printf("Data(%u)\n", NodeData);

  return true;
}

/*
  2024-05-14
  2024-06-02
  2024-06-11
  2024-06-13
*/
