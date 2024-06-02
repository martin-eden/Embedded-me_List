// [me_List] test/debug

/*
  Author: Martin Eden
  Last mod.: 2024-06-02
*/

#include <me_List.h>

#include <me_UartSpeeds.h>
#include <me_InstallStandardStreams.h>
#include <me_BaseTypes.h>

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

void Test()
{
  using
    me_List::TQueue,
    me_List::TListNode,
    me_BaseTypes::TUint_2,
    me_BaseTypes::TBool;

  // TStack List;
  TQueue List;

  for (TUint_2 Counter = 1; Counter <= 4; ++Counter)
  {
    TListNode * Node;

    if (!SpawnNode(&Node))
      break;

    Node->Data = Counter;

    List.Add(Node);
  }

  PrintList(List.Head);

  KillList(List.Head);
}

me_BaseTypes::TBool PrintList(me_List::TListNode * FirstNode)
{
  return Traverse(FirstNode, PrintNode);
}

me_BaseTypes::TBool PrintNode(me_List::TListNode * Node)
{
  Node->PrintWrappings();
  printf("\n");

  return true;
}

/*
  2024-05-14
  2024-06-02
*/
