// [me_List] test/debug

/*
  Author: Martin Eden
  Last mod.: 2024-06-27
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
  me_BaseTypes::TUint_2;

// Forwards:
void PrintNode(TUint_2 Data, TUint_2 State);

// Show stuff
void Test()
{
  /*
    We will create stack (or maybe queue), add some numbers to it,
    print them and release memory.

    Notes

      * List.Release() releases memory explicitly. It's safe to call it
        more than once.

        Here memory is released when <List> variable leaves scope at the
        end of function.

      * List.Add() returns false when there is no memory for node.

        We are not checking it here because we don't care.

      * Test for memory leaks

        Try to add more nodes than memory. Like 4000. Print list.
        Call twice.
  */

  // me_List::TStack List;
  me_List::TQueue List;

  for (TUint_2 Counter = 1; Counter <= 4; ++Counter)
    List.Add(Counter);

  List.Traverse(PrintNode);
}

/*
  Node handler

  First argument is list item data. Second is second piggyback argument
  from Traverse().

  For egocentric functions you need just your data.

  For handlers like "find node with minimum value" you want to store
  your findings somewhere. Or load additional data from somewhere,
  if you are doing "find node with this value". That's why second
  argument. Typically both arguments are pointers.
*/
void PrintNode(
  TUint_2 Data,
  TUint_2 State __attribute__((unused))
)
{
  printf("Data(%u)\n", Data);
}

/*
  2024-05-14
  2024-06-02
  2024-06-11
  2024-06-13
  2024-06-15
  2024-06-27
*/
