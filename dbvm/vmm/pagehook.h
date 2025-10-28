#ifndef PAGEHOOK_H_
#define PAGEHOOK_H_

/*

vmmhelper.h::tcpuinfo增加成员

  int eptHookPendingID;
  PPTE_PAE eptHookPendingPTE;
  _PTE_PAE eptHookPendingPTEValue;
  QWORD eptHookPendingRIPPfn;
*/

//插入到vmcall.c::_handleVMCallInstruction
void eptHookVMCALL(pcpuinfo currentcpuinfo, VMRegisters *vmregisters, ULONG *vmcall_instruction);
//插入到epthandler.c::handleEPTViolation、nphandler.c::handleNestedPagingFault
BOOL eptHookHandleEvent(pcpuinfo currentcpuinfo, QWORD Address);
//插入到 vmeventhandler_amd.c::handleVMEvent_amd
void eptHookNPEventHandle(pcpuinfo currentcpuinfo);

#endif