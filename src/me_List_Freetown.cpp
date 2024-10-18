// List node free functions

/*
  Author: Martin Eden
  Last mod.: 2024-10-18
*/

#include "me_List.h"

#include <me_BaseTypes.h>
#include <me_MemorySegment.h> // TMemorySegment

using namespace me_List;

using
  me_MemorySegment::TMemorySegment,
  me_MemorySegment::Freetown::Reserve,
  me_MemorySegment::Freetown::Release;

/*
  Allocate memory for list node with given data
*/
TBool Freetown::SpawnNode(
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
void Freetown::KillNode(
  TListNode * Node
)
{
  using
    me_MemorySegment::Freetown::FromAddrSize;

  TMemorySegment NodeSeg =
    FromAddrSize((TUint_2) Node, sizeof(TListNode));

  Release(&NodeSeg);
}

/*
  2024-05-14
  ...
  2024-10-05
  2024-10-18
*/
