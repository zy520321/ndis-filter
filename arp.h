#ifndef FLTR_ARP_H
#define FLTR_ARP_H

struct ARP_HEADER {
	/*
	<----------------- 4 Bytes ------------------------>
	____________________________________________________
	  Hardware type         |  Protocol type
	----------------------------------------------------
	  HW length | Prot Len  |  Operation Req 1, Rep 2
	----------------------------------------------------
	  Sender MAC 4 Bytes (HW address of sender)
	----------------------------------------------------
	  Sender MAC 2 Bytes    |  Sender IP 2 Bytes
	----------------------------------------------------
	  Sender IP 2 Bytes     |  Destination MAC 2 Bytes
	----------------------------------------------------
	  Destination MAC 4 Bytes (HW addr of target)
	----------------------------------------------------
	  Destination IP 4 Bytes
	____________________________________________________

	ARP Header

	*/

	USHORT		HardwareType;				// 0x0001 (big endian on network)			// 2
	USHORT		ProtocolType;				// ntohs(0x800)	// 4

	UCHAR		HardwareSize;				// 6 MAC		// 5
	UCHAR		ProtocolSize;				// 4 IPv4		// 6

	USHORT		OperateCode;				// 1 req, 2 rep	// 8

	UCHAR		SourceMACAddress[6];						//14
	UCHAR		SourceIPAddress[4];							//18

	UCHAR		DestinationMACAddress[6];					//24
	UCHAR		DestinationIPAddress[4];					//28
};

void DebugPrintARPHeader(struct ARP_HEADER * arph);

struct ARP_CACHE_NODE{
	struct ARP_HEADER arph;
	struct ARP_HEADER * next;
};

enum ArpCacheEntrySearchResult{
	ACESR_Found,
	ACESR_FoundMAC,
	ACESR_FoundIP,
	ACESR_NotFound
};


#endif