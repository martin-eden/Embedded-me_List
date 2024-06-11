// [me_List] test/debug

/*
  Author: Martin Eden
  Last mod.: 2024-06-11
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

void Test()
{
  using
    me_List::TStack,
    me_List::TQueue,
    me_List::TListNode;

  TStack List;
  // TQueue List;

  for (TUint_2 Counter = 1; Counter <= 4; ++Counter)
  {
    TListNode * Node;

    if (!SpawnNode(&Node))
      break;

    Node->Data = Counter;

    List.Add(Node);
  }

  Traverse(List.Head, PrintNode);

  KillList(List.Head);
}

me_BaseTypes::TBool PrintNode(me_BaseTypes::TUint_2 Data)
{
  printf("Data(%u)", Data);
  printf("\n");

  return true;
}

/*
  2024-05-14
  2024-06-02
  2024-06-11
*/
