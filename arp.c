#include "precomp.h"

/* ArpCache is what keeps unique entries in driver */
struct ARP_CACHE_NODE * ArpCache = NULL;

ULONG ACNTAG = 'cpr@';


void DebugPrintARPHeader(struct ARP_HEADER * arph)
{
	DbgPrint("ARP Header { Hardware type : %d, Protocol type : %d",
		RtlUshortByteSwap(arph->HardwareType), arph->ProtocolType );
	DbgPrint("             Hardware size : %d, Protocol size : %d",
		arph->HardwareSize, arph->ProtocolSize );
	DbgPrint("             Operate code : %d", RtlUshortByteSwap(arph->OperateCode) );
	DbgPrint("             Source MAC : %x:%x:%x-%x:%x:%x, Destination MAC : %x:%x:%x-%x:%x:%x", 
		arph->SourceMACAddress[0], arph->SourceMACAddress[1], arph->SourceMACAddress[2], 
		arph->SourceMACAddress[3], arph->SourceMACAddress[4], arph->SourceMACAddress[5], 
		arph->DestinationMACAddress[0], arph->DestinationMACAddress[1], arph->DestinationMACAddress[2], 
		arph->DestinationMACAddress[3], arph->DestinationMACAddress[4], arph->DestinationMACAddress[5] 
	);
	DbgPrint("             Source IP : %d.%d.%d.%d, Destination IP : %d.%d.%d.%d }",
		arph->SourceIPAddress[0], arph->SourceIPAddress[1], arph->SourceIPAddress[2], arph->SourceIPAddress[3], 
		arph->DestinationIPAddress[0], arph->DestinationIPAddress[1], arph->DestinationIPAddress[2], arph->DestinationIPAddress[3] );

}

struct ARP_CACHE_NODE * CreateNode(struct ARP_HEADER * arph)
{
	struct ARP_CACHE_NODE * acn = ExAllocatePoolWithTag(NonPagedPool, sizeof(struct ARP_CACHE_NODE), ACNTAG);
	if (!acn){
		DbgPrint("ERROR_ARPC_CN_NO_ALLOC : %s", ERROR_ARPC_CN_NO_ALLOC );
		return NULL;
	}
	// acn -> arph = arph; // this would have been a crime. Copy the memory using copy_memory
	RtlCopyMemory(&acn ->arph, arph, sizeof(struct ARP_HEADER));
	if(!ArpCache){
		acn -> next = NULL;
		ArpCache = acn;
	} else {
		acn -> next = ArpCache;
		ArpCache = acn;
	}

	return acn;
}

enum ArpCacheEntrySearchResult SearchForNode(struct ARP_HEADER * arph)
{
	struct ARP_CACHE_NODE * tn = ArpCache;

	if(tn == NULL){
		return ACESR_NotFound;
	}

	while(tn != NULL){
		if(sizeof(struct ARP_HEADER) == 
			RtlCompareMemory(arph, &tn->arph, sizeof(struct ARP_HEADER))){
			/*note: use RtlCompareMemory only if arph, and tn->arph are both resident. */
			return ACESR_Found;
		}
		if((sizeof arph->SourceMACAddress) == 
			RtlCompareMemory(arph->SourceMACAddress, 
							tn->arph.SourceMACAddress, 
							sizeof arph->SourceMACAddress)){
			return ACESR_FoundMAC;
		}

		if((sizeof arph->SourceIPAddress) == 
			RtlCompareMemory(arph->SourceIPAddress, 
							tn->arph.SourceIPAddress, 
							sizeof arph->SourceIPAddress)){
			return ACESR_FoundIP;
		}
	}

	return ACESR_NotFound;
}

void AddArpCacheNode(struct ARP_HEADER *arph)
{
	struct ARP_CACHE_NODE * newNode = CreateNode(arph);
	
	if(!newNode)
		return;


}