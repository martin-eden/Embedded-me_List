// List node free functions

/*
  Author: Martin Eden
  Last mod.: 2024-10-05
*/

#include "me_List.h"

#include <me_BaseTypes.h>
#include <me_MemorySegment.h> // TMemorySegment
#include <me_ManagedMemory.h> // me_ManagedMemory::Freetown::(Reserve/Release)()

using
  me_List::TListNode,
  me_MemorySegment::TMemorySegment,
  me_ManagedMemory::Freetown::Reserve,
  me_ManagedMemory::Freetown::Release;

/*
  Allocate memory for list node with given data
*/
TBool me_List::Freetown::SpawnNode(
  TListNode * * Node,
  TUint_2 Payload
)
{
  TMemorySegment NodeSeg;

  if (!Reserve(&NodeSeg, sizeof(TListNode)))
    return false;

  *Node = (TListNode *) NodeSeg.Start.Addr;

  (*Node)->Payload = Payload;

  return true;
}

/*
  Release memory of list node
*/
void me_List::Freetown::KillNode(
  TListNode * Node
)
{
  TMemorySegment NodeSeg;

  NodeSeg.Start.Addr = (TUint_2) Node;
  NodeSeg.Size = sizeof(TListNode);

  Release(&NodeSeg);
}

/*
  2024-05-14
  ...
  2024-10-05
*/
